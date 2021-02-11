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
/// \file ServiceAreaFacility.h

#ifndef QRT_ServiceAreaFacility_H
#define QRT_ServiceAreaFacility_H

// C++ API headers
#include "NetworkAnalystTypes.h"
#include "NetworkLocation.h"
#include "Point.h"

// STL headers
#include <memory>

namespace QRTImpl { class ServiceAreaFacilityImpl; }

namespace Esri {
namespace ArcGISRuntime {

class ServiceAreaFacility
{
public:
  ServiceAreaFacility();
  explicit ServiceAreaFacility(const Point& point);
  ServiceAreaFacility(const ServiceAreaFacility& other);
  ServiceAreaFacility(ServiceAreaFacility&& other) noexcept;
  ~ServiceAreaFacility();

  ServiceAreaFacility& operator=(const ServiceAreaFacility& other);
  ServiceAreaFacility& operator=(ServiceAreaFacility&& other) noexcept;

  bool isEmpty() const;

  QString name() const;
  void setName(const QString& name);

  CurbApproach curbApproach() const;
  void setCurbApproach(CurbApproach curbApproach);

  NetworkLocation networkLocation() const;
  void setNetworkLocation(const NetworkLocation& networkLocation);

  QList<double> impedanceCutoffs() const;
  void setImpedanceCutoffs(const QList<double>& impedanceCutoffs);

  double distanceToNetworkLocation() const;

  LocationStatus locationStatus() const;

  Point geometry() const;
  void setGeometry(const Point& point);

  double addedCost(const QString& attributeName) const;
  void setAddedCost(const QString& attributeName, double costValue);

  /*!
     \internal
   */
  ServiceAreaFacility(const std::shared_ptr<QRTImpl::ServiceAreaFacilityImpl>& impl);
  std::shared_ptr<QRTImpl::ServiceAreaFacilityImpl> getImpl() const;

private:
  std::shared_ptr<QRTImpl::ServiceAreaFacilityImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ServiceAreaFacility_H
