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
/// \file NetworkAnalystTypes.h

#ifndef QRT_NetworkAnalystTypes_H
#define QRT_NetworkAnalystTypes_H

// Qt headers
#include <QObject>

namespace Esri {
namespace ArcGISRuntime {

  enum class AttributeUnit
  {
    Unknown = 0,
    Inches = 1,
    Feet = 2,
    Yards = 3,
    Miles = 4,
    Millimeters = 5,
    Centimeters = 6,
    Decimeters = 7,
    Meters = 8,
    Kilometers = 9,
    NauticalMiles = 10,
    DecimalDegrees = 11,
    Seconds = 12,
    Minutes = 13,
    Hours = 14,
    Days = 15,
  };

  enum class BarrierType
  {
    Restriction = 0,
    CostAdjustment = 1
  };

  enum class CurbApproach
  {
    EitherSide = 0,
    LeftSide = 1,
    RightSide = 2,
    NoUturn = 3,
    Unknown = 4
  };

  enum class DirectionManeuverType
  {
    Unknown = 0,
    Stop = 1,
    Straight = 2,
    BearLeft = 3,
    BearRight = 4,
    TurnLeft = 5,
    TurnRight = 6,
    SharpLeft = 7,
    SharpRight = 8,
    UTurn = 9,
    Ferry = 10,
    Roundabout = 11,
    HighwayMerge = 12,
    HighwayExit = 13,
    HighwayChange = 14,
    ForkCenter = 15,
    ForkLeft = 16,
    ForkRight = 17,
    Depart = 18,
    TripItem = 19,
    EndOfFerry = 20,
    RampRight = 21,
    RampLeft = 22,
    TurnLeftRight = 23,
    TurnRightLeft = 24,
    TurnRightRight = 25,
    TurnLeftLeft = 26,
    PedestrianRamp = 27,
    Elevator = 28,
    Escalator = 29,
    Stairs = 30,
    DoorPassage = 31
  };

  enum class DirectionMessageType
  {
    Length = 0,
    Time = 1,
    Summary = 2,
    TimeWindow = 3,
    ViolationTime = 4,
    WaitTime = 5,
    ServiceTime = 6,
    EstimatedArrivalTime = 7,
    CumulativeLength = 8,
    StreetName = 9,
    AlternativeName = 10,
    Branch = 11,
    Toward = 12,
    CrossStreet = 13,
    Exit = 14
  };

  enum class DirectionsStyle
  {
    Desktop = 0,
    Navigation = 1,
    Campus = 2
  };

  enum class LocationStatus
  {
    NotLocated = 0,
    OnClosest = 1,
    OnClosestNotRestricted = 2,
    NotReached = 3
  };

  enum class RouteShapeType
  {
    None = 0,
    StraightLine = 1,
    TrueShapeWithMeasures = 2
  };

  enum class UTurnPolicy
  {
    NotAllowed = 0,
    AllowedAtDeadEnds = 1,
    AllowedAtIntersections = 2,
    AllowedAtDeadEndsAndIntersections = 3
  };

  enum class StartTimeUsage
  {
    DepartureTime = 0,
    ArrivalTime = 1
  };

  enum class TravelDirection
  {
    FromFacility = 0,
    ToFacility = 1
  };

  enum class StopType
  {
    Stop = 0,
    Waypoint = 1,
    RestBreak = 2,
  };

  enum class ServiceAreaPolygonDetail
  {
    Generalized = 0,
    Standard = 1,
    High = 2,
  };

  enum class ServiceAreaOverlapGeometry
  {
    Overlap = 0,
    Dissolve = 1,
    Split = 2,
  };

  enum class ServiceAreaPolygonCutoffGeometry
  {
    Rings = 0,
    Disks = 1,
  };

} // namespace ArcGISRuntime
} // namespace Esri

Q_DECLARE_METATYPE(Esri::ArcGISRuntime::DirectionManeuverType)

#endif // QRT_NetworkAnalystTypes_H
