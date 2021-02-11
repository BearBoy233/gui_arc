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
/// \file MultilayerPointSymbol.h

#ifndef QRT_MultilayerPointSymbol_H
#define QRT_MultilayerPointSymbol_H

// C++ API headers
#include "MultilayerSymbol.h"

namespace QRTImpl { class MultilayerPointSymbolImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class MultilayerPointSymbol : public MultilayerSymbol
  {
    Q_OBJECT

  public:
    ~MultilayerPointSymbol();

    float angle() const;
    void setAngle(float angle);

    float size() const;
    void setSize(float size);

    SymbolAngleAlignment angleAlignment() const;
    void setAngleAlignment(SymbolAngleAlignment angleAlignment);

    explicit MultilayerPointSymbol(const std::shared_ptr<QRTImpl::MultilayerPointSymbolImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::MultilayerPointSymbolImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(MultilayerPointSymbol)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_MultilayerPointSymbol_H
