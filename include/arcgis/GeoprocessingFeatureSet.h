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
/// \file GeoprocessingFeatureSet.h

#ifndef QRT_GeoprocessingFeatureSet_H
#define QRT_GeoprocessingFeatureSet_H

// C++ API headers
#include "FeatureSet.h"
#include "Object.h"

namespace QRTImpl { class GeoprocessingFeatureSetImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class GeoprocessingFeatureSet : public Object, public FeatureSet
  {
    Q_OBJECT

  public:
    ~GeoprocessingFeatureSet();

    bool isTransferLimitExceeded() const;

    QList<Field> fields() const override;
    GeometryType geometryType() const override;
    SpatialReference spatialReference() const override;
    FeatureIterator iterator() const override;

    /*! \internal */
    GeoprocessingFeatureSet(const std::shared_ptr<QRTImpl::GeoprocessingFeatureSetImpl>& impl, QObject* parent = nullptr);
    /*! \internal */
    std::shared_ptr<QRTImpl::GeoprocessingFeatureSetImpl> getImpl() const;
    /*! \internal */
    std::shared_ptr<QRTImpl::FeatureSetImpl> iGetImpl() const override;

  private:
    GeoprocessingFeatureSet() = delete;
    std::shared_ptr<QRTImpl::GeoprocessingFeatureSetImpl> m_impl;
    Q_DISABLE_COPY(GeoprocessingFeatureSet)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_GeoprocessingFeatureSet_H

