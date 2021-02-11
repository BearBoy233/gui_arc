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
/// \file PortalItem.h

#ifndef QRT_PortalItem_H
#define QRT_PortalItem_H

// C++ API headers
#include "Error.h"
#include "Item.h"
#include "JsonSerializable.h"
#include "Loadable.h"
#include "NetworkRequestProgress.h"
#include "PortalGroupListModel.h"
#include "PortalItemCommentListModel.h"
#include "PortalTypes.h"

namespace QRTImpl { class PortalItemImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class Portal;

  class PortalItem : public Item, public Loadable, public JsonSerializable
  {
    Q_OBJECT

  public:
    explicit PortalItem(Portal* portal, QObject* parent = nullptr);
    explicit PortalItem(const QString& itemId, QObject* parent = nullptr);
    explicit PortalItem(Portal* portal, const QString& itemId, QObject* parent = nullptr);
    explicit PortalItem(const QUrl& url, QObject* parent = nullptr);
    explicit PortalItem(const QString& json, Portal* portal, QObject* parent = nullptr); // obsolete
    ~PortalItem();

    Error loadError() const override;
    LoadStatus loadStatus() const override;
    void cancelLoad() override;
    void load() override;
    void retryLoad() override;

    PortalAccess access() const;
 
    QString accessAndUseConstraintsHtml() const;

    float averageRating() const;

    int commentCount() const;

    bool isCommentsEnabled() const;

    QString culture() const;

    QString folderId() const;

    QString name() const;

    QString owner() const;

    Portal* portal() const;

    int ratingCount() const;

    QUrl serviceUrl() const;

    qint64 size() const;

    PortalItemType type() const;
    void setType(PortalItemType type);

    QStringList typeKeywords() const;
    void setTypeKeywords(const QStringList& typeKeywords);

    QString typeName() const;

    // float userRating() const;

    int viewCount() const;

    QUrl url() const;

    PortalItemCommentListModel* comments() const;
    void fetchComments();

    PortalGroupListModel* adminGroups() const;
    PortalGroupListModel* memberGroups() const;
    PortalGroupListModel* otherGroups() const;
    void fetchGroups();

    void addRating(float rating);
    void addComment(const QString& comment);
    void updateDataWithJson(const QString& json);
    void updateDataWithUrl(const QUrl& fromUrl, const QString& fileName = QString());

    void shareWith(bool everyone, bool organization);
    void shareWithGroups(const QStringList& groupIds);
    void unshare();
    void unshareGroups(const QStringList& groupIds);

    // JsonSerializable Interface methods
    static PortalItem* fromJson(const QString& json, Portal* portal = nullptr, QObject* parent = nullptr);
    QString toJson() const override;
    QJsonObject unknownJson() const override;
    QJsonObject unsupportedJson() const override;

  signals:
    void doneLoading(Esri::ArcGISRuntime::Error loadError);
    void loadStatusChanged(Esri::ArcGISRuntime::LoadStatus loadStatus);

    void addCommentCompleted(bool success);
    void fetchCommentsCompleted(bool success);

    void fetchGroupsCompleted(bool success);

    void addRatingCompleted(bool success);

    void updateDataCompleted(bool success, const QString& itemId);

    void shareWithCompleted(bool success);
    void shareWithGroupsCompleted(bool success, const QStringList& failedToShareGroupIds);
    void unshareCompleted(bool success);
    void unshareGroupsCompleted(bool success, const QStringList& failedToUnshareGroupIds);

    void fetchDataProgressChanged(const Esri::ArcGISRuntime::NetworkRequestProgress& progress);

  public:
    // internals
    /*!
       \internal
     */
    PortalItem(const std::shared_ptr<QRTImpl::PortalItemImpl>& impl, QObject* parent = nullptr); // used in ItemFactory
    std::shared_ptr<QRTImpl::PortalItemImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(PortalItem)

    void connectSignals();
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_PortalItem_H
