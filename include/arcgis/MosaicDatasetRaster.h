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
/// \file MosaicDatasetRaster.h

#ifndef QRT_MosaicDatasetRaster_H
#define QRT_MosaicDatasetRaster_H

// C++ API headers
#include "AddRastersParameters.h"
#include "Geodatabase.h"
#include "Raster.h"
#include "SpatialReference.h"
#include "TaskWatcher.h"

namespace QRTImpl { class MosaicDatasetRasterImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class MosaicDatasetRaster : public Raster
  {
    Q_OBJECT

  public:
    MosaicDatasetRaster(const QString& path, const QString& tableName, QObject* parent = nullptr);
    ~MosaicDatasetRaster();

    QString tableName() const;

    TaskWatcher addRasters(const AddRastersParameters& parameters);

    static MosaicDatasetRaster* create(const QString& path, const QString& tableName,
                                       const SpatialReference& spatialReference, QObject* parent = nullptr);
    static MosaicDatasetRaster* create(Geodatabase* geodatabase, const QString& tableName,
                                       const SpatialReference& spatialReference, QObject* parent = nullptr);

    static void remove(Geodatabase* geodatabase, const QString& tableName);

    static QStringList tableNames(const QString& path);

    /*!
       \internal
     */
    MosaicDatasetRaster(const std::shared_ptr<QRTImpl::MosaicDatasetRasterImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::MosaicDatasetRasterImpl> getImpl() const;

  signals:
    void addRastersCompleted(QUuid taskId, Esri::ArcGISRuntime::Error error);

  private:
    Q_DISABLE_COPY(MosaicDatasetRaster)

    void connectSignals();
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_MosaicDatasetRaster_H
