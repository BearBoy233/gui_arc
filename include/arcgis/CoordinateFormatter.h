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
/// \file CoordinateFormatter.h

#ifndef QRT_CoordinateFormatter_H
#define QRT_CoordinateFormatter_H

// C++ API headers
#include "GeometryTypes.h"
#include "Object.h"
#include "Point.h"
#include "SpatialReference.h"

namespace Esri {
namespace ArcGISRuntime {

  class CoordinateFormatter : public Object
  {
    Q_OBJECT

  public:
    static CoordinateFormatter* instance();

    ~CoordinateFormatter();

    static Point fromGars(const QString& coordinates,
                          const SpatialReference& spatialReference,
                          GarsConversionMode garsConversionMode);

    static Point fromGeoRef(const QString& coordinates,
                            const SpatialReference& spatialReference);

    static Point fromLatitudeLongitude(const QString& coordinates,
                                       const SpatialReference& spatialReference);

    static Point fromMgrs(const QString& coordinates,
                          const SpatialReference& spatialReference,
                          MgrsConversionMode mgrsConversionMode);

    static Point fromUsng(const QString& coordinates,
                          const SpatialReference& spatialReference);

    static Point fromUtm(const QString& coordinates,
                         const SpatialReference& spatialReference,
                         UtmConversionMode utmConversionMode);

    static QString toGars(const Point& point);

    static QString toGeoRef(const Point& point, int precision);

    static QString toLatitudeLongitude(const Point& point,
                                       LatitudeLongitudeFormat format,
                                       int decimalPlaces);

    static QString toMgrs(const Point& point,
                          MgrsConversionMode mgrsConversionMode,
                          int precision,
                          bool addSpaces);

    static QString toUsng(const Point& point,
                          int precision,
                          bool addSpaces);

    static QString toUtm(const Point& point,
                         UtmConversionMode utmConversionMode,
                         bool addSpaces);

  private:
    CoordinateFormatter();
    Q_DISABLE_COPY(CoordinateFormatter)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_CoordinateFormatter_H
