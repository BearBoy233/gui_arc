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
/// \file ImageAdjustmentLayer.h

#ifndef QRT_ImageAdjustmentLayer_H
#define QRT_ImageAdjustmentLayer_H

// C++ API headers
#include "Layer.h"

namespace Esri {
namespace ArcGISRuntime {

  class ImageAdjustmentLayer : public Layer
  {
    Q_OBJECT

  public:
    ~ImageAdjustmentLayer();

    float brightness() const;
    void setBrightness(float brightness);

    float contrast() const;
    void setContrast(float contrast);

    float gamma() const;
    void setGamma(float gamma);

  protected:
    /*! \internal */
    explicit ImageAdjustmentLayer(const std::shared_ptr<QRTImpl::LayerImpl>& impl, QObject* parent = nullptr);
    /*! \internal */
    Q_DISABLE_COPY(ImageAdjustmentLayer)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ImageAdjustmentLayer_H
