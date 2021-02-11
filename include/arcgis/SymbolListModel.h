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
/// \file SymbolListModel.h

#ifndef QRT_SymbolListModel_H
#define QRT_SymbolListModel_H

// C++ API headers
#include "ArcGISQt_global.h"
#include "Symbol.h"

// Qt headers
#include <QAbstractListModel>

namespace QRTImpl { class SymbolListImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class SymbolListModel : public QAbstractListModel
  {
    Q_OBJECT

  public:

    enum SymbolRoles
    {
      SymbolUrlRole = Qt::UserRole + 1,
    };

    ~SymbolListModel();

    bool isEmpty() const;

    void clear();

    int size() const;

    void append(Symbol* symbol);

    void insert(int index, Symbol* symbol);

    void removeAt(int index);

    void removeOne(Symbol* symbol);

    void move(int from, int to);

    Symbol* at(int index) const;

    bool contains(Symbol* symbol) const;

    int indexOf(Symbol* symbol) const;

    Symbol* first() const;

    Symbol* last() const;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    bool removeRows(int row, int count, const QModelIndex& parent = QModelIndex()) override;

    /*!
       \internal
     */
    SymbolListModel(const std::shared_ptr<QRTImpl::SymbolListImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::SymbolListImpl> getImpl() const;

  signals:
    void symbolAdded(int index);
    void symbolRemoved(int index);
    void errorOccurred(Esri::ArcGISRuntime::Error error);

  protected:
    QHash<int, QByteArray> roleNames() const override;

  private:
    Q_DISABLE_COPY(SymbolListModel)

    SymbolListModel() = delete;
    void setupRoles();
    void connectSignals();

    QHash<int, QByteArray> m_roles;
    std::shared_ptr<QRTImpl::SymbolListImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_SymbolListModel_H
