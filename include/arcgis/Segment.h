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
/// \file Segment.h

#ifndef QRT_Segment_H
#define QRT_Segment_H

// C++ API headers
#include "Point.h"
#include "SpatialReference.h"

namespace QRTImpl { class SegmentImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class Segment
  {
  public:
    ~Segment();

    Segment(const Segment& other);

    Segment(Segment&& other) noexcept;

    Segment& operator=(const Segment& other);

    Segment& operator=(Segment&& other) noexcept;

    Point startPoint() const;

    Point endPoint() const;

    bool isClosed() const;

    SegmentType segmentType() const;

    SpatialReference spatialReference() const;

    bool operator==(const Segment& other) const;

    /*! \internal */
    Segment(const std::shared_ptr<QRTImpl::SegmentImpl>& impl);

    std::shared_ptr<QRTImpl::SegmentImpl> getImpl() const;

  protected:
    Segment();
    std::shared_ptr<QRTImpl::SegmentImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_Segment_H
