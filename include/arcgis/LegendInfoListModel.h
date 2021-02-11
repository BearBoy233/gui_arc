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
/// \file LegendInfoListModel.h

#ifndef QRT_LegendInfoListModel_H
#define QRT_LegendInfoListModel_H

// C++ API headers
#include "LegendInfo.h"
#include "TaskWatcher.h"

// Qt headers
#include <QAbstractListModel>

namespace QRTImpl {
  class LegendInfoListImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class LegendInfoListModel : public QAbstractListModel
  {
    Q_OBJECT

  public:

    enum LegendInfoRoles
    {
      LegendInfoNameRole = Qt::DisplayRole,
      LegendInfoSymbolUrlRole = Qt::UserRole + 1,
      LegendInfoSymbolWidthRole = Qt::UserRole + 2,
      LegendInfoSymbolHeightRole = Qt::UserRole + 3,
      LegendInfoLayerNameRole = Qt::UserRole + 4,
      LegendInfoLayerMinScaleRole = Qt::UserRole + 5,
      LegendInfoLayerMaxScaleRole = Qt::UserRole + 6
    };

    ~LegendInfoListModel();

    bool isEmpty() const;
    void clear();
    int size() const;
    LegendInfo* at(int index) const;

    TaskWatcher fetchLegendInfos(bool recursive = true);

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    LegendInfoListModel(const std::shared_ptr<QRTImpl::LegendInfoListImpl>& impl, QObject* parent = nullptr);

  signals:
    void fetchLegendInfosCompleted();
    void errorOccurred(Esri::ArcGISRuntime::Error error);

  protected:
    QHash<int, QByteArray> roleNames() const override;

  private:
    Q_DISABLE_COPY(LegendInfoListModel)

    LegendInfoListModel() = delete;

    void connectSignals();
    void setupRoles();

    QHash<int, QByteArray> m_roles;

    std::shared_ptr<QRTImpl::LegendInfoListImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_LegendInfoListModel_H
