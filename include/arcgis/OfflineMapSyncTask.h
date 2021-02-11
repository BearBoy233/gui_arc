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
/// \file OfflineMapSyncTask.h

#ifndef QRT_OfflineMapSyncTask_H
#define QRT_OfflineMapSyncTask_H

// C++ API headers
#include "Credential.h"
#include "Loadable.h"
#include "Map.h"
#include "Object.h"
#include "OfflineMapSyncJob.h"
#include "OfflineMapSyncParameters.h"
#include "RemoteResource.h"

namespace QRTImpl
{
  class OfflineMapSyncTaskImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class OfflineMapSyncTask : public Object, public Loadable, public RemoteResource
  {
    Q_OBJECT

  public:
    explicit OfflineMapSyncTask(Map* map, QObject* parent = nullptr);
    OfflineMapSyncTask(Map* map, Credential* credential, QObject* parent = nullptr);
    ~OfflineMapSyncTask();

    Map* map() const;

    OfflineMapSyncJob* syncOfflineMap(const OfflineMapSyncParameters& parameters);

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

  private:
    OfflineMapSyncTask() = delete;
    Q_DISABLE_COPY(OfflineMapSyncTask)
    std::shared_ptr<QRTImpl::OfflineMapSyncTaskImpl> m_impl;

    void connectSignals();
  };
}
}
#endif // QRT_OfflineMapSyncTask_H
