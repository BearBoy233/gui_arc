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
/// \file LocalServerTypes.h

#ifndef QRT_LocalServerTypes_H
#define QRT_LocalServerTypes_H

namespace Esri {
namespace ArcGISRuntime {

enum class LocalServerStatus
{
  Stopped = 0,
  Starting = 1,
  Started = 2,
  Stopping = 3,
  Failed = 4
};

enum class GeoprocessingServiceType
{
  SynchronousExecute = 0,
  AsynchronousSubmit = 1,
  AsynchronousSubmitWithMapServerResult = 2
};

enum class DynamicWorkspaceType
{
  Raster = 0,
  Shapefile = 1,
  EnterpriseGeodatabase = 2,
  FileGeodatabase = 3
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_LocalServerTypes_H
