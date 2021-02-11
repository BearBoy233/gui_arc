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
/// \file GeoPackageRaster.h

#ifndef QRT_GeoPackageRaster_H
#define QRT_GeoPackageRaster_H

// C++ API headers
#include "Raster.h"

namespace QRTImpl { class GeoPackageRasterImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class GeoPackage;

  class GeoPackageRaster : public Raster
  {
    Q_OBJECT

  public:
    ~GeoPackageRaster();

    QString description() const;

    GeoPackage* geoPackage() const;

    /*! \internal */
    explicit GeoPackageRaster(const std::shared_ptr<QRTImpl::GeoPackageRasterImpl>& impl, QObject* parent = nullptr);

  private:
    GeoPackageRaster() = delete;
    Q_DISABLE_COPY(GeoPackageRaster)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_GeoPackageRaster_H
