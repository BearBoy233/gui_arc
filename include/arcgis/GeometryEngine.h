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
/// \file GeometryEngine.h

#ifndef QRT_GeometryEngine_H
#define QRT_GeometryEngine_H

// C++ API headers
#include "AngularUnit.h"
#include "AreaUnit.h"
#include "Envelope.h"
#include "GeometryTypes.h"
#include "LinearUnit.h"
#include "Object.h"
#include "Point.h"
#include "Polygon.h"
#include "Polyline.h"
#include "SpatialReference.h"

namespace QRTImpl {
  class GeometryEngineImpl;
  class ProximityResultImpl;
  class GeodeticDistanceResultImpl;
  class GeodesicEllipseParametersImpl;
  class GeodesicSectorParametersImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class ProximityResult;
  class GeodeticDistanceResult;
  class GeodesicEllipseParameters;
  class GeodesicSectorParameters;
  class DatumTransformation;

  class GeometryEngine : public Object
  {
    Q_OBJECT

  public:
    static GeometryEngine* instance();

    ~GeometryEngine();

    static bool equals(const Geometry& geometry1,
                       const Geometry& geometry2);

    static Geometry project(const Geometry& geometry,
                            const SpatialReference& spatialReference);

    static Geometry project(const Geometry& geometry,
                            const SpatialReference& spatialReference,
                            DatumTransformation* datumTransformation);

    static Geometry normalizeCentralMeridian(const Geometry& geometry);

    static double area(const Geometry& geometry);

    static Polygon buffer(const Geometry& geometry,
                          double distance);

    static QList<Polygon> buffer(const QList<Geometry>& geometries,
                                 const QList<double>& distances,
                                 bool unionResult);

    static bool contains(const Geometry& geometry1,
                         const Geometry& geometry2);

    static Geometry densify(const Geometry& geometry,
                            double maxSegmentLength);

    static Geometry difference(const Geometry& geometry1,
                               const Geometry& geometry2);

    static bool disjoint(const Geometry& geometry1,
                         const Geometry& geometry2);

    static double distance(const Geometry& geometry1,
                           const Geometry& geometry2);

    static double areaGeodetic(const Geometry& geometry,
                               const AreaUnit& unit,
                               GeodeticCurveType curveType);

    static Polygon bufferGeodetic(const Geometry& geometry,
                                  double distance,
                                  const LinearUnit& unit,
                                  double maxDeviation,
                                  GeodeticCurveType curveType);

    static QList<Polygon> bufferGeodetic(const QList<Geometry>& geometries,
                                         const QList<double>& distances,
                                         const LinearUnit& unit,
                                         double maxDeviation,
                                         GeodeticCurveType curveType,
                                         bool unionResult);

    static Geometry densifyGeodetic(const Geometry& geometry,
                                    double maxSegmentLength,
                                    const LinearUnit& lengthUnit,
                                    GeodeticCurveType curveType);

    static GeodeticDistanceResult distanceGeodetic(const Point& point1,
                                                   const Point& point2,
                                                   const LinearUnit& distanceUnit,
                                                   const AngularUnit& azimuthUnit,
                                                   GeodeticCurveType curveType);

    static Geometry ellipseGeodesic(const GeodesicEllipseParameters& parameters);

    static double lengthGeodetic(const Geometry& geometry,
                                 const LinearUnit& lengthUnit,
                                 GeodeticCurveType curveType);

    static QList<Point> moveGeodetic(const QList<Point>& pointCollection,
                                     double distance,
                                     const LinearUnit& distanceUnit,
                                     double azimuth,
                                     const AngularUnit& azimuthUnit,
                                     GeodeticCurveType curveType);

    static Geometry sectorGeodesic(const GeodesicSectorParameters& parameters);

    static Geometry intersection(const Geometry& geometry1,
                                 const Geometry& geometry2);

    static QList<Geometry> intersections(const Geometry& geometry1,
                                         const Geometry& geometry2);

    static bool intersects(const Geometry& geometry1,
                           const Geometry& geometry2);

    static double length(const Geometry& geometry);

    static Geometry simplify(const Geometry& geometry);

    static bool touches(const Geometry& geometry1,
                        const Geometry& geometry2);

    static Geometry unionOf(const Geometry& geometry1,
                            const Geometry& geometry2);

    static Geometry unionOf(const QList<Geometry>& geometries);

    static bool within(const Geometry& geometry1,
                       const Geometry& geometry2);

    static Geometry boundary(const Geometry& geometry);

