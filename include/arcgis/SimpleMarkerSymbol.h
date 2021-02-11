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
/// \file SimpleMarkerSymbol.h

#ifndef QRT_SimpleMarkerSymbol_H
#define QRT_SimpleMarkerSymbol_H

// C++ API headers
#include "MarkerSymbol.h"
#include "SimpleLineSymbol.h"

namespace QRTImpl { class SimpleMarkerSymbolImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class SimpleMarkerSymbol : public MarkerSymbol
  {
    Q_OBJECT

  public:
    explicit SimpleMarkerSymbol(QObject* parent = nullptr);
    SimpleMarkerSymbol(SimpleMarkerSymbolStyle style, const QColor& color, float size, QObject* parent = nullptr);
    ~SimpleMarkerSymbol();

    QColor color() const;
    void setColor(const QColor& color);

    SimpleLineSymbol* outline() const;
    void setOutline(SimpleLineSymbol* outline);

    float size() const;
    void setSize(float size);

    SimpleMarkerSymbolStyle style() const;
    void setStyle(SimpleMarkerSymbolStyle style);

    explicit SimpleMarkerSymbol(const std::shared_ptr<QRTImpl::SimpleMarkerSymbolImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::SimpleMarkerSymbolImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(SimpleMarkerSymbol)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_SimpleMarkerSymbol_H
