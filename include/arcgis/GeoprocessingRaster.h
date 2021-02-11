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
/// \file GeoprocessingRaster.h

#ifndef QRT_GeoprocessingRaster_H
#define QRT_GeoprocessingRaster_H

// C++ API headers
#include "GeoprocessingDataFile.h"

namespace QRTImpl { class GeoprocessingRasterImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class GeoprocessingRaster : public GeoprocessingDataFile
  {
    Q_OBJECT

  public:
    explicit GeoprocessingRaster(QObject* parent = nullptr);
    GeoprocessingRaster(const QUrl& url, const QString& format, QObject* parent = nullptr);
    ~GeoprocessingRaster();

    QString format() const;
    void setFormat(const QString& format);

    /*! \internal */
    GeoprocessingRaster(const std::shared_ptr<QRTImpl::GeoprocessingRasterImpl>& impl, QObject* parent = nullptr);

  private:
    Q_DISABLE_COPY(GeoprocessingRaster)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_GeoprocessingRaster_H

