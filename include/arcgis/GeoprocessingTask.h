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
/// \file GeoprocessingTask.h

#ifndef QRT_GeoprocessingTask_H
#define QRT_GeoprocessingTask_H

// C++ API headers
#include "GeoprocessingJob.h"
#include "GeoprocessingParameters.h"
#include "GeoprocessingTaskInfo.h"
#include "Loadable.h"
#include "Object.h"
#include "RemoteResource.h"
#include "TaskWatcher.h"

// Qt headers
#include <QUrl>

namespace QRTImpl { class GeoprocessingTaskImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class GeoprocessingTask : public Object, public Loadable, public RemoteResource
  {
    Q_OBJECT

  public:
    explicit GeoprocessingTask(const QUrl& url, QObject* parent = nullptr);
    GeoprocessingTask(const QUrl& url, Credential* credential, QObject* parent = nullptr);

    ~GeoprocessingTask();

    TaskWatcher createDefaultParameters();

    GeoprocessingTaskInfo geoprocessingTaskInfo() const;

    GeoprocessingJob* createJob(const GeoprocessingParameters& parameters);

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

    /*!
       \internal
     */
    GeoprocessingTask(const std::shared_ptr<QRTImpl::GeoprocessingTaskImpl>& impl, QObject* parent = nullptr);

    std::shared_ptr<QRTImpl::GeoprocessingTaskImpl> getImpl() const;

  signals:
    void doneLoading(Esri::ArcGISRuntime::Error loadError);
    void loadStatusChanged(Esri::ArcGISRuntime::LoadStatus loadStatus);
    void createDefaultParametersCompleted(QUuid taskId, const Esri::ArcGISRuntime::GeoprocessingParameters& parameters);

  private:
    std::shared_ptr<QRTImpl::GeoprocessingTaskImpl> m_impl;
    void connectSignals();
    Q_DISABLE_COPY(GeoprocessingTask)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_GeoprocessingTask_H
