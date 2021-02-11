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
/// \file Incident.h

#ifndef QRT_Incident_H
#define QRT_Incident_H

// C++ API headers
#include "NetworkAnalystTypes.h"
#include "NetworkLocation.h"
#include "Point.h"

// STL headers
#include <memory>

namespace QRTImpl { class IncidentImpl; }

namespace Esri {
namespace ArcGISRuntime {

class Incident
{
public:
  Incident();
  explicit Incident(const Point& point);
  Incident(const Incident& other);
  Incident(Incident&& other) noexcept;
  ~Incident();

  Incident& operator=(const Incident& other);
  Incident& operator=(Incident&& other) noexcept;

  bool isEmpty() const;

  QString name() const;
  void setName(const QString& name);

  CurbApproach curbApproach() const;
  void setCurbApproach(CurbApproach curbApproach);

  int targetFacilityCount() const;
  void setTargetFacilityCount(int targetFacilityCount);

  NetworkLocation networkLocation() const;
  void setNetworkLocation(const NetworkLocation& networkLocation);

  double impedanceCutoff() const;
  void setImpedanceCutoff(double impedanceCutoff);

  double distanceToNetworkLocation() const;

  LocationStatus locationStatus() const;

  Point geometry() const;
  void setGeometry(const Point& point);

  double addedCost(const QString& attributeName) const;
  void setAddedCost(const QString& attributeName, double costValue);

  /*!
     \internal
   */
  Incident(const std::shared_ptr<QRTImpl::IncidentImpl>& impl);
  std::shared_ptr<QRTImpl::IncidentImpl> getImpl() const;

private:
  std::shared_ptr<QRTImpl::IncidentImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_Incident_H
