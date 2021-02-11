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
/// \file ArcGISTiledSublayer.h

#ifndef QRT_ArcGISTiledSublayer_H
#define QRT_ArcGISTiledSublayer_H

// C++ API headers
#include "ArcGISSublayer.h"

namespace QRTImpl {
  class TileKeyImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class ArcGISTiledSublayer : public ArcGISSublayer
  {
    Q_OBJECT

  public:
    ~ArcGISTiledSublayer();

    /*!
       \internal
     */
    explicit ArcGISTiledSublayer(const std::shared_ptr<QRTImpl::ArcGISSublayerImpl>& impl, QObject* parent = nullptr);

  private:
    Q_DISABLE_COPY(ArcGISTiledSublayer)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ArcGISTiledSublayer_H
