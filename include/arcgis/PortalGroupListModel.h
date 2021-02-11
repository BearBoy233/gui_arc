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
/// \file PortalGroupListModel.h

#ifndef QRT_PortalGroupListModel_H
#define QRT_PortalGroupListModel_H

// C++ API headers
#include "Error.h"

// Qt headers
#include <QAbstractListModel>

namespace QRTImpl { class PortalGroupListImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class PortalGroup;

  class PortalGroupListModel : public QAbstractListModel
  {
    Q_OBJECT

  public:

    enum PortalGroupRoles
    {
      PortalGroupAccessRole = Qt::UserRole + 1, // read-only
      PortalGroupAdminsRole = Qt::UserRole + 2, // read-only
      PortalGroupCreatedRole = Qt::UserRole + 3, // read-only
      PortalGroupGroupDescriptionRole = Qt::UserRole + 4, // read-only
      PortalGroupGroupIdRole = Qt::UserRole + 5, // read-only
      PortalGroupInvitationOnlyRole = Qt::UserRole + 6, // read-only
      PortalGroupModifiedRole = Qt::UserRole + 7,  // read-only
      PortalGroupOwnerRole = Qt::UserRole + 8,  // read-only
      PortalGroupPhoneRole = Qt::UserRole + 9,  // read-only
      PortalGroupSnippetRole = Qt::UserRole + 10, // read-only
      PortalGroupSortFieldRole = Qt::UserRole + 11, // read-only
      PortalGroupSortOrderRole  = Qt::UserRole + 12, // read-only
      PortalGroupTagsRole  = Qt::UserRole + 13, // read-only
      PortalGroupThumbnailUrlRole  = Qt::UserRole + 14, // read-only
      PortalGroupTitleRole = Qt::UserRole + 15, // read-only
      PortalGroupUsersRole = Qt::UserRole + 16, // read-only
      PortalGroupViewOnlyRole = Qt::UserRole + 17 // read-only
    };

    virtual ~PortalGroupListModel();

    bool isEmpty() const;

    void clear();

    int size() const;

    void append(PortalGroup* portalGroup);

    void insert(int index, PortalGroup* portalGroup);

    void removeAt(int index);

    void removeOne(PortalGroup* portalGroup);

    void move(int from, int to);

    PortalGroup* at(int index) const;

    bool contains(PortalGroup* portalGroup) const;

    int indexOf(PortalGroup* portalGroup) const;

    PortalGroup* first() const;

    PortalGroup* last() const;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    bool removeRows(int row, int count, const QModelIndex& parent = QModelIndex()) override;

    /*!
       \internal
     */
    PortalGroupListModel(const std::shared_ptr<QRTImpl::PortalGroupListImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::PortalGroupListImpl> getImpl() const;

  signals:
    void errorOccurred(Esri::ArcGISRuntime::Error error);
    void portalGroupAdded(int index);
    void portalGroupRemoved(int index);

  protected:
    QHash<int, QByteArray> roleNames() const override;

  private:
    Q_DISABLE_COPY(PortalGroupListModel)

    PortalGroupListModel() = delete;
    void setupRoles();
    void connectSignals();

    QHash<int, QByteArray> m_roles;
    std::shared_ptr<QRTImpl::PortalGroupListImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_PortalGroupListModel_H
