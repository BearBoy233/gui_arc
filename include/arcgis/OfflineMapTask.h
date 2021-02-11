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
/// \file OfflineMapTask.h

#ifndef QRT_OfflineMapTask_H
#define QRT_OfflineMapTask_H

// C++ API headers
#include "Credential.h"
#include "DownloadPreplannedOfflineMapParameters.h"
#include "GenerateOfflineMapJob.h"
#include "GenerateOfflineMapParameterOverrides.h"
#include "GenerateOfflineMapParameters.h"
#include "Geometry.h"
#include "Loadable.h"
#include "Map.h"
#include "Object.h"
#include "OfflineMapCapabilities.h"
#include "PortalItem.h"
#include "RemoteResource.h"
#include "TaskWatcher.h"

namespace QRTImpl
{
  class OfflineMapTaskImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class DownloadPreplannedOfflineMapJob;
  class PreplannedMapAreaListModel;
  class PreplannedMapArea;

  class OfflineMapTask : public Object, public Loadable, public RemoteResource
  {
    Q_OBJECT

  public:
    OfflineMapTask(Map* onlineMap, Credential* credential, QObject* parent = nullptr);
    explicit OfflineMapTask(Map* onlineMap, QObject* parent = nullptr);
    explicit OfflineMapTask(PortalItem* portalItem, QObject* parent = nullptr);
    ~OfflineMapTask();

    Map* onlineMap() const;

    PortalItem* portalItem() const;

    TaskWatcher createDefaultGenerateOfflineMapParameters(const Geometry& areaOfInterest);
    TaskWatcher createDefaultGenerateOfflineMapParameters(const Geometry& areaOfInterest, double minScale, double maxScale);

    TaskWatcher createGenerateOfflineMapParameterOverrides(const GenerateOfflineMapParameters& parameters);

    GenerateOfflineMapJob* generateOfflineMap(const GenerateOfflineMapParameters& parameters,
                                              const QString& downloadDirectoryPath);
    GenerateOfflineMapJob* generateOfflineMap(const GenerateOfflineMapParameters& parameters,
                                              const QString& downloadDirectoryPath,
                                              GenerateOfflineMapParameterOverrides* parameterOverrides);

    DownloadPreplannedOfflineMapJob* downloadPreplannedOfflineMap(PreplannedMapArea* area,
                                                                  const QString& downloadDirectoryPath);

    DownloadPreplannedOfflineMapJob* downloadPreplannedOfflineMap(PreplannedMapArea* area,
                                                                  const QString& downloadDirectoryPath,
                                                                  bool excludeBasemap);
    DownloadPreplannedOfflineMapJob* downloadPreplannedOfflineMap(const DownloadPreplannedOfflineMapParameters& parameters,
                                                                  const QString& downloadDirectoryPath);

    TaskWatcher offlineMapCapabilities(const GenerateOfflineMapParameters& parameters);

    TaskWatcher preplannedMapAreas();

    PreplannedMapAreaListModel* preplannedMapAreaList() const;

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
    void createDefaultGenerateOfflineMapParametersCompleted(QUuid taskId, const Esri::ArcGISRuntime::GenerateOfflineMapParameters& parameters);
    void createGenerateOfflineMapParameterOverridesCompleted(QUuid taskId, Esri::ArcGISRuntime::GenerateOfflineMapParameterOverrides* parameterOverrides);
    void offlineMapCapabilitiesCompleted(QUuid taskId, const Esri::ArcGISRuntime::OfflineMapCapabilities& capabilities);
    void preplannedMapAreasCompleted(QUuid taskId);

  private:
    OfflineMapTask() = delete;
    Q_DISABLE_COPY(OfflineMapTask)
    std::shared_ptr<QRTImpl::OfflineMapTaskImpl> m_impl;
    mutable PreplannedMapAreaListModel* m_areasModel = nullptr;

    void connectSignals();
  };
}
}
#endif // QRT_OfflineMapTask_H
