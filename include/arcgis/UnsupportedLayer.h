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
/// \file UnsupportedLayer.h

#ifndef QRT_UnsupportedLayer_H
#define QRT_UnsupportedLayer_H

// C++ API headers
#include "Layer.h"

namespace QRTImpl {
  class UnsupportedLayerImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class UnsupportedLayer : public Layer
  {
    Q_OBJECT

  public:
    ~UnsupportedLayer();

    /*!
      \internal
     */
    explicit UnsupportedLayer(const std::shared_ptr<QRTImpl::UnsupportedLayerImpl>& impl, QObject* parent = nullptr);

  private:
    Q_DISABLE_COPY(UnsupportedLayer)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_UnsupportedLayer_H
