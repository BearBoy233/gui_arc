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
/// \file StretchRenderer.h

#ifndef QRT_StretchRenderer_H
#define QRT_StretchRenderer_H

// C++ API headers
#include "BaseStretchRenderer.h"
#include "ColorRamp.h"

namespace QRTImpl { class StretchRendererImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class StretchRenderer : public BaseStretchRenderer
  {
    Q_OBJECT

  public:
    StretchRenderer(QObject* parent = nullptr);
    StretchRenderer(const StretchParameters& stretchParameters, const QList<double>& gammas, bool estimateStats, PresetColorRampType presetColorRampType, QObject* parent = nullptr);
    StretchRenderer(const StretchParameters& stretchParameters, const QList<double>& gammas, bool estimateStats, ColorRamp* colorRamp, QObject* parent = nullptr);

    ~StretchRenderer();

    ColorRamp* colorRamp()const;

    StretchRenderer(const std::shared_ptr<QRTImpl::StretchRendererImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::StretchRendererImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(StretchRenderer)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_StretchRenderer_H
