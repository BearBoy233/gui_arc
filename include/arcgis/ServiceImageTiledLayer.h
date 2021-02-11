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
/// \file ServiceImageTiledLayer.h

#ifndef QRT_ServiceImageTiledLayer_H
#define QRT_ServiceImageTiledLayer_H

// C++ API headers
#include "ImageTiledLayer.h"
#include "RemoteResource.h"

namespace QRTImpl { class ServiceImageTiledLayerImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class ServiceImageTiledLayer : public ImageTiledLayer, public RemoteResource
  {
    Q_OBJECT

  public:
    ServiceImageTiledLayer(const TileInfo& tileInfo, const Envelope& fullExtent, QObject* parent = nullptr);
    ServiceImageTiledLayer(const TileInfo& tileInfo, const Envelope& fullExtent, Credential* credential, QObject* parent = nullptr);
    ~ServiceImageTiledLayer();

    // RemoteResource interface methods
    QUrl url() const override;
    Credential* credential() const override;
    RequestConfiguration requestConfiguration() const override;
    void setRequestConfiguration(const RequestConfiguration& requestConfiguration) override;

  signals:
    void tileUrlRequest(const TileKey& tileKey);

  protected:
    // custom tiled layer api
    void setTileUrl(const TileKey& tileKey, const QUrl& url);

    /*! \internal */
    explicit ServiceImageTiledLayer(const std::shared_ptr<QRTImpl::LayerImpl>& impl, QObject* parent = nullptr);

    /*! \internal */
    ServiceImageTiledLayer(const std::shared_ptr<QRTImpl::LayerImpl>& impl, Credential* credential, QObject* parent = nullptr);

  private:
    Q_DISABLE_COPY(ServiceImageTiledLayer)
    void connectSignals();
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ServiceImageTiledLayer_H
