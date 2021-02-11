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
/// \file GraphicsOverlay.h

#ifndef QRT_GraphicsOverlay_H
#define QRT_GraphicsOverlay_H

// C++ API headers
#include "Envelope.h"
#include "Graphic.h"
#include "GraphicListModel.h"
#include "LabelDefinitionListModel.h"
#include "LayerSceneProperties.h"
#include "MapTypes.h"
#include "Object.h"
#include "PopupDefinition.h"
#include "PopupSource.h"
#include "Renderer.h"
#include "Symbol.h"

namespace QRTImpl { class GraphicsOverlayImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class GraphicsOverlay : public Object, public PopupSource
  {
    Q_OBJECT

  public:
    explicit GraphicsOverlay(QObject* parent = nullptr);
    ~GraphicsOverlay();

    Envelope extent() const;

    GraphicListModel* graphics() const;

    double maxScale() const;
    void setMaxScale(double maxScale);

    double minScale() const;
    void setMinScale(double minScale);

    float opacity() const;
    void setOpacity(float opacity);

    Renderer* renderer() const;
    void setRenderer(Renderer* renderer);

    GraphicsRenderingMode renderingMode() const;
    void setRenderingMode(GraphicsRenderingMode value);

    LayerSceneProperties sceneProperties() const;
    void setSceneProperties(const LayerSceneProperties& sceneProperties);

    QColor selectionColor() const;
    void setSelectionColor(const QColor& color);

    bool isVisible() const;
    void setVisible(bool visible);

    QString overlayId() const;
    void setOverlayId(const QString& overlayId);

    void clearSelection();

    QList<Graphic*> selectedGraphics() const;

    LabelDefinitionListModel* labelDefinitions() const;

    bool isLabelsEnabled() const;
    void setLabelsEnabled(bool labelsEnabled);

    void selectGraphics(const QList<Graphic*>& graphics);
    void unselectGraphics(const QList<Graphic*>& graphics);

    // PopupSource interface methods
    bool isPopupEnabled() const override;
    void setPopupEnabled(bool popupEnabled) override;
    PopupDefinition* popupDefinition() const override;
    void setPopupDefinition(PopupDefinition* popupDefinition) override;

    GraphicsOverlay(const std::shared_ptr<QRTImpl::GraphicsOverlayImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::GraphicsOverlayImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(GraphicsOverlay)

    std::shared_ptr<QRTImpl::GraphicsOverlayImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_GraphicsOverlay_H
