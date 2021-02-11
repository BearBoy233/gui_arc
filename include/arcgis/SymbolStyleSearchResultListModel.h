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
/// \file SymbolStyleSearchResultListModel.h

#ifndef QRT_SymbolStyleSearchResultListModel_H
#define QRT_SymbolStyleSearchResultListModel_H

// C++ API headers
#include "SymbolStyleSearchResult.h"

// Qt headers
#include <QAbstractListModel>
#include <QList>
#include <QUrl>

namespace QRTImpl {
  class SymbolStyleSearchResultListImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class SymbolStyleSearchResultListModel : public QAbstractListModel
  {
    Q_OBJECT

  public:

    enum SymbolStyleSearchResultRoles
    {
      CategoryRole = Qt::UserRole + 1,
      KeyRole = Qt::UserRole + 2,
      NameRole = Qt::UserRole + 3,
      SymbolClassRole = Qt::UserRole + 4,
      TagsRole = Qt::UserRole + 5,
      SymbolUrlRole = Qt::UserRole + 6
    };

    ~SymbolStyleSearchResultListModel();

    bool isEmpty() const;

    int size() const;

    QList<SymbolStyleSearchResult> searchResults() const;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    /*! \internal */
    SymbolStyleSearchResultListModel(const std::shared_ptr<QRTImpl::SymbolStyleSearchResultListImpl>& impl, QObject* parent = nullptr);

  signals:
    void errorOccurred(Esri::ArcGISRuntime::Error error);

  protected:
    QHash<int, QByteArray> roleNames() const override;

  private:
    Q_DISABLE_COPY(SymbolStyleSearchResultListModel)

    SymbolStyleSearchResultListModel() = delete;

    void connectSignals();
    void setupRoles();

    QHash<int, QByteArray> m_roles;
    std::shared_ptr<QRTImpl::SymbolStyleSearchResultListImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_SymbolStyleSearchResultListModel_H
