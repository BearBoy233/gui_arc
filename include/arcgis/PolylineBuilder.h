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
/// \file PolylineBuilder.h

#ifndef QRT_PolylineBuilder_H
#define QRT_PolylineBuilder_H

// C++ API headers
#include "MultipartBuilder.h"
#include "Polyline.h"
#include "SpatialReference.h"

namespace QRTImpl { class PolylineBuilderImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class PolylineBuilder : public MultipartBuilder
  {
    Q_OBJECT

  public:
    PolylineBuilder(const SpatialReference& spatialReference, QObject* parent = nullptr);

    PolylineBuilder(const Polyline& polyline, QObject* parent = nullptr);

    ~PolylineBuilder();

    Geometry toGeometry() const override;

    Polyline toPolyline() const;

    GeometryBuilderType geometryBuilderType() const override;

    /*!
     \internal
     */
    PolylineBuilder(const std::shared_ptr<QRTImpl::PolylineBuilderImpl>& impl, QObject* parent = nullptr);

    std::shared_ptr<QRTImpl::GeometryBuilderImpl> getImpl() const override;

  private:
    Q_DISABLE_COPY(PolylineBuilder)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_PolylineBuilder_H
