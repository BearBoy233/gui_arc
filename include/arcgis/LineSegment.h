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
/// \file LineSegment.h

#ifndef QRT_LineSegment_H
#define QRT_LineSegment_H

// C++ API headers
#include "Segment.h"

namespace QRTImpl { class LineSegmentImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class LineSegment : public Segment
  {
  public:
    LineSegment();

    ~LineSegment();

    LineSegment(const Point& startPoint,
                const Point& endPoint);

    LineSegment(const Point& startPoint,
                const Point& endPoint,
                const SpatialReference& spatialReference);

    LineSegment(double xStart,
                double yStart,
                double xEnd,
                double yEnd);

    LineSegment(double xStart,
                double yStart,
                double xEnd,
                double yEnd,
                const SpatialReference& spatialReference);

    LineSegment(double xStart,
                double yStart,
                double zStart,
                double xEnd,
                double yEnd,
                double zEnd);

    LineSegment(double xStart,
                double yStart,
                double zStart,
                double xEnd,
                double yEnd,
                double zEnd,
                const SpatialReference& spatialReference);

    LineSegment(const LineSegment& other);

    LineSegment(LineSegment&& other) noexcept;

    LineSegment& operator=(const LineSegment& other);

    LineSegment& operator=(LineSegment&& other) noexcept;

    static LineSegment createLineAtAngleFromStartPoint(const Point& startPoint, double angleRadians, double length);

    /*!
       \internal
     */
    LineSegment(const std::shared_ptr<QRTImpl::LineSegmentImpl>& impl);

    std::shared_ptr<QRTImpl::LineSegmentImpl> getImpl() const;

  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_LineSegment_H
