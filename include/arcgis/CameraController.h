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
/// \file CameraController.h

#ifndef QRT_CameraController_H
#define QRT_CameraController_H

// C++ API headers
#include "Object.h"
#include "SceneViewTypes.h"

namespace QRTImpl { class CameraControllerImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class CameraController : public Object
  {
    Q_OBJECT

  public:
    ~CameraController();

    CameraControllerType cameraControllerType() const;

    /*! \internal */
    explicit CameraController(const std::shared_ptr<QRTImpl::CameraControllerImpl>& impl, QObject* parent = nullptr);

    std::shared_ptr<QRTImpl::CameraControllerImpl> getImpl() const;

  protected:
    std::shared_ptr<QRTImpl::CameraControllerImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_CameraController_H
