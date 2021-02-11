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
/// \file PointBuilder.h

#ifndef QRT_PointBuilder_H
#define QRT_PointBuilder_H

// C++ API headers
#include "GeometryBuilder.h"

namespace QRTImpl { class PointBuilderImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class SpatialReference;
  class Envelope;
  class Point;

  class PointBuilder : public GeometryBuilder
  {
    Q_OBJECT
  public:
    PointBuilder(const Point& point, QObject* parent = nullptr);

    PointBuilder(const SpatialReference& spatialReference, QObject* parent = nullptr);

    ~PointBuilder();

    void setXY(double x, double y);

    void setX(double x);

    void setY(double y);

    void setZ(double z);

    void setM(double m);

    double x() const;

    double y() const;

    double z() const;

    double m() const;

    void offsetBy(double offsetX, double offsetY);

    Geometry toGeometry() const override;

    Point toPoint() const;

    GeometryBuilderType geometryBuilderType() const override;

    /*!
       Internal
     */
    PointBuilder(const std::shared_ptr<QRTImpl::PointBuilderImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::GeometryBuilderImpl> getImpl() const override;

  private:
    Q_DISABLE_COPY(PointBuilder)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_GeometryBuilder_H