    static Geometry clip(const Geometry& geometry,
                         const Envelope& envelope);

    static Geometry convexHull(const Geometry& geometry);

    static QList<Geometry> convexHull(const QList<Geometry>& geometries,
                                      bool unionResult);

    static Point createPointAlong(const Polyline& polyline, double distance);

    static bool crosses(const Geometry& geometry1,
                        const Geometry& geometry2);

    static Geometry generalize(const Geometry& geometry,
                               double maxDeviation,
                               bool removeDegenerateParts);

    static bool isSimple(const Geometry& geometry);

    static Point labelPoint(const Polygon& polygon);

    static ProximityResult nearestCoordinate(const Geometry& geometry,
                                             const Point& point);

    static ProximityResult nearestVertex(const Geometry& geometry,
                                         const Point& point);

    static Geometry offset(const Geometry& geometry,
                           double distance,
                           GeometryOffsetType offsetType,
                           double bevelRatio,
                           double flattenError);

    static bool overlaps(const Geometry& geometry1,
                         const Geometry& geometry2);

    static bool relate(const Geometry& geometry1,
                       const Geometry& geometry2,
                       const QString& relation);

    static Geometry symmetricDifference(const Geometry& geometry1,
                                        const Geometry& geometry2);

    static Envelope combineExtents(const Geometry& geometry1,
                                   const Geometry& geometry2);

    static Envelope combineExtents(const QList<Geometry>& geometries);

    static QList<Polygon> autoComplete(const QList<Geometry>& existingBoundaries,
                                       const QList<Geometry>& newBoundaries);

    static Polyline extend(const Polyline& polyline,
                           const Polyline& extender,
                           GeometryExtendOptions extendOptions);

    static Multipart reshape(const Multipart& geometry,
                             const Polyline& reshaper);

    static QList<Geometry> cut(const Geometry& geometry,
                               const Polyline& cutter);

    static Geometry setM(const Geometry& geometry, double m);
    static Geometry setZ(const Geometry& geometry, double z);
    static Geometry setZAndM(const Geometry& geometry, double z, double m);

    static Geometry removeM(const Geometry& geometry);
    static Geometry removeZ(const Geometry& geometry);
    static Geometry removeZAndM(const Geometry& geometry);

  private:
    GeometryEngine();
    Q_DISABLE_COPY(GeometryEngine)
  };

  /////////////////////////////////////////////
  ///////////// ProximityResult ///////////////
  /////////////////////////////////////////////

  class ProximityResult
  {
  public:
    ProximityResult();
    ProximityResult(const ProximityResult& other);
    ProximityResult(ProximityResult&& other) noexcept;
    ProximityResult& operator =(const ProximityResult& other);
    ProximityResult& operator =(ProximityResult&& other) noexcept;
    ~ProximityResult();

    Point coordinate() const;
    double distance() const;
    int partIndex() const;
    int pointIndex() const;

    static int npos();

    bool isEmpty() const;

    std::shared_ptr<QRTImpl::ProximityResultImpl> getImpl() const;
    /*!
       \internal
    */
    explicit ProximityResult(const std::shared_ptr<QRTImpl::ProximityResultImpl>& impl);

  private:
    std::shared_ptr<QRTImpl::ProximityResultImpl> m_impl;
  };

  /////////////////////////////////////////////
  ///////// GeodeticDistanceResult ////////////
  /////////////////////////////////////////////

  class GeodeticDistanceResult
  {
  public:
    GeodeticDistanceResult();
    GeodeticDistanceResult(const GeodeticDistanceResult& other);
    GeodeticDistanceResult(GeodeticDistanceResult&& other) noexcept;
    GeodeticDistanceResult& operator=(const GeodeticDistanceResult& other);
    GeodeticDistanceResult& operator=(GeodeticDistanceResult&& other) noexcept;
    ~GeodeticDistanceResult();

    AngularUnit azimuthUnit() const;
    double azimuth1() const;
    double azimuth2() const;
    double distance() const;
    LinearUnit distanceUnit() const;

    bool isEmpty() const;

    std::shared_ptr<QRTImpl::GeodeticDistanceResultImpl> getImpl() const;
    /*!
       \internal
    */
    explicit GeodeticDistanceResult(const std::shared_ptr<QRTImpl::GeodeticDistanceResultImpl>& impl);

  private:
    std::shared_ptr<QRTImpl::GeodeticDistanceResultImpl> m_impl;
  };

