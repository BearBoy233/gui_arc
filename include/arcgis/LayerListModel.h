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
/// \file LayerListModel.h

#ifndef QRT_LayerListModel_H
#define QRT_LayerListModel_H

// C++ API headers
#include "ArcGISQt_global.h"
#include "Layer.h"

// Qt headers
#include <QAbstractListModel>

namespace QRTImpl { class LayerListImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class LayerListModel : public QAbstractListModel
  {
    Q_OBJECT

  public:

    enum LayerRoles
    {
      LayerNameRole = Qt::UserRole + 1,
      LayerDescriptionRole = Qt::UserRole + 2,
      LayerVisibleRole = Qt::UserRole + 3,
      LayerCanChangeVisibility = Qt::UserRole + 4,
      LayerLoadErrorRole = Qt::UserRole + 5,
      LayerLoadStatusRole = Qt::UserRole + 6,
      LayerTypeRole = Qt::UserRole + 7,
      LayerAttributionRole = Qt::UserRole + 8,
      LayerShowInLegendRole = Qt::UserRole + 9,
      LayerIdRole = Qt::UserRole + 10,
      LayerMinScaleRole = Qt::UserRole + 11,
      LayerMaxScaleRole = Qt::UserRole + 12,
      LayerOpacityRole = Qt::UserRole + 13
    };

    ~LayerListModel();

    bool isEmpty() const;

    void clear();

    int size() const;

    void append(Layer* layer);

    void insert(int index, Layer* layer);

    void removeAt(int index);

    void removeOne(Layer* layer);

    void move(int from, int to);

    Layer* at(int index) const;

    bool contains(Layer* layer) const;

    int indexOf(Layer* layer) const;

    Layer* first() const;

    Layer* last() const;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;

    bool removeRows(int row, int count, const QModelIndex& parent = QModelIndex()) override;

    /*!
       \internal
     */
    LayerListModel(const std::shared_ptr<QRTImpl::LayerListImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::LayerListImpl> getImpl() const;

  signals:
    void layerAdded(int index);
    void layerRemoved(int index);
    void errorOccurred(Esri::ArcGISRuntime::Error error);

  protected:
    QHash<int, QByteArray> roleNames() const override;

  private:
    Q_DISABLE_COPY(LayerListModel)

    LayerListModel() = delete;
    void setupRoles();
    void connectSignals();

    QHash<int, QByteArray> m_roles;
    std::shared_ptr<QRTImpl::LayerListImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_LayerListModel_H

