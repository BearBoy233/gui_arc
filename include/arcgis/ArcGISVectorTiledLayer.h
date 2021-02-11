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
/// \file ArcGISVectorTiledLayer.h

#ifndef QRT_ArcGISVectorTiledLayer_H
#define QRT_ArcGISVectorTiledLayer_H

// C++ API headers
#include "Credential.h"
#include "Item.h"
#include "ItemResourceCache.h"
#include "Layer.h"
#include "RemoteResource.h"
#include "VectorTileCache.h"
#include "VectorTileSourceInfo.h"
#include "VectorTileStyle.h"

// Qt headers
#include <QUrl>

namespace QRTImpl {
  class ArcGISVectorTiledLayerImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class ArcGISVectorTiledLayer : public Layer, public RemoteResource
  {
    Q_OBJECT

  public:
    explicit ArcGISVectorTiledLayer(const QUrl& url, QObject* parent = nullptr);
    ArcGISVectorTiledLayer(const QUrl& url, Credential* credential, QObject* parent = nullptr);
    explicit ArcGISVectorTiledLayer(Item* item, QObject* parent = nullptr);
    explicit ArcGISVectorTiledLayer(VectorTileCache* vectorTileCache, QObject* parent = nullptr);
    ArcGISVectorTiledLayer(VectorTileCache* vectorTileCache, ItemResourceCache* itemResourceCache, QObject* parent = nullptr);
    ~ArcGISVectorTiledLayer();

    VectorTileSourceInfo sourceInfo() const;

    VectorTileStyle style() const;

    VectorTileCache* vectorTileCache() const;

    ItemResourceCache* itemResourceCache() const;

    // RemoteResource interface methods
    QUrl url() const override;
    Credential* credential() const override;
    RequestConfiguration requestConfiguration() const override;
    void setRequestConfiguration(const RequestConfiguration& requestConfiguration) override;

    ArcGISVectorTiledLayer(const std::shared_ptr<QRTImpl::ArcGISVectorTiledLayerImpl>& impl, QObject* parent = nullptr);

  private:
    Q_DISABLE_COPY(ArcGISVectorTiledLayer)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ArcGISVectorTiledLayer_H
