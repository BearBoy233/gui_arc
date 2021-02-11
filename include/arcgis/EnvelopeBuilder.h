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
/// \file EnvelopeBuilder.h

#ifndef QRT_EnvelopeBuilder_H
#define QRT_EnvelopeBuilder_H

// C++ API headers
#include "GeometryBuilder.h"

namespace QRTImpl { class EnvelopeBuilderImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class SpatialReference;
  class Envelope;
  class Point;

  class EnvelopeBuilder : public GeometryBuilder
  {
    Q_OBJECT

  public:
    EnvelopeBuilder(const Point& center, double width, double height, QObject* parent = nullptr);
    EnvelopeBuilder(const Point& center, double width, double height, double depth, QObject* parent = nullptr);
    EnvelopeBuilder(const Envelope& envelope, QObject* parent = nullptr);
    EnvelopeBuilder(const SpatialReference& spatialReference, QObject* parent = nullptr);

    ~EnvelopeBuilder();

    double xMin() const;

    void setXMin(double xMin);

    double xMax() const;

    void setXMax(double xMax);

    double yMin() const;

    void setYMin(double yMin);

    double yMax() const;

    void setYMax(double yMax);

    double zMin() const;

    void setZMin(double zMin);

    double zMax() const;

    void setZMax(double zMax);

    double mMin() const;

    void setMMin(double mMin);

    double mMax() const;

    void setMMax(double mMax);

    double width() const;

    double height() const;

    double depth() const;

    Point center() const;

    void setM(double mMin, double mMax);

    void setXY(double xMin, double yMin,
               double xMax, double yMax);

    void setZ(double zMin, double zMax);

    void centerAtPoint(const Point& point);

    void unionWithEnvelope(const Envelope& envelope);

    void unionWithPoint(const Point& point);

    void expandByFactor(double factor);

    void expandByFactor(double factor, const Point& anchorPoint);

    void reaspect(double width, double height);

    void offsetBy(double offsetX, double offsetY);

    Geometry toGeometry() const override;

    Envelope toEnvelope() const;

    /*!
     \internal
     */
    GeometryBuilderType geometryBuilderType() const override;

    /*!
       \brief EnvelopeBuilder
       \internal
     */
    EnvelopeBuilder(const std::shared_ptr<QRTImpl::EnvelopeBuilderImpl>& impl, QObject* parent = nullptr);

    /*!
      \brief getImpl
      \internal
      */
    std::shared_ptr<QRTImpl::GeometryBuilderImpl> getImpl() const override;

  private:
    Q_DISABLE_COPY(EnvelopeBuilder)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_EnvelopeBuilder_H

