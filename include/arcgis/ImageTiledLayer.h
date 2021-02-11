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
/// \file ImageTiledLayer.h

#ifndef QRT_ImageTiledLayer_H
#define QRT_ImageTiledLayer_H

// C++ API headers
#include "ImageAdjustmentLayer.h"
#include "MapTypes.h"
#include "TileInfo.h"
#include "TileKey.h"

namespace Esri {
namespace ArcGISRuntime {

  class ImageTiledLayer : public ImageAdjustmentLayer
  {
    Q_OBJECT

  public:
    ImageTiledLayer(const TileInfo& tileInfo, const Envelope& fullExtent, QObject* parent = nullptr);
    ~ImageTiledLayer();

    NoDataTileBehavior noDataTileBehavior() const;
    void setNoDataTileBehavior(NoDataTileBehavior noDataTileBehavior);

    TileInfo tileInfo() const;

    virtual void setAttribution(const QString& attribution);

  signals:
    // custom tiled layer api
    void tileRequest(const TileKey& tileKey);
    void cancelTileRequest(const TileKey& tileKey);

  protected:
    // custom tiled layer api
    void setTileData(const TileKey& tileKey, const QByteArray& data);
    void setTileError(const TileKey& tileKey, const QString& error);
    void setNoDataTile(const TileKey& tileKey);

    /*! \internal */
    explicit ImageTiledLayer(const std::shared_ptr<QRTImpl::LayerImpl>& impl, QObject* parent = nullptr);

  private:
    Q_DISABLE_COPY(ImageTiledLayer)
    void connectSignals();
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ImageTiledLayer_H
