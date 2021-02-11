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
/// \file MarkerSceneSymbol.h

#ifndef QRT_MarkerSceneSymbol_H
#define QRT_MarkerSceneSymbol_H

// C++ API headers
#include "Symbol.h"

namespace QRTImpl { class MarkerSceneSymbolImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class MarkerSceneSymbol : public Symbol
  {
    Q_OBJECT

  public:
    ~MarkerSceneSymbol();

    SceneSymbolAnchorPosition anchorPosition() const;
    void setAnchorPosition(SceneSymbolAnchorPosition anchorPosition);

    QColor color() const;
    void setColor(const QColor& color);

    double depth() const;
    void setDepth(double depth);

    float heading() const;
    void setHeading(float heading);

    double height() const;
    void setHeight(double height);

    float pitch() const;
    void setPitch(float pitch);

    float roll() const;
    void setRoll(float roll);

    double width() const;
    void setWidth(double width);

    /*! \internal */
    explicit MarkerSceneSymbol(const std::shared_ptr<QRTImpl::MarkerSceneSymbolImpl>& impl, QObject* parent = nullptr);
    /*! \internal */
    std::shared_ptr<QRTImpl::MarkerSceneSymbolImpl> getImpl() const;

  protected:
    explicit MarkerSceneSymbol(QObject* parent = nullptr);

  private:
    Q_DISABLE_COPY(MarkerSceneSymbol)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_MarkerSceneSymbol_H
