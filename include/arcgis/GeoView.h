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
/// \file GeoView.h

#ifndef QRT_GeoView_H
#define QRT_GeoView_H

// C++ API headers
#include "Bookmark.h"
#include "GeoElement.h"
#include "Graphic.h"
#include "GraphicsOverlay.h"
#include "GraphicsOverlayListModel.h"
#include "IdentifyGraphicsOverlayResult.h"
#include "IdentifyLayerResult.h"
#include "LayerViewState.h"
#include "MapViewTypes.h"
#include "Object.h"
#include "SelectionProperties.h"
#include "SpatialReference.h"
#include "TaskWatcher.h"
#include "TimeExtent.h"
#include "ViewInsets.h"
#include "Viewpoint.h"

// Qt headers
#include <QImage>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QTouchEvent>
#include <QUuid>
#include <QWheelEvent>

namespace QRTImpl {
  class GeoViewImpl;
}

class QScreen;

namespace Esri {
namespace ArcGISRuntime {

class Layer;

class GeoView
{
public:
  virtual ~GeoView();
  DrawStatus drawStatus() const;
  QString attributionText() const;
  bool isAttributionTextVisible() const;
  void setAttributionTextVisible(bool visible);
  QRectF attributionRect() const;
  bool isNavigating() const;
  bool isWrapAroundEnabled() const;

  GraphicsOverlayListModel* graphicsOverlays() const;

  GeoViewType geoViewType() const;

  Viewpoint currentViewpoint(ViewpointType viewpointType) const;

  LayerViewState layerViewState(Layer* layer) const;

  SpatialReference spatialReference() const;

  TimeExtent timeExtent() const;
  void setTimeExtent(const TimeExtent& timeExtent);

  ViewInsets* viewInsets() const;
  void setViewInsets(ViewInsets* viewInsets);

  SelectionProperties selectionProperties() const;
  void setSelectionProperties(const SelectionProperties& selectionProperties);

  void setViewpointAndWait(const Viewpoint& viewpoint);

  // async methods
  TaskWatcher setBookmark(Bookmark* bookmark);
  TaskWatcher setViewpoint(const Viewpoint& viewpoint);
  TaskWatcher setViewpoint(const Viewpoint& viewpoint, float durationSeconds);

  TaskWatcher exportImage();

  TaskWatcher identifyGraphicsOverlay(GraphicsOverlay* graphicsOverlay,
                                      double screenX,
                                      double screenY,
                                      double tolerance,
                                      bool returnPopupsOnly);

  TaskWatcher identifyGraphicsOverlay(GraphicsOverlay* graphicsOverlay,
                                      double screenX,
                                      double screenY,
                                      double tolerance,
                                      bool returnPopupsOnly,
                                      int maximumResults);

  TaskWatcher identifyGraphicsOverlays(double screenX,
                                       double screenY,
                                       double tolerance,
                                       bool returnPopupsOnly);

  TaskWatcher identifyGraphicsOverlays(double screenX,
                                       double screenY,
                                       double tolerance,
                                       bool returnPopupsOnly,
                                       int maximumResultsPerOverlay);

  TaskWatcher identifyLayer(Layer* layer,
                            double screenX,
                            double screenY,
                            double tolerance,
                            bool returnPopupsOnly);

  TaskWatcher identifyLayer(Layer* layer,
                            double screenX,
                            double screenY,
                            double tolerance,
                            bool returnPopupsOnly,
                            int maximumResults);

  TaskWatcher identifyLayers(double screenX,
                             double screenY,
                             double tolerance,
                             bool returnPopupsOnly);

  TaskWatcher identifyLayers(double screenX,
                             double screenY,
                             double tolerance,
                             bool returnPopupsOnly,
                             int maximumResultsPerLayer);

  int heightInPixels() const;
  int widthInPixels() const;

protected:
  void pauseAndSaveResources();
  void pauseAndRecycleResources();
  void resume();
  virtual void draw();
  bool isReadyToDraw() const;
  void resizeView(int width, int height);
  void handleScreenChanged(QScreen* screen);

  virtual void drawStatusChangedEvent(Esri::ArcGISRuntime::DrawStatus drawStatus);
  virtual void navigatingChangedEvent();
  virtual void spatialReferenceChangedEvent();
  virtual void viewpointChangedEvent();
  virtual void attributionTextChangedEvent();
  virtual void attributionRectChangedEvent();
  virtual void exportImageCompletedEvent(QUuid taskId, const QImage& image);
  virtual void setViewpointCompletedEvent(bool success);
  virtual void setBookmarkCompletedEvent(bool success);
  virtual void layerViewStateChangedEvent(Layer* layer, const LayerViewState& layerViewState);
  virtual void identifyGraphicsOverlayCompletedEvent(QUuid taskId, IdentifyGraphicsOverlayResult* identifyResult);
  virtual void identifyGraphicsOverlaysCompletedEvent(QUuid taskId, const QList<IdentifyGraphicsOverlayResult*>& identifyResults);
  virtual void identifyLayerCompletedEvent(QUuid taskId, IdentifyLayerResult* identifyResult);
  virtual void identifyLayersCompletedEvent(QUuid taskId, const QList<IdentifyLayerResult*>& identifyResults);
  virtual void errorOccurredEvent(const Error& error);

  virtual void geoViewRectChangedEvent(QRectF rect);
  virtual void geoViewMousePressEvent(QMouseEvent& event);
  virtual void geoViewMouseMoveEvent(QMouseEvent& event);
  virtual void geoViewMouseReleaseEvent(QMouseEvent& event);
  virtual void geoViewMouseClickEvent(QMouseEvent& event);
  virtual void geoViewMousePressAndHoldEvent(QMouseEvent& event);
  virtual void geoViewMouseDoubleClickEvent(QMouseEvent& event);
  virtual void geoViewMouseWheelEvent(QWheelEvent& event);
  virtual void geoViewKeyPressEvent(QKeyEvent& event);
  virtual void geoViewKeyReleaseEvent(QKeyEvent& event);
  virtual void geoViewTouchEvent(QTouchEvent& event);
  virtual void drawRequestedEvent() = 0;

  void sendGeoViewRectChangedEvent(QRectF rect);
  void sendGeoViewMousePressEvent(QMouseEvent* event, bool accepted);
  void sendGeoViewMouseMoveEvent(QMouseEvent* event, bool accepted);
  void sendGeoViewMouseReleaseEvent(QMouseEvent* event, bool accepted);
  void sendGeoViewMouseDoubleClickEvent(QMouseEvent* event, bool accepted);
  void sendGeoViewMouseWheelEvent(QWheelEvent* event, bool accepted);
  void sendGeoViewKeyPressEvent(QKeyEvent* event, bool accepted);
  void sendGeoViewKeyReleaseEvent(QKeyEvent* event, bool accepted);
  bool sendGeoViewTouchEvent(QTouchEvent* event, bool accepted);

  virtual QObject* qObjectPointer() const = 0;

  /*!
     \internal
   */
  explicit GeoView(const std::shared_ptr<QRTImpl::GeoViewImpl>& impl);
  /*!
     \internal
   */
  std::shared_ptr<QRTImpl::GeoViewImpl> m_impl;

private:
  Q_DISABLE_COPY(GeoView)

  void connectSignals();
  QObject m_connectionContext;
};

} // namespace ArcGISRuntime
} // namespace Esri

Q_DECLARE_INTERFACE(Esri::ArcGISRuntime::GeoView, "Esri::ArcGISRuntime::GeoView")

#endif // QRT_GeoView_H
