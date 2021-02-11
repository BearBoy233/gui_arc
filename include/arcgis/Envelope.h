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
/// \file Envelope.h

#ifndef QRT_Envelope_H
#define QRT_Envelope_H

// C++ API headers
#include "Geometry.h"
#include "Point.h"

// Qt headers
#include <QMetaType>

// STL headers
#include <memory>

namespace QRTImpl { class EnvelopeImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class Envelope : public Geometry
  {

  public:
     Envelope();
     Envelope(double xMin, double yMin,
              double xMax, double yMax);
     Envelope(double xMin, double yMin,
              double xMax, double yMax,
              const SpatialReference& spatialReference);
      Envelope(double xMin, double yMin,
               double xMax, double yMax,
               double zMin, double zMax);
      Envelope(double xMin, double yMin,
               double xMax, double yMax,
               double zMin, double zMax,
               const SpatialReference& spatialReference);
     Envelope(const Point& corner1, const Point& corner2);

     Envelope(const Envelope& other);
     Envelope(Envelope&& other) noexcept;
     Envelope(const Geometry& other);

     Envelope& operator=(const Envelope& other);
     Envelope& operator=(Envelope&& other) noexcept;
     Envelope& operator=(const Geometry& other);

     ~Envelope();

     bool isValid() const;

     double xMin() const;

     double yMin() const;

     double xMax() const;

     double yMax() const;

     double zMin() const;

     double zMax() const;

     double mMin() const;

     double mMax() const;

     double width() const;

     double height() const;

     double depth() const;

     Point center() const;

     static Envelope createWithM(double xMin, double yMin,
                                 double xMax, double yMax,
                                 double mMin, double mMax);

     static Envelope createWithM(double xMin, double yMin,
                                 double xMax, double yMax,
                                 double mMin, double mMax,
                                 const SpatialReference& spatialReference);

     static Envelope createWithM(double xMin, double yMin,
                                 double xMax, double yMax,
                                 double zMin, double zMax,
                                 double mMin, double mMax);

     static Envelope createWithM(double xMin, double yMin,
                                 double xMax, double yMax,
                                 double zMin, double zMax,
                                 double mMin, double mMax,
                                 const SpatialReference& spatialReference);

     /*! \internal */
     explicit Envelope(const std::shared_ptr<QRTImpl::EnvelopeImpl>& impl);
     std::shared_ptr<QRTImpl::EnvelopeImpl> getImpl() const;
  };

  /*! \internal */
  template<>
  inline Envelope geometry_cast<Envelope>(const Geometry& geometry)
  {
    return geometry.geometryType() == GeometryType::Envelope ? static_cast<Envelope>(geometry) : Envelope();
  }

} // namespace ArcGISRuntime
} // namespace Esri

Q_DECLARE_METATYPE(Esri::ArcGISRuntime::Envelope)

#endif // QRT_Envelope_H

