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
/// \file TileKey.h

#ifndef QRT_TileKey_H
#define QRT_TileKey_H

// C++ API headers
#include "ArcGISQt_global.h"

// STL headers
#include <memory>

namespace QRTImpl {
  class TileKeyImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class TileKey
  {
  public:
    TileKey();
    TileKey(int level, int column, int row);
    ~TileKey();
    TileKey(const TileKey& other);
    TileKey(TileKey&& other) noexcept;
    TileKey& operator=(const TileKey& other);
    TileKey& operator=(TileKey&& other) noexcept;

    int column() const;

    int level() const;

    int row() const;

    explicit TileKey(const std::shared_ptr<QRTImpl::TileKeyImpl>& impl);
    std::shared_ptr<QRTImpl::TileKeyImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::TileKeyImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_TileKey_H
