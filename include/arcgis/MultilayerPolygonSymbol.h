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
/// \file MultilayerPolygonSymbol.h

#ifndef QRT_MultilayerPolygonSymbol_H
#define QRT_MultilayerPolygonSymbol_H

// C++ API headers
#include "MultilayerSymbol.h"

namespace QRTImpl { class MultilayerPolygonSymbolImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class MultilayerPolygonSymbol : public MultilayerSymbol
  {
    Q_OBJECT

  public:
    ~MultilayerPolygonSymbol();

    /*! \internal */
    explicit MultilayerPolygonSymbol(const std::shared_ptr<QRTImpl::MultilayerPolygonSymbolImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::MultilayerPolygonSymbolImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(MultilayerPolygonSymbol)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_MultilayerPolygonSymbol_H
