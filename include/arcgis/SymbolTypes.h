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
/// \file SymbolTypes.h

#ifndef QRT_SymbolTypes_H
#define QRT_SymbolTypes_H

namespace Esri {
namespace ArcGISRuntime {

enum class FontDecoration
{
  LineThrough = 0,
  None = 1,
  Underline = 2
};

enum class FontStyle
{
  Italic = 0,
  Normal = 1,
  Oblique = 2
};

enum class FontWeight
{
  Bold = 0,
  Normal = 1
};

enum class HorizontalAlignment
{
  Center = 0,
  Justify = 1,
  Left = 2,
  Right = 3
};

enum class RendererNormalizationType
{
  ByField = 0,
  ByLog = 1,
  ByPercentOfTotal = 2,
  None = 3
};

enum class RendererClassificationMethod
{
  DefinedInterval = 0,
  EqualInterval = 1,
  GeometricalInterval = 2,
  NaturalBreaks = 3,
  Quantile = 4,
  StandardDeviation = 5,
  Manual = 6
};

enum class RendererType
{
  ClassBreaksRenderer = 0,
  DictionaryRenderer = 1,
  SimpleRenderer = 2,
  UniqueValueRenderer = 3,
  UnsupportedRenderer = 4,
  HeatmapRenderer = 5,
  Unknown = -1
};

enum class RotationType
{
  Arithmetic = 0,
  Geographic = 1
};

enum class SceneSymbolAnchorPosition
{
  Top = 0,
  Bottom = 1,
  Center = 2,
  Origin = 3
};

enum class SimpleFillSymbolStyle
{
  BackwardDiagonal = 0,
  Cross = 1,
  DiagonalCross = 2,
  ForwardDiagonal = 3,
  Horizontal = 4,
  Null = 5,
  Solid = 6,
  Vertical = 7
};

enum class SimpleLineSymbolStyle
{
  Dash = 0,
  DashDot = 1,
  DashDotDot = 2,
  Dot = 3,
  Null = 4,
  Solid = 5
};

enum class SimpleMarkerSymbolStyle
{
  Circle = 0,
  Cross = 1,
  Diamond = 2,
  Square = 3,
  Triangle = 4,
  X = 5
};

enum class SimpleMarkerSceneSymbolStyle
{
  Cone = 0,
  Cube = 1,
  Cylinder = 2,
  Diamond = 3,
  Sphere = 4,
  Tetrahedron = 5
};

enum class SymbolAngleAlignment
{
  Map = 0,
  Screen = 1
};

enum class SymbolType
{
  SimpleFillSymbol = 0,
  SimpleLineSymbol = 1,
  SimpleMarkerSymbol = 2,
  PictureMarkerSymbol = 3,
  TextSymbol = 4,
  SimpleMarkerSceneSymbol = 5,
  ModelSceneSymbol = 6,
  DistanceCompositeSceneSymbol = 7,
  UnsupportedSymbol = 8,
  CompositeSymbol = 9,
  PictureFillSymbol = 10,
  MultilayerPointSymbol = 11,
  MultilayerPolylineSymbol = 12,
  MultilayerPolygonSymbol = 13,
  Unknown = -1
};

enum class VerticalAlignment
{
  Baseline = 0,
  Bottom = 1,
  Middle = 2,
  Top = 3
};

enum class SymbolStyleType
{
  DictionarySymbolStyle = 0,
  SymbolStyle = 1,
  Unknown = -1
};

enum class SimpleLineSymbolMarkerStyle
{
  None = 0,
  Arrow = 1
};

enum class SimpleLineSymbolMarkerPlacement
{
  Begin = 0,
  End = 1,
  BeginAndEnd = 2
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_SymbolTypes_H
