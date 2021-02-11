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
/// \file Renderer.h

#ifndef QRT_Renderer_H
#define QRT_Renderer_H

// C++ API headers
#include "Feature.h"
#include "Graphic.h"
#include "JsonSerializable.h"
#include "Object.h"
#include "RendererSceneProperties.h"
#include "Symbol.h"

namespace QRTImpl { class RendererImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class Renderer : public Object, public JsonSerializable
  {
    Q_OBJECT

  public:
    ~Renderer();

    virtual bool operator==(const Renderer* other) const;

    RendererType rendererType() const;

    QString rotationExpression() const;
    void setRotationExpression(const QString& expression);

    RotationType rotationType() const;
    void setRotationType(RotationType type);

    RendererSceneProperties sceneProperties() const;
    void setSceneProperties(const RendererSceneProperties& sceneProperties);

    Symbol* symbol(Feature* feature) const;

    Symbol* symbol(Graphic* graphic) const;

    Renderer* clone(QObject* parent = nullptr) const;

    static Renderer* fromJson(const QString& json, QObject* parent = nullptr);
    QString toJson() const override;
    QJsonObject unknownJson() const override;
    QJsonObject unsupportedJson() const override;

    Renderer(const std::shared_ptr<QRTImpl::RendererImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::RendererImpl> getImpl() const;

  protected:
    explicit Renderer(QObject* parent = nullptr);

    std::shared_ptr<QRTImpl::RendererImpl> m_impl;

  private:
    Q_DISABLE_COPY(Renderer)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_Renderer_H
