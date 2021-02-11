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
/// \file PreplannedMapAreaListModel.h

#ifndef QRT_PreplannedMapAreaListModel_H
#define QRT_PreplannedMapAreaListModel_H

// C++ API headers
#include "Error.h"

// Qt headers
#include <QAbstractListModel>
#include <QList>
#include <QUuid>

namespace QRTImpl {
  class OfflineMapTaskImpl;
  class PreplannedMapAreaImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class PreplannedMapArea;

  class PreplannedMapAreaListModel : public QAbstractListModel
  {
    Q_OBJECT

  public:

    enum PreplannedMapAreaRoles
    {
      ItemTitleRole = Qt::UserRole + 1,
      ItemIdRole = Qt::UserRole + 2,
      ItemDescriptionRole = Qt::UserRole + 3,
      ItemThumbnailUrlRole = Qt::UserRole + 4
    };

    ~PreplannedMapAreaListModel();

    bool isEmpty() const;

    PreplannedMapArea* at(int index) const;

    bool contains(PreplannedMapArea* area) const;

    int indexOf(PreplannedMapArea* area) const;

    PreplannedMapArea* first() const;

    PreplannedMapArea* last() const;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    /*!
       \internal
     */
    explicit PreplannedMapAreaListModel(const std::shared_ptr<QRTImpl::OfflineMapTaskImpl>& taskImpl,
                                        QObject* parent = nullptr);

    /*!
       \internal
     */
    PreplannedMapAreaListModel(const std::shared_ptr<QRTImpl::OfflineMapTaskImpl>& taskImpl,
                               const QList<std::shared_ptr<QRTImpl::PreplannedMapAreaImpl>>& areas,
                               QObject* parent = nullptr);

  protected:
    QHash<int, QByteArray> roleNames() const override;

  private slots:
    void updateAreas(QUuid taskId, const QList<std::shared_ptr<QRTImpl::PreplannedMapAreaImpl>>& areas);

  private:
    Q_DISABLE_COPY(PreplannedMapAreaListModel)

    PreplannedMapAreaListModel() = delete;
    void setupRoles();

    QHash<int, QByteArray> m_roles;
    QList<std::shared_ptr<QRTImpl::PreplannedMapAreaImpl>> m_data;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_PreplannedMapAreaListModel_H
