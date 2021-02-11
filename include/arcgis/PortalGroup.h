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
/// \file PortalGroup.h

#ifndef QRT_PortalGroup_H
#define QRT_PortalGroup_H

// C++ API headers
#include "JsonSerializable.h"
#include "Object.h"
#include "PortalTypes.h"

// Qt headers
#include <QDateTime>
#include <QString>
#include <QStringList>
#include <QUrl>

// STL headers
#include <memory>

namespace QRTImpl { class PortalGroupImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class Portal;

  class PortalGroup : public Object, public JsonSerializable
  {
    Q_OBJECT
      
  public:
    ~PortalGroup();

    PortalAccess access() const;
    QStringList admins() const;
    QDateTime created() const;
    QString groupDescription() const;
    QString groupId() const;
    bool isInvitationOnly() const;
    QDateTime modified() const;
    QString owner() const;
    QString phone() const;
    Portal* portal() const;
    QString snippet() const;
    PortalGroupSortField sortField() const;
    PortalQuerySortOrder sortOrder() const;
    QStringList tags() const;
    QUrl thumbnailUrl() const;
    QString title() const;
    QStringList users() const;
    bool isViewOnly() const;

    void fetchGroupUsers();

    // JsonSerializable Interface methods
    static PortalGroup* fromJson(const QString& json, QObject* parent = nullptr); // obsolete
    static PortalGroup* fromJson(const QString& json, Portal* portal = nullptr, QObject* parent = nullptr);
    QString toJson() const override;
    QJsonObject unknownJson() const override;
    QJsonObject unsupportedJson() const override;

  signals:
    void fetchGroupUsersCompleted(bool success);

  public:
    /*! \internal */
    PortalGroup(const std::shared_ptr<QRTImpl::PortalGroupImpl>& impl, QObject* parent = nullptr);
    /*! \internal */
    std::shared_ptr<QRTImpl::PortalGroupImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(PortalGroup)

    std::shared_ptr<QRTImpl::PortalGroupImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_PortalGroup_H
