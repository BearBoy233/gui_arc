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
/// \file BookmarkListModel.h

#ifndef QRT_BookmarkListModel_H
#define QRT_BookmarkListModel_H

// C++ API headers
#include "ArcGISQt_global.h"
#include "Bookmark.h"

// Qt headers
#include <QAbstractListModel>

namespace QRTImpl { class BookmarkListImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class BookmarkListModel : public QAbstractListModel
  {
    Q_OBJECT

  public:

    enum BookmarkRoles
    {
      BookmarkNameRole = Qt::UserRole + 1,
    };

    ~BookmarkListModel();

    bool isEmpty() const;

    void clear();

    int size() const;

    void append(Bookmark* bookmark);

    void insert(int index, Bookmark* bookmark);

    void removeAt(int index);

    void removeOne(Bookmark* bookmark);

    void move(int from, int to);

    Bookmark* at(int index) const;

    bool contains(Bookmark* bookmark) const;

    int indexOf(Bookmark* bookmark) const;

    Bookmark* first() const;

    Bookmark* last() const;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;

    bool removeRows(int row, int count, const QModelIndex& parent = QModelIndex()) override;

    /*!
       \internal
     */
    BookmarkListModel(const std::shared_ptr<QRTImpl::BookmarkListImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::BookmarkListImpl> getImpl() const;

  signals:
    void bookmarkAdded(int index);
    void bookmarkRemoved(int index);
    void errorOccurred(Esri::ArcGISRuntime::Error error);

  protected:
    QHash<int, QByteArray> roleNames() const override;

  private:
    Q_DISABLE_COPY(BookmarkListModel)

    BookmarkListModel() = delete;
    void setupRoles();
    void connectSignals();

    QHash<int, QByteArray> m_roles;
    std::shared_ptr<QRTImpl::BookmarkListImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_BookmarkListModel_H

