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
/// \file SimpleRenderer.h

#ifndef QRT_SimpleRenderer_H
#define QRT_SimpleRenderer_H

// C++ API headers
#include "Renderer.h"

namespace QRTImpl { class SimpleRendererImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class SimpleRenderer : public Renderer
  {
    Q_OBJECT

  public:
    explicit SimpleRenderer(QObject* parent = nullptr);
    explicit SimpleRenderer(Symbol* symbol, QObject* parent = nullptr);
    ~SimpleRenderer();

    QString description() const;
    void setDescription(const QString& description);

    QString label() const;
    void setLabel(const QString& label);

    Symbol* symbol() const;
    void setSymbol(Symbol* symbol);

    SimpleRenderer(const std::shared_ptr<QRTImpl::SimpleRendererImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::SimpleRendererImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(SimpleRenderer)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_SimpleRenderer_H
