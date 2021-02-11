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
/// \file TileInfo.h

#ifndef QRT_TileInfo_H
#define QRT_TileInfo_H

// C++ API headers
#include "ArcGISQt_global.h"
#include "LevelOfDetail.h"
#include "Point.h"
#include "ServiceTypes.h"
#include "SpatialReference.h"

// Qt headers
#include <QList>

namespace QRTImpl {
  class TileInfoImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class TileInfo
  {
  public:
    TileInfo();
    TileInfo(int dpi,
             TileImageFormat format,
             const QList<LevelOfDetail>& levelsOfDetail,
             const SpatialReference& spatialReference,
             const Point& origin,
             int tileHeight,
             int tileWidth);
    TileInfo(const TileInfo& other);
    TileInfo(TileInfo&& other) noexcept;
    TileInfo& operator=(const TileInfo& other);
    TileInfo& operator=(TileInfo&& other) noexcept;
    ~TileInfo();

    bool isEmpty() const;

    int dpi() const;

    QList<LevelOfDetail> levelsOfDetail() const;

    Point origin() const;

    SpatialReference spatialReference() const;

    int tileHeight() const;

    int tileWidth() const;

    TileImageFormat format() const;

    float compressionQuality() const;

    TileInfo(const std::shared_ptr<QRTImpl::TileInfoImpl>& impl);
    std::shared_ptr<QRTImpl::TileInfoImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::TileInfoImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_TileInfo_H
