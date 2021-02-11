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
/// \file MapServiceCapabilities.h

#ifndef QRT_MapServiceCapabilities_H
#define QRT_MapServiceCapabilities_H

// C++ API headers
#include "ArcGISQt_global.h"

// STL headers
#include <memory>

namespace QRTImpl {
  class MapServiceCapabilitiesImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class MapServiceCapabilities
  {
  public:
    MapServiceCapabilities();
    ~MapServiceCapabilities();
    MapServiceCapabilities(const MapServiceCapabilities& other);
    MapServiceCapabilities(MapServiceCapabilities&& other) noexcept;
    MapServiceCapabilities& operator=(const MapServiceCapabilities& other);
    MapServiceCapabilities& operator=(MapServiceCapabilities&& other) noexcept;

    bool isSupportsData() const;

    bool isSupportsMap() const;

    bool isSupportsQuery() const;

    bool isSupportsTilemap() const;

    bool isSupportsTilesOnly() const;

    MapServiceCapabilities(const std::shared_ptr<QRTImpl::MapServiceCapabilitiesImpl>& impl);
    std::shared_ptr<QRTImpl::MapServiceCapabilitiesImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::MapServiceCapabilitiesImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_MapServiceCapabilities_H
