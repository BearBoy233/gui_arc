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
/// \file LayerSceneProperties.h

#ifndef QRT_LayerSceneProperties_H
#define QRT_LayerSceneProperties_H

// C++ API headers
#include "SceneViewTypes.h"

// STL headers
#include <memory>

namespace QRTImpl { class LayerScenePropertiesImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class LayerSceneProperties
  {
  public:
    LayerSceneProperties();
    LayerSceneProperties(SurfacePlacement surfacePlacement);
    LayerSceneProperties(const LayerSceneProperties& other);
    LayerSceneProperties(LayerSceneProperties&& other) noexcept;
    ~LayerSceneProperties();

    LayerSceneProperties& operator=(const LayerSceneProperties& other);
    LayerSceneProperties& operator=(LayerSceneProperties&& other) noexcept;

    bool isEmpty() const;

    SurfacePlacement surfacePlacement() const;
    void setSurfacePlacement(SurfacePlacement surfacePlacement);

    /*! \internal */
    LayerSceneProperties(const std::shared_ptr<QRTImpl::LayerScenePropertiesImpl>& impl);
    /*! \internal */
    std::shared_ptr<QRTImpl::LayerScenePropertiesImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::LayerScenePropertiesImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_LayerSceneProperties_H
