// COPYRIGHT 1995-2017 ESRI
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
/// \file BingMapsLayer.h

#ifndef QRT_BingMapsLayer_H
#define QRT_BingMapsLayer_H

// C++ API headers
#include "MapTypes.h"
#include "Portal.h"
#include "ServiceImageTiledLayer.h"

namespace Esri {
namespace ArcGISRuntime {

  class BingMapsLayer : public ServiceImageTiledLayer
  {
    Q_OBJECT

  public:
    BingMapsLayer(const QString& bingMapsKey,
                  BingMapsLayerStyle style,
                  QObject* parent = nullptr);

    BingMapsLayer(Portal* portal,
                  BingMapsLayerStyle style,
                  QObject* parent = nullptr);

    ~BingMapsLayer();

    QString culture() const;
    void setCulture(const QString& culture);

    QString key() const;
    void setKey(const QString& bingMapsKey);

    Portal* portal() const;

    BingMapsLayerStyle style() const;

    /*! \internal */
    explicit BingMapsLayer(const std::shared_ptr<QRTImpl::LayerImpl>& impl, QObject* parent = nullptr);

  private:
    Q_DISABLE_COPY(BingMapsLayer)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_BingMapsLayer_H
