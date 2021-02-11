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
/// \file PolygonBarrier.h

#ifndef QRT_PolygonBarrier_H
#define QRT_PolygonBarrier_H

// C++ API headers
#include "NetworkAnalystTypes.h"
#include "Polygon.h"

// STL headers
#include <memory>

namespace QRTImpl { class PolygonBarrierImpl; }

namespace Esri {
namespace ArcGISRuntime {

class PolygonBarrier
{
public:
  PolygonBarrier();
  explicit PolygonBarrier(const Polygon& polygon);
  PolygonBarrier(const PolygonBarrier& other);
  PolygonBarrier(PolygonBarrier&& other) noexcept;
  ~PolygonBarrier();

  PolygonBarrier& operator=(const PolygonBarrier& other);
  PolygonBarrier& operator=(PolygonBarrier&& other) noexcept;

  bool isEmpty() const;

  Polygon geometry() const;
  void setGeometry(const Polygon& polygon);

  QString name() const;
  void setName(const QString& name);

  BarrierType barrierType() const;
  void setBarrierType(BarrierType type);

  double scaleFactorForCost(const QString& attributeName) const;
  void setScaleFactorForCost(const QString& attributeName, double scaleFactorForCost);

  /*!
     \internal
   */
  PolygonBarrier(const std::shared_ptr<QRTImpl::PolygonBarrierImpl>& impl);
  std::shared_ptr<QRTImpl::PolygonBarrierImpl> getImpl() const;

private:
  std::shared_ptr<QRTImpl::PolygonBarrierImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_PolygonBarrier_H
