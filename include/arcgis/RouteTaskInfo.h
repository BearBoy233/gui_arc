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
/// \file RouteTaskInfo.h

#ifndef QRT_RouteTaskInfo_H
#define QRT_RouteTaskInfo_H

// C++ API headers
#include "CoreTypes.h"
#include "CostAttribute.h"
#include "NetworkAnalystTypes.h"
#include "RestrictionAttribute.h"
#include "SpatialReference.h"
#include "TravelMode.h"

// Qt headers
#include <QDateTime>
#include <QMap>
#include <QStringList>

// STL headers
#include <memory>

namespace QRTImpl { class RouteTaskInfoImpl; }

namespace Esri {
namespace ArcGISRuntime {

class RouteTaskInfo
{
public:
  RouteTaskInfo();
  RouteTaskInfo(const RouteTaskInfo& other);
  RouteTaskInfo(RouteTaskInfo&& other) noexcept;
  ~RouteTaskInfo();

  RouteTaskInfo& operator=(const RouteTaskInfo& other);
  RouteTaskInfo& operator=(RouteTaskInfo&& other) noexcept;

  bool isEmpty() const;

  QStringList accumulateAttributeNames() const;

  QMap<QString, CostAttribute> costAttributes() const;

  QString defaultTravelModeName() const;

  UnitSystem directionsDistanceUnits() const;

  QString directionsLanguage() const;

  DirectionsStyle directionsStyle() const;

  bool isFindBestSequence() const;

  QDateTime startTime() const;

  QString networkName() const;

  SpatialReference outputSpatialReference() const;

  bool isPreserveFirstStop() const;

  bool isPreserveLastStop() const;

  QMap<QString, RestrictionAttribute> restrictionAttributes() const;

  RouteShapeType routeShapeType() const;

  QStringList supportedLanguages() const;

  QStringList supportedRestrictionUsageParameterValues() const;

  QList<TravelMode> travelModes() const;

  /*!
     \internal
   */
  RouteTaskInfo(const std::shared_ptr<QRTImpl::RouteTaskInfoImpl>& impl);
  std::shared_ptr<QRTImpl::RouteTaskInfoImpl> getImpl() const;

private:
  std::shared_ptr<QRTImpl::RouteTaskInfoImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_RouteTaskInfo_H
