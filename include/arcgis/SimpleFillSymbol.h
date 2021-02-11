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
/// \file SimpleFillSymbol.h

#ifndef QRT_SimpleFillSymbol_H
#define QRT_SimpleFillSymbol_H

// C++ API headers
#include "FillSymbol.h"

namespace QRTImpl { class SimpleFillSymbolImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class SimpleFillSymbol : public FillSymbol
  {
    Q_OBJECT

  public:
    explicit SimpleFillSymbol(QObject* parent = nullptr);
    SimpleFillSymbol(SimpleFillSymbolStyle style, const QColor& color, QObject* parent = nullptr);
    SimpleFillSymbol(SimpleFillSymbolStyle style, const QColor& color, LineSymbol* outline, QObject* parent = nullptr);
    ~SimpleFillSymbol();

    SimpleFillSymbolStyle style() const;
    void setStyle(SimpleFillSymbolStyle style);

    explicit SimpleFillSymbol(const std::shared_ptr<QRTImpl::SimpleFillSymbolImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::SimpleFillSymbolImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(SimpleFillSymbol)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_SimpleFillSymbol_H
