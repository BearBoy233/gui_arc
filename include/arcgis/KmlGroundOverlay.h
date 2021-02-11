// COPYRIGHT 1995-2018 ESRI
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
/// \file KmlGroundOverlay.h

#ifndef QRT_KmlGroundOverlay_H
#define QRT_KmlGroundOverlay_H

// C++ API headers
#include "Geometry.h"
#include "KmlNode.h"
#include "MapTypes.h"

// Qt headers
#include <QColor>

namespace Esri {
namespace ArcGISRuntime {

  class KmlGroundOverlay : public KmlNode
  {
    Q_OBJECT

  public:
    ~KmlGroundOverlay();

    double altitude() const;

    KmlAltitudeMode altitudeMode() const;

    QColor color() const;

    int drawOrder() const;

    Geometry geometry() const;

    double rotation() const;

    /*! \internal */
    explicit KmlGroundOverlay(const std::shared_ptr<QRTImpl::KmlNodeImpl>& impl, QObject* parent = nullptr);

  private:
    Q_DISABLE_COPY(KmlGroundOverlay)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_KmlGroundOverlay_H
