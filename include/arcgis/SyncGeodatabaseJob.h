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
/// \file SyncGeodatabaseJob.h

#ifndef QRT_SyncGeodatabaseJob_H
#define QRT_SyncGeodatabaseJob_H

// C++ API headers
#include "Job.h"
#include "SyncLayerResult.h"

namespace Esri {
namespace ArcGISRuntime {

  class SyncGeodatabaseJob : public Job
  {
    Q_OBJECT

  public:
    ~SyncGeodatabaseJob();

    QList<SyncLayerResult*> result() const;

    /*!
       \internal
     */
    SyncGeodatabaseJob(const std::shared_ptr<QRTImpl::JobImpl>& impl, QObject* parent = nullptr);

  private:
    SyncGeodatabaseJob() = delete;

    Q_DISABLE_COPY(SyncGeodatabaseJob)
  };
}
}
#endif // QRT_SyncGeodatabaseJob_H
