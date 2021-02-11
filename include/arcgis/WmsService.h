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
/// \file WmsService.h

#ifndef QRT_WmsService_H
#define QRT_WmsService_H

// C++ API headers
#include "Loadable.h"
#include "MapTypes.h"
#include "Object.h"
#include "RemoteResource.h"
#include "WmsLayerInfo.h"
#include "WmsServiceInfo.h"

// Qt headers
#include <QList>
#include <QUrl>

namespace QRTImpl { class WmsServiceImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class WmsService : public Object, public Loadable, public RemoteResource
  {
    Q_OBJECT

  public:
    explicit WmsService(const QUrl& url, QObject* parent = nullptr);
    WmsService(const QUrl& url, Credential* credential, QObject* parent = nullptr);

    ~WmsService();

    QMap<QString, QString> customParameters() const;
    void setCustomParameters(const QMap<QString, QString>& customParameters);

    WmsServiceInfo serviceInfo() const;

    WmsVersion version() const;

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

    /*!
       \internal
     */
    WmsService(const std::shared_ptr<QRTImpl::WmsServiceImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::WmsServiceImpl> getImpl() const;

  signals:
    void doneLoading(Esri::ArcGISRuntime::Error loadError);
    void loadStatusChanged(Esri::ArcGISRuntime::LoadStatus loadStatus);

  private:
    std::shared_ptr<QRTImpl::WmsServiceImpl> m_impl;
    Q_DISABLE_COPY(WmsService)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_WmsService_H
