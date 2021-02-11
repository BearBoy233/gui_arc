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
/// \file ExportTileCacheTask.h

#ifndef QRT_ExportTileCacheTask_H
#define QRT_ExportTileCacheTask_H

// C++ API headers
#include "ArcGISMapServiceInfo.h"
#include "Credential.h"
#include "EstimateTileCacheSizeJob.h"
#include "ExportTileCacheJob.h"
#include "ExportTileCacheParameters.h"
#include "Geometry.h"
#include "Loadable.h"
#include "Object.h"
#include "RemoteResource.h"
#include "TaskWatcher.h"

namespace QRTImpl
{
  class ExportTileCacheTaskImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class ExportTileCacheTask : public Object, public Loadable, public RemoteResource
  {
    Q_OBJECT

  public:
    explicit ExportTileCacheTask(const QUrl& url, QObject* parent = nullptr);
    ExportTileCacheTask(const QUrl& url, Credential* credential, QObject* parent = nullptr);
    ~ExportTileCacheTask();

    ArcGISMapServiceInfo mapServiceInfo() const;

    TaskWatcher createDefaultExportTileCacheParameters(const Geometry& areaOfInterest, double minScale, double maxScale);
    EstimateTileCacheSizeJob* estimateTileCacheSize(const ExportTileCacheParameters& parameters);
    ExportTileCacheJob* exportTileCache(const ExportTileCacheParameters& parameters, const QString& downloadFilePath);

    // Loadable Interface methods
    Error loadError() const override;
    LoadStatus loadStatus() const override;
    void cancelLoad() override;
    void load() override;
    void retryLoad() override;

    // RemoteResource interface methods
    QUrl url() const override;
    Credential* credential() const override;
    RequestConfiguration requestConfiguration() const override;
    void setRequestConfiguration(const RequestConfiguration& requestConfiguration) override;

  signals:
    void doneLoading(Esri::ArcGISRuntime::Error loadError);
    void loadStatusChanged(Esri::ArcGISRuntime::LoadStatus loadStatus);
    void defaultExportTileCacheParametersCompleted(QUuid taskId, Esri::ArcGISRuntime::ExportTileCacheParameters defaultExportTileCacheParameters);

  private:
    ExportTileCacheTask() = delete;
    Q_DISABLE_COPY(ExportTileCacheTask)
    std::shared_ptr<QRTImpl::ExportTileCacheTaskImpl> m_impl;

    void connectSignals();
  };
}
}
#endif // QRT_ExportTileCacheTask_H
