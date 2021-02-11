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
/// \file HillshadeRenderer.h

#ifndef QRT_HillshadeRenderer_H
#define QRT_HillshadeRenderer_H

// C++ API headers
#include "RasterRenderer.h"

namespace QRTImpl { class HillshadeRendererImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class HillshadeRenderer : public RasterRenderer
  {
    Q_OBJECT

  public:
    HillshadeRenderer(QObject* parent = nullptr);
    HillshadeRenderer(double altitude, double azimuth, double zFactor, QObject* parent = nullptr);
    HillshadeRenderer(double altitude, double azimuth, double zFactor, SlopeType slopeType, double pixelSizeFactor, double pixelSizePower, int outputBitDepth, QObject* parent = nullptr);
    ~HillshadeRenderer();

    HillshadeRenderer(const std::shared_ptr<QRTImpl::HillshadeRendererImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::HillshadeRendererImpl> getImpl() const;

    double altitude() const;
    double azimuth() const;
    int outputBitDepth() const;
    double pixelSizeFactor() const;
    double pixelSizePower() const;
    SlopeType slopeType() const;
    double zFactor() const;

  private:
    Q_DISABLE_COPY(HillshadeRenderer)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_HillshadeRenderer_H
