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
/// \file DirectionManeuverListModel.h

#ifndef QRT_DirectionManeuverListModel_H
#define QRT_DirectionManeuverListModel_H

// C++ API headers
#include "ArcGISQt_global.h"
#include "DirectionManeuver.h"

// Qt headers
#include <QAbstractListModel>

// STL headers
#include <memory>

namespace QRTImpl { class DirectionManeuverImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class DirectionManeuverListModel : public QAbstractListModel
  {
    Q_OBJECT

  public:

    enum DirectionManeuverRoles
    {
      DirectionManeuverTypeRole = Qt::UserRole + 1,
      DirectionTextRole = Qt::UserRole + 2,
      DurationRole = Qt::UserRole + 3,
      EstimatedArrivalTimeRole = Qt::UserRole + 4,
      EstimatedArrivalTimeShiftRole = Qt::UserRole + 5,
      GeometryRole = Qt::UserRole + 6,
      LengthRole = Qt::UserRole + 7
    };

    ~DirectionManeuverListModel();

    QList<DirectionManeuver> directionManeuvers() const;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    /*! \internal */
    explicit DirectionManeuverListModel(const QList<std::shared_ptr<QRTImpl::DirectionManeuverImpl>>& directionManeuvers, QObject* parent = nullptr);

  protected:
    /*! \internal */
    QHash<int, QByteArray> roleNames() const override;

  private:
    /*! \internal */
    Q_DISABLE_COPY(DirectionManeuverListModel)

    DirectionManeuverListModel() = delete;

    void setupRoles();

    QList<DirectionManeuver> m_directionManeuvers;
    QHash<int, QByteArray> m_roles;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_DirectionManeuverListModel_H
