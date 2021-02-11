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
/// \file WmtsService.h

#ifndef QRT_WmtsService_H
#define QRT_WmtsService_H

// C++ API headers
#include "Loadable.h"
#include "Object.h"
#include "RemoteResource.h"
#include "WmtsLayerInfo.h"
#include "WmtsServiceInfo.h"
#include "WmtsTileMatrixSet.h"

// Qt headers
#include <QList>
#include <QUrl>

namespace QRTImpl { class WmtsServiceImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class WmtsService : public Object, public Loadable, public RemoteResource
  {
    Q_OBJECT

  public:
    explicit WmtsService(const QUrl& url, QObject* parent = nullptr);
    WmtsService(const QUrl& url, Credential* credential, QObject* parent = nullptr);

    ~WmtsService();

    WmtsServiceInfo serviceInfo() const;

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
    WmtsService(const std::shared_ptr<QRTImpl::WmtsServiceImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::WmtsServiceImpl> getImpl() const;

  signals:
    void doneLoading(Esri::ArcGISRuntime::Error loadError);
    void loadStatusChanged(Esri::ArcGISRuntime::LoadStatus loadStatus);

  private:
    std::shared_ptr<QRTImpl::WmtsServiceImpl> m_impl;
    Q_DISABLE_COPY(WmtsService)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_WmtsService_H
