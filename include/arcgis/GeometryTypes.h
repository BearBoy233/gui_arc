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
/// \file GeometryTypes.h

#ifndef QRT_GeometryTypes_H
#define QRT_GeometryTypes_H

// Qt headers
#include <QObject>

namespace Esri {
namespace ArcGISRuntime {

  enum class GeometryType
  {
    Unknown = -1,
    Point = 1,
    Envelope = 2,
    Polyline = 3,
    Polygon = 4,
    Multipoint = 5
  };

  enum class GeometryBuilderType
  {
    PointBuilder = 1,
    EnvelopeBuilder = 2,
    PolylineBuilder = 3,
    PolygonBuilder = 4,
    MultipointBuilder = 5,
    Unknown = -1
  };

  enum class AngularUnitId
  {
    Other   = 0,
    Degrees = 9102,
    Grads   = 9105,
    Minutes = 9103,
    Radians = 9101,
    Seconds = 9104
  };

  enum class AreaUnitId
  {
    Other             = 0,
    Acres             = 109402,
    Hectares          = 109401,
    SquareCentimeters = 109451,
    SquareDecimeters  = 109450,
    SquareFeet        = 109405,
    SquareKilometers  = 109414,
    SquareMeters      = 109404,
    SquareMillimeters = 109452,
    SquareMiles       = 109439,
    SquareYards       = 109442
  };

  enum class LinearUnitId
  {
    Other         = 0,
    Centimeters   = 1033,
    Feet          = 9002,
    Inches        = 109008,
    Kilometers    = 9036,
    Meters        = 9001,
    Miles         = 9093,
    Millimeters   = 1025,
    NauticalMiles = 9030,
    Yards         = 9096
  };

  enum class UnitType
  {
    LinearUnit  = 0,
    AngularUnit = 1,
    AreaUnit    = 2,
    Unknown     = -1
  };

  enum class SegmentType
  {
    LineSegment = 1,
    Unknown = -1
  };

  enum class GeodeticCurveType
  {
    Geodesic = 0,
    Loxodrome = 1,
    GreatElliptic = 2,
    NormalSection = 3,
    ShapePreserving = 4
  };

  enum class GeometryOffsetType
  {
    Mitered = 0,
    Bevelled = 1,
    Rounded = 2,
    Squared = 3
  };

  enum class GeometryExtendOptions
  {
    Default = 0,
    RelocateEnds = 1,
    KeepEndAttributes = 2,
    NoEndAttributes = 4,
    DoNotExtendFromStartPoint = 8,
    DoNotExtendFromEndPoint = 16
  };

  enum class GarsConversionMode
  {
    LowerLeft = 0,
    Center = 1
  };

  enum class MgrsConversionMode
  {
    Automatic = 0,
    New180InZone01 = 1,
    New180InZone60 = 2,
    Old180InZone01 = 3,
    Old180InZone60 = 4
  };

  enum class UtmConversionMode
  {
    LatitudeBandIndicators = 0,
    NorthSouthIndicators = 1
  };

  enum class LatitudeLongitudeFormat
  {
    DecimalDegrees = 0,
    DegreesDecimalMinutes = 1,
    DegreesMinutesSeconds = 2
  };

  enum class DatumTransformationType
  {
    GeographicTransformation = 1
  };

} // namespace ArcGISRuntime
} // namespace Esri

Q_DECLARE_METATYPE(Esri::ArcGISRuntime::AngularUnitId)
Q_DECLARE_METATYPE(Esri::ArcGISRuntime::AreaUnitId)
Q_DECLARE_METATYPE(Esri::ArcGISRuntime::GeometryType)
Q_DECLARE_METATYPE(Esri::ArcGISRuntime::GeometryBuilderType)
Q_DECLARE_METATYPE(Esri::ArcGISRuntime::LinearUnitId)
Q_DECLARE_METATYPE(Esri::ArcGISRuntime::UnitType)
Q_DECLARE_METATYPE(Esri::ArcGISRuntime::SegmentType)
Q_DECLARE_METATYPE(Esri::ArcGISRuntime::GeodeticCurveType)
Q_DECLARE_METATYPE(Esri::ArcGISRuntime::DatumTransformationType)

#endif // QRT_GeometryTypes_H
