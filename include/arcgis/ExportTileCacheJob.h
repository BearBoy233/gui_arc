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
/// \file ExportTileCacheJob.h

#ifndef QRT_ExportTileCacheJob_H
#define QRT_ExportTileCacheJob_H

// C++ API headers
#include "Job.h"
#include "TileCache.h"

namespace QRTImpl {
  class ExportTileCacheJobImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class ExportTileCacheJob : public Job
  {
    Q_OBJECT

  public:
    ~ExportTileCacheJob();

    TileCache* result() const;

    /*!
       \internal
     */
    ExportTileCacheJob(const std::shared_ptr<QRTImpl::ExportTileCacheJobImpl>& impl, QObject* parent = nullptr);

  private:
    ExportTileCacheJob() = delete;

    Q_DISABLE_COPY(ExportTileCacheJob)
  };
}
}
#endif // QRT_ExportTileCacheJob_H
