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
/// \file RasterTypes.h

#ifndef QRT_RasterTypes_H
#define QRT_RasterTypes_H

namespace Esri {
namespace ArcGISRuntime {

  enum class RasterType
  {
    Unknown = -1,
    Raster = 0,
    MosaicDatasetRaster = 1,
    GeopackageRaster = 2,
    GeoPackageRaster = 2,
    ImageServiceRaster = 3
  };

  enum class RasterRendererType
  {
    RasterRenderer = 0, // deprecated since Esri::ArcGISRuntime 100.3
    BlendRenderer = 1,
    ColormapRenderer = 2,
    HillshadeRenderer = 3,
    RgbRenderer = 4,
    StretchRenderer = 5
  };

  enum class StretchParametersType
  {
    Unknown = -1,
    MinMaxStretchParameters = 0,
    StandardDeviationStretchParameters = 1,
    HistogramEqualizationStretchParameters = 2,
    PercentClipStretchParameters = 3
  };

  enum class PresetColorRampType
  {
    None = -1,
    Elevation = 0,
    DemScreen = 1,
    DemLight = 2
  };

  enum class PansharpenType
  {
    None = -1,
    Ihs = 0,
    Brovey = 1,
    Mean = 2,
    Esri = 3,
    GramSchmidt = 4
  };

  enum class SlopeType
  {
    None = -1,
    Degree = 0,
    PercentRise = 1,
    Scaled = 2
  };

  enum class PixelType
  {
    Unknown = -1,
    Uint1 = 0,
    Uint2 = 1,
    Uint4 = 2,
    Uint8 = 3,
    Int8 = 4,
    Uint16 = 5,
    Int16 = 6,
    Uint32 = 7,
    Int32 = 8,
    Float32 = 9,
    Float64 = 10
  };

  enum class AddRastersParametersType
  {
    AddRastersParameters = 0,
    FrameCameraAddRastersParameters = 1
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_RasterTypes_H
