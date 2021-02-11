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
/// \file OfflineMapSyncJob.h

#ifndef QRT_OfflineMapSyncJob_H
#define QRT_OfflineMapSyncJob_H

// C++ API headers
#include "Job.h"
#include "OfflineMapSyncParameters.h"
#include "OfflineMapSyncResult.h"

namespace QRTImpl {
  class OfflineMapSyncJobImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class OfflineMapSyncJob : public Job
  {
    Q_OBJECT

  public:
    ~OfflineMapSyncJob();

    OfflineMapSyncResult* result() const;

    OfflineMapSyncParameters parameters() const;

    /*!
       \internal
     */
    OfflineMapSyncJob(const std::shared_ptr<QRTImpl::OfflineMapSyncJobImpl>& impl, QObject* parent = nullptr);

  private:
    OfflineMapSyncJob() = delete;

    Q_DISABLE_COPY(OfflineMapSyncJob)
  };
}
}

#endif // QRT_OfflineMapSyncJob_H
