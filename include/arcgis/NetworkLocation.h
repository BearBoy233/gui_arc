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
/// \file NetworkLocation.h

#ifndef QRT_NetworkLocation_H
#define QRT_NetworkLocation_H

// C++ API headers
#include "SourceObjectPosition.h"

// STL headers
#include <memory>

namespace QRTImpl { class NetworkLocationImpl; }

namespace Esri {
namespace ArcGISRuntime {

class NetworkLocation
{
public:
  NetworkLocation();
  NetworkLocation(const NetworkLocation& other);
  NetworkLocation(NetworkLocation&& other) noexcept;
  ~NetworkLocation();

  NetworkLocation& operator=(const NetworkLocation& other);
  NetworkLocation& operator=(NetworkLocation&& other) noexcept;

  bool isEmpty() const;

  bool isOnRightSideOfSource() const;
  void setOnRightSideOfSource(bool onRightSideOfSource);

  QString sourceName() const;
  void setSourceName(const QString& sourceName);

  SourceObjectPosition sourceObjectPosition() const;
  void setSourceObjectPosition(const SourceObjectPosition& sourceObjectPosition);

  /*!
     \internal
   */
  NetworkLocation(const std::shared_ptr<QRTImpl::NetworkLocationImpl>& impl);
  std::shared_ptr<QRTImpl::NetworkLocationImpl> getImpl() const;

private:
  std::shared_ptr<QRTImpl::NetworkLocationImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_NetworkLocation_H
