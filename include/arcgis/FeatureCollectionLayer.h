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
/// \file FeatureCollectionLayer.h

#ifndef QRT_FeatureCollectionLayer_H
#define QRT_FeatureCollectionLayer_H

// C++ API headers
#include "FeatureCollection.h"
#include "Layer.h"

namespace QRTImpl {
  class FeatureCollectionLayerImpl;
}

namespace Esri {
namespace ArcGISRuntime {
  class FeatureCollectionLayer: public Layer
  {
    Q_OBJECT

  public:
    explicit FeatureCollectionLayer(FeatureCollection* featureCollection, QObject* parent = nullptr);
    ~FeatureCollectionLayer();

    FeatureCollection* featureCollection() const;

    QList<Layer*> layers() const;

    explicit FeatureCollectionLayer(const std::shared_ptr<QRTImpl::FeatureCollectionLayerImpl>& impl, QObject* parent = nullptr);

  private:

    Q_DISABLE_COPY(FeatureCollectionLayer)
  };
}
}
#endif // QRT_FeatureCollectionLayer_H
