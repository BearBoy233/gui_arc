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
/// \file OpenStreetMapLayer.h

#ifndef QRT_OpenStreetMapLayer_H
#define QRT_OpenStreetMapLayer_H

// C++ API headers
#include "WebTiledLayer.h"

namespace QRTImpl {
  class OpenStreetMapLayerImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class OpenStreetMapLayer : public WebTiledLayer
  {
    Q_OBJECT

  public:
    explicit OpenStreetMapLayer(QObject* parent = nullptr);

    ~OpenStreetMapLayer();

    void setAttribution(const QString& attribution) override;

    /*! \internal */
    explicit OpenStreetMapLayer(const std::shared_ptr<QRTImpl::LayerImpl>& impl, QObject* parent = nullptr);

  private:
    Q_DISABLE_COPY(OpenStreetMapLayer)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_OpenStreetMapLayer_H
