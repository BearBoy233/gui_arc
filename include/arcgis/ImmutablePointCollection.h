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
/// \file ImmutablePointCollection.h

#ifndef QRT_ImmutablePointCollection_H
#define QRT_ImmutablePointCollection_H

// C++ API headers
#include "Point.h"
#include "SpatialReference.h"

// STL headers
#include <memory>

namespace QRTImpl { class ImmutablePointCollectionImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class ImmutablePointCollection
  {
  public:
    ImmutablePointCollection();

    ImmutablePointCollection(const ImmutablePointCollection& other);

    ImmutablePointCollection(ImmutablePointCollection&& other) noexcept;

    ~ImmutablePointCollection();

    ImmutablePointCollection& operator=(const ImmutablePointCollection& other);

    ImmutablePointCollection& operator=(ImmutablePointCollection&& other) noexcept;

    bool isEmpty() const;

    int size() const;

    SpatialReference spatialReference() const;

    Point point(int index) const;

    int indexOf(const Point& point) const;

    std::shared_ptr<QRTImpl::ImmutablePointCollectionImpl> getImpl() const;

    /*! \internal */
    ImmutablePointCollection(const std::shared_ptr<QRTImpl::ImmutablePointCollectionImpl>& impl);

  private:
    std::shared_ptr<QRTImpl::ImmutablePointCollectionImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ImmutablePointCollection_H

