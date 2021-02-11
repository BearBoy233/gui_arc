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
/// \file Route.h

#ifndef QRT_ClosestFacilityRoute_H
#define QRT_ClosestFacilityRoute_H

// C++ API headers
#include "DirectionManeuverListModel.h"
#include "Polyline.h"

// Qt headers
#include <QDateTime>
#include <QString>

// STL headers
#include <memory>

namespace QRTImpl { class ClosestFacilityRouteImpl; }

namespace Esri {
namespace ArcGISRuntime {

class ClosestFacilityRoute
{
public:
  ClosestFacilityRoute();
  ClosestFacilityRoute(const ClosestFacilityRoute& other);
  ClosestFacilityRoute(ClosestFacilityRoute&& other) noexcept;
  ~ClosestFacilityRoute();

  ClosestFacilityRoute& operator=(const ClosestFacilityRoute& other);
  ClosestFacilityRoute& operator=(ClosestFacilityRoute&& other) noexcept;

  bool isEmpty() const;

  Polyline routeGeometry() const;

  double travelTime() const;

  double totalTime() const;

  QDateTime startTime() const;

  double startTimeShift() const;

  QDateTime endTime() const;

  double endTimeShift() const;

  double totalLength() const;

  CurbApproach departureCurbApproach() const;

  CurbApproach arrivalCurbApproach() const;

  DirectionManeuverListModel* directionManeuvers(QObject* parent = nullptr) const;

  double cost(const QString& attributeName) const;

  /*!
     \internal
   */
  ClosestFacilityRoute(const std::shared_ptr<QRTImpl::ClosestFacilityRouteImpl>& impl);
  std::shared_ptr<QRTImpl::ClosestFacilityRouteImpl> getImpl() const;

private:
  std::shared_ptr<QRTImpl::ClosestFacilityRouteImpl> m_impl;
  mutable DirectionManeuverListModel* m_directionManeuvers = nullptr;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ClosestFacilityRoute_H
