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
/// \file SceneViewTypes.h

#ifndef QRT_SceneViewTypes_H
#define QRT_SceneViewTypes_H

// Qt headers
#include <QObject>

namespace Esri {
namespace ArcGISRuntime {

  enum class AnalysisType
  {
    Unknown = -1,
    LocationViewshed = 1,
    LocationLineOfSight = 2,
    GeoElementViewshed = 3,
    GeoElementLineOfSight = 4,
    LocationDistanceMeasurement = 5
  };

  enum class AtmosphereEffect
  {
    None = 0,
    HorizonOnly = 1,
    Realistic = 2
  };

  enum class ElevationSourceType
  {
    Unknown = 0,
    ArcGISTiledElevationSource = 1,
    RasterElevationSource = 2
  };

  enum class ExtrusionMode
  {
    None = 0,
    Minimum = 1,
    Maximum = 2,
    AbsoluteHeight = 3,
    BaseHeight = 4
  };

  enum class LightingMode
  {
    NoLight = 0,
    Light = 1,
    LightAndShadows = 2
  };

  enum class SceneLocationVisibility
  {
    Visible = 0,
    HiddenByBaseSurface = 1,
    HiddenByEarth = 2,
    HiddenByElevation = 3,
    NotOnScreen = 4
  };

  enum class SurfacePlacement
  {
    Draped = 0,
    Absolute = 1,
    Relative = 2
  };

  enum class SceneViewTilingScheme
  {
    Geographic = 0,
    WebMercator = 1
  };

  enum class LineOfSightTargetVisibility
  {
    Visible = 0,
    Obstructed = 1,
    Unknown = 2
  };

  enum class CameraControllerType
  {
    Unknown = -1,
    GlobeCameraController = 1,
    OrbitGeoElementCameraController = 2,
    OrbitLocationCameraController = 3
  };

} // namespace ArcGISRuntime
} // namespace Esri

Q_DECLARE_METATYPE(Esri::ArcGISRuntime::ElevationSourceType)
Q_DECLARE_METATYPE(Esri::ArcGISRuntime::AnalysisType)

#endif // QRT_SceneViewTypes_H
