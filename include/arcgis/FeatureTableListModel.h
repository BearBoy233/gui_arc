// COPYRIGHT 1995-2017 ESRI
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
/// \file FeatureTableListModel.h

#ifndef QRT_FeatureTableListModel_H
#define QRT_FeatureTableListModel_H

// C++ API headers
#include "ArcGISQt_global.h"
#include "Error.h"

// Qt headers
#include <QAbstractListModel>

// STL headers
#include <memory>

namespace QRTImpl { class FeatureTableListImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class FeatureTable;
  class FeatureTableListModel : public QAbstractListModel
  {
    Q_OBJECT

  public:

    enum FeatureTableRoles
    {
      NameRole = Qt::UserRole + 1, // read-only
      GeometryTypeRole = Qt::UserRole + 2, // read-only
      HasGeometryRole = Qt::UserRole + 3, // read-only
      EditableRole = Qt::UserRole + 4, // read-only
      NumberOfFeaturesRole = Qt::UserRole + 5, // read-only
      LoadErrorRole = Qt::UserRole + 6, // read-only
      LoadStatusRole = Qt::UserRole + 7 // read-only
    };

    ~FeatureTableListModel();

    bool isEmpty() const;

    void clear();

    int size() const;

    void append(FeatureTable* featureTable);

    void insert(int index, FeatureTable* featureTable);

    void removeAt(int index);

    void removeOne(FeatureTable* featureTable);

    void move(int from, int to);

    FeatureTable* at(int index) const;

    bool contains(FeatureTable* featureTable) const;

    int indexOf(FeatureTable* featureTable) const;

    FeatureTable* first() const;

    FeatureTable* last() const;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    bool removeRows(int row, int count, const QModelIndex& parent = QModelIndex()) override;

    /*!
       \internal
     */
    FeatureTableListModel(const std::shared_ptr<QRTImpl::FeatureTableListImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::FeatureTableListImpl> getImpl() const;

  signals:
    void featureTableAdded(int index);
    void featureTableRemoved(int index);
    void errorOccurred(Esri::ArcGISRuntime::Error error);

  protected:
    QHash<int, QByteArray> roleNames() const override;

  private:
    Q_DISABLE_COPY(FeatureTableListModel)

    FeatureTableListModel() = delete;
    void setupRoles();
    void connectSignals();

    QHash<int, QByteArray> m_roles;
    std::shared_ptr<QRTImpl::FeatureTableListImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_FeatureTableListModel_H
