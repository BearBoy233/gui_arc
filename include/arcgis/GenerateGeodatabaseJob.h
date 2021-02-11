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
/// \file GenerateGeodatabaseJob.h

#ifndef QRT_GenerateGeodatabaseJob_H
#define QRT_GenerateGeodatabaseJob_H

// C++ API headers
#include "Geodatabase.h"
#include "Job.h"

namespace Esri {
namespace ArcGISRuntime {

  class GenerateGeodatabaseJob : public Job
  {
    Q_OBJECT

  public:
    ~GenerateGeodatabaseJob();

    Geodatabase* result() const;

    /*!
       \internal
     */
    GenerateGeodatabaseJob(const std::shared_ptr<QRTImpl::JobImpl>& impl, QObject* parent = nullptr);

  private:
    GenerateGeodatabaseJob() = delete;

    Q_DISABLE_COPY(GenerateGeodatabaseJob)

  };
}
}
#endif // QRT_GenerateGeodatabaseJob_H
