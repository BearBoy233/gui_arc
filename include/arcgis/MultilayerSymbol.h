// COPYRIGHT 1995-2017 ESRI
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
/// \file MultilayerSymbol.h

#ifndef QRT_MultilayerSymbol_H
#define QRT_MultilayerSymbol_H

// C++ API headers
#include "Symbol.h"

// Qt headers
#include <QColor>

namespace QRTImpl { class MultilayerSymbolImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class MultilayerSymbol : public Symbol
  {
    Q_OBJECT

  public:
    ~MultilayerSymbol();

    QColor color() const;
    void setColor(const QColor& color);

    explicit MultilayerSymbol(const std::shared_ptr<QRTImpl::MultilayerSymbolImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::MultilayerSymbolImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(MultilayerSymbol)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_MultilayerSymbol_H
