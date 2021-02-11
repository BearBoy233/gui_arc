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
/// \file RouteResult.h

#ifndef QRT_RouteResult_H
#define QRT_RouteResult_H

// C++ API headers
#include "PointBarrier.h"
#include "PolygonBarrier.h"
#include "PolylineBarrier.h"
#include "Route.h"

// Qt headers
#include <QDateTime>
#include <QList>
#include <QStringList>

// STL headers
#include <memory>

namespace QRTImpl { class RouteResultImpl; }

namespace Esri {
namespace ArcGISRuntime {

class RouteResult
{
public:
  RouteResult();
  RouteResult(const RouteResult& other);
  RouteResult(RouteResult&& other) noexcept;
  ~RouteResult();

  RouteResult& operator=(const RouteResult& other);
  RouteResult& operator=(RouteResult&& other) noexcept;

  bool isEmpty() const;

  QStringList messages() const;

  QList<PointBarrier> pointBarriers() const;

  QList<PolygonBarrier> polygonBarriers() const;

  QList<PolylineBarrier> polylineBarriers() const;

  QList<Route> routes() const;

  QString directionsLanguage() const;

  /*!
     \internal
   */
  RouteResult(const std::shared_ptr<QRTImpl::RouteResultImpl>& impl);
  std::shared_ptr<QRTImpl::RouteResultImpl> getImpl() const;

private:
  std::shared_ptr<QRTImpl::RouteResultImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_RouteResult_H
