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
/// \file GeoprocessingJob.h

#ifndef QRT_GeoprocessingJob_H
#define QRT_GeoprocessingJob_H

// C++ API headers
#include "GeoprocessingParameters.h"
#include "GeoprocessingResult.h"
#include "Job.h"

namespace QRTImpl { class GeoprocessingJobImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class GeoprocessingJob : public Job
  {
    Q_OBJECT

  public:
    ~GeoprocessingJob();

    GeoprocessingResult* result() const;

    GeoprocessingParameters parameters() const;

    /*! \internal */
    GeoprocessingJob(const std::shared_ptr<QRTImpl::GeoprocessingJobImpl>& impl, QObject* parent = nullptr);

  private:
    GeoprocessingJob() = delete;
    Q_DISABLE_COPY(GeoprocessingJob)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_GeoprocessingJob_H
