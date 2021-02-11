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
/// \file ExportVectorTilesParameters.h

#ifndef QRT_ExportVectorTilesParameters_H
#define QRT_ExportVectorTilesParameters_H

// C++ API headers
#include "Geometry.h"
#include "Object.h"

namespace QRTImpl { class ExportVectorTilesParametersImpl; }

namespace Esri {
namespace ArcGISRuntime {

class ExportVectorTilesParameters
{

public:
  ExportVectorTilesParameters();
  ExportVectorTilesParameters(const Geometry& areaOfInterest);
  ExportVectorTilesParameters(const ExportVectorTilesParameters& other);
  ExportVectorTilesParameters(ExportVectorTilesParameters&& other) noexcept;
  ~ExportVectorTilesParameters();

  ExportVectorTilesParameters& operator=(const ExportVectorTilesParameters& other);
  ExportVectorTilesParameters& operator=(ExportVectorTilesParameters&& other) noexcept;

  Geometry areaOfInterest() const;
  void setAreaOfInterest(const Geometry& areaOfInterest);

  int maxLevel() const;
  void setMaxLevel(int maxLevel);

  /*!
     \internal
   */
  explicit ExportVectorTilesParameters(const std::shared_ptr<QRTImpl::ExportVectorTilesParametersImpl>& impl);
  std::shared_ptr<QRTImpl::ExportVectorTilesParametersImpl> getImpl() const;

private:
  std::shared_ptr<QRTImpl::ExportVectorTilesParametersImpl> m_impl;
};

} // ArcGISRuntime
} // Esri

#endif // QRT_ExportVectorTilesParameters_H
