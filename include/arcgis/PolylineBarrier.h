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
/// \file PolylineBarrier.h

#ifndef QRT_PolylineBarrier_H
#define QRT_PolylineBarrier_H

// C++ API headers
#include "NetworkAnalystTypes.h"
#include "Polyline.h"

// STL headers
#include <memory>

namespace QRTImpl { class PolylineBarrierImpl; }

namespace Esri {
namespace ArcGISRuntime {

class PolylineBarrier
{
public:
  PolylineBarrier();
  explicit PolylineBarrier(const Polyline& polyline);
  PolylineBarrier(const PolylineBarrier& other);
  PolylineBarrier(PolylineBarrier&& other) noexcept;
  ~PolylineBarrier();

  PolylineBarrier& operator=(const PolylineBarrier& other);
  PolylineBarrier& operator=(PolylineBarrier&& other) noexcept;

  bool isEmpty() const;

  Polyline geometry() const;
  void setGeometry(const Polyline& polyline);

  QString name() const;
  void setName(const QString& name);

  BarrierType barrierType() const;
  void setBarrierType(BarrierType type);

  double scaleFactorForCost(const QString& attributeName) const;
  void setScaleFactorForCost(const QString& attributeName, double scaleFactorForCost);

  /*!
     \internal
   */
  PolylineBarrier(const std::shared_ptr<QRTImpl::PolylineBarrierImpl>& impl);
  std::shared_ptr<QRTImpl::PolylineBarrierImpl> getImpl() const;

private:
  std::shared_ptr<QRTImpl::PolylineBarrierImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_PolylineBarrier_H
