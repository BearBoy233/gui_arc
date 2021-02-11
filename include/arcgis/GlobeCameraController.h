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
/// \file GlobeCameraController.h

#ifndef QRT_GlobeCameraController_H
#define QRT_GlobeCameraController_H

// C++ API headers
#include "CameraController.h"

namespace Esri {
namespace ArcGISRuntime {

  class GlobeCameraController : public CameraController
  {
    Q_OBJECT

  public:
    GlobeCameraController(QObject* parent = nullptr);
    ~GlobeCameraController();

    /*! \internal */
    explicit GlobeCameraController(const std::shared_ptr<QRTImpl::CameraControllerImpl>& impl, QObject* parent = nullptr);
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_GlobeCameraController_H
