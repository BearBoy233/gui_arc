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
/// \file Polygon.h

#ifndef QRT_Polygon_H
#define QRT_Polygon_H

// C++ API headers
#include "Multipart.h"
#include "Polyline.h"

// STL headers
#include <memory>

namespace QRTImpl { class PolygonImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class Polygon : public Multipart
  {
  public:
    Polygon();

    Polygon(const Polygon& other);
    Polygon(Polygon&& other) noexcept;
    Polygon(const Geometry& other);

    Polygon& operator=(const Polygon& other);
    Polygon& operator=(Polygon&& other) noexcept;

    ~Polygon();

    bool isValid() const;

    Polyline toPolyline() const;

    /*! \internal */
    explicit Polygon(const std::shared_ptr<QRTImpl::PolygonImpl>& impl);
    std::shared_ptr<QRTImpl::PolygonImpl> getImpl() const;
  };

  /*! \internal */
  template<>
  inline Polygon geometry_cast<Polygon>(const Geometry& geometry)
  {
    return geometry.geometryType() == GeometryType::Polygon ? static_cast<Polygon>(geometry) : Polygon();
  }

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_Polygon_H

