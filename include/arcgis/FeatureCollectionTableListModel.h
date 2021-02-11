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
/// \file FeatureCollectionTableListModel.h

#ifndef QRT_FeatureCollectionTableListModel_H
#define QRT_FeatureCollectionTableListModel_H

// C++ API headers
#include "ArcGISQt_global.h"
#include "FeatureCollectionTable.h"

// Qt headers
#include <QAbstractListModel>

namespace QRTImpl { class FeatureCollectionTableListImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class FeatureCollectionTableListModel : public QAbstractListModel
  {
    Q_OBJECT

  public:

    enum FeatureCollectionTableRoles
    {
      FeatureCollectionTableTitleRole = Qt::UserRole + 1
    };

    ~FeatureCollectionTableListModel();

    bool isEmpty() const;

    void clear();

    int size() const;

    void append(FeatureCollectionTable* featureCollectionTable);

    void insert(int index, FeatureCollectionTable* featureCollectionTable);

    void removeAt(int index);

    void removeOne(FeatureCollectionTable* featureCollectionTable);

    void move(int from, int to);

    FeatureCollectionTable* at(int index) const;

    bool contains(FeatureCollectionTable* featureCollectionTable) const;

    int indexOf(FeatureCollectionTable* featureCollectionTable) const;

    FeatureCollectionTable* first() const;

    FeatureCollectionTable* last() const;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;

    bool removeRows(int row, int count, const QModelIndex& parent = QModelIndex()) override;

    /*!
       \internal
     */
    FeatureCollectionTableListModel(const std::shared_ptr<QRTImpl::FeatureCollectionTableListImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::FeatureCollectionTableListImpl> getImpl() const;

  signals:
    void featureCollectionTableAdded(int index);
    void featureCollectionTableRemoved(int index);
    void errorOccurred(Esri::ArcGISRuntime::Error error);

  protected:
    QHash<int, QByteArray> roleNames() const override;

  private:
    Q_DISABLE_COPY(FeatureCollectionTableListModel)

    FeatureCollectionTableListModel() = delete;
    void setupRoles();
    void connectSignals();

    QHash<int, QByteArray> m_roles;
    std::shared_ptr<QRTImpl::FeatureCollectionTableListImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_FeatureCollectionTableListModel_H
