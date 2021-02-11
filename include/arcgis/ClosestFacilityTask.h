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
/// \file ClosestFacilityTask.h

#ifndef QRT_ClosestFacilityTask_H
#define QRT_ClosestFacilityTask_H

// C++ API headers
#include "ClosestFacilityParameters.h"
#include "ClosestFacilityResult.h"
#include "ClosestFacilityTaskInfo.h"
#include "Credential.h"
#include "Loadable.h"
#include "Object.h"
#include "RemoteResource.h"
#include "TaskWatcher.h"
#include "TransportationNetworkDataset.h"

// Qt headers
#include <QUrl>
#include <QUuid>

namespace QRTImpl { class ClosestFacilityTaskImpl; }

namespace Esri {
namespace ArcGISRuntime {

class ClosestFacilityTask : public Object, public Loadable, public RemoteResource
{
  Q_OBJECT

public:
  ClosestFacilityTask(const QString& databasePath, const QString& networkName, QObject* parent = nullptr);
  ClosestFacilityTask(const QUrl& url, Credential* credential, QObject* parent = nullptr);
  ClosestFacilityTask(const QUrl& url, QObject* parent = nullptr);
  ClosestFacilityTask(TransportationNetworkDataset* transportationNetworkDataset, QObject* parent = nullptr);
  ~ClosestFacilityTask();

  ClosestFacilityTaskInfo closestFacilityTaskInfo() const;

  TransportationNetworkDataset* transportationNetworkDataset() const;

  TaskWatcher createDefaultParameters();

  TaskWatcher solveClosestFacility(const ClosestFacilityParameters& closestFacilityParameters);

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
  ClosestFacilityTask(const std::shared_ptr<QRTImpl::ClosestFacilityTaskImpl>& impl, QObject* parent = nullptr);
  std::shared_ptr<QRTImpl::ClosestFacilityTaskImpl> getImpl() const;

signals:
  void createDefaultParametersCompleted(QUuid taskId, Esri::ArcGISRuntime::ClosestFacilityParameters defaultParameters);
  void solveClosestFacilityCompleted(QUuid taskId, Esri::ArcGISRuntime::ClosestFacilityResult closestFacilityResult);
  void doneLoading(Esri::ArcGISRuntime::Error loadError);
  void loadStatusChanged(Esri::ArcGISRuntime::LoadStatus loadStatus);

private:
  Q_DISABLE_COPY(ClosestFacilityTask)

  void connectSignals();

  std::shared_ptr<QRTImpl::ClosestFacilityTaskImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ClosestFacilityTask_H
