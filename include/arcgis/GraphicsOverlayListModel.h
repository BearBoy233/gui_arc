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
/// \file GraphicsOverlaysListModel.h

#ifndef QRT_GraphicsOverlaysListModel_H
#define QRT_GraphicsOverlaysListModel_H

// C++ API headers
#include "GraphicsOverlay.h"

// Qt headers
#include <QAbstractListModel>

namespace QRTImpl {
  class GraphicsOverlayListImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class GraphicsOverlayListModel : public QAbstractListModel
  {
    Q_OBJECT

  public:

    enum GraphicsOverlayRoles
    {
      GraphicsOverlayMinScaleRole = Qt::UserRole + 1,
      GraphicsOverlayMaxScaleRole = Qt::UserRole + 2,
      GraphicsOverlayOpacityRole = Qt::UserRole + 3,
      GraphicsOverlayVisibleRole = Qt::UserRole + 4,
      GraphicsOverlaySelectionColorRole = Qt::UserRole + 5,
      GraphicsOverlayIdRole = Qt::UserRole + 6
    };

    ~GraphicsOverlayListModel();

    bool isEmpty() const;

    void clear();

    int size() const;

    void append(GraphicsOverlay* graphicsOverlay);

    void insert(int index, GraphicsOverlay* graphicsOverlay);

    void removeAt(int index);

    void removeOne(GraphicsOverlay* graphicsOverlay);

    void move(int from, int to);

    GraphicsOverlay* at(int index) const;

    bool contains(GraphicsOverlay* graphicsOverlay) const;

    int indexOf(GraphicsOverlay* graphicsOverlay) const;

    GraphicsOverlay* first() const;

    GraphicsOverlay* last() const;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;

    bool removeRows(int row, int count, const QModelIndex& parent = QModelIndex()) override;

    /*!
     \internal
     */
    GraphicsOverlayListModel(const std::shared_ptr<QRTImpl::GraphicsOverlayListImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::GraphicsOverlayListImpl> getImpl() const;

  signals:
    void graphicsOverlayAdded(int index);
    void graphicsOverlayRemoved(int index);

  protected:
    QHash<int, QByteArray> roleNames() const override;

  private:
    Q_DISABLE_COPY(GraphicsOverlayListModel)

    GraphicsOverlayListModel() = delete;
    void setupRoles();

    QHash<int, QByteArray> m_roles;
    std::shared_ptr<QRTImpl::GraphicsOverlayListImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_GraphicsOverlaysListModel_H
