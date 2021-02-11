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
/// \file UniqueValueRenderer.h

#ifndef QRT_UniqueValueRenderer_H
#define QRT_UniqueValueRenderer_H

// C++ API headers
#include "Renderer.h"

// Qt headers
#include <QAbstractListModel>

namespace QRTImpl {
  class UniqueValueImpl;
  class UniqueValueRendererImpl;
  class UniqueValueListImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class UniqueValue : public Object, public JsonSerializable
  {
    Q_OBJECT

  public:
    explicit UniqueValue(QObject* parent = nullptr);
    UniqueValue(const QString& label, const QString& description, const QVariantList& values, Symbol* symbol, QObject* parent = nullptr);
    ~UniqueValue();

    bool operator ==(const UniqueValue* other) const;

    QString description() const;
    void setDescription(const QString& description);

    QString label() const;
    void setLabel(const QString& label);

    Symbol* symbol() const;
    void setSymbol(Symbol* symbol);

    QVariantList values() const;
    void setValues(const QVariantList& values);

    UniqueValue* clone(QObject* parent = nullptr) const;

    static UniqueValue* fromJson(const QString& json, QObject* parent = nullptr);
    QString toJson() const override;
    QJsonObject unknownJson() const override;
    QJsonObject unsupportedJson() const override;

    UniqueValue(const std::shared_ptr<QRTImpl::UniqueValueImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::UniqueValueImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(UniqueValue)

    std::shared_ptr<QRTImpl::UniqueValueImpl> m_impl;
  };

  class UniqueValueListModel : public QAbstractListModel
  {
    Q_OBJECT

  public:

    enum UniqueValueRoles
    {
      UniqueValueDescriptionRole = Qt::UserRole + 1,
      UniqueValueLabelRole = Qt::UserRole + 2,
      UniqueValueValuesRole = Qt::UserRole + 3
    };

    ~UniqueValueListModel();

    bool isEmpty() const;

    void clear();

    int size() const;

    void append(UniqueValue* uniqueValue);

    void insert(int index, UniqueValue* uniqueValue);

    void removeAt(int index);

    void removeOne(UniqueValue* uniqueValue);

    void move(int from, int to);

    UniqueValue* at(int index) const;

    bool contains(UniqueValue* uniqueValue) const;

    int indexOf(UniqueValue* uniqueValue) const;

    UniqueValue* first() const;

    UniqueValue* last() const;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;

    bool removeRows(int row, int count, const QModelIndex& parent = QModelIndex()) override;

    UniqueValueListModel(const std::shared_ptr<QRTImpl::UniqueValueListImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::UniqueValueListImpl> getImpl() const;

  signals:
    void uniqueValueAdded(int index);
    void uniqueValueRemoved(int index);
    void errorOccurred(Esri::ArcGISRuntime::Error error);

  protected:
    QHash<int, QByteArray> roleNames() const override;

  private:
    Q_DISABLE_COPY(UniqueValueListModel)

    UniqueValueListModel() = delete;
    void setupRoles();
    void connectSignals();

    QHash<int, QByteArray> m_roles;
    std::shared_ptr<QRTImpl::UniqueValueListImpl> m_impl;
  };

  class UniqueValueRenderer : public Renderer
  {
    Q_OBJECT

  public:
    explicit UniqueValueRenderer(QObject* parent = nullptr);
    UniqueValueRenderer(const QString& defaultLabel, Symbol* symbol, const QStringList& fieldNames, const QList<UniqueValue*>& uniqueValues, QObject* parent = nullptr);
    ~UniqueValueRenderer();

    QString defaultLabel() const;
    void setDefaultLabel(const QString& label);

    Symbol* defaultSymbol() const;
    void setDefaultSymbol(Symbol* symbol);

    QStringList fieldNames() const;
    void setFieldNames(const QStringList& fieldNames);

    UniqueValueListModel* uniqueValues() const;

    UniqueValueRenderer(const std::shared_ptr<QRTImpl::UniqueValueRendererImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::UniqueValueRendererImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(UniqueValueRenderer)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_UniqueValueRenderer_H
