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
/// \file Stop.h

#ifndef QRT_Stop_H
#define QRT_Stop_H

// C++ API headers
#include "NetworkAnalystTypes.h"
#include "NetworkLocation.h"
#include "Point.h"

// STL headers
#include <memory>

namespace QRTImpl { class StopImpl; }

namespace Esri {
namespace ArcGISRuntime {

class Stop
{
public:
  Stop();
  explicit Stop(const Point& point);
  Stop(const Stop& other);
  Stop(Stop&& other) noexcept;
  ~Stop();

  Stop& operator=(const Stop& other);
  Stop& operator=(Stop&& other) noexcept;

  bool isEmpty() const;

  CurbApproach arrivalCurbApproach() const;
  CurbApproach departureCurbApproach() const;

  CurbApproach curbApproach() const;
  void setCurbApproach(CurbApproach curbApproach);

  double currentBearing() const;
  void setCurrentBearing(double currentBearing);

  double currentBearingTolerance() const;
  void setCurrentBearingTolerance(double currentBearingTolerance);

  double distanceToNetworkLocation() const;

  Point geometry() const;
  void setGeometry(const Point& point);

  QDateTime arrivalTime() const;

  double arrivalTimeShift() const;

  QDateTime departureTime() const;

  double departureTimeShift() const;

  QDateTime timeWindowStart() const;
  void setTimeWindowStart(const QDateTime& timeWindowStart);

  QDateTime timeWindowEnd() const;
  void setTimeWindowEnd(const QDateTime& timeWindowEnd);

  LocationStatus locationStatus() const;

  QString name() const;
  void setName(const QString& name);

  double navigationLatency() const;
  void setNavigationLatency(double navigationLatency);

  double navigationSpeed() const;
  void setNavigationSpeed(double navigationSpeed);

  NetworkLocation networkLocation() const;
  void setNetworkLocation(const NetworkLocation& networkLocation);

  QString routeName() const;
  void setRouteName(const QString& routeName);

  int sequence() const;

  double violationTime() const;
  double waitTime() const;

  double cumulativeCost(const QString& attributeName) const;

  double addedCost(const QString& attributeName) const;
  void setAddedCost(const QString& attributeName, double addedCost);

  StopType stopType() const;
  void setStopType(StopType stopType);

  /*!
     \internal
   */
  Stop(const std::shared_ptr<QRTImpl::StopImpl>& impl);
  std::shared_ptr<QRTImpl::StopImpl> getImpl() const;

private:
  std::shared_ptr<QRTImpl::StopImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_Stop_H
