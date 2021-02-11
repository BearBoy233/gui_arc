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
/// \file ExportTileCacheParameters.h

#ifndef QRT_ExportTileCacheParameters_H
#define QRT_ExportTileCacheParameters_H

// C++ API headers
#include "Geometry.h"

namespace QRTImpl {
  class ExportTileCacheParametersImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class ExportTileCacheParameters
  {

  public:
    ExportTileCacheParameters();
    ExportTileCacheParameters(const ExportTileCacheParameters& other);
    ExportTileCacheParameters(ExportTileCacheParameters&& other) noexcept;
    ~ExportTileCacheParameters();

    ExportTileCacheParameters& operator=(const ExportTileCacheParameters& other);
    ExportTileCacheParameters& operator=(ExportTileCacheParameters&& other) noexcept;

    bool isEmpty() const;

    Geometry areaOfInterest() const;
    void setAreaOfInterest(const Geometry& areaOfInterest);

    double compressionQuality() const;
    void setCompressionQuality(double compressionQuality);

    QList<int> levelIds() const;
    void setLevelIds(const QList<int>& levelIds);

    /*!
       \internal
     */
    explicit ExportTileCacheParameters(const std::shared_ptr<QRTImpl::ExportTileCacheParametersImpl>& impl);
    std::shared_ptr<QRTImpl::ExportTileCacheParametersImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::ExportTileCacheParametersImpl> m_impl;
  };
}
}
#endif // QRT_ExportTileCacheParameters_H
