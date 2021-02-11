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
/// \file MapViewTypes.h

#ifndef QRT_MapViewTypes_H
#define QRT_MapViewTypes_H

// Qt headers
#include <QFlags>

namespace Esri {
namespace ArcGISRuntime {

  enum class AnimationCurve
  {
    Linear = 0,
    EaseInQuad = 1,
    EaseOutQuad = 2,
    EaseInOutQuad = 3,
    EaseInCubic = 4,
    EaseOutCubic = 5,
    EaseInOutCubic = 6,
    EaseInQuart = 7,
    EaseOutQuart = 8,
    EaseInOutQuart = 9,
    EaseInQuint = 10,
    EaseOutQuint = 11,
    EaseInOutQuint = 12,
    EaseInSine = 13,
    EaseOutSine = 14,
    EaseInOutSine = 15,
    EaseInExpo = 16,
    EaseOutExpo = 17,
    EaseInOutExpo = 18,
    EaseInCirc = 19,
    EaseOutCirc = 20,
    EaseInOutCirc = 21
  };

  enum class DrawStatus
  {
    InProgress = 0,
    Completed = 1
  };

  enum class GeoViewType
  {
    MapView = 0,
    SceneView = 1,
    Unknown = -1
  };

  enum class LayerViewStatus
  {
    Active = 1,
    NotVisible = 2,
    OutOfScale = 4,
    Loading = 8,
    Error = 16
  };

  Q_DECLARE_FLAGS(LayerViewStatusFlags, LayerViewStatus)

  enum class LocationDisplayAutoPanMode
  {
    Off = 0,
    Recenter = 1,
    Navigation = 2,
    CompassNavigation = 3
  };

  enum class WrapAroundMode
  {
    EnabledWhenSupported = 0,
    Disabled = 1
  };

  enum class GridLabelPosition
  {
    Geographic = 0,
    BottomLeft = 1,
    BottomRight = 2,
    TopLeft = 3,
    TopRight = 4,
    Center = 5,
    AllSides = 6
  };

  enum class GridType
  {
    Unknown = -1,
    LatitudeLongitudeGrid = 0,
    UTMGrid = 1,
    MGRSGrid = 2,
    USNGGrid = 3
  };

  enum class LatitudeLongitudeGridLabelFormat
  {
    DecimalDegrees = 0,
    DegreesMinutesSeconds = 1
  };

  enum class MGRSGridLabelUnit
  {
    KilometersMeters = 0,
    Meters = 1
  };

  enum class USNGGridLabelUnit
  {
    KilometersMeters = 0,
    Meters = 1
  };

} // namespace ArcGISRuntime
} // namespace Esri

Q_DECLARE_OPERATORS_FOR_FLAGS(Esri::ArcGISRuntime::LayerViewStatusFlags)

#endif // QRT_MapViewTypes_H
