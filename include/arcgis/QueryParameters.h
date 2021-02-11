// COPYRIGHT 1995-2016 ESRI
// TRADE SECRETS: ESRI PROPRIETARY AND CONFIDENTIAL
// Unpublished material - all rights reserved under the
// Copyright Laws of the United States and applicable international
// laws, treaties, and conventions.
//
// For additional information, contact:
// Environmental Systems Research Institute, Inc.
// Attn: Contracts and Legal Services Department
// 380 New York Street
// Redlands, California, 92373
// USA
//
// email: contracts@esri.com
/// \file QueryParameters.h

#ifndef QRT_QueryParameters_H
#define QRT_QueryParameters_H

// C++ API headers
#include "CoreTypes.h"
#include "Geometry.h"
#include "OrderBy.h"
#include "SpatialReference.h"
#include "TimeExtent.h"

// Qt headers
#include <QList>

// STL headers
#include <memory>

namespace QRTImpl {
  class QueryParametersImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class QueryParameters
  {
  public:
    QueryParameters();
    QueryParameters(const QueryParameters& other);
    QueryParameters(QueryParameters&& other) noexcept;
    ~QueryParameters();

    QueryParameters& operator=(const QueryParameters& other);
    QueryParameters& operator=(QueryParameters&& other) noexcept;

    bool isEmpty() const;
    void clear();

    Geometry geometry() const;
    void setGeometry(const Geometry& geometry);

    SpatialReference inSpatialReference() const;

    double maxAllowableOffset() const;
    void setMaxAllowableOffset(double maxAllowableOffset);

    int maxFeatures() const;
    void setMaxFeatures(int maxFeatures);

    QList<qint64> objectIds() const;
    void setObjectIds(const QList<qint64>& objectIds);

    QList<OrderBy> orderByFields() const;
    void setOrderByFields(const QList<OrderBy>& orderByFields);

    SpatialReference outSpatialReference() const;
    void setOutSpatialReference(const SpatialReference& spatialReference);

    bool isReturnGeometry() const;
    void setReturnGeometry(bool returnGeometry);

    SpatialRelationship spatialRelationship() const;
    void setSpatialRelationship(SpatialRelationship relationship);

    QString whereClause() const;
    void setWhereClause(const QString& whereClause);

    int resultOffset() const;
    void setResultOffset(int resultOffset);

    TimeExtent timeExtent() const;
    void setTimeExtent(const TimeExtent& timeExtent);

    QueryParameters(const std::shared_ptr<QRTImpl::QueryParametersImpl>& impl);
    std::shared_ptr<QRTImpl::QueryParametersImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::QueryParametersImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_QueryParameters_H
