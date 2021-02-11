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
/// \file DirectionMessage.h

#ifndef QRT_DirectionMessage_H
#define QRT_DirectionMessage_H

// C++ API headers
#include "NetworkAnalystTypes.h"

// Qt headers
#include <QString>

// STL headers
#include <memory>

namespace QRTImpl { class DirectionMessageImpl; }

namespace Esri {
namespace ArcGISRuntime {

class DirectionMessage
{
public:
  DirectionMessage();
  DirectionMessage(const DirectionMessage& other);
  DirectionMessage(DirectionMessage&& other) noexcept;
  ~DirectionMessage();

  DirectionMessage& operator=(const DirectionMessage& other);
  DirectionMessage& operator=(DirectionMessage&& other) noexcept;

  bool isEmpty() const;

  QString text() const;

  DirectionMessageType directionMessageType() const;

  /*!
     \internal
   */
  DirectionMessage(const std::shared_ptr<QRTImpl::DirectionMessageImpl>& impl);
  std::shared_ptr<QRTImpl::DirectionMessageImpl> getImpl() const;

private:
  std::shared_ptr<QRTImpl::DirectionMessageImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_DirectionMessage_H
