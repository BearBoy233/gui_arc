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
/// \file DistanceCompositeSceneSymbol.h

#ifndef QRT_DistanceCompositeSceneSymbol_H
#define QRT_DistanceCompositeSceneSymbol_H

// C++ API headers
#include "Symbol.h"

// Qt headers
#include <QAbstractListModel>

namespace QRTImpl {
  class DistanceCompositeSceneSymbolImpl;
  class DistanceSymbolRangeListImpl;
  class DistanceSymbolRangeImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class DistanceSymbolRange : public Object
  {
    Q_OBJECT

  public:
    DistanceSymbolRange(QObject* parent = nullptr);
    DistanceSymbolRange(Symbol* symbol, QObject* parent = nullptr);
    DistanceSymbolRange(Symbol* symbol, double minDistance, double maxDistance, QObject* parent = nullptr);
    ~DistanceSymbolRange();

    double maxDistance() const;
    void setMaxDistance(double maxDistance);

    double minDistance() const;
    void setMinDistance(double minDistance);

    Symbol* symbol() const;
    void setSymbol(Symbol* symbol);

    /*!
      \internal
     */
    DistanceSymbolRange(const std::shared_ptr<QRTImpl::DistanceSymbolRangeImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::DistanceSymbolRangeImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(DistanceSymbolRange)

    std::shared_ptr<QRTImpl::DistanceSymbolRangeImpl> m_impl;
  };

  class DistanceSymbolRangeListModel : public QAbstractListModel
  {
    Q_OBJECT

  public:

    enum DistanceSymbolRangeRoles
    {
      DistanceSymbolRangeMaxDistanceRole = Qt::UserRole + 1,
      DistanceSymbolRangeMinDistanceRole = Qt::UserRole + 2,
      DistanceSymbolRangeSymbolRole = Qt::UserRole + 3
    };

    ~DistanceSymbolRangeListModel();

    bool isEmpty() const;

    void clear();

    int size() const;

    void append(DistanceSymbolRange* distanceSymbolRange);

    void insert(int index, DistanceSymbolRange* distanceSymbolRange);

    void removeAt(int index);

    void removeOne(DistanceSymbolRange* distanceSymbolRange);

    void move(int from, int to);

    DistanceSymbolRange* at(int index) const;

    bool contains(DistanceSymbolRange* distanceSymbolRange) const;

    int indexOf(DistanceSymbolRange* distanceSymbolRange) const;

    DistanceSymbolRange* first() const;

    DistanceSymbolRange* last() const;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;

    bool removeRows(int row, int count, const QModelIndex& parent = QModelIndex()) override;

    /*!
      \internal
     */
    DistanceSymbolRangeListModel(const std::shared_ptr<QRTImpl::DistanceSymbolRangeListImpl>& impl, QObject* parent = nullptr);
    /*!
      \internal
     */
    std::shared_ptr<QRTImpl::DistanceSymbolRangeListImpl> getImpl() const;

  signals:
    void distanceSymbolRangeAdded(int index);
    void distanceSymbolRangeRemoved(int index);
    void errorOccurred(Esri::ArcGISRuntime::Error error);

/*!
  \internal
 */
  protected:
    QHash<int, QByteArray> roleNames() const override;

  private:
    Q_DISABLE_COPY(DistanceSymbolRangeListModel)

    DistanceSymbolRangeListModel() = delete;
    void setupRoles();
    void connectSignals();

    QHash<int, QByteArray> m_roles;
    std::shared_ptr<QRTImpl::DistanceSymbolRangeListImpl> m_impl;
  };

  class DistanceCompositeSceneSymbol : public Symbol
  {
    Q_OBJECT

  public:
    explicit DistanceCompositeSceneSymbol(QObject* parent = nullptr);
    ~DistanceCompositeSceneSymbol();

    DistanceSymbolRangeListModel* ranges() const;

    /*!
      \internal
     */
    explicit DistanceCompositeSceneSymbol(const std::shared_ptr<QRTImpl::DistanceCompositeSceneSymbolImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::DistanceCompositeSceneSymbolImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(DistanceCompositeSceneSymbol)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_DistanceCompositeSceneSymbol_H
