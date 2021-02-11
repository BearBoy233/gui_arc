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
/// \file PortalItemCommentListModel.h

#ifndef QRT_PortalItemCommentListModel_H
#define QRT_PortalItemCommentListModel_H

// C++ API headers
#include "Error.h"

// Qt headers
#include <QAbstractListModel>

namespace QRTImpl { class PortalItemCommentListImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class PortalItemComment;

  class PortalItemCommentListModel : public QAbstractListModel
  {
    Q_OBJECT

  public:

    enum PortalItemCommentRoles
    {
      PortalItemCommentCommentRole = Qt::UserRole + 1, // read-only
      PortalItemCommentCommentIdRole = Qt::UserRole + 2, // read-only
      PortalItemCommentCreatedRole = Qt::UserRole + 3, // read-only
      PortalItemCommentOwnerRole = Qt::UserRole + 4  // read-only
    };

    virtual ~PortalItemCommentListModel();

    bool isEmpty() const;

    void clear();

    int size() const;

    void append(PortalItemComment* portalItemComment);

    void insert(int index, PortalItemComment* portalItemComment);

    void removeAt(int index);

    void removeOne(PortalItemComment* portalItemComment);

    void move(int from, int to);

    PortalItemComment* at(int index) const;

    bool contains(PortalItemComment* portalItemComment) const;

    int indexOf(PortalItemComment* portalItemComment) const;

    PortalItemComment* first() const;

    PortalItemComment* last() const;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    bool removeRows(int row, int count, const QModelIndex& parent = QModelIndex()) override;

    /*!
       \internal
     */
    PortalItemCommentListModel(const std::shared_ptr<QRTImpl::PortalItemCommentListImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::PortalItemCommentListImpl> getImpl() const;

  signals:
    void errorOccurred(Esri::ArcGISRuntime::Error error);
    void portalItemCommentAdded(int index);
    void portalItemCommentRemoved(int index);

  protected:
    QHash<int, QByteArray> roleNames() const override;

  private:
    Q_DISABLE_COPY(PortalItemCommentListModel)

    PortalItemCommentListModel() = delete;
    void setupRoles();
    void connectSignals();

    QHash<int, QByteArray> m_roles;
    std::shared_ptr<QRTImpl::PortalItemCommentListImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_PortalItemCommentListModel_H
