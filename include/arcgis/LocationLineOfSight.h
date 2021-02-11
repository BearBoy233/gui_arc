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
/// \file LocationLineOfSight.h

#ifndef QRT_LocationLineOfSight_H
#define QRT_LocationLineOfSight_H

// C++ API headers
#include "LineOfSight.h"
#include "Point.h"

namespace QRTImpl { class LocationLineOfSightImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class LocationLineOfSight : public LineOfSight
  {
    Q_OBJECT

  public:
    LocationLineOfSight(const Point& observerLocation, const Point& targetLocation, QObject* parent = nullptr);
    ~LocationLineOfSight();

    Point observerLocation() const;
    void setObserverLocation(const Point& observerLocation);

    Point targetLocation() const;
    void setTargetLocation(const Point& targetLocation);

    /*! \internal */
    explicit LocationLineOfSight(const std::shared_ptr<QRTImpl::LocationLineOfSightImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::LocationLineOfSightImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(LocationLineOfSight)
    LocationLineOfSight() = delete;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_LocationLineOfSight_H
