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
/// \file ArcGISTiledLayer.h

#ifndef QRT_ArcGISTiledLayer_H
#define QRT_ArcGISTiledLayer_H

// C++ API headers
#include "ArcGISMapServiceInfo.h"
#include "ArcGISSublayerListModel.h"
#include "Credential.h"
#include "ImageTiledLayer.h"
#include "Item.h"
#include "RemoteResource.h"
#include "TileCache.h"

// Qt headers
#include <QUrl>

namespace QRTImpl {
  class ArcGISTiledLayerImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class ArcGISTiledLayer : public ImageTiledLayer, public RemoteResource
  {
    Q_OBJECT

  public:
    explicit ArcGISTiledLayer(const QUrl& url, QObject* parent = nullptr);
    ArcGISTiledLayer(const QUrl& url, Credential* credential, QObject* parent = nullptr);
    explicit ArcGISTiledLayer(Item* item, QObject* parent = nullptr);
    explicit ArcGISTiledLayer(TileCache* tileCache, QObject* parent = nullptr);
    ~ArcGISTiledLayer();

    QList<ArcGISSublayer*> tiledSublayers() const;

    ArcGISMapServiceInfo mapServiceInfo() const;

    TileCache* tileCache() const;

    quint64 refreshInterval() const;
    void setRefreshInterval(quint64 milliseconds);

    // RemoteResource interface methods
    QUrl url() const override;
    Credential* credential() const override;
    RequestConfiguration requestConfiguration() const override;
    void setRequestConfiguration(const RequestConfiguration& requestConfiguration) override;

    explicit ArcGISTiledLayer(const std::shared_ptr<QRTImpl::ArcGISTiledLayerImpl>& impl, QObject* parent = nullptr);

  private:
    Q_DISABLE_COPY(ArcGISTiledLayer)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ArcGISTiledLayer_H
