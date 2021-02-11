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
/// \file ImmutablePart.h

#ifndef QRT_ImmutablePart_H
#define QRT_ImmutablePart_H

// C++ API headers
#include "ImmutablePointCollection.h"
#include "Point.h"
#include "Segment.h"
#include "SpatialReference.h"

// STL headers
#include <memory>

namespace QRTImpl { class ImmutablePartImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class ImmutablePart
  {
  public:
    ImmutablePart();

    ImmutablePart(const ImmutablePart& other);

    ImmutablePart(ImmutablePart&& other) noexcept;

    ~ImmutablePart();

    ImmutablePart& operator=(const ImmutablePart& other);

    ImmutablePart& operator=(ImmutablePart&& other) noexcept;

    bool isEmpty() const;

    bool hasCurves() const;

    SpatialReference spatialReference() const;

    int pointCount() const;

    Point point(int pointIndex) const;

    Point startPoint() const;

    Point endPoint() const;

    ImmutablePointCollection points() const;

    int startPointIndexFromSegmentIndex(int segmentIndex) const;

    int endPointIndexFromSegmentIndex(int segmentIndex) const;

    int segmentCount() const;

    Segment segment(int segmentIndex) const;

    int segmentIndexFromStartPointIndex(int pointIndex) const;

    int segmentIndexFromEndPointIndex(int pointIndex) const;

    void segmentIndexFromPointIndex(int pointIndex, int& outStartPointSegmentIndex, int& outEndPointSegmentIndex) const;

    std::shared_ptr<QRTImpl::ImmutablePartImpl> getImpl() const;

    /*! \internal */
    ImmutablePart(const std::shared_ptr<QRTImpl::ImmutablePartImpl>& impl);

  private:
    std::shared_ptr<QRTImpl::ImmutablePartImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ImmutablePart_H

