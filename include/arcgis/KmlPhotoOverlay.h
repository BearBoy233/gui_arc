// COPYRIGHT 1995-2018 ESRI
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
/// \file KmlPhotoOverlay.h

#ifndef QRT_KmlPhotoOverlay_H
#define QRT_KmlPhotoOverlay_H

// C++ API headers
#include "KmlNode.h"

namespace Esri {
namespace ArcGISRuntime {

  class KmlPhotoOverlay : public KmlNode
  {
    Q_OBJECT

  public:
    ~KmlPhotoOverlay();

    /*! \internal */
    explicit KmlPhotoOverlay(const std::shared_ptr<QRTImpl::KmlNodeImpl>& impl, QObject* parent = nullptr);

  private:
    Q_DISABLE_COPY(KmlPhotoOverlay)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_KmlPhotoOverlay_H
