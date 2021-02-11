// COPYRIGHT 1995-2018 ESRI
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
/// \file KmlDataset.h

#ifndef QRT_KmlDataset_H
#define QRT_KmlDataset_H

// C++ API headers
#include "Credential.h"
#include "KmlNetworkLink.h"
#include "KmlNode.h"
#include "Loadable.h"
#include "Object.h"
#include "RemoteResource.h"

// Qt headers
#include <QUrl>
#include <QUuid>

namespace QRTImpl { class KmlDatasetImpl; }

namespace Esri {
namespace ArcGISRuntime {

class KmlDataset : public Object, public Loadable, public RemoteResource
{
  Q_OBJECT

public:
  explicit KmlDataset(const QUrl& url, QObject* parent = nullptr);
  KmlDataset(const QUrl& url, Credential* credential, QObject* parent = nullptr);
  ~KmlDataset();

  QList<KmlNode*> rootNodes() const;

  // Loadable interface methods
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

  /*! \internal */
  explicit KmlDataset(const std::shared_ptr<QRTImpl::KmlDatasetImpl>& impl, QObject* parent = nullptr);
  std::shared_ptr<QRTImpl::KmlDatasetImpl> getImpl() const;

signals:
  void kmlNetworkLinkMessageReceived(Esri::ArcGISRuntime::KmlNetworkLink* networkLink,
                                     const QString& message);
  void kmlNodeRefreshStatusChanged(Esri::ArcGISRuntime::KmlNode* target,
                                   Esri::ArcGISRuntime::KmlRefreshStatus refreshStatus);
  void doneLoading(Esri::ArcGISRuntime::Error loadError);
  void loadStatusChanged(Esri::ArcGISRuntime::LoadStatus loadStatus);

private:
  KmlDataset() = delete;
  Q_DISABLE_COPY(KmlDataset)

  void connectNotify(const QMetaMethod& signal) override;
  void disconnectNotify(const QMetaMethod& signal) override;

  void connectSignals();

  QMetaObject::Connection m_nodeRefreshStatusChangedConn;
  std::shared_ptr<QRTImpl::KmlDatasetImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_KmlDataset_H
