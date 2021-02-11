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
/// \file MapServiceLayerIdInfo.h

#ifndef QRT_MapServiceLayerIdInfo_H
#define QRT_MapServiceLayerIdInfo_H

// C++ API headers
#include "IdInfo.h"

namespace QRTImpl { class MapServiceLayerIdInfoImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class MapServiceLayerIdInfo : public IdInfo
  {
  public:
    MapServiceLayerIdInfo();

    MapServiceLayerIdInfo(const MapServiceLayerIdInfo& other);
    MapServiceLayerIdInfo(MapServiceLayerIdInfo&& other) noexcept;
    MapServiceLayerIdInfo(const IdInfo& other);

    MapServiceLayerIdInfo& operator=(const MapServiceLayerIdInfo& other);
    MapServiceLayerIdInfo& operator=(MapServiceLayerIdInfo&& other) noexcept;

    ~MapServiceLayerIdInfo();

    bool isValid() const;

    bool isDefaultVisible() const;

    double maxScale() const;

    double minScale() const;

    qint64 parentLayerId() const;

    QList<qint64> sublayerIds() const;

    /*! \internal */
    explicit MapServiceLayerIdInfo(const std::shared_ptr<QRTImpl::MapServiceLayerIdInfoImpl>& impl);
    std::shared_ptr<QRTImpl::MapServiceLayerIdInfoImpl> getImpl() const;
  };

  /*! \internal */
  template<> inline MapServiceLayerIdInfo
  idinfo_cast<MapServiceLayerIdInfo>(const IdInfo& idInfo)
  {
    return idInfo.idInfoType() == IdInfoType::MapServiceLayerIdInfo ? static_cast<MapServiceLayerIdInfo>(idInfo) : MapServiceLayerIdInfo();
  }

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_MapServiceLayerIdInfo_H
