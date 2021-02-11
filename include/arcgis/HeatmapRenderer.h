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
/// \file HeatmapRenderer.h
///
#ifndef HeatmapRenderer_H
#define HeatmapRenderer_H

// C++ API headers
#include "Renderer.h"

namespace QRTImpl { class HeatmapRendererImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class HeatmapRenderer : public Renderer
  {
    Q_OBJECT

  public:
    ~HeatmapRenderer();

    /*! \internal */
    HeatmapRenderer(const std::shared_ptr<QRTImpl::HeatmapRendererImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::HeatmapRendererImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(HeatmapRenderer)

    HeatmapRenderer() = delete;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // HeatmapRenderer_H

