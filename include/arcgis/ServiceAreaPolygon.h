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
/// \file ServiceAreaPolygon.h

#ifndef QRT_ServiceAreaPolygon_H
#define QRT_ServiceAreaPolygon_H

// C++ API headers
#include "NetworkAnalystTypes.h"
#include "Polygon.h"

// STL headers
#include <memory>

namespace QRTImpl { class ServiceAreaPolygonImpl; }

namespace Esri {
namespace ArcGISRuntime {

class ServiceAreaPolygon
{
public:
  ServiceAreaPolygon();
  ServiceAreaPolygon(const ServiceAreaPolygon& other);
  ServiceAreaPolygon(ServiceAreaPolygon&& other) noexcept;
  ~ServiceAreaPolygon();

  ServiceAreaPolygon& operator=(const ServiceAreaPolygon& other);
  ServiceAreaPolygon& operator=(ServiceAreaPolygon&& other) noexcept;

  bool isEmpty() const;

  Polygon geometry() const;

  double fromImpedanceCutoff() const;
  double toImpedanceCutoff() const;

  /*!
     \internal
   */
  ServiceAreaPolygon(const std::shared_ptr<QRTImpl::ServiceAreaPolygonImpl>& impl);
  std::shared_ptr<QRTImpl::ServiceAreaPolygonImpl> getImpl() const;

private:
  std::shared_ptr<QRTImpl::ServiceAreaPolygonImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ServiceAreaPolygon_H
