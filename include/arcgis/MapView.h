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
/// \file MapView.h

#ifndef QRT_MapView_H
#define QRT_MapView_H

// C++ API headers
#include "BackgroundGrid.h"
#include "CalloutData.h"
#include "GeoView.h"
#include "Grid.h"
#include "LocationDisplay.h"
#include "MapViewTypes.h"
#include "Point.h"
#include "Polygon.h"
#include "ViewLabelProperties.h"

namespace QRTImpl {
  class MapViewImpl;
}

namespace Esri {
namespace ArcGISRuntime {

class Map;

class MapView : public GeoView
{
public:
  ~MapView();

  bool isMagnifierMapPanningEnabled() const;
  void setMagnifierMapPanningEnabled(bool magnifierMapPanningEnabled);
  bool isMagnifierEnabled() const;
  void setMagnifierEnabled(bool magnifierEnabled);

  bool isRotationByPinchingEnabled() const;
  void setRotationByPinchingEnabled(bool rotationByPinching);

  bool isZoomByPinchingEnabled() const;
  void setZoomByPinchingEnabled(bool zoomByPinching);

  QPointF locationToScreen(const Point& mapPoint) const;
  Point screenToLocation(double screenX, double screenY) const;

  int mapHeight() const;
  int mapWidth() const;
  double mapRotation() const;
  double mapScale() const;
  double unitsPerDIP() const;

  WrapAroundMode wrapAroundMode() const;
  void setWrapAroundMode(WrapAroundMode wrapAroundMode);

  ViewLabelProperties labeling() const;
  void setLabeling(const ViewLabelProperties& viewLabelProperties);

  LocationDisplay* locationDisplay() const;
  CalloutData* calloutData() const;

  void setMap(Map* map);
  Map* map() const;

  Polygon visibleArea() const;

  BackgroundGrid backgroundGrid() const;
  void setBackgroundGrid(const BackgroundGrid& backgroundGrid);

  Grid* grid() const;
  void setGrid(Grid* grid);

  // async methods
  TaskWatcher setViewpointAnimated(const Viewpoint& viewpoint, float durationSeconds, AnimationCurve curve);
  TaskWatcher setViewpointRotation(double angleDegrees);
  TaskWatcher setViewpointScale(double scale);
  TaskWatcher setViewpointCenter(const Point& center);
  TaskWatcher setViewpointCenter(const Point& center, double scale);
  TaskWatcher setViewpointGeometry(const Geometry& boundingGeometry);
  TaskWatcher setViewpointGeometry(const Geometry& boundingGeometry, double paddingInDIPS);

  MapView(const std::shared_ptr<QRTImpl::MapViewImpl>& impl);
  std::shared_ptr<QRTImpl::MapViewImpl> getImpl() const;

protected:
  MapView(int width, int height);

  virtual void mapRotationChangedEvent();
  virtual void mapScaleChangedEvent();

private:
  Q_DISABLE_COPY(MapView)

  QObject m_mapViewConnectionContext;
};

} // namespace ArcGISRuntime
} // namespace Esri

Q_DECLARE_INTERFACE(Esri::ArcGISRuntime::MapView, "Esri::ArcGISRuntime::MapView")

#endif // QRT_MapView_H
