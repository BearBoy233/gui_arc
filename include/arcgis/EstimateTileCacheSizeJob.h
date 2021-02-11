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
/// \file EstimateTileCacheSizeJob.h

#ifndef QRT_EstimateTileCacheSizeJob_H
#define QRT_EstimateTileCacheSizeJob_H

// C++ API headers
#include "EstimateTileCacheSizeResult.h"
#include "Job.h"

namespace QRTImpl {
  class EstimateTileCacheSizeJobImpl;
  class JobImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class EstimateTileCacheSizeJob: public Job
  {
    Q_OBJECT

  public:
    ~EstimateTileCacheSizeJob();

    EstimateTileCacheSizeResult* result() const;

    /*!
       \internal
     */
    EstimateTileCacheSizeJob(const std::shared_ptr<QRTImpl::EstimateTileCacheSizeJobImpl>& impl, QObject* parent = nullptr);

  private:
    EstimateTileCacheSizeJob() = delete;

    Q_DISABLE_COPY(EstimateTileCacheSizeJob)

  };
}
}
#endif // QRT_EstimateTileCacheSizeJob_H
