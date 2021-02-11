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
/// \file Camera.h

#ifndef QRT_Camera_H
#define QRT_Camera_H

// C++ API headers
#include "Point.h"

namespace QRTImpl { class CameraImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class Camera
  {
  public:
    Camera();
    Camera(double latitude, double longitude, double altitude, double heading, double pitch, double roll);
    Camera(const Point& locationPoint, double heading, double pitch, double roll);
    Camera(const Point& lookAtPoint, double distance, double heading, double pitch, double roll);
    Camera(const Camera& other);
    Camera(Camera&& other) noexcept;
    ~Camera();

    Camera& operator=(const Camera& other);
    Camera& operator=(Camera&& other) noexcept;

    bool operator==(const Camera& other) const;

    bool isEmpty() const;

    double heading() const;
    Point location() const;
    double pitch() const;
    double roll() const;

    Camera elevate(double deltaAltitude) const;
    Camera moveForward(double distance) const;
    Camera moveTo(const Point& location) const;
    Camera moveToward(const Point& targetPoint, double distance) const;
    Camera rotateAround(const Point& targetPoint, double deltaHeading, double deltaPitch, double deltaRoll) const;
    Camera rotateTo(double heading, double pitch, double roll) const;
    Camera zoomToward(const Point& targetPoint, double factor) const;

    /*!
       \internal
     */
    Camera(const std::shared_ptr<QRTImpl::CameraImpl>& impl);
    std::shared_ptr<QRTImpl::CameraImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::CameraImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_Camera_H
