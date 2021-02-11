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
/// \file ClassBreaksRenderer.h

#ifndef QRT_ClassBreaksRenderer_H
#define QRT_ClassBreaksRenderer_H

// C++ API headers
#include "Renderer.h"

// Qt headers
#include <QAbstractListModel>

namespace QRTImpl {
  class ClassBreakImpl;
  class ClassBreaksRendererImpl;
  class ClassBreakListImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class ClassBreak : public Object, public JsonSerializable
  {
    Q_OBJECT

  public:
    explicit ClassBreak(QObject* parent = nullptr);
    ClassBreak(const QString& label, const QString& description, double minValue, double maxValue, Symbol* symbol, QObject* parent = nullptr);
    ~ClassBreak();

    bool operator ==(const ClassBreak* other) const;

    QString description() const;
    void setDescription(const QString& description);

    QString label() const;
    void setLabel(const QString& label);

    double maxValue() const;
    void setMaxValue(double maxValue);

    double minValue() const;
    void setMinValue(double minValue);

    Symbol* symbol() const;
    void setSymbol(Symbol* symbol);

    ClassBreak* clone(QObject* parent = nullptr) const;

    static ClassBreak* fromJson(const QString& json, QObject* parent = nullptr);
    QString toJson() const override;
    QJsonObject unknownJson() const override;
    QJsonObject unsupportedJson() const override;

    ClassBreak(const std::shared_ptr<QRTImpl::ClassBreakImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::ClassBreakImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(ClassBreak)

    std::shared_ptr<QRTImpl::ClassBreakImpl> m_impl;
  };

  class ClassBreakListModel : public QAbstractListModel
  {
    Q_OBJECT

  public:

    enum ClassBreakRoles
    {
      ClassBreakDescriptionRole = Qt::UserRole + 1,
      ClassBreakLabelRole = Qt::UserRole + 2,
      ClassBreakMaxValueRole = Qt::UserRole + 3,
      ClassBreakMinValueRole = Qt::UserRole + 4
    };

    ~ClassBreakListModel();

    bool isEmpty() const;

    void clear();

    int size() const;

    void append(ClassBreak* classBreak);

    void insert(int index, ClassBreak* classBreak);

    void removeAt(int index);

    void removeOne(ClassBreak* classBreak);

    void move(int from, int to);

    ClassBreak* at(int index) const;

    bool contains(ClassBreak* classBreak) const;

    int indexOf(ClassBreak* classBreak) const;

    ClassBreak* first() const;

    ClassBreak* last() const;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;

    bool removeRows(int row, int count, const QModelIndex& parent = QModelIndex()) override;

    ClassBreakListModel(const std::shared_ptr<QRTImpl::ClassBreakListImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::ClassBreakListImpl> getImpl() const;

  signals:
    void classBreakAdded(int index);
    void classBreakRemoved(int index);
    void errorOccurred(Esri::ArcGISRuntime::Error error);

  protected:
    QHash<int, QByteArray> roleNames() const override;

  private:
    Q_DISABLE_COPY(ClassBreakListModel)

    ClassBreakListModel() = delete;
    void setupRoles();
    void connectSignals();

    QHash<int, QByteArray> m_roles;
    std::shared_ptr<QRTImpl::ClassBreakListImpl> m_impl;
  };

  class ClassBreaksRenderer : public Renderer
  {
    Q_OBJECT

  public:
    explicit ClassBreaksRenderer(QObject* parent = nullptr);
    ClassBreaksRenderer(const QString& field, const QList<ClassBreak*>& classBreaks, QObject* parent = nullptr);
    ~ClassBreaksRenderer();

    Symbol* backgroundFillSymbol() const;
    void setBackgroundFillSymbol(Symbol* backgroundFillSymbol);

    ClassBreakListModel* classBreaks() const;

    QString defaultLabel() const;
    void setDefaultLabel(const QString& label);

    Symbol* defaultSymbol() const;
    void setDefaultSymbol(Symbol* symbol);

    QString fieldName() const;
    void setFieldName(const QString& fieldName);

    double minValue() const;
    void setMinValue(double minValue);

    QString normalizationField() const;
    void setNormalizationField(const QString& field);

    double normalizationTotal() const;
    void setNormalizationTotal(double total);

    RendererNormalizationType normalizationType() const;
    void setNormalizationType(RendererNormalizationType type);

    RendererClassificationMethod classificationMethod() const;

    ClassBreaksRenderer(const std::shared_ptr<QRTImpl::ClassBreaksRendererImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::ClassBreaksRendererImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(ClassBreaksRenderer)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ClassBreaksRenderer_H
