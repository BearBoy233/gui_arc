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
/// \file PortalItemListModel.h

#ifndef QRT_PortalItemListModel_H
#define QRT_PortalItemListModel_H

// C++ API headers
#include "Error.h"

// Qt headers
#include <QAbstractListModel>

namespace QRTImpl { class PortalItemListImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class PortalItem;

  class PortalItemListModel : public QAbstractListModel
  {
    Q_OBJECT

  public:

    enum PortalItemRoles
    {
      PortalItemUrlRole = Qt::UserRole + 1, // read-only
      PortalItemItemIdRole = Qt::UserRole + 2, // read-only
      PortalItemAccessRole = Qt::UserRole + 3, // read-only
      PortalItemAccessAndUseConstraintsHtmlRole = Qt::UserRole + 4, // read-only
      PortalItemAverageRatingRole = Qt::UserRole + 5, // read-only
      PortalItemCommentCountRole = Qt::UserRole + 6, // read-only
      PortalItemCommentsEnabledRole = Qt::UserRole + 7, // read-only
      PortalItemCultureRole = Qt::UserRole + 8, // read-only
      PortalItemFolderIdRole = Qt::UserRole + 9, // read-only
      PortalItemNameRole = Qt::UserRole + 10, // read-only
      PortalItemOwnerRole = Qt::UserRole + 11, // read-only
      PortalItemRatingCountRole = Qt::UserRole + 12, // read-only
      PortalItemServiceUrlRole = Qt::UserRole + 13, // read-only
      PortalItemSizeRole = Qt::UserRole + 14, // read-only
      PortalItemTypeRole = Qt::UserRole + 15, // read-only
      PortalItemTypeKeywordsRole = Qt::UserRole + 16,
      PortalItemTypeNameRole = Qt::UserRole + 17, // read-only
      PortalItemViewCountRole = Qt::UserRole + 18, // read-only
      PortalItemDescriptionRole = Qt::UserRole + 19, // read-only
      PortalItemExtentRole = Qt::UserRole + 20, // read-only
      PortalItemSnippetRole = Qt::UserRole + 21, // read-only
      PortalItemTitleRole = Qt::UserRole + 22, // read-only
      PortalItemAccessInformationRole = Qt::UserRole + 23, // read-only
      PortalItemTagsRole = Qt::UserRole + 24, // read-only
      PortalItemCreatedRole = Qt::UserRole + 25, // read-only
      PortalItemModifiedRole = Qt::UserRole + 26, // read-only
      PortalItemSpatialReferenceRole = Qt::UserRole + 27, // read-only
      PortalItemThumbnailUrlRole = Qt::UserRole + 28 // read-only
    };

    virtual ~PortalItemListModel();

    bool isEmpty() const;

    void clear();

    int size() const;

    void append(PortalItem* portalItem);

    void insert(int index, PortalItem* portalItem);

    void removeAt(int index);

    void removeOne(PortalItem* portalItem);

    void move(int from, int to);

    PortalItem* at(int index) const;

    bool contains(PortalItem* portalItem) const;

    int indexOf(PortalItem* portalItem) const;

    PortalItem* first() const;

    PortalItem* last() const;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    bool removeRows(int row, int count, const QModelIndex& parent = QModelIndex()) override;

    /*!
       \internal
     */
    PortalItemListModel(const std::shared_ptr<QRTImpl::PortalItemListImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::PortalItemListImpl> getImpl() const;

  signals:
    void errorOccurred(Esri::ArcGISRuntime::Error error);
    void portalItemAdded(int index);
    void portalItemRemoved(int index);

  protected:
    QHash<int, QByteArray> roleNames() const override;

  private:
    friend class ImmutablePortalItemListModel;
    Q_DISABLE_COPY(PortalItemListModel)

    PortalItemListModel() = delete;
    void setupRoles();
    void connectSignals();
    void updatePortalItems(const std::shared_ptr<const QRTImpl::PortalItemListImpl>& portalItems);

    QHash<int, QByteArray> m_roles;
    std::shared_ptr<QRTImpl::PortalItemListImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_PortalItemListModel_H
