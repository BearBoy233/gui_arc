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
/// \file GeometryBuilder.h

#ifndef QRT_GeometryBuilder_H
#define QRT_GeometryBuilder_H

// C++ API headers
#include "GeometryTypes.h"
#include "Object.h"

namespace QRTImpl { class GeometryBuilderImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class SpatialReference;
  class Envelope;
  class Geometry;

  class GeometryBuilder : public Object
  {
    Q_OBJECT

  public:
    ~GeometryBuilder();

    static GeometryBuilder* create(const Geometry& geometry, QObject* parent = nullptr);
    static GeometryBuilder* create(GeometryType geometryType, const SpatialReference& spatialReference, QObject* parent = nullptr);

    bool isEmpty() const;

    bool isSketchValid() const;

    virtual GeometryBuilderType geometryBuilderType() const;

    SpatialReference spatialReference() const;

    bool hasZ() const;

    bool hasM() const;

    Envelope extent() const;

    void replaceGeometry(const Geometry& geometry);

    virtual Geometry toGeometry() const;

    GeometryBuilder(const std::shared_ptr<QRTImpl::GeometryBuilderImpl>& impl, QObject* parent = nullptr);

    virtual std::shared_ptr<QRTImpl::GeometryBuilderImpl> getImpl() const;

  protected:
    friend class Geometry;
    std::shared_ptr<QRTImpl::GeometryBuilderImpl> m_impl;

    /*!
       \internal
     */
    Q_DISABLE_COPY(GeometryBuilder)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_GeometryBuilder_H

