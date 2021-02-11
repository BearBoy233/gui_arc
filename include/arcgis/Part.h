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
/// \file Part.h

#ifndef QRT_Part_H
#define QRT_Part_H

// C++ API headers
#include "ImmutablePointCollection.h"
#include "Object.h"
#include "Point.h"
#include "Segment.h"
#include "SpatialReference.h"

namespace QRTImpl { class PartImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class Part : public Object
  {
    Q_OBJECT

  public:
    Part(const SpatialReference& spatialReference, QObject* parent = nullptr);

    ~Part();

    bool isEmpty() const;

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

    int addPoint(const Point& point);

    int addPoint(double x, double y);

    int addPoint(double x, double y, double z);

    void addPoints(const QList<Point>& points);

    void insertPoint(int pointIndex, const Point& point);

    void insertPoint(int pointIndex, double x, double y);

    void insertPoint(int pointIndex, double x, double y, double z);

    void setPoint(int pointIndex, const Point& point);

    void removePoint(int pointIndex);

    int addSegment(const Segment& segment);

    void insertSegment(int segmentIndex, const Segment& segment);

    void setSegment(int segmentIndex, const Segment& segment);

    void removeSegment(int segmentIndex);

    void removeAll();

    std::shared_ptr<QRTImpl::PartImpl> getImpl() const;

    /*!
     \internal
     */
    Part(const std::shared_ptr<QRTImpl::PartImpl>& impl, QObject* parent = nullptr);

  private:
    std::shared_ptr<QRTImpl::PartImpl> m_impl;
    Q_DISABLE_COPY(Part)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_Part_H

