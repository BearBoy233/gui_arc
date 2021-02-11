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
/// \file PointBarrier.h

#ifndef QRT_PointBarrier_H
#define QRT_PointBarrier_H

// C++ API headers
#include "NetworkAnalystTypes.h"
#include "Point.h"

// STL headers
#include <memory>

namespace QRTImpl { class PointBarrierImpl; }

namespace Esri {
namespace ArcGISRuntime {

class PointBarrier
{
public:
  PointBarrier();
  explicit PointBarrier(const Point& point);
  PointBarrier(const PointBarrier& other);
  PointBarrier(PointBarrier&& other) noexcept;
  ~PointBarrier();

  PointBarrier& operator=(const PointBarrier& other);
  PointBarrier& operator=(PointBarrier&& other) noexcept;

  bool isEmpty() const;

  CurbApproach curbApproach() const;
  void setCurbApproach(CurbApproach curbApproach);

  Point geometry() const;
  void setGeometry(const Point& point);

  QString name() const;
  void setName(const QString& name);

  LocationStatus locationStatus() const;

  BarrierType barrierType() const;
  void setBarrierType(BarrierType type);

  double addedCost(const QString& attributeName) const;
  void setAddedCost(const QString& attributeName, double addedCost);

  /*!
     \internal
   */
  PointBarrier(const std::shared_ptr<QRTImpl::PointBarrierImpl>& impl);
  std::shared_ptr<QRTImpl::PointBarrierImpl> getImpl() const;

private:
  std::shared_ptr<QRTImpl::PointBarrierImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_PointBarrier_H
