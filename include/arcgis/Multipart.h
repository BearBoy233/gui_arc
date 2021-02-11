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
/// \file Multipart.h

#ifndef QRT_Multipart_H
#define QRT_Multipart_H

// C++ API headers
#include "Geometry.h"
#include "ImmutablePartCollection.h"

// STL headers
#include <memory>

namespace QRTImpl { class MultipartImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class Multipart : public Geometry
  {
  public:
    Multipart(const Multipart& other);
    Multipart(Multipart&& other) noexcept;
    Multipart(const Geometry& other);

    Multipart& operator=(const Multipart& other);
    Multipart& operator=(Multipart&& other) noexcept;

    ~Multipart();

    bool isValid() const;

    ImmutablePartCollection parts() const;

    /*!
       \internal
     */
    explicit Multipart(const std::shared_ptr<QRTImpl::MultipartImpl>& impl);
    std::shared_ptr<QRTImpl::MultipartImpl> getImpl() const;

  protected:
    Multipart();
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_Multipart_H

