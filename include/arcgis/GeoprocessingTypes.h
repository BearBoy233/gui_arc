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
/// \file GeoprocessingTypes.h

#ifndef QRT_GeoprocessingTypes_H
#define QRT_GeoprocessingTypes_H

namespace Esri {
namespace ArcGISRuntime {

  enum class GeoprocessingExecutionType
  {
    Unknown = -1,
    AsynchronousSubmit = 0,
    SynchronousExecute = 1
  };

  enum class GeoprocessingLinearUnits
  {
    Unknown = -1,
    Centimeter = 0,
    Decimeter = 1,
    Kilometer = 2,
    Meter = 3,
    Millimeter = 4,
    Point = 5,
    USNauticalMile = 6,
    USSurveyFoot = 7,
    USSurveyInch = 8,
    USSurveyMile = 9,
    USSurveyYard = 10
  };

  enum class GeoprocessingParameterDirection
  {
    Input = 0,
    Output = 1
  };

  enum class GeoprocessingParameterType
  {
    GeoprocessingBoolean = 0,
    GeoprocessingDataFile = 1,
    GeoprocessingDate = 2,
    GeoprocessingDouble = 3,
    GeoprocessingFeatures = 4,
    GeoprocessingLinearUnit = 5,
    GeoprocessingLong = 6,
    GeoprocessingMultiValue = 7,
    GeoprocessingRaster = 8,
    GeoprocessingString = 9,
    GeoprocessingUnknownParameter = 10
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_GeoprocessingTypes_H
