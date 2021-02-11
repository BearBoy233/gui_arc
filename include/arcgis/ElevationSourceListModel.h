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
/// \file ElevationSourceListModel.h

#ifndef QRT_ElevationSourceListModel_H
#define QRT_ElevationSourceListModel_H

// C++ API headers
#include "ArcGISQt_global.h"
#include "ElevationSource.h"

// Qt headers
#include <QAbstractListModel>

namespace QRTImpl { class ElevationSourceListImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class ElevationSourceListModel : public QAbstractListModel
  {
    Q_OBJECT

  public:

    enum ElevationSourceRoles
    {
      ElevationSourceNameRole = Qt::UserRole + 1,
      ElevationSourceEnabledRole = Qt::UserRole + 2,
      ElevationSourceTypeRole = Qt::UserRole + 3
    };

    ~ElevationSourceListModel();

    bool isEmpty() const;

    void clear();

    int size() const;

    void append(ElevationSource* elevationSource);

    void insert(int index, ElevationSource* elevationSource);

    void removeAt(int index);

    void removeOne(ElevationSource* elevationSource);

    void move(int from, int to);

    ElevationSource* at(int index) const;

    bool contains(ElevationSource* elevationSource) const;

    int indexOf(ElevationSource* elevationSource) const;

    ElevationSource* first() const;

    ElevationSource* last() const;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;

    bool removeRows(int row, int count, const QModelIndex& parent = QModelIndex()) override;

    /*!
       \internal
     */
    ElevationSourceListModel(const std::shared_ptr<QRTImpl::ElevationSourceListImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::ElevationSourceListImpl> getImpl() const;

  signals:
    void elevationSourceAdded(int index);
    void elevationSourceRemoved(int index);
    void errorOccurred(Esri::ArcGISRuntime::Error error);

  protected:
    QHash<int, QByteArray> roleNames() const override;

  private:
    Q_DISABLE_COPY(ElevationSourceListModel)

    ElevationSourceListModel() = delete;
    void setupRoles();
    void connectSignals();

    QHash<int, QByteArray> m_roles;
    std::shared_ptr<QRTImpl::ElevationSourceListImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ElevationSourceListModel_H
