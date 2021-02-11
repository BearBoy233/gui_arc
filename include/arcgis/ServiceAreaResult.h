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
/// \file ServiceAreaResult.h

#ifndef QRT_ServiceAreaResult_H
#define QRT_ServiceAreaResult_H

// C++ API headers
#include "PointBarrier.h"
#include "PolygonBarrier.h"
#include "PolylineBarrier.h"
#include "ServiceAreaFacility.h"
#include "ServiceAreaPolygon.h"
#include "ServiceAreaPolyline.h"

// Qt headers
#include <QDateTime>
#include <QList>
#include <QStringList>

// STL headers
#include <memory>

namespace QRTImpl { class ServiceAreaResultImpl; }

namespace Esri {
namespace ArcGISRuntime {

class ServiceAreaResult
{
public:
  ServiceAreaResult();
  ServiceAreaResult(const ServiceAreaResult& other);
  ServiceAreaResult(ServiceAreaResult&& other) noexcept;
  ~ServiceAreaResult();

  ServiceAreaResult& operator=(const ServiceAreaResult& other);
  ServiceAreaResult& operator=(ServiceAreaResult&& other) noexcept;

  bool isEmpty() const;

  QList<ServiceAreaFacility> facilities() const;

  QList<PointBarrier> pointBarriers() const;

  QList<PolygonBarrier> polygonBarriers() const;

  QList<PolylineBarrier> polylineBarriers() const;

  QStringList messages() const;

  QList<ServiceAreaPolyline> resultPolylines(int facilityIndex) const;

  QList<ServiceAreaPolygon> resultPolygons(int facilityIndex) const;

  /*!
     \internal
   */
  ServiceAreaResult(const std::shared_ptr<QRTImpl::ServiceAreaResultImpl>& impl);
  std::shared_ptr<QRTImpl::ServiceAreaResultImpl> getImpl() const;

private:
  std::shared_ptr<QRTImpl::ServiceAreaResultImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ServiceAreaResult_H
