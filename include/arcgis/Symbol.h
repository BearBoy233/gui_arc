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
/// \file Symbol.h

#ifndef QRT_Symbol_H
#define QRT_Symbol_H

// C++ API headers
#include "Geometry.h"
#include "JsonSerializable.h"
#include "Object.h"
#include "SymbolTypes.h"
#include "TaskWatcher.h"

// Qt headers
#include <QImage>
#include <QUuid>

// STL headers
#include <memory>

namespace QRTImpl { class SymbolImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class Symbol : public Object, public JsonSerializable
  {
    Q_OBJECT

  public:
    ~Symbol();

    bool operator==(const Symbol* other) const;

    SymbolType symbolType() const;

    TaskWatcher createSwatch(const Geometry& geometry, float width, float height, const QColor& backgroundColor = QColor());
    TaskWatcher createSwatch(const Geometry& geometry, float width, float height, float screenScale, const QColor& backgroundColor = QColor());
    TaskWatcher createSwatch(float width, float height, float screenScale, const QColor& backgroundColor = QColor());
    TaskWatcher createSwatch(const QColor& backgroundColor = QColor());
    TaskWatcher createSwatch(float screenScale, const QColor& backgroundColor = QColor());

    static Symbol* fromJson(const QString& json, QObject* parent = nullptr);
    QString toJson() const override;
    QJsonObject unknownJson() const override;
    QJsonObject unsupportedJson() const override;

    explicit Symbol(const std::shared_ptr<QRTImpl::SymbolImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::SymbolImpl> getImpl() const;

  signals:
    void createSwatchCompleted(QUuid taskId, QImage image);

  protected:
    Symbol(QObject* parent = nullptr);

    std::shared_ptr<QRTImpl::SymbolImpl> m_impl;

  private:
    Q_DISABLE_COPY(Symbol)

    void connectSignals();
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_Symbol_H

