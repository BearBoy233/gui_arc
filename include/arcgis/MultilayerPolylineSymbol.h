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
/// \file MultilayerPolylineSymbol.h

#ifndef QRT_MultilayerPolylineSymbol_H
#define QRT_MultilayerPolylineSymbol_H

// C++ API headers
#include "MultilayerSymbol.h"

namespace QRTImpl { class MultilayerPolylineSymbolImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class MultilayerPolylineSymbol : public MultilayerSymbol
  {
    Q_OBJECT

  public:
    ~MultilayerPolylineSymbol();

    explicit MultilayerPolylineSymbol(const std::shared_ptr<QRTImpl::MultilayerPolylineSymbolImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::MultilayerPolylineSymbolImpl> getImpl() const;

    float width() const;
    void setWidth(float width);

  private:
    Q_DISABLE_COPY(MultilayerPolylineSymbol)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_MultilayerPolylineSymbol_H
