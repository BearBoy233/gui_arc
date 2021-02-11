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
/// \file FrameCameraAddRastersParameters.h

#ifndef QRT_FrameCameraAddRastersParameters_H
#define QRT_FrameCameraAddRastersParameters_H

// C++ API headers
#include "AddRastersParameters.h"

// Qt headers
#include <QString>

namespace QRTImpl { class FrameCameraAddRastersParametersImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class FrameCameraAddRastersParameters : public AddRastersParameters
  {

  public:
    FrameCameraAddRastersParameters();
    FrameCameraAddRastersParameters(const FrameCameraAddRastersParameters& other);
    FrameCameraAddRastersParameters(const AddRastersParameters& other);
    FrameCameraAddRastersParameters(FrameCameraAddRastersParameters&& other) noexcept;

    ~FrameCameraAddRastersParameters();

    FrameCameraAddRastersParameters& operator=(const FrameCameraAddRastersParameters& other);
    FrameCameraAddRastersParameters& operator=(FrameCameraAddRastersParameters&& other) noexcept;

    QString camerasFile() const;
    void setCamerasFile(const QString& cameras);

    QString framesFile() const;
    void setFramesFile(const QString& frames);

    bool isShareRasterInfo() const;
    void setShareRasterInfo(bool status);

    /*!
       \internal
     */
    FrameCameraAddRastersParameters(const std::shared_ptr<QRTImpl::FrameCameraAddRastersParametersImpl>& impl);
    std::shared_ptr<QRTImpl::FrameCameraAddRastersParametersImpl> getImpl() const;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_FrameCameraAddRastersParameters_H
