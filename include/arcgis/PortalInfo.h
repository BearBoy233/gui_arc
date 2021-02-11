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
/// \file PortalInfo.h

#ifndef QRT_PortalInfo_H
#define QRT_PortalInfo_H

// C++ API headers
#include "Basemap.h"
#include "Envelope.h"
#include "JsonSerializable.h"
#include "LicenseInfo.h"
#include "Object.h"
#include "PortalTypes.h"

namespace QRTImpl { class PortalInfoImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class Portal;
  class PortalHelperServices;

  class PortalInfo : public Object, public JsonSerializable
  {
    Q_OBJECT

  public:
    // constructors and destrutor
    ~PortalInfo();

    // properties
    PortalAccess access() const;
    bool isAllSsl() const;
    QString basemapGalleryGroupQuery() const;
    QString bingKey() const;
    bool isCanSearchPublic() const;
    bool isCanShareBingPublic() const;
    bool isCanSharePublic() const;
    bool isCommentsEnabled() const;
    QDateTime created() const;
    QString culture() const;
    QUrl customBaseDomainUrl() const;
    Basemap* defaultBasemap() const;
    Envelope defaultExtent() const;
    QStringList featuredGroupsQueries() const;
    QString featuredItemsGroupQuery() const;
    PortalHelperServices* helperServices() const;
    int homePageFeaturedContentCount() const;
    QString homePageFeaturedContentGroupQuery() const;
    QString ipCountryCode() const;
    bool isPortal() const;
    LicenseInfo licenseInfo() const;
    QDateTime modified() const;
    QString organizationId() const;
    QUrl organizationBannerUrl() const;
    QString organizationDescription() const;
    QString organizationName() const;
    QString organizationSubdomain() const;
    Portal* portal() const;
    PortalMode portalMode() const;
    QString portalName() const;
    QUrl portalThumbnailUrl() const;
    bool isShowHomePageDescription() const;
    bool isSupportsOAuth() const;
    QUrl thumbnailUrl() const;

    // JsonSerializable Interface methods
    static PortalInfo* fromJson(const QString& json, QObject* parent = nullptr);
    QString toJson() const override;
    QJsonObject unknownJson() const override;
    QJsonObject unsupportedJson() const override;

  private:
    friend class Portal;
    PortalInfo(const std::shared_ptr<QRTImpl::PortalInfoImpl>& impl, QObject* parent = nullptr);

    Q_DISABLE_COPY(PortalInfo)
    std::shared_ptr<QRTImpl::PortalInfoImpl> m_impl;
    mutable PortalHelperServices* m_helperServices = nullptr;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_PortalInfo_H

