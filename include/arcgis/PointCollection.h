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
/// \file PointCollection.h

#ifndef QRT_PointCollection_H
#define QRT_PointCollection_H

// C++ API headers
#include "ImmutablePointCollection.h"
#include "Object.h"
#include "Point.h"
#include "SpatialReference.h"

namespace QRTImpl { class PointCollectionImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class PointCollection : public Object
  {
    Q_OBJECT

  public:
    PointCollection(const SpatialReference& spatialReference, QObject* parent = nullptr);

    ~PointCollection();

    bool isEmpty() const;

    int size() const;

    SpatialReference spatialReference() const;

    Point point(int index) const;

    int indexOf(const Point& point) const;

    int addPoint(const Point& point);

    int addPoint(double x, double y);

    int addPoint(double x, double y, double z);

    void addPoints(const QList<Point>& points);

    void setPoint(int pointIndex, const Point& point);

    void addPoints(PointCollection* points);

    void addPoints(const ImmutablePointCollection& points);

    void insertPoint(int pointIndex, const Point& point);

    void insertPoint(int pointIndex, double x, double y);

    void insertPoint(int pointIndex, double x, double y, double z);

    void removeAll();

    void removePoint(int pointIndex);

    std::shared_ptr<QRTImpl::PointCollectionImpl> getImpl() const;

    /*!
     \internal
     */
    PointCollection(const std::shared_ptr<QRTImpl::PointCollectionImpl>& impl, QObject* parent = nullptr);

  private:
    std::shared_ptr<QRTImpl::PointCollectionImpl> m_impl;
    Q_DISABLE_COPY(PointCollection)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_PointCollection_H

