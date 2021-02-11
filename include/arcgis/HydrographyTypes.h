// COPYRIGHT 1995-2017 ESRI
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
/// \file HydrographyTypes.h

#ifndef QRT_HydrographyTypes_H
#define QRT_HydrographyTypes_H

namespace Esri {
namespace ArcGISRuntime {

  enum class EncAreaSymbolizationType
  {
    Plain = 4,
    Symbolized = 5
  };

  enum class EncColorScheme
  {
    Day = 1,
    Dusk = 2,
    Night = 3
  };

  enum class EncDisplayDepthUnits
  {
    Meters = 1,
    Feet = 2,
    Fathoms = 3
  };

  enum class EncPointSymbolizationType
  {
    Simplified = 2,
    PaperChart = 1
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_HydrographyTypes_H
