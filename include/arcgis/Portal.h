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
/// \file Portal.h

#ifndef QRT_Portal_H
#define QRT_Portal_H

// C++ API headers
#include "Basemap.h"
#include "BasemapListModel.h"
#include "Credential.h"
#include "Error.h"
#include "Loadable.h"
#include "Object.h"
#include "PortalGroup.h"
#include "PortalGroupListModel.h"
#include "PortalInfo.h"
#include "PortalItem.h"
#include "PortalItemListModel.h"
#include "PortalQueryParametersForGroups.h"
#include "PortalQueryParametersForItems.h"
#include "PortalQueryResultSetForGroups.h"
#include "PortalQueryResultSetForItems.h"
#include "PortalUser.h"
#include "RemoteResource.h"

namespace QRTImpl { class PortalImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class Portal : public Object, public Loadable, public RemoteResource
  {
    Q_OBJECT

  public:
    // constructors & destructor
    explicit Portal(QObject* parent = nullptr);
    explicit Portal(bool loginRequired, QObject* parent = nullptr);
    explicit Portal(const QUrl& url, QObject* parent = nullptr);
    explicit Portal(const QUrl& url, bool loginRequired, QObject* parent = nullptr);
    explicit Portal(Credential* credential, QObject* parent = nullptr);
    explicit Portal(const QUrl& url, Credential* credential, QObject* parent = nullptr);

    ~Portal();

    void setCredential(Credential *credential);

    bool isLoginRequired() const;

    PortalInfo* portalInfo() const;
    PortalUser* portalUser() const;
      
    BasemapListModel* basemaps() const;
    PortalItemListModel* featuredItems() const;
    PortalGroupListModel* featuredGroups() const;
    PortalItemListModel* homepageFeaturedContent() const;
      
    // find functions
    void findItems(const PortalQueryParametersForItems& queryParameters);
    void findGroups(const PortalQueryParametersForGroups& queryParameters);

    // fetch data
    void fetchBasemaps();
    void fetchFeaturedItems();
    void fetchFeaturedGroups();
    void fetchHomepageFeaturedContent();

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

    /*! \internal */
    explicit Portal(const std::shared_ptr<QRTImpl::PortalImpl>& impl, QObject* parent = nullptr);

    std::shared_ptr<QRTImpl::PortalImpl> getImpl() const;

  signals:
    void doneLoading(Esri::ArcGISRuntime::Error loadError);
    void loadStatusChanged(Esri::ArcGISRuntime::LoadStatus loadStatus);

    // find signals
    void findItemsCompleted(Esri::ArcGISRuntime::PortalQueryResultSetForItems* result);
    void findGroupsCompleted(Esri::ArcGISRuntime::PortalQueryResultSetForGroups* result);

    // fetch data
    void basemapsChanged();
    void featuredItemsChanged();
    void featuredGroupsChanged();
    void homepageFeaturedContentChanged();

  private:
    Q_DISABLE_COPY(Portal)
    std::shared_ptr<QRTImpl::PortalImpl> m_impl;

    void connectSignals();
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_Portal_H
