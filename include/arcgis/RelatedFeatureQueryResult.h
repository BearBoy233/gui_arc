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
/// \file RelatedFeatureQueryResult.h

#ifndef QRT_RelatedFeatureQueryResult_H
#define QRT_RelatedFeatureQueryResult_H

// C++ API headers
#include "ArcGISFeature.h"
#include "FeatureSet.h"
#include "Object.h"
#include "RelationshipInfo.h"

namespace QRTImpl {
  class RelatedFeatureQueryResultImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class ArcGISFeatureTable;

  class RelatedFeatureQueryResult : public Object, public FeatureSet
  {
    Q_OBJECT

  public:
    ~RelatedFeatureQueryResult();

    ArcGISFeature* feature() const;
    ArcGISFeatureTable* relatedTable() const;
    RelationshipInfo relationshipInfo() const;

    bool isTransferLimitExceeded() const;

    FeatureIterator iterator() const override;
    QList<Field> fields() const override;
    GeometryType geometryType() const override;
    SpatialReference spatialReference() const override;

    RelatedFeatureQueryResult(const std::shared_ptr<QRTImpl::RelatedFeatureQueryResultImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::RelatedFeatureQueryResultImpl> getImpl() const;
    std::shared_ptr<QRTImpl::FeatureSetImpl> iGetImpl() const override;

  private:
    std::shared_ptr<QRTImpl::RelatedFeatureQueryResultImpl> m_impl;

    Q_DISABLE_COPY(RelatedFeatureQueryResult)

    RelatedFeatureQueryResult() = delete;
  };

} // namespace ArcGISRuntime
} // namespace Esri

Q_DECLARE_METATYPE(Esri::ArcGISRuntime::RelatedFeatureQueryResult*)

#endif // QRT_RelatedFeatureQueryResult_H
