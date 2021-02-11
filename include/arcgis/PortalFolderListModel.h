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
/// \file PortalFolderListModel.h

#ifndef QRT_PortalFolderListModel_H
#define QRT_PortalFolderListModel_H

// C++ API headers
#include "Error.h"
#include "PortalFolder.h"

// Qt headers
#include <QAbstractListModel>

namespace QRTImpl { class PortalFolderListImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class PortalFolderListModel : public QAbstractListModel
  {
    Q_OBJECT

  public:

    enum PortalFolderRoles
    {
      PortalFolderCreatedRole = Qt::UserRole + 1, // read-only
      PortalFolderFolderIdRole = Qt::UserRole + 2, // read-only
      PortalFolderTitleRole = Qt::UserRole + 3 // read-only
    };

    virtual ~PortalFolderListModel();

    bool isEmpty() const;

    void clear();

    int size() const;

    void append(const PortalFolder& portalFolder);

    void insert(int index, const PortalFolder& portalFolder);

    void removeAt(int index);

    void removeOne(const PortalFolder& portalFolder);

    void move(int from, int to);

    PortalFolder at(int index) const;

    bool contains(const PortalFolder& portalFolder) const;

    int indexOf(const PortalFolder& portalFolder) const;

    PortalFolder first() const;

    PortalFolder last() const;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    bool removeRows(int row, int count, const QModelIndex& parent = QModelIndex()) override;

    /*!
       \internal
     */
    PortalFolderListModel(const std::shared_ptr<QRTImpl::PortalFolderListImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::PortalFolderListImpl> getImpl() const;

  signals:
    void errorOccurred(Esri::ArcGISRuntime::Error error);
    void portalFolderAdded(int index);
    void portalFolderRemoved(int index);

  protected:
    QHash<int, QByteArray> roleNames() const override;

  private:
    Q_DISABLE_COPY(PortalFolderListModel)

    PortalFolderListModel() = delete;
    void setupRoles();
    void connectSignals();

    QHash<int, QByteArray> m_roles;
    std::shared_ptr<QRTImpl::PortalFolderListImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_PortalFolderListModel_H
