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
/// \file WmtsLayer.h

#ifndef QRT_WmtsLayer_H
#define QRT_WmtsLayer_H

// C++ API headers
#include "ImageTiledLayer.h"
#include "RemoteResource.h"
#include "ServiceTypes.h"
#include "WmtsLayerInfo.h"
#include "WmtsTileMatrixSet.h"

// Qt headers
#include <QUrl>

namespace QRTImpl {
  class WmtsLayerImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class WmtsLayer : public ImageTiledLayer, public RemoteResource
  {
    Q_OBJECT

  public:
    WmtsLayer(const QUrl& url,
              const QString& wmtsLayerId,
              QObject* parent = nullptr);

    WmtsLayer(const QUrl& url,
              const QString& wmtsLayerId,
              Credential* credential,
              QObject* parent = nullptr);

    WmtsLayer(const QUrl& url,
              const QString& wmtsLayerId,
              TileImageFormat preferredImageFormat,
              QObject* parent = nullptr);

    WmtsLayer(const QUrl& url,
              const QString& wmtsLayerId,
              TileImageFormat preferredImageFormat,
              Credential* credential,
              QObject* parent = nullptr);

    WmtsLayer(const QUrl& url,
              const QString& wmtsLayerId,
              const QString& tileMatrixSetId,
              QObject* parent = nullptr);

    WmtsLayer(const QUrl& url,
              const QString& wmtsLayerId,
              const QString& tileMatrixSetId,
              Credential* credential,
              QObject* parent = nullptr);

    WmtsLayer(const QUrl& url,
              const QString& wmtsLayerId,
              const QString& tileMatrixSetId,
              TileImageFormat preferredImageFormat,
              QObject* parent = nullptr);

    WmtsLayer(const QUrl& url,
              const QString& wmtsLayerId,
              const QString& tileMatrixSetId,
              TileImageFormat preferredImageFormat,
              Credential* credential,
              QObject* parent = nullptr);

    explicit WmtsLayer(const WmtsLayerInfo& layerInfo,
                       QObject* parent = nullptr);

    WmtsLayer(const WmtsLayerInfo& layerInfo,
              TileImageFormat preferredImageFormat,
              QObject* parent = nullptr);

    WmtsLayer(const WmtsLayerInfo& layerInfo,
              const WmtsTileMatrixSet& tileMatrixSet,
              QObject* parent = nullptr);

    WmtsLayer(const WmtsLayerInfo& layerInfo,
              const WmtsTileMatrixSet& tileMatrixSet,
              TileImageFormat preferredImageFormat,
              QObject* parent = nullptr);

    ~WmtsLayer();

    QString tileMatrixSetId() const;

    TileImageFormat preferredImageFormat() const;

    WmtsLayerInfo layerInfo() const;

    QString wmtsLayerId() const;

    WmtsTileMatrixSet tileMatrixSet() const;

    // RemoteResource interface methods
    QUrl url() const override;
    Credential* credential() const override;
    RequestConfiguration requestConfiguration() const override;
    void setRequestConfiguration(const RequestConfiguration& requestConfiguration) override;

    /*! \internal */
    explicit WmtsLayer(const std::shared_ptr<QRTImpl::WmtsLayerImpl>& impl, QObject* parent = nullptr);

  private:
    Q_DISABLE_COPY(WmtsLayer)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_WmtsLayer_H
