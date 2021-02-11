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
/// \file LineSymbol.h

#ifndef QRT_LineSymbol_H
#define QRT_LineSymbol_H

// C++ API headers
#include "Symbol.h"

// Qt headers
#include <QColor>

namespace QRTImpl { class LineSymbolImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class LineSymbol : public Symbol
  {
    Q_OBJECT

  public:
    ~LineSymbol();

    QColor color() const;
    void setColor(const QColor& color);

    float width() const;
    void setWidth(float width);

    bool isAntiAlias() const;
    void setAntiAlias(bool antiAlias);

    explicit LineSymbol(const std::shared_ptr<QRTImpl::LineSymbolImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::LineSymbolImpl> getImpl() const;

  protected:
    explicit LineSymbol(QObject* parent = nullptr);

  private:
    Q_DISABLE_COPY(LineSymbol)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_LineSymbol_H
