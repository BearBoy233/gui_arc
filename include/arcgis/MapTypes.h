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
/// \file MapTypes.h

#ifndef QRT_MapTypes_H
#define QRT_MapTypes_H

namespace Esri {
namespace ArcGISRuntime {

  enum class ArcGISFeatureLayerInfoServiceType
  {
    Layer = 0,
    Table = 1,
    GroupLayer = 2,
    Unknown = -1
  };

  enum class ArcGISMapServiceSublayerType
  {
    FeatureLayer = 0,
    Table = 1,
    GroupLayer = 2,
    RasterLayer = 3,
    NetworkAnalysisLayer = 4,
    Unknown = -1
  };

  enum class ArcGISSublayerType
  {
    ArcGISMapImageSublayer = 0,
    ArcGISTiledSublayer = 1,
    Unknown = -1
  };

  enum class BasemapType
  {
    Imagery = 0,
    ImageryWithLabels = 1,
    Streets = 2,
    Topographic = 3,
    TerrainWithLabels = 4,
    LightGrayCanvas = 5,
    NationalGeographic = 6,
    Oceans = 7,
    OpenStreetMap = 8,
    ImageryWithLabelsVector = 9,
    StreetsVector = 10,
    TopographicVector = 11,
    TerrainWithLabelsVector = 12,
    LightGrayCanvasVector = 13,
    NavigationVector = 14,
    StreetsNightVector = 15,
    StreetsWithReliefVector = 16,
    DarkGrayCanvasVector = 17
  };

  enum class FeatureRenderingMode
  {
    Automatic = 0,
    Static = 1,
    Dynamic = 2
  };

  enum class GraphicsRenderingMode
  {
    Dynamic = 0,
    Static = 1
  };

  enum class JoinType
  {
    InnerJoin = 0,
    LeftOuterJoin = 1,
    Unknown = -1
  };

  enum class MapServiceImageFormat
  {
    Default = 0,
    PNG = 1,
    PNG8 = 2,
    PNG24 = 3,
    PNG32 = 4,
    JPG = 5,
    JPGPNG = 6,
    BMP = 7,
    GIF = 8,
    TIFF = 9,
    Unknown = -1
  };

  enum class LayerType
  {
    ImageTiledLayer = 1,
    ServiceImageTiledLayer = 2,
    ArcGISMapImageLayer = 3,
    ArcGISTiledLayer = 4,
    FeatureCollectionLayer = 5,
    FeatureLayer = 6,
    KMLLayer = 7,
    BingMapLayer = 8, // obsolete, use BingMapsLayer
    RasterLayer = 9,
    UnsupportedLayer = 10,
    MobileBasemapLayer = 11,
    ArcGISVectorTiledLayer = 12,
    ArcGISSceneLayer = 13,
    WmtsLayer = 14,
    OpenStreetMapLayer = 15,
    WebTiledLayer = 16,
    BingMapsLayer = 17,
    EncLayer = 18,
    WmsLayer = 19,
    UnknownLayer = -1
  };

  enum class LoadStatus
  {
    Loaded = 0,
    Loading = 1,
    FailedToLoad = 2,
    NotLoaded = 3,
    Unknown = -1
  };

  enum class SelectionMode
  {
    Add = 0,
    New = 1,
    Subtract = 2
  };

  enum class SublayerSourceType
  {
    MapSublayerSource = 0,
    TableQuerySublayerSource = 1,
    TableJoinSublayerSource = 2,
    TableSublayerSource = 3,
    RasterSublayerSource = 4,
    Unknown = -1
  };

  enum class ViewpointType
  {
    CenterAndScale = 0,
    BoundingGeometry = 1,
    Unknown = -1
  };

  enum class NoDataTileBehavior
  {
    UpSample = 0,
    Blank = 1,
    Show = 2,
    Unknown = -1
  };

  enum class BingMapsLayerStyle
  {
    Unknown = -1,
    Aerial = 0,
    Hybrid = 1,
    Road = 2
  };

  enum class CacheStorageFormat
  {
    Unknown = -1,
    Compact = 0,
    CompactV2 = 1,
    Exploded = 2
  };

  enum class WmsVersion
  {
    V110 = 110,
    V111 = 111,
    V130 = 130
  };

  enum class KmlAltitudeMode
  {
    ClampToGround = 0,
    RelativeToGround = 1,
    Absolute = 2,
    Unknown = -1
  };

  enum class KmlDatasetEventType
  {
    AutoBalloonPopup = 0,
    HideBalloonPopup = 1,
    BeginNodeAutoRefresh = 2,
    NodeAutoRefreshed = 3,
    Unknown = -1
  };

  enum class KmlGeometryType
  {
    Point = 0,
    Polyline = 1,
    Polygon = 2,
    Model = 3,
    Unknown = -1
  };

  enum class KmlGraphicType
  {
    None = 0,
    Point = 1,
    Polyline = 2,
    Polygon = 3,
    ExtrudedPoint = 4,
    ExtrudedPolyline = 5,
    ExtrudedPolygon = 6,
    Model = 7,
    MultiGeometry = 8,
    Unknown = -1
  };

  enum class KmlListItemType
  {
    Check = 0,
    RadioFolder = 1,
    CheckHideChildren = 2,
    Unknown = -1
  };

  enum class KmlNodeType
  {
    KmlDocument = 0,
    KmlFolder = 1,
    KmlNetworkLink = 2,
    KmlPlacemark = 3,
    KmlPhotoOverlay = 4,
    KmlGroundOverlay = 5,
    KmlScreenOverlay = 6,
    KmlTour = 7,
    Unknown = -1
  };

  enum class KmlViewpointType
  {
    Camera = 0,
    LookAt = 1,
    Unknown = -1
  };

  enum class KmlRefreshStatus
  {
    None = 0,
    InProgress = 1,
    Completed = 2,
    Failed = 3
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_MapTypes_H
