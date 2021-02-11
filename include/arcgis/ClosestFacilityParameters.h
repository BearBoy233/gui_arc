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
/// \file ClosestFacilityParameters.h

#ifndef QRT_ClosestFacilityParameters_H
#define QRT_ClosestFacilityParameters_H

// C++ API headers
#include "ArcGISFeatureTable.h"
#include "CoreTypes.h"
#include "Facility.h"
#include "Incident.h"
#include "NetworkAnalystTypes.h"
#include "PointBarrier.h"
#include "PolygonBarrier.h"
#include "PolylineBarrier.h"
#include "QueryParameters.h"
#include "SpatialReference.h"
#include "TravelMode.h"

// Qt headers
#include <QDateTime>
#include <QStringList>

namespace QRTImpl { class ClosestFacilityParametersImpl; }

namespace Esri {
namespace ArcGISRuntime {

class ClosestFacilityParameters
{
public:
  ClosestFacilityParameters();
  ClosestFacilityParameters(const ClosestFacilityParameters& other);
  ClosestFacilityParameters(ClosestFacilityParameters&& other) noexcept;
  ~ClosestFacilityParameters();

  ClosestFacilityParameters& operator=(const ClosestFacilityParameters& other);
  ClosestFacilityParameters& operator=(ClosestFacilityParameters&& other) noexcept;

  bool isEmpty() const;

  QStringList accumulateAttributeNames() const;
  void setAccumulateAttributeNames(const QStringList& accumulateAttributeNames);

  TravelMode travelMode() const;
  void setTravelMode(const TravelMode& travelMode);

  int defaultTargetFacilityCount() const;
  void setDefaultTargetFacilityCount(int defaultTargetFacilityCount);

  double defaultImpedanceCutoff() const;
  void setDefaultImpedanceCutoff(double defaultImpedanceCutoff);

  QDateTime startTime() const;
  void setStartTime(const QDateTime& startTime);

  StartTimeUsage startTimeUsage() const;
  void setStartTimeUsage(StartTimeUsage startTimeUsage);

  TravelDirection travelDirection() const;
  void setTravelDirection(TravelDirection travelDirection);

  RouteShapeType routeShapeType() const;
  void setRouteShapeType(RouteShapeType routeShapeType);

  SpatialReference outputSpatialReference() const;
  void setOutputSpatialReference(const SpatialReference& outputSpatialReference);

  bool isReturnPointBarriers() const;
  void setReturnPointBarriers(bool returnPointBarriers);

  bool isReturnPolylineBarriers() const;
  void setReturnPolylineBarriers(bool returnPolylineBarriers);

  bool isReturnPolygonBarriers() const;
  void setReturnPolygonBarriers(bool returnPolygonBarriers);

  bool isReturnRoutes() const;
  void setReturnRoutes(bool returnRoutes);

  bool isReturnDirections() const;
  void setReturnDirections(bool returnDirections);

  UnitSystem directionsDistanceUnits() const;
  void setDirectionsDistanceUnits(UnitSystem directionsDistanceUnits);

  QString directionsLanguage() const;
  void setDirectionsLanguage(const QString& directionsLanguage);

  DirectionsStyle directionsStyle() const;
  void setDirectionsStyle(DirectionsStyle directionsStyle);

  QString searchWhereClause(const QString& sourceName) const;
  void setSearchWhereClause(const QString& sourceName, const QString& searchWhereClause);

  void clearFacilities();
  void setFacilities(const QList<Facility>& facilities);
  void setFacilitiesWithFeatureTable(ArcGISFeatureTable* featureTable,
                                     const QueryParameters& queryParameters);

  void clearIncidents();
  void setIncidents(const QList<Incident>& incidents);
  void setIncidentsWithFeatureTable(ArcGISFeatureTable* featureTable,
                                    const QueryParameters& queryParameters);

  void clearPointBarriers();
  void setPointBarriers(const QList<PointBarrier>& pointBarriers);
  void setPointBarriersWithFeatureTable(ArcGISFeatureTable* featureTable,
                                        const QueryParameters& queryParameters);

  void clearPolylineBarriers();
  void setPolylineBarriers(const QList<PolylineBarrier>& polylineBarriers);
  void setPolylineBarriersWithFeatureTable(ArcGISFeatureTable* featureTable,
                                           const QueryParameters& queryParameters);

  void clearPolygonBarriers();
  void setPolygonBarriers(const QList<PolygonBarrier>& polygonBarriers);
  void setPolygonBarriersWithFeatureTable(ArcGISFeatureTable* featureTable,
                                          const QueryParameters& queryParameters);

  /*!
     \internal
   */
  ClosestFacilityParameters(const std::shared_ptr<QRTImpl::ClosestFacilityParametersImpl>& impl);
  std::shared_ptr<QRTImpl::ClosestFacilityParametersImpl> getImpl() const;

private:
  std::shared_ptr<QRTImpl::ClosestFacilityParametersImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ClosestFacilityParameters_H
