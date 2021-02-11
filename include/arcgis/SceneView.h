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
/// \file SceneView.h

#ifndef QRT_SceneView_H
#define QRT_SceneView_H

// C++ API headers
#include "AnalysisOverlayListModel.h"
#include "Camera.h"
#include "CameraController.h"
#include "GeoView.h"
#include "LocationToScreenResult.h"
#include "SceneViewTypes.h"

// Qt headers
#include <QtGlobal>

namespace QRTImpl {
  class SceneViewImpl;
  class DeviceImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class Scene;

  class SceneView : public GeoView
  {
  public:
    ~SceneView();

    int sceneHeight() const;
    int sceneWidth() const;

    void setArcGISScene(Scene* scene);
    Scene* arcGISScene() const;

    QColor ambientLightColor() const;
    void setAmbientLightColor(const QColor& color);

    AtmosphereEffect atmosphereEffect() const;
    void setAtmosphereEffect(AtmosphereEffect atmosphereEffect);

    LightingMode sunLighting() const;
    void setSunLighting(LightingMode lightingMode);

    QDateTime sunTime() const;
    void setSunTime(const QDateTime& sunTime);

    LocationToScreenResult locationToScreen(const Point& scenePoint) const;
    Point screenToBaseSurface(double screenX, double screenY) const;
    TaskWatcher screenToLocation(double screenX, double screenY);

    Camera currentViewpointCamera() const;
    void setViewpointCameraAndWait(const Camera& camera);

    CameraController* cameraController() const;
    void setCameraController(CameraController* cameraController);

    AnalysisOverlayListModel* analysisOverlays() const;

#if defined(Q_OS_ANDROID)
    static quint64 memoryLimit();
    static void setMemoryLimit(quint64 memoryLimitBytes);
#endif

    // async methods
    TaskWatcher setViewpointCamera(const Camera& camera);
    TaskWatcher setViewpointCamera(const Camera& camera, float durationSeconds);

    /*!
      \internal
     */
    SceneView(const std::shared_ptr<QRTImpl::SceneViewImpl>& impl);
    std::shared_ptr<QRTImpl::SceneViewImpl> getImpl() const;

  protected:
    SceneView(int width, int height);

    virtual void screenToLocationCompletedEvent(QUuid taskId, const Point& location);
    virtual void setViewpointCameraCompletedEvent(bool success);

  private:
    Q_DISABLE_COPY(SceneView)

    void connectSignals();

    QObject m_sceneViewConnectionContext;
  };

} // namespace ArcGISRuntime
} // namespace Esri

Q_DECLARE_INTERFACE(Esri::ArcGISRuntime::SceneView, "Esri::ArcGISRuntime::SceneView")

#endif // QRT_SceneView_H
