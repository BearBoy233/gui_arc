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
/// \file BlendRenderer.h

#ifndef QRT_BlendRenderer_H
#define QRT_BlendRenderer_H

// C++ API headers
#include "ColorRamp.h"
#include "HillshadeRenderer.h"
#include "Raster.h"

namespace QRTImpl { class BlendRendererImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class BlendRenderer : public HillshadeRenderer
  {
    Q_OBJECT

  public:
    BlendRenderer(QObject* parent = nullptr);
    BlendRenderer(Raster* elevationRaster, QObject* parent = nullptr);
    BlendRenderer(Raster* elevationRaster, double altitude, double azimuth, double zFactor, QObject* parent = nullptr);
    BlendRenderer(Raster* elevationRaster,
                  const QList<double>& outputMinValues, const QList<double>& outputMaxValues,
                  const QList<double>& sourceMinValues, const QList<double>& sourceMaxValues,
                  const QList<double>& noDataValues, const QList<double>& gammas,
                  ColorRamp* colorRamp,
                  double altitude, double azimuth, double zFactor,
                  SlopeType slopeType, double pixelSizeFactor, double pixelSizePower,
                  int outputBitDepth, QObject* parent = nullptr);
    ~BlendRenderer();

    BlendRenderer(const std::shared_ptr<QRTImpl::BlendRendererImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::BlendRendererImpl> getImpl() const;

    Raster* elevationRaster() const;
    QList<double> gammas() const;
    QList<double> outputMinValues() const;
    QList<double> outputMaxValues() const;
    QList<double> sourceMinValues() const;
    QList<double> sourceMaxValues() const;
    QList<double> noDataValues() const;

  private:
    Q_DISABLE_COPY(BlendRenderer)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_BlendRenderer_H
