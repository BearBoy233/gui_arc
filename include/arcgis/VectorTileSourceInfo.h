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
/// \file VectorTileSourceInfo.h

#ifndef QRT_VectorTileSourceInfo_H
#define QRT_VectorTileSourceInfo_H

// C++ API headers
#include "Envelope.h"
#include "LevelOfDetail.h"
#include "Point.h"
#include "SpatialReference.h"
#include "VectorTileStyle.h"

// STL headers
#include <memory>

namespace QRTImpl {
  class VectorTileSourceInfoImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class VectorTileSourceInfo
  {
  public:
    VectorTileSourceInfo();
    VectorTileSourceInfo(const VectorTileSourceInfo& other);
    VectorTileSourceInfo(VectorTileSourceInfo&& other) noexcept;
    ~VectorTileSourceInfo();

    VectorTileSourceInfo& operator=(const VectorTileSourceInfo& other);
    VectorTileSourceInfo& operator=(VectorTileSourceInfo&& other) noexcept;

    bool isEmpty() const;

    QUrl url() const;

    VectorTileStyle defaultStyle() const;

    QUrl defaultStyleUrl() const;

    bool isExportTilesAllowed() const;

    Envelope fullExtent() const;

    Envelope initialExtent() const;

    int maxExportTilesCount() const;

    double minScale() const;

    double maxScale() const;

    QString name() const;

    Point origin() const;

    SpatialReference spatialReference() const;

    QList<LevelOfDetail> levelsOfDetail() const;

    QString version() const;

    VectorTileSourceInfo(const std::shared_ptr<QRTImpl::VectorTileSourceInfoImpl>& impl);
    std::shared_ptr<QRTImpl::VectorTileSourceInfoImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::VectorTileSourceInfoImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_VectorTileSourceInfo_H
