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
/// \file SimpleLineSymbol.h

#ifndef QRT_SimpleLineSymbol_H
#define QRT_SimpleLineSymbol_H

// C++ API headers
#include "LineSymbol.h"

namespace QRTImpl { class SimpleLineSymbolImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class SimpleLineSymbol : public LineSymbol
  {
    Q_OBJECT

  public:
    explicit SimpleLineSymbol(QObject* parent = nullptr);
    SimpleLineSymbol(SimpleLineSymbolStyle style, const QColor& color, float width, QObject* parent = nullptr);
    SimpleLineSymbol(SimpleLineSymbolStyle style,
                     const QColor& color,
                     float width,
                     SimpleLineSymbolMarkerStyle markerStyle,
                     SimpleLineSymbolMarkerPlacement markerPlacement,
                     QObject* parent = nullptr);

    ~SimpleLineSymbol();

    SimpleLineSymbolStyle style() const;
    void setStyle(SimpleLineSymbolStyle style);

    SimpleLineSymbolMarkerStyle markerStyle() const;
    void setMarkerStyle(SimpleLineSymbolMarkerStyle markerStyle);

    SimpleLineSymbolMarkerPlacement markerPlacement() const;
    void setMarkerPlacement(SimpleLineSymbolMarkerPlacement markerPlacement);

    explicit SimpleLineSymbol(const std::shared_ptr<QRTImpl::SimpleLineSymbolImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::SimpleLineSymbolImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(SimpleLineSymbol)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_SimpleLineSymbol_H
