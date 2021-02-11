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
/// \file RasterRenderer.h

#ifndef QRT_RasterRenderer_H
#define QRT_RasterRenderer_H

// C++ API headers
#include "Object.h"
#include "RasterTypes.h"

namespace QRTImpl { class RasterRendererImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class RasterRenderer : public Object
  {
    Q_OBJECT

  public:
    ~RasterRenderer();

    RasterRendererType rendererType() const;
    RasterRenderer(const std::shared_ptr<QRTImpl::RasterRendererImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::RasterRendererImpl> getImpl() const;

  protected:
    std::shared_ptr<QRTImpl::RasterRendererImpl> m_impl;

  private:
    RasterRenderer() = delete;

    Q_DISABLE_COPY(RasterRenderer)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_RasterRenderer_H
