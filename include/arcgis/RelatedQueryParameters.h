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
/// \file RelatedQueryParameters.h

#ifndef QRT_RelatedQueryParameters_H
#define QRT_RelatedQueryParameters_H

// C++ API headers
#include "CoreTypes.h"
#include "QueryParameters.h"
#include "RelationshipInfo.h"

// Qt headers
#include <QStringList>

// STL headers
#include <memory>

namespace QRTImpl {
  class RelatedQueryParametersImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class RelatedQueryParameters
  {
  public:
    RelatedQueryParameters();
    explicit RelatedQueryParameters(const RelationshipInfo& relationshipInfo);
    RelatedQueryParameters(const RelatedQueryParameters& other);
    RelatedQueryParameters(RelatedQueryParameters&& other) noexcept;
    ~RelatedQueryParameters();

    RelatedQueryParameters& operator=(const RelatedQueryParameters& other);
    RelatedQueryParameters& operator=(RelatedQueryParameters&& other) noexcept;

    bool isEmpty() const;
    void clear();

    QList<OrderBy> orderByFields() const;
    void setOrderByFields(const QList<OrderBy>& orderByFields);

    RelationshipInfo relationshipInfo() const;
    void setRelationshipInfo(const RelationshipInfo& relationshipInfo);

    bool isReturnGeometry() const;
    void setReturnGeometry(bool returnGeometry);

    QString whereClause() const;
    void setWhereClause(const QString& whereClause);

    int maxFeatures() const;
    void setMaxFeatures(int maxFeatures);

    int resultOffset() const;
    void setResultOffset(int resultOffset);

    RelatedQueryParameters(const std::shared_ptr<QRTImpl::RelatedQueryParametersImpl>& impl);
    std::shared_ptr<QRTImpl::RelatedQueryParametersImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::RelatedQueryParametersImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_RelatedQueryParameters_H
