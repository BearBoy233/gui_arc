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
/// \file PortalUser.h

#ifndef QRT_PortalUser_H
#define QRT_PortalUser_H

// C++ API headers
#include "JsonSerializable.h"
#include "Loadable.h"
#include "Object.h"
#include "PortalFolder.h"
#include "PortalFolderListModel.h"
#include "PortalItem.h"
#include "PortalItemListModel.h"
#include "PortalPrivilege.h"
#include "PortalPrivilegeListModel.h"
#include "PortalResult.h"
#include "PortalTypes.h"

// Qt headers
#include <QDateTime>
#include <QUrl>

namespace QRTImpl { class PortalUserImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class Portal;

  class PortalUser : public Object, public Loadable, public JsonSerializable
  {
    Q_OBJECT

  public:
    explicit PortalUser(Portal* portal, const QString& username, QObject* parent = nullptr);
    ~PortalUser();

    Error loadError() const override;
    LoadStatus loadStatus() const override;
    void cancelLoad() override;
    void load() override;
    void retryLoad() override;

    PortalAccess access() const;
    QDateTime created() const;
    QString email() const;
    QString favoritesGroupId() const;
    QString fullName() const;
    PortalGroupListModel* groups() const;
    QDateTime modified() const;
    QString organizationId() const;
    QString phone() const;
    Portal* portal() const;
    PortalPrivilegeListModel* privileges() const;
    PortalUserRole role() const;
    QStringList tags() const;
    QUrl thumbnailUrl() const;
    UnitSystem units() const;
    QString userDescription() const;
    QString username() const;

    PortalFolderListModel* folders() const;
    PortalItemListModel* items() const;

    void fetchContent();
    void fetchContentInFolder(const QString& folderId);

    void addPortalItemWithJson(PortalItem* portalItem,
                               const QString& json,
                               const PortalFolder& toFolder = PortalFolder());
    void addPortalItemWithUrl(PortalItem* portalItem,
                              const QUrl& fromUrl,
                              const QString& fileName = QString(),
                              const PortalFolder& toFolder = PortalFolder());
    void deletePortalItem(PortalItem* portalItem);
    void movePortalItem(PortalItem* portalItem, const PortalFolder& toFolder = PortalFolder());
    void movePortalItems(const QList<PortalItem*>& portalItems, const PortalFolder& toFolder = PortalFolder());

    void createFolder(const QString& title);
    void deleteFolder(const PortalFolder& folder);

    void addToFavorites(PortalItem* portalItem);
    void removeFromFavorites(PortalItem* portalItem);
    void fetchFavoritesStatus(PortalItem* portalItem);

    // JsonSerializable Interface methods
    static PortalUser* fromJson(const QString& json, QObject* parent = nullptr); // obsolete
    static PortalUser* fromJson(const QString& json, Portal* portal = nullptr, QObject* parent = nullptr);
    QString toJson() const override;
    QJsonObject unknownJson() const override;
    QJsonObject unsupportedJson() const override;

    /*!
       \internal
     */
    PortalUser(const std::shared_ptr<QRTImpl::PortalUserImpl>& impl, QObject* parent = nullptr);

  signals:
    void doneLoading(Esri::ArcGISRuntime::Error loadError);
    void loadStatusChanged(Esri::ArcGISRuntime::LoadStatus loadStatus);

    void fetchContentCompleted(bool success);

    void addPortalItemCompleted(bool success);
    void deletePortalItemCompleted(bool success);
    void movePortalItemCompleted(bool success);
    void movePortalItemsCompleted(QList<Esri::ArcGISRuntime::PortalResult> results);

    void createFolderCompleted(bool success, Esri::ArcGISRuntime::PortalFolder folder);
    void deleteFolderCompleted(bool success);

    void addToFavoritesCompleted(bool success);
    void removeFromFavoritesCompleted(bool success);
    void fetchFavoritesStatusCompleted(bool status);

  private:
    Q_DISABLE_COPY(PortalUser)
    std::shared_ptr<QRTImpl::PortalUserImpl> m_impl;

    void connectSignals();
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_PortalUser_H

