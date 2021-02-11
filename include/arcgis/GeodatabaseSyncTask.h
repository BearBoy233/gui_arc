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
/// \file GeodatabaseSyncTask.h

#ifndef QRT_GeodatabaseSyncTask_H
#define QRT_GeodatabaseSyncTask_H

// C++ API headers
#include "ArcGISFeatureServiceInfo.h"
#include "Credential.h"
#include "GenerateGeodatabaseJob.h"
#include "GenerateGeodatabaseParameters.h"
#include "Geodatabase.h"
#include "Loadable.h"
#include "Object.h"
#include "RemoteResource.h"
#include "SyncGeodatabaseJob.h"
#include "SyncGeodatabaseParameters.h"
#include "SyncLayerResult.h"
#include "TaskTypes.h"
#include "TaskWatcher.h"

// Qt headers
#include <QUrl>
#include <QUuid>

namespace QRTImpl
{
  class GeodatabaseSyncTaskImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class GeodatabaseSyncTask: public Object, public Loadable, public RemoteResource
  {
    Q_OBJECT

  public:
    static GeodatabaseSyncTask* instance();

    explicit GeodatabaseSyncTask(const QUrl& url, QObject* parent = nullptr);
    GeodatabaseSyncTask(const QUrl& url, Credential* credential, QObject* parent = nullptr);
    ~GeodatabaseSyncTask();

    ArcGISFeatureServiceInfo featureServiceInfo() const;

    TaskWatcher createDefaultGenerateGeodatabaseParameters(const Geometry& extent);

    TaskWatcher createDefaultSyncGeodatabaseParameters(Geodatabase* geodatabase);
    TaskWatcher createDefaultSyncGeodatabaseParameters(Geodatabase* geodatabase, SyncDirection syncDirection);

    GenerateGeodatabaseJob* generateGeodatabase(const GenerateGeodatabaseParameters& parameters, const QString& pathToGeodatabaseFile);

    static TaskWatcher importGeodatabaseDelta(Geodatabase* geodatabase, const QString& pathToDeltaFile);

    SyncGeodatabaseJob* syncGeodatabase(const SyncGeodatabaseParameters& parameters, Geodatabase* geodatabase);
    SyncGeodatabaseJob* syncGeodatabase(SyncDirection syncDirection, bool rollbackOnFailure, Geodatabase* geodatabase);

    TaskWatcher unregisterGeodatabase(Geodatabase* geodatabase);
    TaskWatcher unregisterGeodatabase(const QUuid& syncId);

    TaskWatcher registerSyncEnabledGeodatabase(Geodatabase* geodatabase);

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
    void defaultGenerateGeodatabaseParametersCompleted(QUuid taskId, Esri::ArcGISRuntime::GenerateGeodatabaseParameters defaultGenerateParameters);
    void defaultSyncGeodatabaseParametersCompleted(QUuid taskId, Esri::ArcGISRuntime::SyncGeodatabaseParameters defaultSyncParameters);
    void unregisterGeodatabaseCompleted(QUuid taskId);
    void registerSyncEnabledGeodatabaseCompleted(QUuid taskId);
    void importGeodatabaseDeltaCompleted(QUuid taskId, const QList<Esri::ArcGISRuntime::SyncLayerResult*>& syncLayerResults);

    /*! \internal */
  private:
    GeodatabaseSyncTask(QObject* parent = nullptr);
    Q_DISABLE_COPY(GeodatabaseSyncTask)
    std::shared_ptr<QRTImpl::GeodatabaseSyncTaskImpl> m_impl;

    void connectSignals();
  };
}
}

#endif // QRT_GeodatabaseSyncTask_H
