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
/// \file ClosestFacilityResult.h

#ifndef QRT_ClosestFacilityResult_H
#define QRT_ClosestFacilityResult_H

// C++ API headers
#include "ClosestFacilityRoute.h"
#include "Facility.h"
#include "Incident.h"
#include "PointBarrier.h"
#include "PolygonBarrier.h"
#include "PolylineBarrier.h"

// Qt headers
#include <QDateTime>
#include <QList>
#include <QStringList>

// STL headers
#include <memory>

namespace QRTImpl { class ClosestFacilityResultImpl; }

namespace Esri {
namespace ArcGISRuntime {

class ClosestFacilityResult
{
public:
  ClosestFacilityResult();
  ClosestFacilityResult(const ClosestFacilityResult& other);
  ClosestFacilityResult(ClosestFacilityResult&& other) noexcept;
  ~ClosestFacilityResult();

  ClosestFacilityResult& operator=(const ClosestFacilityResult& other);
  ClosestFacilityResult& operator=(ClosestFacilityResult&& other) noexcept;

  bool isEmpty() const;

  QList<Facility> facilities() const;

  QList<Incident> incidents() const;

  QList<PointBarrier> pointBarriers() const;

  QList<PolygonBarrier> polygonBarriers() const;

  QList<PolylineBarrier> polylineBarriers() const;

  QStringList messages() const;

  QString directionsLanguage() const;

  ClosestFacilityRoute route(int facilityIndex, int incidentIndex) const;

  QList<double> facilityCosts(const QString& attributeName, int facilityIndex) const;

  QList<int> rankedFacilityIndexes(int incidentIndex) const;

  /*!
     \internal
   */
  ClosestFacilityResult(const std::shared_ptr<QRTImpl::ClosestFacilityResultImpl>& impl);
  std::shared_ptr<QRTImpl::ClosestFacilityResultImpl> getImpl() const;

private:
  std::shared_ptr<QRTImpl::ClosestFacilityResultImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ClosestFacilityResult_H
