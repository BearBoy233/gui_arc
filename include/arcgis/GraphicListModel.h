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
/// \file GraphicListModel.h

#ifndef QRT_GraphicListModel_H
#define QRT_GraphicListModel_H

// C++ API headers
#include "Graphic.h"

// Qt headers
#include <QAbstractListModel>

namespace QRTImpl {
  class GraphicListImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class GraphicListModel : public QAbstractListModel
  {
    Q_OBJECT

  public:

    enum GraphicRoles
    {
      GraphicSelectedRole = Qt::UserRole + 1,
      GraphicVisibleRole = Qt::UserRole + 2,
      GraphicZIndexRole = Qt::UserRole + 3,
      GraphicAttributesRole = Qt::UserRole + 4
    };

    ~GraphicListModel();

    bool isEmpty() const;

    void clear();

    int size() const;

    void append(Graphic* graphic);

    void append(const QList<Graphic*>& graphics);

    void insert(int index, Graphic* graphic);

    void removeAt(int index);

    void removeOne(Graphic* graphic);

    void move(int from, int to);

    Graphic* at(int index) const;

    bool contains(Graphic* graphic) const;

    int indexOf(Graphic* graphic) const;

    Graphic* first() const;

    Graphic* last() const;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;

    bool removeRows(int row, int count, const QModelIndex& parent = QModelIndex()) override;

    /*!
       \internal
     */
    GraphicListModel(const std::shared_ptr<QRTImpl::GraphicListImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::GraphicListImpl> getImpl() const;

  signals:
    void graphicAdded(int index);
    void graphicRemoved(int index);

  protected:
    QHash<int, QByteArray> roleNames() const override;

  private:
    Q_DISABLE_COPY(GraphicListModel)

    GraphicListModel() = delete;
    void setupRoles();

    QHash<int, QByteArray> m_roles;
    std::shared_ptr<QRTImpl::GraphicListImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_GraphicListModel_H
