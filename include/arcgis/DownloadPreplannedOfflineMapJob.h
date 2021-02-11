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
/// \file DownloadPreplannedOfflineMapJob.h

#ifndef QRT_DownloadPreplannedOfflineMapJob_H
#define QRT_DownloadPreplannedOfflineMapJob_H

// C++ API headers
#include "DownloadPreplannedOfflineMapParameters.h"
#include "DownloadPreplannedOfflineMapResult.h"
#include "Job.h"
#include "Map.h"
#include "PreplannedMapArea.h"

namespace QRTImpl {
  class DownloadPreplannedOfflineMapJobImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class DownloadPreplannedOfflineMapJob : public Job
  {
    Q_OBJECT

  public:
    ~DownloadPreplannedOfflineMapJob();

    DownloadPreplannedOfflineMapParameters parameters() const;

    DownloadPreplannedOfflineMapResult* result() const;

    QString downloadDirectoryPath() const;

    Map* onlineMap() const;

    PreplannedMapArea* preplannedMapArea() const;

    bool excludeBasemap() const;

    /*!
       \internal
     */
    explicit DownloadPreplannedOfflineMapJob(const std::shared_ptr<QRTImpl::DownloadPreplannedOfflineMapJobImpl>& impl, QObject* parent = nullptr);

  private:
    DownloadPreplannedOfflineMapJob() = delete;

    Q_DISABLE_COPY(DownloadPreplannedOfflineMapJob)
  };
}
}

#endif // QRT_DownloadPreplannedOfflineMapJob_H
