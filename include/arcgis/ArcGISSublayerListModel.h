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
/// \file ArcGISSublayerListModel.h

#ifndef QRT_ArcGISSublayerListModel_H
#define QRT_ArcGISSublayerListModel_H

// C++ API headers
#include "ArcGISQt_global.h"
#include "ArcGISSublayer.h"

// Qt headers
#include <QAbstractListModel>

namespace QRTImpl { class ArcGISSublayerListImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class ArcGISSublayerListModel : public QAbstractListModel
  {
    Q_OBJECT

  public:

      enum SublayerRoles
      {
        SublayerNameRole = Qt::UserRole + 1,
        SublayerIdRole = Qt::UserRole + 2,
        SublayerMinScaleRole = Qt::UserRole + 3,
        SublayerMaxScaleRole = Qt::UserRole + 4,
        SublayerTypeRole = Qt::UserRole + 5,
        SublayerCanChangeVisibilityRole = Qt::UserRole + 6,
        SublayerVisibleRole = Qt::UserRole + 7,
        SublayerShowInLegendRole = Qt::UserRole + 8,
        SublayerDefinitionExpressionRole = Qt::UserRole + 9,
        SublayerOpacityRole = Qt::UserRole + 10,
        SublayerScaleSymbolsRole = Qt::UserRole + 11,
        SublayerLabelsEnabledRole = Qt::UserRole + 12
      };

    ~ArcGISSublayerListModel();

    bool isEmpty() const;

    void clear();

    int size() const;

    void append(ArcGISSublayer* sublayer);

    void insert(int index, ArcGISSublayer* sublayer);

    void removeAt(int index);

    void removeOne(ArcGISSublayer* sublayer);

    void move(int from, int to);

    ArcGISSublayer* at(int index) const;

    bool contains(ArcGISSublayer* sublayer) const;

    int indexOf(ArcGISSublayer* sublayer) const;

    ArcGISSublayer* first() const;

    ArcGISSublayer* last() const;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;

    bool removeRows(int row, int count, const QModelIndex& parent = QModelIndex()) override;

    /*!
       \internal
     */
    ArcGISSublayerListModel(const std::shared_ptr<QRTImpl::ArcGISSublayerListImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::ArcGISSublayerListImpl> getImpl() const;

  signals:
    void sublayerAdded(int index);
    void sublayerRemoved(int index);
    void errorOccurred(Esri::ArcGISRuntime::Error error);

/*!
   \internal
 */
  protected:
    QHash<int, QByteArray> roleNames() const override;

  private:
    Q_DISABLE_COPY(ArcGISSublayerListModel)

    ArcGISSublayerListModel() = delete;
    void setupRoles();
    void connectSignals();

    QHash<int, QByteArray> m_roles;
    std::shared_ptr<QRTImpl::ArcGISSublayerListImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ArcGISSublayerListModel_H

