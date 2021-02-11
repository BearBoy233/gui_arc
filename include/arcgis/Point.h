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
/// \file Point.h

#ifndef QRT_Point_H
#define QRT_Point_H

// C++ API headers
#include "Geometry.h"
#include "SpatialReference.h"

// STL headers
#include <memory>

namespace QRTImpl { class PointImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class Point : public Geometry
  {
  public:
    Point();
    Point(double x, double y);
    Point(double x, double y, const SpatialReference& spatialReference);
    Point(double x, double y, double z);
    Point(double x, double y, double z, const SpatialReference& spatialReference);

    Point(const Point& other);
    Point(Point&& other) noexcept;
    Point(const Geometry& other);

    Point& operator=(const Point& other);
    Point& operator=(Point&& other) noexcept;

    ~Point();

    double x() const;
    double y() const;
    double z() const;
    double m() const;

    bool isValid() const;

    static Point createWithM(double x, double y, double m);
    static Point createWithM(double x, double y, double m, const SpatialReference& spatialReference);
    static Point createWithM(double x, double y, double z, double m);
    static Point createWithM(double x, double y, double z, double m, const SpatialReference& spatialReference);

    /*! \internal */
    explicit Point(const std::shared_ptr<QRTImpl::PointImpl>& impl);
    std::shared_ptr<QRTImpl::PointImpl> getImpl() const;
  };

  /*! \internal */
  template<>
  inline Point geometry_cast<Point>(const Geometry& geometry)
  {
    return geometry.geometryType() == GeometryType::Point ? static_cast<Point>(geometry) : Point();
  }

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_Point_H

