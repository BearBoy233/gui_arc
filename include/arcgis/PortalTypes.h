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
/// \file PortalTypes.h

#ifndef QRT_PortalTypes_H
#define QRT_PortalTypes_H

namespace Esri {
namespace ArcGISRuntime {

  /* API doc for these types is maintained in qt-cpp/qdoc/PortalTypes.qdoc */

  enum class PortalAccess
  {
    Unknown = -1,
    Organization = 0,
    Private = 1,
    Public = 2,
    Shared = 3
  };

  enum class PortalFileType
  {
    Unknown = -1,
    CSV,
    Shapefile,
    TilePackage,
    FeatureService,
    FeatureCollection,
    ServiceDefinition
  };

  enum class PortalItemType
  {
    Unknown = -1,
    ArcGISProAddIn = 0,
    ArcPadPackage = 1,
    CADDrawing = 2,
    CSV = 3,
    CityEngineWebScene = 4,
    CodeAttachment = 5,
    CodeSample = 6,
    ColorSet = 7,
    DesktopAddIn = 8,
    DesktopApplication = 9,
    DesktopApplicationTemplate = 10,
    DesktopStyle = 11,
    DocumentLink = 12,
    ExplorerAddIn = 13,
    ExplorerLayer = 14,
    ExplorerMap = 15,
    FeatureCollection = 16,
    FeatureCollectionTemplate = 17,
    FeatureService = 18,
    FileGeodatabase = 19,
    Form = 20,
    GeocodingService = 21,
    GeodataService = 22,
    GeometryService = 23,
    GeoprocessingPackage = 24,
    GeoprocessingPackageProVersion = 25,
    GeoprocessingSample = 26,
    GeoprocessingService = 27,
    GlobeDocument = 28,
    GlobeService = 29,
    Image = 30,
    ImageCollection = 31,
    ImageService = 32,
    InsightsModel = 33,
    InsightsPage = 34,
    InsightsWorkbook = 35,
    IWorkKeynote = 36,
    IWorkNumbers = 37,
    IWorkPages = 38,
    KML = 39,
    KMLCollection = 40,
    Layer = 41,
    LayerPackage = 42,
    Layout = 43,
    LocatorPackage = 44,
    MapDocument = 45,
    MapPackage = 46,
    MapService = 47,
    MapTemplate = 48,
    MicrosoftExcel = 49,
    MicrosoftPowerpoint = 50,
    MicrosoftWord = 51,
    MobileApplication = 52,
    MobileBasemapPackage = 53,
    MobileMapPackage = 54,
    NativeApplication = 55,
    NativeApplicationInstaller = 56,
    NativeApplicationTemplate = 57,
    NetCDF = 58,
    NetworkAnalysisService = 59,
    OperationView = 60,
    OperationsDashboardAddIn = 61,
    OperationsDashboardExtension = 62,
    PDF = 63,
    ProjectPackage = 64,
    ProjectTemplate = 65,
    ProMap = 66,
    PublishedMap = 67,
    RasterFunctionTemplate = 68,
    RelationalDatabaseConnection = 69,
    ReportTemplate = 70,
    RulePackage = 71,
    SceneDocument = 72,
    ScenePackage = 73,
    SceneService = 74,
    ServiceDefinition = 75,
    ShapeFile = 76,
    StatisticalDataCollection = 77,
    SymbolSet = 78,
    TaskFile = 79,
    TilePackage = 80,
    VectorTilePackage = 81,
    VectorTileService = 82,
    VisioDocument = 83,
    Vr360Experience = 84,
    WFS = 85,
    WMS = 86,
    WMTS = 87,
    WebMap = 88,
    WebMappingApplication = 89,
    WebScene = 90,
    WindowsMobilePackage = 91,
    WorkflowManagerPackage = 92,
    WorkflowManagerService = 93,
    WorkforceProject = 94,
    SQLiteGeodatabase = 95,
    MapArea = 96,
    HubInitiative = 97,
    HubSiteApplication = 98,
    HubPage = 99,
    AppBuilderExtension = 100,
    AppBuilderWidgetPackage = 101,
    Dashboard = 102,
    ArcGISProConfiguration = 103
  };

  enum class PortalMode
  {
    Unknown = -1,
    MultiTenant,
    SingleTenant
  };

  enum class PortalPrivilegeRole
  {
    Unknown = -1,
    Administrator,
    Publisher,
    User
  };

  enum class PortalPrivilegeRealm
  {
    Unknown = -1,
    Portal,
    Features,
    OpenData,
    Premium,
    Marketplace
  };

  enum class PortalPrivilegeType
  {
    Unknown = -1,
    Edit,
    FullEdit,
    Manage,
    Purchase,
    StartTrial,
    DesignateGroup,
    OpenDataAdmin,
    AssignToGroups,
    ChangeUserRoles,
    DeleteGroups,
    DeleteItems,
    DeleteUsers,
    DisableUsers,
    InviteUsers,
    ManageEnterpriseGroups,
    ManageLicenses,
    ReassignGroups,
    ReassignItems,
    ReassignUsers,
    UpdateGroups,
    UpdateItems,
    UpdateUsers,
    ViewGroups,
    ViewItems,
    ViewUsers,
    PublishFeatures,
    PublishScenes,
    PublishTiles,
    CreateGroup,
    CreateItem,
    JoinGroup,
    JoinNonOrgGroup,
    ShareGroupToOrg,
    ShareGroupToPublic,
    ShareToGroup,
    ShareToOrg,
    ShareToPublic,
    Demographics,
    Elevation,
    Geocode,
    Geoenrichment,
    NetworkAnalysis,
    SpatialAnalysis,
    CreateUpdateCapableGroup,
    ViewOrgGroups,
    ViewOrgItems,
    ViewOrgUsers,
    Geoanalytics,
    Rasteranalysis,
  };

  enum class PortalReadyState
  {
    Uninitialized,
    Loading,
    Errored,
    Completed,
    Aborting
  };

  enum class PortalGroupSortField
  {
    AverageRating,
    Created,
    Modified,
    Owner,
    Title,
    Unknown,
    ViewCount
  };

  enum class PortalQuerySortOrder
  {
    Ascending,
    Descending
  };

  enum class PortalStatus
  {
    Unknown = -1,
    Partial,
    Processing,
    Failed,
    Completed
  };

  enum class PortalUserRole
  {
    Unknown = -1,
    Publisher,
    Admin,
    User
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_PortalTypes_H

