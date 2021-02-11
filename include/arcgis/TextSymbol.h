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
/// \file TextSymbol.h

#ifndef QRT_TextSymbol_H
#define QRT_TextSymbol_H

// C++ API headers
#include "MarkerSymbol.h"

// Qt headers
#include <QColor>

namespace QRTImpl { class TextSymbolImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class TextSymbol : public MarkerSymbol
  {
    Q_OBJECT

  public:
    explicit TextSymbol(QObject* parent = nullptr);
    TextSymbol(const QString& text, const QColor& color, float size, HorizontalAlignment hAlign, VerticalAlignment vAlign, QObject* parent = nullptr);
    ~TextSymbol();

    QColor backgroundColor() const;
    void setBackgroundColor(const QColor& backgroundColor);

    QColor color() const;
    void setColor(const QColor& color);

    FontDecoration fontDecoration() const;
    void setFontDecoration(FontDecoration fontDecoration);

    QString fontFamily() const;
    void setFontFamily(const QString& fontFamily);

    FontStyle fontStyle() const;
    void setFontStyle(FontStyle fontStyle);

    FontWeight fontWeight() const;
    void setFontWeight(FontWeight fontWeight);

    HorizontalAlignment horizontalAlignment() const;
    void setHorizontalAlignment(HorizontalAlignment hAlign);

    float size() const;
    void setSize(float size);

    QString text() const;
    void setText(const QString& text);

    VerticalAlignment verticalAlignment() const;
    void setVerticalAlignment(VerticalAlignment vAlign);

    QColor outlineColor() const;
    void setOutlineColor(const QColor& outlineColor);

    float outlineWidth() const;
    void setOutlineWidth(float outlineWidth);

    QColor haloColor() const;
    void setHaloColor(const QColor& haloColor);

    float haloWidth() const;
    void setHaloWidth(float haloWidth);

    bool isKerningEnabled() const;
    void setKerningEnabled(bool kerningEnabled);

    explicit TextSymbol(const std::shared_ptr<QRTImpl::TextSymbolImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::TextSymbolImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(TextSymbol)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_TextSymbol_H
