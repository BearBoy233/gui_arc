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
/// \file ServiceAreaTaskInfo.h

#ifndef QRT_ServiceAreaTaskInfo_H
#define QRT_ServiceAreaTaskInfo_H

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

namespace QRTImpl { class ServiceAreaTaskInfoImpl; }

namespace Esri {
namespace ArcGISRuntime {

class ServiceAreaTaskInfo
{
public:
  ServiceAreaTaskInfo();
  ServiceAreaTaskInfo(const ServiceAreaTaskInfo& other);
  ServiceAreaTaskInfo(ServiceAreaTaskInfo&& other) noexcept;
  ~ServiceAreaTaskInfo();

  ServiceAreaTaskInfo& operator=(const ServiceAreaTaskInfo& other);
  ServiceAreaTaskInfo& operator=(ServiceAreaTaskInfo&& other) noexcept;

  bool isEmpty() const;

  QString networkName() const;

  QMap<QString, CostAttribute> costAttributes() const;

  QMap<QString, RestrictionAttribute> restrictionAttributes() const;

  QStringList supportedRestrictionUsageParameterValues() const;

  QStringList accumulateAttributeNames() const;

  QList<TravelMode> travelModes() const;

  QString defaultTravelModeName() const;

  QDateTime startTime() const;

  SpatialReference outputSpatialReference() const;

  QList<double> defaultImpedanceCutoffs() const;

  TravelDirection travelDirection() const;

  double polygonBufferDistance() const;

  ServiceAreaPolygonDetail polygonDetail() const;

  ServiceAreaOverlapGeometry geometryAtOverlap() const;

  ServiceAreaPolygonCutoffGeometry geometryAtCutoff() const;

  bool isReturnPolylines() const;

  bool isReturnPolygons() const;

  /*!
     \internal
   */
  ServiceAreaTaskInfo(const std::shared_ptr<QRTImpl::ServiceAreaTaskInfoImpl>& impl);
  std::shared_ptr<QRTImpl::ServiceAreaTaskInfoImpl> getImpl() const;

private:
  std::shared_ptr<QRTImpl::ServiceAreaTaskInfoImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ServiceAreaTaskInfo_H
