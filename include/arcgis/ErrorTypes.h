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
/// \file ErrorTypes.h

#ifndef QRT_ErrorTypes_H
#define QRT_ErrorTypes_H

namespace Esri {
namespace ArcGISRuntime {

  enum class ErrorDomainType
  {
    Unknown = -1,
    ArcGISRuntime = 0,
    ArcGISServer = 1
  };

  enum class ExtendedErrorType
  {
    None = -1,
    NetworkError = 0,
    FileIOError = 1
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ErrorTypes_H
