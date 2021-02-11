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
/// \file ImmutablePartCollection.h

#ifndef QRT_ImmutablePartCollection_H
#define QRT_ImmutablePartCollection_H

// C++ API headers
#include "ImmutablePart.h"
#include "SpatialReference.h"

// STL headers
#include <memory>

namespace QRTImpl { class ImmutablePartCollectionImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class ImmutablePartCollection
  {
  public:
    ImmutablePartCollection();

    ImmutablePartCollection(const ImmutablePartCollection& other);

    ImmutablePartCollection(ImmutablePartCollection&& other) noexcept;

    ~ImmutablePartCollection();

    ImmutablePartCollection& operator=(const ImmutablePartCollection& other);

    ImmutablePartCollection& operator=(ImmutablePartCollection&& other) noexcept;

    bool isEmpty() const;

    int size() const;

    SpatialReference spatialReference() const;

    ImmutablePart part(int index) const;

    int indexOf(const ImmutablePart& part) const;

    std::shared_ptr<QRTImpl::ImmutablePartCollectionImpl> getImpl() const;

    /*! \internal */
    ImmutablePartCollection(const std::shared_ptr<QRTImpl::ImmutablePartCollectionImpl>& impl);

  private:
    std::shared_ptr<QRTImpl::ImmutablePartCollectionImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ImmutablePartCollection_H

