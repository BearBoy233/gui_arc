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
/// \file OfflineMapTypes.h

#ifndef QRT_OfflineMapTypes_H
#define QRT_OfflineMapTypes_H

namespace Esri {
namespace ArcGISRuntime {

  enum class ReturnLayerAttachmentOption
  {
    None = 0,
    AllLayers = 1,
    ReadOnlyLayers = 2,
    EditableLayers = 3
  };

  enum class OfflineMapParametersType
  {
    Unknown = -1,
    GenerateGeodatabase = 0,
    ExportVectorTiles = 1,
    ExportTileCache = 2
  };

  enum class DestinationTableRowFilter
  {
    All = 0,
    RelatedOnly = 1
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_OfflineMapTypes_H
