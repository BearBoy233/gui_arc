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
/// \file TaskTypes.h

#ifndef QRT_TaskTypes_H
#define QRT_TaskTypes_H

namespace Esri {
namespace ArcGISRuntime {

  enum class JobType
  {
    Unknown = -1,
    GenerateGeodatabaseJob = 0,
    SyncGeodatabaseJob = 1,
    ExportTileCacheJob = 2,
    EstimateTileCacheSizeJob = 3,
    GeoprocessingJob = 4,
    GenerateOfflineMapJob = 5,
    ExportVectorTilesJob = 6,
    OfflineMapSyncJob = 7,
    DownloadPreplannedOfflineMapJob = 8
  };

  enum class JobMessageSeverity
  {
    Info = 0,
    Warning = 1,
    Error = 2,
    Unknown = -1
  };

  enum class JobMessageSource
  {
    Client = 0,
    Service = 1
  };

  enum class JobStatus
  {
    NotStarted = 0,
    Started = 1,
    Paused = 2,
    Succeeded = 3,
    Failed = 4
  };

  enum class AttachmentSyncDirection
  {
    None = 0,
    Upload = 1,
    Bidirectional = 2
  };

  enum class SyncDirection
  {
    None = 0,
    Download = 1,
    Upload = 2,
    Bidirectional = 3
  };

  enum class SyncModel
  {
    None = 0,
    Geodatabase = 1,
    Layer = 2
  };

  enum class GenerateLayerQueryOption
  {
    Unknown = -1,
    All = 0,
    None = 1,
    UseFilter = 2
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_TaskTypes_H
