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
/// \file PolygonBuilder.h

#ifndef QRT_PolygonBuilder_H
#define QRT_PolygonBuilder_H

// C++ API headers
#include "MultipartBuilder.h"
#include "Polygon.h"
#include "Polyline.h"
#include "SpatialReference.h"

namespace QRTImpl { class PolygonBuilderImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class PolygonBuilder : public MultipartBuilder
  {
    Q_OBJECT

  public:
    PolygonBuilder(const SpatialReference& spatialReference, QObject* parent = nullptr);

    PolygonBuilder(const Polygon& polygon, QObject* parent = nullptr);

    ~PolygonBuilder();

    Geometry toGeometry() const override;

    Polygon toPolygon() const;

    Polyline toPolyline() const;

    GeometryBuilderType geometryBuilderType() const override;

    /*!
     \internal
     */
    PolygonBuilder(const std::shared_ptr<QRTImpl::PolygonBuilderImpl>& impl, QObject* parent = nullptr);

    std::shared_ptr<QRTImpl::GeometryBuilderImpl> getImpl() const override;

  private:
    Q_DISABLE_COPY(PolygonBuilder)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_PolygonBuilder_H
