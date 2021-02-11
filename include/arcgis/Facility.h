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
/// \file Facility.h

#ifndef QRT_Facility_H
#define QRT_Facility_H

// C++ API headers
#include "NetworkAnalystTypes.h"
#include "NetworkLocation.h"
#include "Point.h"

// STL headers
#include <memory>

namespace QRTImpl { class FacilityImpl; }

namespace Esri {
namespace ArcGISRuntime {

class Facility
{
public:
  Facility();
  explicit Facility(const Point& point);
  Facility(const Facility& other);
  Facility(Facility&& other) noexcept;
  ~Facility();

  Facility& operator=(const Facility& other);
  Facility& operator=(Facility&& other) noexcept;

  bool isEmpty() const;

  QString name() const;
  void setName(const QString& name);

  CurbApproach curbApproach() const;
  void setCurbApproach(CurbApproach curbApproach);

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
  Facility(const std::shared_ptr<QRTImpl::FacilityImpl>& impl);
  std::shared_ptr<QRTImpl::FacilityImpl> getImpl() const;

private:
  std::shared_ptr<QRTImpl::FacilityImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_Facility_H
