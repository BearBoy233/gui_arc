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
/// \file OrbitGeoElementCameraController.h

#ifndef QRT_OrbitGeoElementCameraController_H
#define QRT_OrbitGeoElementCameraController_H

// C++ API headers
#include "CameraController.h"
#include "GeoElement.h"
#include "TaskWatcher.h"

namespace Esri {
namespace ArcGISRuntime {

  class OrbitGeoElementCameraController : public CameraController
  {
    Q_OBJECT

  public:
    OrbitGeoElementCameraController(GeoElement* geoElement, double distance, QObject* parent = nullptr);
    ~OrbitGeoElementCameraController();

    double cameraDistance() const;
    void setCameraDistance(double distance);

    double cameraHeadingOffset() const;
    void setCameraHeadingOffset(double cameraHeading);

    double cameraPitchOffset() const;
    void setCameraPitchOffset(double cameraPitch);

    bool isAutoHeadingEnabled() const;
    void setAutoHeadingEnabled(bool enabled);

    bool isAutoPitchEnabled() const;
    void setAutoPitchEnabled(bool enabled);

    bool isAutoRollEnabled() const;
    void setAutoRollEnabled(bool enabled);

    bool isCameraDistanceInteractive() const;
    void setCameraDistanceInteractive(bool interactiveDistance);

    bool isCameraHeadingOffsetInteractive() const;
    void setCameraHeadingOffsetInteractive(bool interactiveHeading);

    bool isCameraPitchOffsetInteractive() const;
    void setCameraPitchOffsetInteractive(bool interactivePitch);

    double maxCameraDistance() const;
    void setMaxCameraDistance(double maxDistance);

    double maxCameraHeadingOffset() const;
    void setMaxCameraHeadingOffset(double maxHeading);

    double maxCameraPitchOffset() const;
    void setMaxCameraPitchOffset(double maxPitch);

    double minCameraDistance() const;
    void setMinCameraDistance(double minDistance);

    double minCameraHeadingOffset() const;
    void setMinCameraHeadingOffset(double minHeading);

    double minCameraPitchOffset() const;
    void setMinCameraPitchOffset(double minPitch);

    GeoElement* targetGeoElement() const;

    float targetVerticalScreenFactor() const;
    void setTargetVerticalScreenFactor(float verticalFactor);

    double targetOffsetX() const;
    void setTargetOffsetX(double offsetX);

    double targetOffsetY() const;
    void setTargetOffsetY(double offsetY);

    double targetOffsetZ() const;
    void setTargetOffsetZ(double offsetZ);

    TaskWatcher moveCamera(double distanceDelta,
                           double headingDelta,
                           double pitchDelta,
                           float duration);

    TaskWatcher setTargetOffsets(double x,
                                 double y,
                                 double z,
                                 float duration);

    /*! \internal */
    OrbitGeoElementCameraController(const std::shared_ptr<QRTImpl::CameraControllerImpl>& impl, QObject* parent = nullptr);

  signals:
    void cameraDistanceChanged();
    void cameraHeadingOffsetChanged();
    void cameraPitchOffsetChanged();
    void moveCameraCompleted(QUuid taskId, bool succeeded);
    void setTargetOffsetsCompleted(QUuid taskId, bool succeeded);

  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_OrbitGeoElementCameraController_H
