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
/// \file ColorRamp.h

#ifndef QRT_ColorRamp_H
#define QRT_ColorRamp_H

// C++ API headers
#include "Object.h"
#include "RasterTypes.h"

namespace QRTImpl { class ColorRampImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class ColorRamp : public Object
  {
    Q_OBJECT

  public:

    ~ColorRamp();
    static ColorRamp* create(PresetColorRampType presetColorRampType, int size = 256, QObject* parent = nullptr);

    ColorRamp(const std::shared_ptr<QRTImpl::ColorRampImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::ColorRampImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::ColorRampImpl> m_impl;

    Q_DISABLE_COPY(ColorRamp)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ColorRamp_H
