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
/// \file GeodatabaseTypes.h

#ifndef QRT_GeodatabaseTypes_H
#define QRT_GeodatabaseTypes_H

namespace Esri {
namespace ArcGISRuntime {

enum class EditOperation
{
  Unknown = -1,
  Add = 0,
  Update = 1,
  Delete = 2
};

enum class EditResultType
{
  Unknown = -1,
  FeatureEditResult = 0,
  EditResult = 1
};

enum class FeatureObjectType
{
  Unknown = -1,
  ArcGISFeature = 0,
  Feature = 1
};

enum class FeatureRequestMode
{
  Undefined = 0,
  OnInteractionCache = 1,
  OnInteractionNoCache = 2,
  ManualCache = 3
};

enum class FeatureTableType
{
  Unknown = -1,
  FeatureTable = 0,
  ServiceFeatureTable = 1,
  GeodatabaseFeatureTable = 2,
  FeatureCollectionTable = 3,
  ShapefileFeatureTable = 4,
  GeoPackageFeatureTable = 5
};

enum class GeodatabaseDatasetType
{
  Unknown = -1,
  TransportationNetworkDataset = 0
};

enum class QueryFeatureFields
{
  IdsOnly = 0,
  Minimum = 1,
  LoadAll = 2
};

enum class RelationshipConstraintViolationType
{
    None = 0,
    Cardinality = 1,
    Orphaned = 2
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_GeodatabaseTypes_H
