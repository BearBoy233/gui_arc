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
/// \file KmlViewpoint.h

#ifndef QRT_KmlViewpoint_H
#define QRT_KmlViewpoint_H

// C++ API headers
#include "MapTypes.h"
#include "Point.h"

namespace QRTImpl { class KmlViewpointImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class KmlViewpoint
  {
  public:
    KmlViewpoint();
    KmlViewpoint(const KmlViewpoint& other);
    KmlViewpoint(KmlViewpoint&& other) noexcept;
    ~KmlViewpoint();

    KmlViewpoint& operator=(const KmlViewpoint& other);
    KmlViewpoint& operator=(KmlViewpoint&& other) noexcept;

    bool isEmpty() const;

    KmlAltitudeMode altitudeMode() const;

    double heading() const;

    Point location() const;

    double pitch() const;

    double range() const;

    double roll() const;

    KmlViewpointType type() const;

    /*! \internal */
    explicit KmlViewpoint(const std::shared_ptr<QRTImpl::KmlViewpointImpl>& impl);
    std::shared_ptr<QRTImpl::KmlViewpointImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::KmlViewpointImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_KmlViewpoint_H
