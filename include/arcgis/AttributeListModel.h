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
/// \file AttributeListModel.h

#ifndef QRT_AttributeListModel_H
#define QRT_AttributeListModel_H

// C++ API headers
#include "Error.h"

// Qt headers
#include <QAbstractListModel>

// STL headers
#include <memory>

namespace QRTImpl { class AttributeListImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class AttributeListModel : public QAbstractListModel
  {
    Q_OBJECT

  public:

    enum AttributeRoles
    {
      AttributeNameRole = Qt::UserRole + 1,
      AttributeValueRole = Qt::UserRole + 2
    };

    ~AttributeListModel();

    bool operator==(AttributeListModel* other) const;
    QVariant operator[](const QString& attributeName) const;
    AttributeListModel& operator+=(const QPair<QString, QVariant>& attribute);
    AttributeListModel& operator<<(const QPair<QString, QVariant>& attribute);

    bool isEmpty() const;
    int size() const;

    QStringList attributeNames() const;
    QVariant attributeValue(const QString& attributeName) const;
    bool containsAttribute(const QString& attributeName) const;
    void insertAttribute(const QString& attributeName, const QVariant& attributeValue);
    void removeAttribute(const QString& attributeName);
    void removeAllAttributes();
    void replaceAttribute(const QString& attributeName, const QVariant& attributeValue);

    QVariantMap attributesMap() const;
    void setAttributesMap(const QVariantMap& attributes);

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;

    bool removeRows(int row, int count, const QModelIndex& parent = QModelIndex()) override;

    /*! \internal */
    AttributeListModel(const std::shared_ptr<QRTImpl::AttributeListImpl>& impl, QObject* parent = nullptr);

  signals:
    void errorOccurred(Esri::ArcGISRuntime::Error error);

  protected:
    QHash<int, QByteArray> roleNames() const override;

  private:
    Q_DISABLE_COPY(AttributeListModel)

    /*! \internal */
    AttributeListModel() = delete;

    void connectSignals();
    void setupRoles();

    std::shared_ptr<QRTImpl::AttributeListImpl> m_impl;

    QHash<int, QByteArray> m_roles;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_AttributeListModel_H
