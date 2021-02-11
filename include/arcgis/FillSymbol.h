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
/// \file FillSymbol.h

#ifndef QRT_FillSymbol_H
#define QRT_FillSymbol_H

// C++ API headers
#include "LineSymbol.h"
#include "Symbol.h"

// Qt headers
#include <QColor>

namespace QRTImpl { class FillSymbolImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class FillSymbol : public Symbol
  {
    Q_OBJECT

  public:
    ~FillSymbol();

    QColor color() const;
    void setColor(const QColor& color);

    LineSymbol* outline() const;
    void setOutline(LineSymbol* outline);

    explicit FillSymbol(const std::shared_ptr<QRTImpl::FillSymbolImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::FillSymbolImpl> getImpl() const;

  protected:
    explicit FillSymbol(QObject* parent = nullptr);

  private:
    Q_DISABLE_COPY(FillSymbol)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_FillSymbol_H
