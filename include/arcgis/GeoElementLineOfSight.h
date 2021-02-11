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
/// \file GeoElementLineOfSight.h

#ifndef QRT_GeoElementLineOfSight_H
#define QRT_GeoElementLineOfSight_H

// C++ API headers
#include "GeoElement.h"
#include "LineOfSight.h"

namespace QRTImpl { class GeoElementLineOfSightImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class GeoElementLineOfSight : public LineOfSight
  {
    Q_OBJECT

  public:
    GeoElementLineOfSight(GeoElement* observerGeoElement, GeoElement* targetGeoElement, QObject* parent = nullptr);
    ~GeoElementLineOfSight();

    GeoElement* observerGeoElement() const;

    GeoElement* targetGeoElement() const;

    double observerOffsetX() const;
    void setObserverOffsetX(double offsetX);

    double observerOffsetY() const;
    void setObserverOffsetY(double offsetY);

    double observerOffsetZ() const;
    void setObserverOffsetZ(double offsetZ);

    double targetOffsetX() const;
    void setTargetOffsetX(double offsetX);

    double targetOffsetY() const;
    void setTargetOffsetY(double offsetY);

    double targetOffsetZ() const;
    void setTargetOffsetZ(double offsetZ);

    /*! \internal */
    explicit GeoElementLineOfSight(const std::shared_ptr<QRTImpl::GeoElementLineOfSightImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::GeoElementLineOfSightImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(GeoElementLineOfSight)
    GeoElementLineOfSight() = delete;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_GeoElementLineOfSight_H
