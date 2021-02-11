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
/// \file LayerViewState.h

#ifndef QRT_LayerViewState_H
#define QRT_LayerViewState_H

// C++ API headers
#include "ArcGISQt_global.h"
#include "Error.h"
#include "MapViewTypes.h"

// STL headers
#include <memory>

namespace QRTImpl { class LayerViewStateImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class LayerViewState
  {
  public:
    LayerViewState();
    ~LayerViewState();
    LayerViewState(const LayerViewState& other);
    LayerViewState(LayerViewState&& other) noexcept;
    LayerViewState& operator=(const LayerViewState& other);
    LayerViewState& operator=(LayerViewState&& other) noexcept;

    Error error() const;

    LayerViewStatus status() const;

    LayerViewStatusFlags statusFlags() const;

    std::shared_ptr<QRTImpl::LayerViewStateImpl> getImpl() const;
    explicit LayerViewState(const std::shared_ptr<QRTImpl::LayerViewStateImpl>& impl);

  private:
    std::shared_ptr<QRTImpl::LayerViewStateImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_LayerViewState_H
