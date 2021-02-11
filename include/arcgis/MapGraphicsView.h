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
/// \file MapGraphicsView.h

#ifndef QRT_MapGraphicsView_H
#define QRT_MapGraphicsView_H

// C++ API headers
#include "MapView.h"
#include "MapViewTypes.h"

#ifndef GRAPHICSVIEW_SUPPORTED
#error "MapGraphicsView is not supported on this platform."
#endif

#include <QGraphicsView>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QKeyEvent>
#include <QTouchEvent>

namespace Esri {
namespace ArcGISRuntime {

class MapGraphicsScene;
class Map;

class MapGraphicsView : public QGraphicsView, public MapView
{
  Q_OBJECT
  Q_INTERFACES(Esri::ArcGISRuntime::MapView Esri::ArcGISRuntime::GeoView)

public:
  explicit MapGraphicsView(QWidget* parent = nullptr);
  explicit MapGraphicsView(Map* map, QWidget* parent = nullptr);
  ~MapGraphicsView();

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
  void exportImageCompleted(QUuid taskId, QImage image);
  void setViewpointCompleted(bool succeeded);
  void setBookmarkCompleted(bool succeeded);
  void identifyGraphicsOverlayCompleted(QUuid taskId, Esri::ArcGISRuntime::IdentifyGraphicsOverlayResult* identifyResult);
  void identifyGraphicsOverlaysCompleted(QUuid taskId, QList<Esri::ArcGISRuntime::IdentifyGraphicsOverlayResult*> identifyResults);
  void identifyLayerCompleted(QUuid taskId, Esri::ArcGISRuntime::IdentifyLayerResult* identifyResult);
  void identifyLayersCompleted(QUuid taskId, QList<Esri::ArcGISRuntime::IdentifyLayerResult*> identifyResults);
  void errorOccurred(Esri::ArcGISRuntime::Error error);

protected:
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
  virtual void showEvent(QShowEvent *event) override;

  QObject* qObjectPointer() const override;

private:
  Q_DISABLE_COPY(MapGraphicsView)
  friend class MapGraphicsScene;
  void resizeEvent(QResizeEvent* event) override;
  void wheelEvent(QWheelEvent* event) override;
  void setSceneRect(qreal x, qreal y, qreal w, qreal h);
  void makeContextCurrent();
  void initialize();
  std::unique_ptr<MapGraphicsScene> m_scene;
  QList<QMetaObject::Connection> m_windowConnections;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_MapGraphicsView_H
