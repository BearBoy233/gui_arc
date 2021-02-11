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
/// \file ServiceAreaTask.h

#ifndef QRT_ServiceAreaTask_H
#define QRT_ServiceAreaTask_H

// C++ API headers
#include "Credential.h"
#include "Loadable.h"
#include "Object.h"
#include "RemoteResource.h"
#include "ServiceAreaParameters.h"
#include "ServiceAreaResult.h"
#include "ServiceAreaTaskInfo.h"
#include "TaskWatcher.h"
#include "TransportationNetworkDataset.h"

// Qt headers
#include <QUrl>
#include <QUuid>

namespace QRTImpl { class ServiceAreaTaskImpl; }

namespace Esri {
namespace ArcGISRuntime {

class ServiceAreaTask : public Object, public Loadable, public RemoteResource
{
  Q_OBJECT

public:
  ServiceAreaTask(const QString& databasePath, const QString& networkName, QObject* parent = nullptr);
  ServiceAreaTask(const QUrl& url, Credential* credential, QObject* parent = nullptr);
  ServiceAreaTask(const QUrl& url, QObject* parent = nullptr);
  ServiceAreaTask(TransportationNetworkDataset* transportationNetworkDataset, QObject* parent = nullptr);
  ~ServiceAreaTask();

  ServiceAreaTaskInfo serviceAreaTaskInfo() const;

  TransportationNetworkDataset* transportationNetworkDataset() const;

  TaskWatcher createDefaultParameters();

  TaskWatcher solveServiceArea(const ServiceAreaParameters& serviceAreaParameters);

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
  ServiceAreaTask(const std::shared_ptr<QRTImpl::ServiceAreaTaskImpl>& impl, QObject* parent = nullptr);
  std::shared_ptr<QRTImpl::ServiceAreaTaskImpl> getImpl() const;

signals:
  void createDefaultParametersCompleted(QUuid taskId, Esri::ArcGISRuntime::ServiceAreaParameters defaultParameters);
  void solveServiceAreaCompleted(QUuid taskId, Esri::ArcGISRuntime::ServiceAreaResult serviceAreaResult);
  void doneLoading(Esri::ArcGISRuntime::Error loadError);
  void loadStatusChanged(Esri::ArcGISRuntime::LoadStatus loadStatus);

private:
  Q_DISABLE_COPY(ServiceAreaTask)

  void connectSignals();

  std::shared_ptr<QRTImpl::ServiceAreaTaskImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ServiceAreaTask_H
