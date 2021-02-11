// COPYRIGHT 1995-2017 ESRI
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
/// \file WmsFeature.h

#ifndef QRT_WmsFeature_H
#define QRT_WmsFeature_H

// C++ API headers
#include "GeoElement.h"
#include "Object.h"

namespace QRTImpl { class WmsFeatureImpl; }

namespace Esri {
namespace ArcGISRuntime {
  class AttributeListModel;

  class WmsFeature : public Object, public GeoElement
  {
    Q_OBJECT

  public:
    ~WmsFeature();

    AttributeListModel* attributes() const override;

    Geometry geometry() const override;
    void setGeometry(const Geometry& geometry) override;

    /*! \internal */
    WmsFeature(const std::shared_ptr<QRTImpl::WmsFeatureImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::WmsFeatureImpl> getImpl() const;
    std::shared_ptr<QRTImpl::GeoElementImpl> iGetImpl() const override;

  signals:
    void geometryChanged();

  private:
    Q_DISABLE_COPY(WmsFeature)

    std::shared_ptr<QRTImpl::WmsFeatureImpl> m_impl;

    WmsFeature() = delete;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_WmsFeature_H
