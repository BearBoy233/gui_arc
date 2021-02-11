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
/// \file ClosestFacilityTaskInfo.h

#ifndef QRT_ClosestFacilityTaskInfo_H
#define QRT_ClosestFacilityTaskInfo_H

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

namespace QRTImpl { class ClosestFacilityTaskInfoImpl; }

namespace Esri {
namespace ArcGISRuntime {

class ClosestFacilityTaskInfo
{
public:
  ClosestFacilityTaskInfo();
  ClosestFacilityTaskInfo(const ClosestFacilityTaskInfo& other);
  ClosestFacilityTaskInfo(ClosestFacilityTaskInfo&& other) noexcept;
  ~ClosestFacilityTaskInfo();

  ClosestFacilityTaskInfo& operator=(const ClosestFacilityTaskInfo& other);
  ClosestFacilityTaskInfo& operator=(ClosestFacilityTaskInfo&& other) noexcept;

  bool isEmpty() const;

  QString networkName() const;

  QMap<QString, CostAttribute> costAttributes() const;

  QMap<QString, RestrictionAttribute> restrictionAttributes() const;

  QStringList supportedRestrictionUsageParameterValues() const;

  QList<TravelMode> travelModes() const;

  QString defaultTravelModeName() const;

  QStringList accumulateAttributeNames() const;

  QDateTime startTime() const;

  StartTimeUsage startTimeUsage() const;

  int defaultTargetFacilityCount() const;

  double defaultImpedanceCutoff() const;

  TravelDirection travelDirection() const;

  RouteShapeType routeShapeType() const;

  SpatialReference outputSpatialReference() const;

  QStringList supportedLanguages() const;

  UnitSystem directionsDistanceUnits() const;

  QString directionsLanguage() const;

  DirectionsStyle directionsStyle() const;

  /*!
     \internal
   */
  ClosestFacilityTaskInfo(const std::shared_ptr<QRTImpl::ClosestFacilityTaskInfoImpl>& impl);
  std::shared_ptr<QRTImpl::ClosestFacilityTaskInfoImpl> getImpl() const;

private:
  std::shared_ptr<QRTImpl::ClosestFacilityTaskInfoImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ClosestFacilityTaskInfo_H
