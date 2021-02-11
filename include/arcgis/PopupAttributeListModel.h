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
/// \file PopupAttributeListModel.h

#ifndef QRT_PopupAttributeListModel_H
#define QRT_PopupAttributeListModel_H

// C++ API headers
#include "Error.h"
#include "PopupField.h"

// Qt headers
#include <QAbstractListModel>

// STL headers
#include <memory>

namespace QRTImpl
{
  class PopupFieldImpl;
  class PopupManagerImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class PopupAttributeListModel : public QAbstractListModel
  {
    Q_OBJECT

    Q_PROPERTY(int count READ rowCount CONSTANT)

  public:

    enum PopupAttributeRoles
    {
      PopupAttributeFieldNameRole = Qt::UserRole + 1,
      PopupAttributeFieldValueRole = Qt::UserRole + 2,
      PopupAttributePopupDateFormatRole = Qt::UserRole + 3,
      PopupAttributeDecimalPlacesRole = Qt::UserRole + 4,
      PopupAttributeIsUseThousandsSeparatorRole = Qt::UserRole + 5,
      PopupAttributeIsEditableRole = Qt::UserRole + 6,
      PopupAttributeIsVisibleRole = Qt::UserRole + 7,
      PopupAttributeIsNullableRole = Qt::UserRole + 8,
      PopupAttributeLabelRole = Qt::UserRole + 9,
      PopupAttributePopupStringFieldOptionRole = Qt::UserRole + 10,
      PopupAttributeTooltipRole = Qt::UserRole + 11,
      PopupAttributeFormattedValueRole = Qt::UserRole + 12,
      PopupAttributeFieldTypeRole = Qt::UserRole + 13,
      PopupAttributeMaxLengthRole = Qt::UserRole + 14,
      PopupAttributeIsFeatureTypeRole = Qt::UserRole + 15,
      PopupAttributeValidationErrorTextRole = Qt::UserRole + 16,
      PopupAttributeRangeDomainValidationTextRole = Qt::UserRole + 17,
      PopupAttributeUseThousandsSeparatorRole = Qt::UserRole + 18,
      PopupAttributeEditableRole = Qt::UserRole + 19,
      PopupAttributeAttributeVisibleRole = Qt::UserRole + 20,
      PopupAttributeNullableRole = Qt::UserRole + 21,
      PopupAttributeFeatureTypeRole = Qt::UserRole + 22
    };

    ~PopupAttributeListModel();

    QList<PopupField*> popupFields() const;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;

    /*!
       \internal
     */
    PopupAttributeListModel(const QList<std::shared_ptr<QRTImpl::PopupFieldImpl>>& popupFields,
                            const std::shared_ptr<QRTImpl::PopupManagerImpl>& popupManager,
                            QObject* parent = nullptr);

  signals:
    void errorOccurred(Esri::ArcGISRuntime::Error error);

  protected:
    /*!
       \internal
     */
    QHash<int, QByteArray> roleNames() const override;

  private:
    Q_DISABLE_COPY(PopupAttributeListModel)

    PopupAttributeListModel() = delete;

    void setupRoles();

    QList<std::shared_ptr<QRTImpl::PopupFieldImpl>> m_popupFields;
    std::weak_ptr<QRTImpl::PopupManagerImpl> m_popupManager;

    QHash<int, QByteArray> m_roles;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_PopupAttributeListModel_H
