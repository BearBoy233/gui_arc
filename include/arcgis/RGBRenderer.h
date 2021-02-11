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
/// \file RGBRenderer.h

#ifndef QRT_RGBRenderer_H
#define QRT_RGBRenderer_H

// C++ API headers
#include "BaseStretchRenderer.h"
#include "Raster.h"
#include "RasterTypes.h"

namespace QRTImpl { class RGBRendererImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class RGBRenderer : public BaseStretchRenderer
  {
    Q_OBJECT

  public:
    RGBRenderer(QObject* parent = nullptr);
    RGBRenderer(const StretchParameters& stretchParameters, QObject* parent = nullptr);
    RGBRenderer(const StretchParameters& stretchParameters, const QList<int>& bandIndexes, PansharpenType pansharpenType, Raster* panchromaticRaster,  const QList<double>& weights, QObject* parent = nullptr);
    RGBRenderer(const StretchParameters& stretchParameters, const QList<int>& bandIndexes, const QList<double>& gammas, bool estimateStatistics, QObject* parent = nullptr);
    RGBRenderer(const StretchParameters& stretchParameters, const QList<int>& bandIndexes, const QList<double>& gammas, bool estimateStatistics, PansharpenType pansharpenType, Raster* panchromaticRaster, const QList<double>& weights, QObject* parent = nullptr);

    ~RGBRenderer();

    QList<int> bandIndexes() const;
    Raster* panchromaticRaster() const;
    PansharpenType pansharpenType() const;
    QList<double> weights() const;

    RGBRenderer(const std::shared_ptr<QRTImpl::RGBRendererImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::RGBRendererImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(RGBRenderer)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_RGBRenderer_H
