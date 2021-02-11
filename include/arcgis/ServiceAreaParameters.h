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
/// \file ServiceAreaParameters.h

#ifndef QRT_ServiceAreaParameters_H
#define QRT_ServiceAreaParameters_H

// C++ API headers
#include "ArcGISFeatureTable.h"
#include "CoreTypes.h"
#include "NetworkAnalystTypes.h"
#include "PointBarrier.h"
#include "PolygonBarrier.h"
#include "PolylineBarrier.h"
#include "QueryParameters.h"
#include "ServiceAreaFacility.h"
#include "SpatialReference.h"
#include "TravelMode.h"

// Qt headers
#include <QDateTime>
#include <QStringList>

namespace QRTImpl { class ServiceAreaParametersImpl; }

namespace Esri {
namespace ArcGISRuntime {

class ServiceAreaParameters
{
public:
  ServiceAreaParameters();
  ServiceAreaParameters(const ServiceAreaParameters& other);
  ServiceAreaParameters(ServiceAreaParameters&& other) noexcept;
  ~ServiceAreaParameters();

  ServiceAreaParameters& operator=(const ServiceAreaParameters& other);
  ServiceAreaParameters& operator=(ServiceAreaParameters&& other) noexcept;

  bool isEmpty() const;

  QStringList accumulateAttributeNames() const;
  void setAccumulateAttributeNames(const QStringList& accumulateAttributeNames);

  TravelMode travelMode() const;
  void setTravelMode(const TravelMode& travelMode);

  QDateTime startTime() const;
  void setStartTime(const QDateTime& startTime);

  SpatialReference outputSpatialReference() const;
  void setOutputSpatialReference(const SpatialReference& outputSpatialReference);

  QList<double> defaultImpedanceCutoffs() const;
  void setDefaultImpedanceCutoffs(const QList<double>& defaultImpedanceCutoffs);

  TravelDirection travelDirection() const;
  void setTravelDirection(TravelDirection travelDirection);

  double polygonBufferDistance() const;
  void setPolygonBufferDistance(double polygonBufferDistance);

  ServiceAreaPolygonDetail polygonDetail() const;
  void setPolygonDetail(ServiceAreaPolygonDetail polygonDetail);

  ServiceAreaOverlapGeometry geometryAtOverlap() const;
  void setGeometryAtOverlap(ServiceAreaOverlapGeometry geometryAtOverlap);

  ServiceAreaPolygonCutoffGeometry geometryAtCutoff() const;
  void setGeometryAtCutoff(ServiceAreaPolygonCutoffGeometry geometryAtCutoff);

  bool isReturnPointBarriers() const;
  void setReturnPointBarriers(bool returnPointBarriers);

  bool isReturnPolylineBarriers() const;
  void setReturnPolylineBarriers(bool returnPolylineBarriers);

  bool isReturnPolygonBarriers() const;
  void setReturnPolygonBarriers(bool returnPolygonBarriers);

  bool isReturnPolylines() const;
  void setReturnPolylines(bool returnPolylines);

  bool isReturnPolygons() const;
  void setReturnPolygons(bool returnPolygons);

  void clearFacilities();
  void setFacilities(const QList<ServiceAreaFacility>& facilities);
  void setFacilitiesWithFeatureTable(ArcGISFeatureTable* featureTable,
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
  ServiceAreaParameters(const std::shared_ptr<QRTImpl::ServiceAreaParametersImpl>& impl);
  std::shared_ptr<QRTImpl::ServiceAreaParametersImpl> getImpl() const;

private:
  std::shared_ptr<QRTImpl::ServiceAreaParametersImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ServiceAreaParameters_H
