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
/// \file MobileBasemapLayer.h

#ifndef QRT_MobileBasemapLayer_H
#define QRT_MobileBasemapLayer_H

// C++ API headers
#include "Layer.h"

namespace QRTImpl {
  class MobileBasemapLayerImpl;
}

namespace Esri {
namespace ArcGISRuntime {
  class MobileBasemapLayer: public Layer
  {
    Q_OBJECT

  public:
    ~MobileBasemapLayer();

    QString path() const;

    QList<qint64> subLayerIds() const;

    explicit MobileBasemapLayer(const std::shared_ptr<QRTImpl::MobileBasemapLayerImpl>& impl, QObject* parent = nullptr);

  private:
    MobileBasemapLayer() = delete;

    Q_DISABLE_COPY(MobileBasemapLayer)
  };
}
}
#endif // QRT_MobileBasemapLayer_H
