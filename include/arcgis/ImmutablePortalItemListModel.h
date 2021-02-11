// COPYRIGHT 1995-2018 ESRI
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
/// \file ImmutablePortalItemListModel.h

#ifndef QRT_ImmutablePortalItemListModel_H
#define QRT_ImmutablePortalItemListModel_H

// C++ API headers
#include "Error.h"
#include "PortalItemListModel.h"

// Qt headers
#include <QAbstractListModel>
#include <QUuid>

namespace QRTImpl {
  class PortalItemListImpl;
  class PreplannedMapAreaImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class PortalItem;

  class ImmutablePortalItemListModel : public QAbstractListModel
  {
    Q_OBJECT

  public:

    virtual ~ImmutablePortalItemListModel();

    bool isEmpty() const;

    int size() const;

    PortalItem* at(int index) const;

    bool contains(PortalItem* portalItem) const;

    int indexOf(PortalItem* portalItem) const;

    PortalItem* first() const;

    PortalItem* last() const;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    /*!
       \internal
     */
    ImmutablePortalItemListModel(const std::shared_ptr<QRTImpl::PreplannedMapAreaImpl>& areaImpl,
                                 const std::shared_ptr<const QRTImpl::PortalItemListImpl>& portalItems,
                                 QObject* parent = nullptr);

    /*!
       \internal
     */
    std::shared_ptr<QRTImpl::PortalItemListImpl> getImpl() const;

  signals:
    void errorOccurred(Esri::ArcGISRuntime::Error error);

  protected:
    QHash<int, QByteArray> roleNames() const override;

  private:
    Q_DISABLE_COPY(ImmutablePortalItemListModel)

    ImmutablePortalItemListModel() = delete;
    void connectSignals();

    QHash<int, QByteArray> m_roles;
    std::shared_ptr<PortalItemListModel> m_data;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ImmutablePortalItemListModel_H
