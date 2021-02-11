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
/// \file FeatureQueryResult.h

#ifndef QRT_FeatureQueryResult_H
#define QRT_FeatureQueryResult_H

// C++ API headers
#include "Feature.h"
#include "FeatureSet.h"
#include "Object.h"

namespace QRTImpl {
  class FeatureQueryResultImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class FeatureQueryResult : public Object, public FeatureSet
  {
    Q_OBJECT

  public:
    ~FeatureQueryResult();

    bool isTransferLimitExceeded() const;

    FeatureIterator iterator() const override;
    QList<Field> fields() const override;
    GeometryType geometryType() const override;
    SpatialReference spatialReference() const override;

    FeatureQueryResult(const std::shared_ptr<QRTImpl::FeatureQueryResultImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::FeatureQueryResultImpl> getImpl() const;
    std::shared_ptr<QRTImpl::FeatureSetImpl> iGetImpl() const override;

  private:
    Q_DISABLE_COPY(FeatureQueryResult)

    FeatureQueryResult() = delete;

    std::shared_ptr<QRTImpl::FeatureQueryResultImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_FeatureQueryResult_H
