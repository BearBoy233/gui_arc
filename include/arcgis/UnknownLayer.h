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
/// \file UnknownLayer.h

#ifndef QRT_UnknownLayer_H
#define QRT_UnknownLayer_H

// C++ API headers
#include "Layer.h"

namespace QRTImpl {
  class UnknownLayerImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class UnknownLayer : public Layer
  {
    Q_OBJECT

  public:
    ~UnknownLayer();

    /*! \internal */
    explicit UnknownLayer(const std::shared_ptr<QRTImpl::UnknownLayerImpl>& impl, QObject* parent = nullptr);

  private:
    Q_DISABLE_COPY(UnknownLayer)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_UnknownLayer_H
