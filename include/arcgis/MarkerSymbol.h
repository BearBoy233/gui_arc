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
/// \file MarkerSymbol.h

#ifndef QRT_MarkerSymbol_H
#define QRT_MarkerSymbol_H

// C++ API headers
#include "Symbol.h"

namespace QRTImpl { class MarkerSymbolImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class MarkerSymbol : public Symbol
  {
    Q_OBJECT

  public:
    ~MarkerSymbol();

    float angle() const;
    void setAngle(float angle);

    SymbolAngleAlignment angleAlignment() const;
    void setAngleAlignment(SymbolAngleAlignment angleAlignment);

    float leaderOffsetX() const;
    void setLeaderOffsetX(float offset);

    float leaderOffsetY() const;
    void setLeaderOffsetY(float offset);

    float offsetX() const;
    void setOffsetX(float offset);

    float offsetY() const;
    void setOffsetY(float offset);

    RotationType rotationType() const;
    void setRotationType(RotationType rotationType);

    explicit MarkerSymbol(const std::shared_ptr<QRTImpl::MarkerSymbolImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::MarkerSymbolImpl> getImpl() const;

  protected:
    explicit MarkerSymbol(QObject* parent = nullptr);

  private:
    Q_DISABLE_COPY(MarkerSymbol)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_MarkerSymbol_H
