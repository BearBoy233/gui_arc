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
/// \file Polyline.h

#ifndef QRT_Polyline_H
#define QRT_Polyline_H

// C++ API headers
#include "Multipart.h"

// STL headers
#include <memory>

namespace QRTImpl { class PolylineImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class Polyline : public Multipart
  {
  public:
    Polyline();

    Polyline(const Polyline& other);
    Polyline(Polyline&& other) noexcept;
    Polyline(const Geometry& other);

    Polyline& operator=(const Polyline& other);
    Polyline& operator=(Polyline&& other) noexcept;

    ~Polyline();

    bool isValid() const;

    /*! \internal */
    explicit Polyline(const std::shared_ptr<QRTImpl::PolylineImpl>& impl);
    std::shared_ptr<QRTImpl::PolylineImpl> getImpl() const;
  };

  /*! \internal */
  template<>
  inline Polyline geometry_cast<Polyline>(const Geometry& geometry)
  {
    return geometry.geometryType() == GeometryType::Polyline ? static_cast<Polyline>(geometry) : Polyline();
  }

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_Polyline_H

