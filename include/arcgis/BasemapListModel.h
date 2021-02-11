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
/// \file BasemapListModel.h

#ifndef QRT_BasemapListModel_H
#define QRT_BasemapListModel_H

// C++ API headers
#include "Error.h"

// Qt headers
#include <QAbstractListModel>

namespace QRTImpl { class BasemapListImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class Basemap;

  class BasemapListModel : public QAbstractListModel
  {
    Q_OBJECT

  public:

    enum BasemapRoles
    {
      BasemapNameRole = Qt::UserRole + 1,
      BasemapUrlRole = Qt::UserRole + 2,
      BasemapItemAccessInformationRole = Qt::UserRole + 3, // read-only
      BasemapItemCreatedRole = Qt::UserRole + 4, // read-only
      BasemapItemDescriptionRole = Qt::UserRole + 5, // read-only
      BasemapItemIdRole = Qt::UserRole + 6, // read-only
      BasemapItemTypeRole = Qt::UserRole + 7, // read-only
      BasemapItemModifiedRole = Qt::UserRole + 8, // read-only
      BasemapItemSnippetRole = Qt::UserRole + 9, // read-only
      BasemapItemTagsRole = Qt::UserRole + 10, // read-only
      BasemapItemTitleRole = Qt::UserRole + 11, // read-only
      BasemapItemThumbnailUrlRole = Qt::UserRole + 12 // read-only
    };

    virtual ~BasemapListModel();

    bool isEmpty() const;

    void clear();

    int size() const;

    void append(Basemap* basemap);

    void insert(int index, Basemap* basemap);

    void removeAt(int index);

    void removeOne(Basemap* basemap);

    void move(int from, int to);

    Basemap* at(int index) const;

    bool contains(Basemap* basemap) const;

    int indexOf(Basemap* basemap) const;

    Basemap* first() const;

    Basemap* last() const;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;

    bool removeRows(int row, int count, const QModelIndex& parent = QModelIndex()) override;

    /*!
       \internal
     */
    BasemapListModel(const std::shared_ptr<QRTImpl::BasemapListImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::BasemapListImpl> getImpl() const;

  signals:
    void errorOccurred(Esri::ArcGISRuntime::Error error);
    void basemapAdded(int index);
    void basemapRemoved(int index);

  protected:
    QHash<int, QByteArray> roleNames() const override;

  private:
    Q_DISABLE_COPY(BasemapListModel)

    BasemapListModel() = delete;
    void setupRoles();
    void connectSignals();

    QHash<int, QByteArray> m_roles;
    std::shared_ptr<QRTImpl::BasemapListImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_BasemapListModel_H
