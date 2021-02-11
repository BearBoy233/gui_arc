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
/// \file GenerateOfflineMapJob.h

#ifndef QRT_GenerateOfflineMapJob_H
#define QRT_GenerateOfflineMapJob_H

// C++ API headers
#include "GenerateOfflineMapParameterOverrides.h"
#include "GenerateOfflineMapParameters.h"
#include "GenerateOfflineMapResult.h"
#include "Job.h"
#include "Map.h"

namespace QRTImpl {
  class GenerateOfflineMapJobImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class GenerateOfflineMapJob : public Job
  {
    Q_OBJECT

  public:
    ~GenerateOfflineMapJob();

    GenerateOfflineMapResult* result() const;

    QString downloadDirectoryPath() const;

    Map* onlineMap() const;

    GenerateOfflineMapParameters parameters() const;

    GenerateOfflineMapParameterOverrides* parameterOverrides() const;

    /*!
       \internal
     */
    GenerateOfflineMapJob(const std::shared_ptr<QRTImpl::GenerateOfflineMapJobImpl>& impl, QObject* parent = nullptr);

  private:
    GenerateOfflineMapJob() = delete;

    Q_DISABLE_COPY(GenerateOfflineMapJob)
  };
}
}

#endif // QRT_GenerateOfflineMapJob_H
