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
/// \file RouteTask.h

#ifndef QRT_RouteTask_H
#define QRT_RouteTask_H

// C++ API headers
#include "Credential.h"
#include "FeatureCollection.h"
#include "Loadable.h"
#include "Object.h"
#include "PortalItem.h"
#include "RemoteResource.h"
#include "RouteParameters.h"
#include "RouteResult.h"
#include "RouteTaskInfo.h"
#include "TaskWatcher.h"
#include "TransportationNetworkDataset.h"

// Qt headers
#include <QMap>
#include <QUrl>
#include <QUuid>

namespace QRTImpl { class RouteTaskImpl; }

namespace Esri {
namespace ArcGISRuntime {

class RouteTask : public Object, public Loadable, public RemoteResource
{
  Q_OBJECT

public:
  static RouteTask* instance();

  RouteTask(const QString& pathToDatabase, const QString& networkName, QObject* parent = nullptr);
  RouteTask(const QUrl& url, Credential* credential, QObject* parent = nullptr);
  explicit RouteTask(const QUrl& url, QObject* parent = nullptr);
  explicit RouteTask(TransportationNetworkDataset* transportationNetworkDataset, QObject* parent = nullptr);

  ~RouteTask();

  TaskWatcher createDefaultParameters();

  TaskWatcher createParameters(const FeatureCollection& featureCollection);

  TaskWatcher createParametersWithPortalItem(PortalItem* portalItem);

  RouteTaskInfo routeTaskInfo() const;

  TransportationNetworkDataset* transportationNetworkDataset() const;

  TaskWatcher solveRoute(const RouteParameters& routeParameters);

  static TaskWatcher createRouteResult(PortalItem* portalItem);

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
  explicit RouteTask(const std::shared_ptr<QRTImpl::RouteTaskImpl>& impl, QObject* parent = nullptr);
  std::shared_ptr<QRTImpl::RouteTaskImpl> getImpl() const;

signals:
  void createDefaultParametersCompleted(QUuid taskId, Esri::ArcGISRuntime::RouteParameters defaultParameters);
  void createParametersCompleted(QUuid taskId, Esri::ArcGISRuntime::RouteParameters parameters);
  void createParametersWithPortalItemCompleted(QUuid taskId, Esri::ArcGISRuntime::RouteParameters parameters);
  void solveRouteCompleted(QUuid taskId, Esri::ArcGISRuntime::RouteResult routeResult);
  void doneLoading(Esri::ArcGISRuntime::Error loadError);
  void loadStatusChanged(Esri::ArcGISRuntime::LoadStatus loadStatus);
  void createRouteResultCompleted(QUuid taskId, Esri::ArcGISRuntime::RouteResult routeResult);

private:
  Q_DISABLE_COPY(RouteTask)

  void connectSignals();

  std::shared_ptr<QRTImpl::RouteTaskImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_RouteTask_H
