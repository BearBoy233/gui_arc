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
/// \file PortalPrivilegeListModel.h

#ifndef QRT_PortalPrivilegeListModel_H
#define QRT_PortalPrivilegeListModel_H

// C++ API headers
#include "Error.h"
#include "PortalPrivilege.h"

// Qt headers
#include <QAbstractListModel>

namespace QRTImpl { class PortalPrivilegeListImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class PortalPrivilegeListModel : public QAbstractListModel
  {
    Q_OBJECT

  public:

    enum PortalPrivilegeRoles
    {
      PortalPrivilegeRealmRole = Qt::UserRole + 1, // read-only
      PortalPrivilegeRoleRole = Qt::UserRole + 2, // read-only
      PortalPrivilegeTypeRole = Qt::UserRole + 3, // read-only
      TypeNameRole = Qt::UserRole + 4 // read-only
    };

    virtual ~PortalPrivilegeListModel();

    bool isEmpty() const;

    void clear();

    int size() const;

    void append(const PortalPrivilege& portalPrivilege);

    void insert(int index, const PortalPrivilege& portalPrivilege);

    void removeAt(int index);

    void removeOne(const PortalPrivilege& portalPrivilege);

    void move(int from, int to);

    PortalPrivilege at(int index) const;

    bool contains(const PortalPrivilege& portalPrivilege) const;

    int indexOf(const PortalPrivilege& portalPrivilege) const;

    PortalPrivilege first() const;

    PortalPrivilege last() const;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    bool removeRows(int row, int count, const QModelIndex& parent = QModelIndex()) override;

    /*!
       \internal
     */
    PortalPrivilegeListModel(const std::shared_ptr<QRTImpl::PortalPrivilegeListImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::PortalPrivilegeListImpl> getImpl() const;

  signals:
    void errorOccurred(Esri::ArcGISRuntime::Error error);
    void portalPrivilegeAdded(int index);
    void portalPrivilegeRemoved(int index);

  protected:
    QHash<int, QByteArray> roleNames() const override;

  private:
    Q_DISABLE_COPY(PortalPrivilegeListModel)

    PortalPrivilegeListModel() = delete;
    void setupRoles();
    void connectSignals();

    QHash<int, QByteArray> m_roles;
    std::shared_ptr<QRTImpl::PortalPrivilegeListImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_PortalPrivilegeListModel_H
