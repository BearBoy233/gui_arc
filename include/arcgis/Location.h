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
/// \file Location.h

#ifndef QRT_Location_H
#define QRT_Location_H

// C++ API headers
#include "ArcGISQt_global.h"
#include "Point.h"

namespace QRTImpl { class LocationImpl; }

namespace Esri {
namespace ArcGISRuntime {

class Location
{
public:
  Location();
  ~Location();
  Location(const Location& other);
  Location(Location&& other) noexcept;
  Location& operator=(const Location& other);
  Location& operator=(Location&& other) noexcept;

  double course() const;

  double horizontalAccuracy() const;

  bool isLastKnown() const;

  Point position() const;

  double velocity() const;

  /*!
     \internal
   */
  Location(const std::shared_ptr<QRTImpl::LocationImpl>& impl);
  std::shared_ptr<QRTImpl::LocationImpl> getImpl() const;

private:
  std::shared_ptr<QRTImpl::LocationImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_Location_H
