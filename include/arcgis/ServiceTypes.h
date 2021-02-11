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
/// \file ServiceTypes.h

#ifndef QRT_ServiceTypes_H
#define QRT_ServiceTypes_H

// Qt headers
#include <QObject>

namespace Esri {
namespace ArcGISRuntime {

  enum class AntialiasingMode
  {
    None = 0,
    Fastest = 1,
    Fast = 2,
    Normal = 3,
    Best = 4
  };

  enum class DomainType
  {
    Unknown = -1,
    CodedValueDomain = 0,
    InheritedDomain = 1,
    RangeDomain = 2
  };

  enum class DrawingTool
  {
    Unknown = -1,
    AutoCompletePolygon = 0,
    Circle = 1,
    DownArrow = 2,
    Ellipse = 3,
    FreeHand = 4,
    LeftArrow = 5,
    Line = 6,
    None = 7,
    Point = 8,
    Polygon = 9,
    Rectangle = 10,
    RightArrow = 11,
    Text = 12,
    Triangle = 13,
    UpArrow = 14
  };

  enum class FieldType
  {
    Unknown = -1,
    Int16 = 0,
    Int32 = 1,
    GUID = 3,
    Float32 = 4,
    Float64 = 5,
    Date = 6,
    Text = 7,
    OID = 8,
    GlobalID = 9,
    Blob = 10,
    Geometry = 11,
    Raster = 12,
    Xml = 13
  };

  enum class IdInfoType
  {
    IdInfo = 0,
    MapServiceLayerIdInfo = 1,
    Unknown = -1
  };

  enum class TileImageFormat
  {
    PNG = 0,
    PNG8 = 1,
    PNG24 = 2,
    PNG32 = 3,
    JPG = 4,
    MIXED = 5,
    LERC = 6,
    Unknown = -1
  };

  enum class LabelingPlacement
  {
    Unknown = -1,
    LineAboveAfter = 0,
    LineAboveAlong = 1,
    LineAboveBefore = 2,
    LineAboveEnd = 3,
    LineAboveStart = 4,
    LineBelowAfter = 5,
    LineBelowAlong = 6,
    LineBelowBefore = 7,
    LineBelowEnd = 8,
    LineBelowStart = 9,
    LineCenterAfter = 10,
    LineCenterAlong = 11,
    LineCenterBefore = 12,
    LineCenterEnd = 13,
    LineCenterStart = 14,
    PointAboveCenter = 15,
    PointAboveLeft = 16,
    PointAboveRight = 17,
    PointBelowCenter = 18,
    PointBelowLeft = 19,
    PointBelowRight = 20,
    PointCenterCenter = 21,
    PointCenterLeft = 22,
    PointCenterRight = 23,
    PolygonAlwaysHorizontal = 24
  };

  enum class RelationshipCardinality
  {
    Unknown = -1,
    ManyToMany = 0,
    OneToMany = 1,
    OneToOne = 2
  };

  enum class RelationshipRole
  {
    Unknown = -1,
    Destination = 0,
    Origin = 1
  };

  enum class ServiceType
  {
    Unknown = -1,
    FeatureService = 0,
    ImageService = 1,
    MapService = 2
  };

  enum class TextAntialiasingMode
  {
    None = 0,
    Normal = 1,
    Force = 2
  };

  enum class TimeRelation
  {
    Unknown = -1,
    Overlaps = 0,
    AfterStartOverlapsEnd = 1,
    OverlapsStartWithinEnd = 2
  };

  enum class TimeUnit
  {
    Unknown = -1,
    Centuries = 0,
    Days = 1,
    Decades = 2,
    Hours = 3,
    Milliseconds = 4,
    Minutes = 5,
    Months = 6,
    Seconds = 7,
    Weeks = 8,
    Years = 9
  };

} // namespace ArcGISRuntime
} // namespace Esri

Q_DECLARE_METATYPE(Esri::ArcGISRuntime::FieldType)

#endif // QRT_ServiceTypes_H
