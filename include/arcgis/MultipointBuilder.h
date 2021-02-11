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
/// \file MultipointBuilder.h

#ifndef QRT_MultipointBuilder_H
#define QRT_MultipointBuilder_H

// C++ API headers
#include "GeometryBuilder.h"
#include "Multipoint.h"
#include "PointCollection.h"
#include "SpatialReference.h"

// STL headers
#include <memory>

namespace QRTImpl { class MultipointBuilderImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class MultipointBuilder : public GeometryBuilder
  {
    Q_OBJECT

  public:
    MultipointBuilder(const SpatialReference& spatialReference, QObject* parent = nullptr);

    MultipointBuilder(const Multipoint& multipoint, QObject* parent = nullptr);

    ~MultipointBuilder();

    PointCollection* points() const;

    void setPoints(PointCollection* points);

    Geometry toGeometry() const override;

    Multipoint toMultipoint() const;

    GeometryBuilderType geometryBuilderType() const override;

    MultipointBuilder(const std::shared_ptr<QRTImpl::MultipointBuilderImpl>& impl, QObject* parent = nullptr);

    std::shared_ptr<QRTImpl::GeometryBuilderImpl> getImpl() const override;

  private:
    Q_DISABLE_COPY(MultipointBuilder)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_MultipointBuilder_H

