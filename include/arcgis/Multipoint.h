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
/// \file Multipoint.h

#ifndef QRT_Multipoint_H
#define QRT_Multipoint_H

// C++ API headers
#include "Geometry.h"
#include "ImmutablePointCollection.h"

// STL headers
#include <memory>

namespace QRTImpl { class MultipointImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class Multipoint : public Geometry
  {
  public:
    Multipoint();

    Multipoint(const Multipoint& other);
    Multipoint(Multipoint&& other) noexcept;
    Multipoint(const Geometry& other);

    Multipoint& operator=(const Multipoint& other);
    Multipoint& operator=(Multipoint&& other) noexcept;

    ~Multipoint();

    ImmutablePointCollection points() const;

    bool isValid() const;

    /*! \internal */
    explicit Multipoint(const std::shared_ptr<QRTImpl::MultipointImpl>& impl);
    std::shared_ptr<QRTImpl::MultipointImpl> getImpl() const;
  };

  /*! \internal */
  template<>
  inline Multipoint geometry_cast<Multipoint>(const Geometry& geometry)
  {
    return geometry.geometryType() == GeometryType::Multipoint ? static_cast<Multipoint>(geometry) : Multipoint();
  }

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_Multipoint_H

