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
/// \file CompositeSymbol.h

#ifndef QRT_CompositeSymbol_H
#define QRT_CompositeSymbol_H

// C++ API headers
#include "Symbol.h"
#include "SymbolListModel.h"

namespace QRTImpl { class CompositeSymbolImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class CompositeSymbol : public Symbol
  {
    Q_OBJECT

  public:
    explicit CompositeSymbol(QObject* parent = nullptr);
    explicit CompositeSymbol(const QList<Symbol*>& symbols, QObject* parent = nullptr);
    ~CompositeSymbol();

    SymbolListModel* symbols() const;

    /*! \internal */
    explicit CompositeSymbol(const std::shared_ptr<QRTImpl::CompositeSymbolImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::CompositeSymbolImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(CompositeSymbol)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_CompositeSymbol_H