  /////////////////////////////////////////////
  ///////// GeodesicEllipseParameters /////////
  /////////////////////////////////////////////

  class GeodesicEllipseParameters
  {
  public:
    GeodesicEllipseParameters();
    GeodesicEllipseParameters(const Point& center, double semiAxis1Length, double semiAxis2Length);
    GeodesicEllipseParameters(double axisDirection,
                              const AngularUnit& angularUnit,
                              const Point& center,
                              const LinearUnit& linearUnit,
                              unsigned int maxPointCount,
                              double maxSegmentLength,
                              GeometryType geometryType,
                              double semiAxis1Length,
                              double semiAxis2Length);
    GeodesicEllipseParameters(const GeodesicEllipseParameters& other);
    GeodesicEllipseParameters(GeodesicEllipseParameters&& other) noexcept;
    GeodesicEllipseParameters& operator=(const GeodesicEllipseParameters& other);
    GeodesicEllipseParameters& operator=(GeodesicEllipseParameters&& other) noexcept;
    ~GeodesicEllipseParameters();

    AngularUnit angularUnit() const;
    void setAngularUnit(const AngularUnit& angularUnit);
    double axisDirection() const;
    void setAxisDirection(double direction);
    Point center() const;
    void setCenter(const Point& center);
    GeometryType geometryType() const;
    void setGeometryType(GeometryType type);
    LinearUnit linearUnit() const;
    void setLinearUnit(const LinearUnit& linearUnit);
    unsigned int maxPointCount() const;
    void setMaxPointCount(unsigned int count);
    double maxSegmentLength() const;
    void setMaxSegmentLength(double length);
    double semiAxis1Length() const;
    void setSemiAxis1Length(double length);
    double semiAxis2Length() const;
    void setSemiAxis2Length(double length);

    std::shared_ptr<QRTImpl::GeodesicEllipseParametersImpl> getImpl() const;
    /*!
       \internal
    */
    GeodesicEllipseParameters(const std::shared_ptr<QRTImpl::GeodesicEllipseParametersImpl>& impl);

  private:
    std::shared_ptr<QRTImpl::GeodesicEllipseParametersImpl> m_impl;
  };

  /////////////////////////////////////////////
  ///////// GeodesicSectorParameters //////////
  /////////////////////////////////////////////

  class GeodesicSectorParameters
  {
  public:
    GeodesicSectorParameters();
    GeodesicSectorParameters(const Point& center,
                             double semiAxis1Length,
                             double semiAxis2Length,
                             double sectorAngle,
                             double startDirection);
    GeodesicSectorParameters(double axisDirection,
                             const AngularUnit& angularUnit,
                             const Point& center,
                             const LinearUnit& linearUnit,
                             unsigned int maxPointCount,
                             double maxSegmentLength,
                             GeometryType geometryType,
                             double sectorAngle,
                             double semiAxis1Length,
                             double semiAxis2Length,
                             double startDirection);
    GeodesicSectorParameters(const GeodesicSectorParameters& other);
    GeodesicSectorParameters(GeodesicSectorParameters&& other) noexcept;
    GeodesicSectorParameters& operator=(const GeodesicSectorParameters& other);
    GeodesicSectorParameters& operator=(GeodesicSectorParameters&& other) noexcept;
    ~GeodesicSectorParameters();

    AngularUnit angularUnit() const;
    void setAngularUnit(const AngularUnit& angularUnit);
    double axisDirection() const;
    void setAxisDirection(double direction);
    Point center() const;
    void setCenter(const Point& center);
    GeometryType geometryType() const;
    void setGeometryType(GeometryType type);
    LinearUnit linearUnit() const;
    void setLinearUnit(const LinearUnit& linearUnit);
    unsigned int maxPointCount() const;
    void setMaxPointCount(unsigned int count);
    double maxSegmentLength() const;
    void setMaxSegmentLength(double length);
    double sectorAngle() const;
    void setSectorAngle(double angle);
    double semiAxis1Length() const;
    void setSemiAxis1Length(double length);
    double semiAxis2Length() const;
    void setSemiAxis2Length(double length);
    double startDirection() const;
    void setStartDirection(double direction);

    std::shared_ptr<QRTImpl::GeodesicSectorParametersImpl> getImpl() const;
    GeodesicSectorParameters(const std::shared_ptr<QRTImpl::GeodesicSectorParametersImpl>& impl);

  private:
    std::shared_ptr<QRTImpl::GeodesicSectorParametersImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_GeometryEngine_H
