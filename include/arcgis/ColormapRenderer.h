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
/// \file ColormapRenderer.h

#ifndef QRT_ColormapRenderer_H
#define QRT_ColormapRenderer_H

// C++ API headers
#include "Colormap.h"
#include "RasterRenderer.h"

// Qt headers
#include <QColor>

namespace QRTImpl { class ColormapRendererImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class ColormapRenderer : public RasterRenderer
  {
    Q_OBJECT

  public:
    ColormapRenderer(const QList<QColor>& colors, QObject* parent = nullptr);
    ColormapRenderer(Colormap* colormap, QObject* parent = nullptr);
    ~ColormapRenderer();

    QList<QColor> colors() const;
    Colormap* colormap() const;

    ColormapRenderer(const std::shared_ptr<QRTImpl::ColormapRendererImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::ColormapRendererImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(ColormapRenderer)

  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ColormapRenderer_H
