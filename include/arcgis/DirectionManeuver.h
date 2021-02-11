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
/// \file DirectionManeuver.h

#ifndef QRT_DirectionManeuver_H
#define QRT_DirectionManeuver_H

// C++ API headers
#include "DirectionEvent.h"
#include "DirectionMessage.h"
#include "Geometry.h"
#include "NetworkAnalystTypes.h"

// Qt headers
#include <QDateTime>
#include <QList>
#include <QString>

// STL headers
#include <memory>

namespace QRTImpl { class DirectionManeuverImpl; }

namespace Esri {
namespace ArcGISRuntime {

class DirectionManeuver
{
public:
  DirectionManeuver();
  DirectionManeuver(const DirectionManeuver& other);
  DirectionManeuver(DirectionManeuver&& other) noexcept;
  ~DirectionManeuver();

  DirectionManeuver& operator=(const DirectionManeuver& other);
  DirectionManeuver& operator=(DirectionManeuver&& other) noexcept;

  bool isEmpty() const;

  QList<DirectionEvent> directionEvents() const;

  QString directionText() const;

  double duration() const;

  QDateTime estimatedArrivalTime() const;

  double estimatedArrivalTimeShift() const;

  Geometry geometry() const;

  double length() const;

  QList<DirectionMessage> maneuverMessages() const;

  DirectionManeuverType directionManeuverType() const;

  int fromLevel() const;

  int toLevel() const;

  /*!
     \internal
   */
  DirectionManeuver(const std::shared_ptr<QRTImpl::DirectionManeuverImpl>& impl);
  std::shared_ptr<QRTImpl::DirectionManeuverImpl> getImpl() const;

private:
  std::shared_ptr<QRTImpl::DirectionManeuverImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_DirectionManeuver_H
