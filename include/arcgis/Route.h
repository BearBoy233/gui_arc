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
/// \file Route.h

#ifndef QRT_Route_H
#define QRT_Route_H

// C++ API headers
#include "DirectionManeuverListModel.h"
#include "Polyline.h"
#include "Stop.h"

// Qt headers
#include <QDateTime>
#include <QList>
#include <QString>

// STL headers
#include <memory>

namespace QRTImpl { class RouteImpl; }

namespace Esri {
namespace ArcGISRuntime {

class Route
{
public:
  Route();
  Route(const Route& other);
  Route(Route&& other) noexcept;
  ~Route();

  Route& operator=(const Route& other);
  Route& operator=(Route&& other) noexcept;

  bool isEmpty() const;

  DirectionManeuverListModel* directionManeuvers(QObject* parent = nullptr) const;

  QDateTime startTime() const;

  double startTimeShift() const;

  QDateTime endTime() const;

  double endTimeShift() const;

  Polyline routeGeometry() const;

  QString routeName() const;

  QList<Stop> stops() const;

  double totalLength() const;

  double totalTime() const;

  double travelTime() const;

  double violationTime() const;

  double waitTime() const;

  double cost(const QString& attributeName) const;

  /*!
     \internal
   */
  Route(const std::shared_ptr<QRTImpl::RouteImpl>& impl);
  std::shared_ptr<QRTImpl::RouteImpl> getImpl() const;

private:
  std::shared_ptr<QRTImpl::RouteImpl> m_impl;
  mutable DirectionManeuverListModel* m_directionManeuvers = nullptr;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_Route_H
