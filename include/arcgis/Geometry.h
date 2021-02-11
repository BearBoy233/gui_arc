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
/// \file Geometry.h

#ifndef QRT_Geometry_H
#define QRT_Geometry_H

// C++ API headers
#include "ArcGISQt_global.h"
#include "GeometryTypes.h"
#include "JsonSerializable.h"

// Qt headers
#include <QDebug>

// STL headers
#include <memory>

namespace QRTImpl { class GeometryImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class SpatialReference;
  class Envelope;
  class GeometryBuilder;

  class Geometry : public JsonSerializable
  {
  public:
    Geometry();

    Geometry(const Geometry& other);
    Geometry(Geometry&& other) noexcept;

    Geometry& operator=(const Geometry& other);
    Geometry& operator=(Geometry&& other) noexcept;

    bool operator==(const Geometry& other) const;

    ~Geometry();

    bool isEmpty() const;

    bool equalsWithTolerance(const Geometry& other, double tolerance) const;

    GeometryType geometryType() const;

    SpatialReference spatialReference() const;

    int dimension() const;

    bool hasZ() const;

    bool hasM() const;

    bool hasCurves() const;

    Envelope extent() const;

    static Geometry fromJson(const QString& json);

    QString toJson() const override;

    QJsonObject unknownJson() const override;

    QJsonObject unsupportedJson() const override;

    /*!
       \internal
     */
    explicit Geometry(const std::shared_ptr<QRTImpl::GeometryImpl>& impl);
    std::shared_ptr<QRTImpl::GeometryImpl> getImpl() const;

  protected:
    std::shared_ptr<QRTImpl::GeometryImpl> m_impl;
  };

  /*!
    \brief Type-safe cast helper for geometry types.

    Cast Geometry-derived class to Geometry is always valid.

    \code
    Point point(x, y);
    Geometry geometry = geometry_cast<Geometry>(point);
    \endcode

    But cast from Geometry to Geometry-derived class is valid only if \l Geometry::geometryType
    is the same type as target type.

    \code
    const QString pointJson = "{\"x\":5, \"y\":10}";
    Geometry geometry = Geometry::fromJson(pointJson);
    Point point = geometry_cast<Point>(geometry);
    QASSERT(point.isValid());

    const QString envelopeJson = "{\"xmin\":5, \"ymin\":5, \"xmax\":10, \"ymax\":10}";
    Geometry geometry = Geometry::fromJson(envelopeJson);
    Point invalidPoint = geometry_cast<Point>(geometry);
    QASSERT(!invalidPoint.isValid());
    \endcode

    \since Esri::ArcGISRuntime 100.2
  */
  template<typename T>
  T geometry_cast(const Geometry&)
  {
    return Geometry();
  }

  template<>
  inline Geometry geometry_cast<Geometry>(const Geometry& geometry)
  {
    return geometry;
  }

  /*!
     \internal
   */
  QDebug& operator<< (QDebug& dbg, const Geometry& geometry);

} // namespace ArcGISRuntime
} // namespace Esri

Q_DECLARE_METATYPE(Esri::ArcGISRuntime::Geometry)

#endif // QRT_Geometry_H

