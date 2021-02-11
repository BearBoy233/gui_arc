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
/// \file LocationDisplay.h

#ifndef QRT_LocationDisplay_H
#define QRT_LocationDisplay_H

// C++ API headers
#include "FillSymbol.h"
#include "Location.h"
#include "MapViewTypes.h"
#include "Object.h"
#include "Point.h"
#include "Symbol.h"

class QGeoPositionInfoSource;
class QCompass;

namespace QRTImpl { class LocationDisplayImpl; }

namespace Esri {
namespace ArcGISRuntime {

class LocationDisplay : public Object
{
  Q_OBJECT

public:
  ~LocationDisplay();

  void start();
  void stop();
  bool isStarted() const;

  QGeoPositionInfoSource* positionSource() const;
  void setPositionSource(QGeoPositionInfoSource* positionSource);

  QCompass* compass() const;
  void setCompass(QCompass* compass);

  LocationDisplayAutoPanMode autoPanMode() const;
  void setAutoPanMode(LocationDisplayAutoPanMode autoPanMode);

  double heading() const;

  Location location() const;

  Point mapLocation() const;

  int acquiringTimeout() const;
  void setAcquiringTimeout(int timeoutMilliseconds);

  double initialZoomScale() const;
  void setInitialZoomScale(double initialScale);

  float navigationPointHeightFactor() const;
  void setNavigationPointHeightFactor(float pointHeightFactor);

  float opacity() const;
  void setOpacity(float opacity);

  bool isShowAccuracy() const;
  void setShowAccuracy(bool enable);

  bool isShowLocation() const;
  void setShowLocation(bool enable);

  bool isShowPingAnimationSymbol() const;
  void setShowPingAnimationSymbol(bool enable);

  bool isUseCourseSymbolOnMovement() const;
  void setUseCourseSymbolOnMovement(bool enable);

  float wanderExtentFactor() const;
  void setWanderExtentFactor(float wanderFactor);

  Symbol* accuracySymbol() const;
  void setAccuracySymbol(Symbol* accuracySymbol);

  Symbol* acquiringSymbol() const;
  void setAcquiringSymbol(Symbol* acquiringSymbol);

  Symbol* courseSymbol() const;
  void setCourseSymbol(Symbol* courseSymbol);

  Symbol* defaultSymbol() const;
  void setDefaultSymbol(Symbol* defaultSymbol);

  Symbol* headingSymbol() const;
  void setHeadingSymbol(Symbol* headingSymbol);

  Symbol* pingAnimationSymbol() const;
  void setPingAnimationSymbol(Symbol* pingSymbol);

  /*!
     \internal
   */
  LocationDisplay(const std::shared_ptr<QRTImpl::LocationDisplayImpl>& impl, QObject* parent = nullptr);
  std::shared_ptr<QRTImpl::LocationDisplayImpl> getImpl() const;

signals:
  void autoPanModeChanged(Esri::ArcGISRuntime::LocationDisplayAutoPanMode autoPanMode);
  void locationChanged(Esri::ArcGISRuntime::Location location);
  void statusChanged(bool started);
  void headingChanged();

private:
  Q_DISABLE_COPY(LocationDisplay)

  std::shared_ptr<QRTImpl::LocationDisplayImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_LocationDisplay_H
