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
/// \file KmlGeometry.h

#ifndef QRT_KmlGeometry_H
#define QRT_KmlGeometry_H

// C++ API headers
#include "Geometry.h"
#include "MapTypes.h"

// STL headers
#include <memory>

namespace QRTImpl { class KmlGeometryImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class KmlGeometry
  {
  public:
    KmlGeometry();
    KmlGeometry(const KmlGeometry& other);
    KmlGeometry(KmlGeometry&& other) noexcept;
    ~KmlGeometry();

    KmlGeometry& operator=(const KmlGeometry& other);
    KmlGeometry& operator=(KmlGeometry&& other) noexcept;

    bool isEmpty() const;

    KmlAltitudeMode altitudeMode() const;

    Geometry geometry() const;

    bool isExtruded() const;

    bool isTessellated() const;

    KmlGeometryType type() const;

    /*! \internal */
    explicit KmlGeometry(const std::shared_ptr<QRTImpl::KmlGeometryImpl>& impl);
    std::shared_ptr<QRTImpl::KmlGeometryImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::KmlGeometryImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_KmlGeometry_H
