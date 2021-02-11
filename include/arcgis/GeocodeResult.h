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
/// \file GeocodeResult.h

#ifndef QRT_GeocodeResult_H
#define QRT_GeocodeResult_H

// C++ API headers
#include "ArcGISQt_global.h"
#include "Envelope.h"
#include "Point.h"

// Qt headers
#include <QVariantMap>

// STL headers
#include <memory>

namespace QRTImpl { class GeocodeResultImpl; }

namespace Esri {
namespace ArcGISRuntime {

class GeocodeResult
{
public:
  GeocodeResult();
  GeocodeResult(const GeocodeResult& other);
  GeocodeResult(GeocodeResult&& other) noexcept;
  GeocodeResult& operator=(const GeocodeResult& other);
  GeocodeResult& operator=(GeocodeResult&& other) noexcept;
  ~GeocodeResult();

  QVariantMap attributes() const;

  Point displayLocation() const;

  Envelope extent() const;

  Point inputLocation() const;

  QString label() const;

  Point routeLocation() const;

  double score() const;

  bool isEmpty() const;

  /*!
     \internal
   */
  GeocodeResult(const std::shared_ptr<QRTImpl::GeocodeResultImpl>& impl);
  std::shared_ptr<QRTImpl::GeocodeResultImpl> getImpl() const;

private:
  std::shared_ptr<QRTImpl::GeocodeResultImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_GeocodeResult_H
