// COPYRIGHT 1995-2016 ESRI
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
/// \file RouteParameters.h

#ifndef QRT_RouteParameters_H
#define QRT_RouteParameters_H

// C++ API headers
#include "ArcGISFeatureTable.h"
#include "CoreTypes.h"
#include "NetworkAnalystTypes.h"
#include "PointBarrier.h"
#include "PolygonBarrier.h"
#include "PolylineBarrier.h"
#include "QueryParameters.h"
#include "SpatialReference.h"
#include "Stop.h"
#include "TravelMode.h"

// Qt headers
#include <QDateTime>
#include <QStringList>

namespace QRTImpl { class RouteParametersImpl; }

namespace Esri {
namespace ArcGISRuntime {

class RouteParameters
{
public:
  RouteParameters();
  RouteParameters(const RouteParameters& other);
  RouteParameters(RouteParameters&& other) noexcept;
  ~RouteParameters();

  RouteParameters& operator=(const RouteParameters& other);
  RouteParameters& operator=(RouteParameters&& other) noexcept;

  bool isEmpty() const;

  QStringList accumulateAttributeNames() const;
  void setAccumulateAttributeNames(const QStringList& accumulateAttributeNames);

  UnitSystem directionsDistanceUnits() const;
  void setDirectionsDistanceUnits(UnitSystem directionsDistanceUnits);

  QString directionsLanguage() const;
  void setDirectionsLanguage(const QString& directionsLanguage);

  DirectionsStyle directionsStyle() const;
  void setDirectionsStyle(DirectionsStyle directionsStyle);

  bool isFindBestSequence() const;
  void setFindBestSequence(bool findBestSequence);

  QDateTime startTime() const;
  void setStartTime(const QDateTime& startTime);

  SpatialReference outputSpatialReference() const;
  void setOutputSpatialReference(const SpatialReference& outputSpatialReference);

  bool isPreserveFirstStop() const;
  void setPreserveFirstStop(bool preserveFirstStop);

  bool isPreserveLastStop() const;
  void setPreserveLastStop(bool preserveLastStop);

  bool isReturnDirections() const;
  void setReturnDirections(bool returnDirections);

  bool isReturnPointBarriers() const;
  void setReturnPointBarriers(bool returnPointBarriers);

  bool isReturnPolygonBarriers() const;
  void setReturnPolygonBarriers(bool returnPolygonBarriers);

  bool isReturnPolylineBarriers() const;
  void setReturnPolylineBarriers(bool returnPolylineBarriers);

  bool isReturnRoutes() const;
  void setReturnRoutes(bool returnRoutes);

  bool isReturnStops() const;
  void setReturnStops(bool returnStops);

  RouteShapeType routeShapeType() const;
  void setRouteShapeType(RouteShapeType routeShapeType);

  TravelMode travelMode() const;
  void setTravelMode(const TravelMode& travelMode);

  QString searchWhereClause(const QString& sourceName) const;
  void setSearchWhereClause(const QString& sourceName, const QString& searchWhereClause);

  void clearStops();
  void setStops(const QList<Stop>& stops);
  void setStopsWithFeatureTable(ArcGISFeatureTable* featureTable,
                                const QueryParameters& queryParameters);

  void clearPointBarriers();
  void setPointBarriers(const QList<PointBarrier>& pointBarriers);
  void setPointBarriersWithFeatureTable(ArcGISFeatureTable* featureTable,
                                        const QueryParameters& queryParameters);

  void clearPolygonBarriers();
  void setPolygonBarriers(const QList<PolygonBarrier>& polygonBarriers);
  void setPolygonBarriersWithFeatureTable(ArcGISFeatureTable* featureTable,
                                          const QueryParameters& queryParameters);

  void clearPolylineBarriers();
  void setPolylineBarriers(const QList<PolylineBarrier>& polylineBarriers);
  void setPolylineBarriersWithFeatureTable(ArcGISFeatureTable* featureTable,
                                           const QueryParameters& queryParameters);

  /*!
     \internal
   */
  RouteParameters(const std::shared_ptr<QRTImpl::RouteParametersImpl>& impl);
  std::shared_ptr<QRTImpl::RouteParametersImpl> getImpl() const;

private:
  std::shared_ptr<QRTImpl::RouteParametersImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_RouteParameters_H
