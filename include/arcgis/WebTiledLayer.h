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
/// \file WebTiledLayer.h

#ifndef QRT_WebTiledLayer_H
#define QRT_WebTiledLayer_H

// C++ API headers
#include "ServiceImageTiledLayer.h"

namespace QRTImpl {
  class WebTiledLayerImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class WebTiledLayer : public ServiceImageTiledLayer
  {
    Q_OBJECT

  public:
    explicit WebTiledLayer(const QString& templateUrl,
                           QObject* parent = nullptr);

    WebTiledLayer(const QString& templateUrl,
                  Credential* credential,
                  QObject* parent = nullptr);

    WebTiledLayer(const QString& templateUrl,
                  const QStringList& subDomains,
                  QObject* parent = nullptr);

    WebTiledLayer(const QString& templateUrl,
                  const QStringList& subDomains,
                  Credential* credential,
                  QObject* parent = nullptr);

    WebTiledLayer(const QString& templateUrl,
                  const TileInfo& tileInfo,
                  const Envelope& fullExtent,
                  QObject* parent = nullptr);

    WebTiledLayer(const QString& templateUrl,
                  const TileInfo& tileInfo,
                  const Envelope& fullExtent,
                  Credential* credential,
                  QObject* parent = nullptr);

    WebTiledLayer(const QString& templateUrl,
                  const QStringList& subDomains,
                  const TileInfo& tileInfo,
                  const Envelope& fullExtent,
                  QObject* parent = nullptr);

    WebTiledLayer(const QString& templateUrl,
                  const QStringList& subDomains,
                  const TileInfo& tileInfo,
                  const Envelope& fullExtent,
                  Credential* credential,
                  QObject* parent = nullptr);

    ~WebTiledLayer();

    QStringList subDomains() const;

    QString templateUrl() const;

    /*! \internal */
    explicit WebTiledLayer(const std::shared_ptr<QRTImpl::LayerImpl>& impl, QObject* parent = nullptr);

  private:
    Q_DISABLE_COPY(WebTiledLayer)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_WebTiledLayer_H
