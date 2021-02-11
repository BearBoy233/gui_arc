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
/// \file OrbitLocationCameraController.h

#ifndef QRT_OrbitLocationCameraController_H
#define QRT_OrbitLocationCameraController_H

// C++ API headers
#include "CameraController.h"
#include "Point.h"
#include "TaskWatcher.h"

namespace Esri {
namespace ArcGISRuntime {

  class OrbitLocationCameraController : public CameraController
  {
    Q_OBJECT

  public:
    OrbitLocationCameraController(const Point& point, double distance, QObject* parent = nullptr);
    OrbitLocationCameraController(const Point& targetPoint, const Point& cameraPoint, QObject* parent = nullptr);
    ~OrbitLocationCameraController();

    double cameraDistance() const;
    void setCameraDistance(double distance);

    double cameraHeadingOffset() const;
    void setCameraHeadingOffset(double cameraHeadingOffset);

    double cameraPitchOffset() const;
    void setCameraPitchOffset(double cameraPitchOffset);

    bool isCameraDistanceInteractive() const;
    void setCameraDistanceInteractive(bool interactiveDistance);

    bool isCameraHeadingOffsetInteractive() const;
    void setCameraHeadingOffsetInteractive(bool interactiveHeadingOffset);

    bool isCameraPitchOffsetInteractive() const;
    void setCameraPitchOffsetInteractive(bool interactivePitchOffset);

    double maxCameraDistance() const;
    void setMaxCameraDistance(double maxDistance);

    double maxCameraHeadingOffset() const;
    void setMaxCameraHeadingOffset(double maxHeadingOffset);

    double maxCameraPitchOffset() const;
    void setMaxCameraPitchOffset(double maxPitchOffset);

    double minCameraDistance() const;
    void setMinCameraDistance(double minDistance);

    double minCameraHeadingOffset() const;
    void setMinCameraHeadingOffset(double minHeadingOffset);

    double minCameraPitchOffset() const;
    void setMinCameraPitchOffset(double minPitchOffset);

    Point targetLocation() const;

    TaskWatcher moveCamera(double distanceDelta,
                           double headingDelta,
                           double pitchDelta,
                           float duration);

    /*! \internal */
    OrbitLocationCameraController(const std::shared_ptr<QRTImpl::CameraControllerImpl>& impl, QObject* parent = nullptr);

  signals:
    void cameraDistanceChanged();
    void cameraHeadingOffsetChanged();
    void cameraPitchOffsetChanged();
    void moveCameraCompleted(QUuid taskId, bool succeeded);

  private:
    void connectSignals();
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_OrbitLocationCameraController_H
