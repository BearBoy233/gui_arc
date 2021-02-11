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
/// \file LabelDefinitionListModel.h

#ifndef QRT_LabelDefinitionListModel_H
#define QRT_LabelDefinitionListModel_H

// C++ API headers
#include "ArcGISQt_global.h"
#include "LabelDefinition.h"

// Qt headers
#include <QAbstractListModel>

namespace QRTImpl { class LabelDefinitionListImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class LabelDefinitionListModel : public QAbstractListModel
  {
    Q_OBJECT

  public:

    enum LabelDefinitionRoles
    {
      LabelDefinitionJsonRole = Qt::UserRole + 1,
    };

    ~LabelDefinitionListModel();

    bool isEmpty() const;

    void clear();

    int size() const;

    void append(LabelDefinition* labelDefinition);

    void insert(int index, LabelDefinition* labelDefinition);

    void removeAt(int index);

    void removeOne(LabelDefinition* labelDefinition);

    void move(int from, int to);

    LabelDefinition* at(int index) const;

    bool contains(LabelDefinition* labelDefinition) const;

    int indexOf(LabelDefinition* labelDefinition) const;

    LabelDefinition* first() const;

    LabelDefinition* last() const;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    bool removeRows(int row, int count, const QModelIndex& parent = QModelIndex()) override;

    /*!
       \internal
     */
    LabelDefinitionListModel(const std::shared_ptr<QRTImpl::LabelDefinitionListImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::LabelDefinitionListImpl> getImpl() const;

  signals:
    void labelDefinitionAdded(int index);
    void labelDefinitionRemoved(int index);
    void errorOccurred(Esri::ArcGISRuntime::Error error);

  protected:
    QHash<int, QByteArray> roleNames() const override;

  private:
    Q_DISABLE_COPY(LabelDefinitionListModel)

    LabelDefinitionListModel() = delete;
    void setupRoles();
    void connectSignals();

    QHash<int, QByteArray> m_roles;
    std::shared_ptr<QRTImpl::LabelDefinitionListImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_LabelDefinitionListModel_H
