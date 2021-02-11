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
/// \file ExportVectorTilesJob.h

#ifndef QRT_ExportVectorTilesJob_H
#define QRT_ExportVectorTilesJob_H

// C++ API headers
#include "ExportVectorTilesParameters.h"
#include "ExportVectorTilesResult.h"
#include "Job.h"

namespace QRTImpl { class ExportVectorTilesJobImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class ExportVectorTilesJob : public Job
  {
    Q_OBJECT

  public:
    ~ExportVectorTilesJob();

    ExportVectorTilesResult* result() const;

    ExportVectorTilesParameters parameters() const;

    QString vectorTileCachePath() const;

    QString itemResourcePath() const;

    /*!
       \internal
     */
    ExportVectorTilesJob(const std::shared_ptr<QRTImpl::ExportVectorTilesJobImpl>& impl, QObject* parent = nullptr);

  private:
    Q_DISABLE_COPY(ExportVectorTilesJob)

    ExportVectorTilesJob() = delete;
  };

}
}

#endif // QRT_ExportVectorTilesJob_H
