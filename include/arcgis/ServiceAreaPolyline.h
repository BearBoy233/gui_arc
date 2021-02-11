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
/// \file ServiceAreaPolyline.h

#ifndef QRT_ServiceAreaPolyline_H
#define QRT_ServiceAreaPolyline_H

// C++ API headers
#include "NetworkAnalystTypes.h"
#include "NetworkLocation.h"
#include "Polyline.h"

// STL headers
#include <memory>

namespace QRTImpl { class ServiceAreaPolylineImpl; }

namespace Esri {
namespace ArcGISRuntime {

class ServiceAreaPolyline
{
public:
  ServiceAreaPolyline();
  ServiceAreaPolyline(const ServiceAreaPolyline& other);
  ServiceAreaPolyline(ServiceAreaPolyline&& other) noexcept;
  ~ServiceAreaPolyline();

  ServiceAreaPolyline& operator=(const ServiceAreaPolyline& other);
  ServiceAreaPolyline& operator=(ServiceAreaPolyline&& other) noexcept;

  bool isEmpty() const;

  Polyline geometry() const;

  NetworkLocation fromNetworkLocation() const;
  NetworkLocation toNetworkLocation() const;

  double fromCumulativeCost(const QString& attributeName) const;
  double toCumulativeCost(const QString& attributeName) const;

  /*!
     \internal
   */
  ServiceAreaPolyline(const std::shared_ptr<QRTImpl::ServiceAreaPolylineImpl>& impl);
  std::shared_ptr<QRTImpl::ServiceAreaPolylineImpl> getImpl() const;

private:
  std::shared_ptr<QRTImpl::ServiceAreaPolylineImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ServiceAreaPolyline_H
