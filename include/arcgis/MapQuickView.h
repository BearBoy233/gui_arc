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
/// \file MapQuickView.h

#ifndef QRT_MapQuickView_H
#define QRT_MapQuickView_H

// C++ API headers
#include "MapView.h"
#include "MapViewTypes.h"

// Qt headers
#include <QKeyEvent>
#include <QMouseEvent>
#include <QQuickFramebufferObject>
#include <QTouchEvent>
#include <QWheelEvent>

namespace Esri {
namespace ArcGISRuntime {

  class Map;

  class MapQuickView : public QQuickFramebufferObject, public MapView
  {
    Q_OBJECT
    Q_INTERFACES(Esri::ArcGISRuntime::MapView Esri::ArcGISRuntime::GeoView)

    Q_PROPERTY(ViewInsets* viewInsets READ viewInsets CONSTANT)
    Q_PROPERTY(QVariant attributionTop READ attributionTop NOTIFY attributionTopChanged)
    Q_PROPERTY(QRectF attributionRect READ attributionRect NOTIFY attributionRectChanged)

  public:
    explicit MapQuickView(QQuickItem* parent = nullptr);
    explicit MapQuickView(Map* map, QQuickItem* parent = nullptr);
    ~MapQuickView();

    QVariant attributionTop() const;

  signals:
    void rectChanged(QRectF rect);
    void mousePressed(QMouseEvent& mouseEvent);
    void mouseMoved(QMouseEvent& mouseEvent);
    void mouseReleased(QMouseEvent& mouseEvent);
    void mouseClicked(QMouseEvent& mouseEvent);
    void mousePressedAndHeld(QMouseEvent& mouseEvent);
    void mouseDoubleClicked(QMouseEvent& mouseEvent);
    void mouseWheelChanged(QWheelEvent& wheelEvent);
    void keyPressed(QKeyEvent& keyEvent);
    void keyReleased(QKeyEvent& keyEvent);
    void touched(QTouchEvent& event);

    void mapChanged();
    void mapRotationChanged();
    void mapScaleChanged();
    void drawStatusChanged(Esri::ArcGISRuntime::DrawStatus status);
    void layerViewStateChanged(Esri::ArcGISRuntime::Layer* layer, Esri::ArcGISRuntime::LayerViewState layerViewState);
    void navigatingChanged();
    void spatialReferenceChanged();
    void viewpointChanged();
    void attributionTextChanged();
    void attributionRectChanged();
    void attributionTopChanged();
    void exportImageCompleted(QUuid taskId, QImage image);
    void setViewpointCompleted(bool succeeded);
    void setBookmarkCompleted(bool succeeded);
    void identifyGraphicsOverlayCompleted(QUuid taskId, Esri::ArcGISRuntime::IdentifyGraphicsOverlayResult* identifyResult);
    void identifyGraphicsOverlaysCompleted(QUuid taskId, QList<Esri::ArcGISRuntime::IdentifyGraphicsOverlayResult*> identifyResults);
    void identifyLayerCompleted(QUuid taskId, Esri::ArcGISRuntime::IdentifyLayerResult* identifyResult);
    void identifyLayersCompleted(QUuid taskId, QList<Esri::ArcGISRuntime::IdentifyLayerResult*> identifyResults);
    void errorOccurred(Esri::ArcGISRuntime::Error error);

  protected:
    void geometryChanged(const QRectF& newGeometry, const QRectF& oldGeometry) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    void touchEvent(QTouchEvent *event) override;

    virtual void mapRotationChangedEvent() override;
    virtual void mapScaleChangedEvent() override;
    virtual void drawStatusChangedEvent(Esri::ArcGISRuntime::DrawStatus drawStatus) override;
    virtual void navigatingChangedEvent() override;
    virtual void spatialReferenceChangedEvent() override;
    virtual void viewpointChangedEvent() override;
    virtual void attributionTextChangedEvent() override;
    virtual void attributionRectChangedEvent() override;
    virtual void exportImageCompletedEvent(QUuid taskId, const QImage& image) override;
    virtual void setViewpointCompletedEvent(bool success) override;
    virtual void setBookmarkCompletedEvent(bool success) override;
    virtual void layerViewStateChangedEvent(Layer* layer, const LayerViewState& layerViewState) override;
    virtual void identifyGraphicsOverlayCompletedEvent(QUuid taskId, IdentifyGraphicsOverlayResult* identifyResult) override;
    virtual void identifyGraphicsOverlaysCompletedEvent(QUuid taskId, const QList<IdentifyGraphicsOverlayResult*>& identifyResults) override;
    virtual void identifyLayerCompletedEvent(QUuid taskId, IdentifyLayerResult* identifyResult) override;
    virtual void identifyLayersCompletedEvent(QUuid taskId, const QList<IdentifyLayerResult*>& identifyResults) override;
    virtual void errorOccurredEvent(const Error& error) override;

    virtual void geoViewRectChangedEvent(QRectF rect) override;
    virtual void geoViewMousePressEvent(QMouseEvent& event) override;
    virtual void geoViewMouseMoveEvent(QMouseEvent& event) override;
    virtual void geoViewMouseReleaseEvent(QMouseEvent& event) override;
    virtual void geoViewMouseClickEvent(QMouseEvent& event) override;
    virtual void geoViewMousePressAndHoldEvent(QMouseEvent& event) override;
    virtual void geoViewMouseDoubleClickEvent(QMouseEvent& event) override;
    virtual void geoViewMouseWheelEvent(QWheelEvent& event) override;
    virtual void geoViewKeyPressEvent(QKeyEvent& event) override;
    virtual void geoViewKeyReleaseEvent(QKeyEvent& event) override;
    virtual void geoViewTouchEvent(QTouchEvent& event) override;
    virtual void drawRequestedEvent() override;

    QObject* qObjectPointer() const override;

  private:
    Q_DISABLE_COPY(MapQuickView)
    void initialize();

    QQuickFramebufferObject::Renderer* createRenderer() const override;

    std::unique_ptr<QQuickItem> m_attributionItem;
    QRectF m_lastAttributionRect;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_MapQuickView_H
