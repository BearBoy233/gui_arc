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
/// \file DirectionEvent.h

#ifndef QRT_DirectionEvent_H
#define QRT_DirectionEvent_H

// C++ API headers
#include "DirectionMessage.h"
#include "Point.h"

// Qt headers
#include <QDateTime>
#include <QList>
#include <QString>

// STL headers
#include <memory>

namespace QRTImpl { class DirectionEventImpl; }

namespace Esri {
namespace ArcGISRuntime {

class DirectionEvent
{
public:
  DirectionEvent();
  DirectionEvent(const DirectionEvent& other);
  DirectionEvent(DirectionEvent&& other) noexcept;
  ~DirectionEvent();

  DirectionEvent& operator=(const DirectionEvent& other);
  DirectionEvent& operator=(DirectionEvent&& other) noexcept;

  bool isEmpty() const;

  QDateTime estimatedArrivalTime() const;

  double estimatedArrivalTimeShift() const;

  QString eventText() const;

  QList<DirectionMessage> eventMessages() const;

  Point geometry() const;

  /*!
     \internal
   */
  DirectionEvent(const std::shared_ptr<QRTImpl::DirectionEventImpl>& impl);
  std::shared_ptr<QRTImpl::DirectionEventImpl> getImpl() const;

private:
  std::shared_ptr<QRTImpl::DirectionEventImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_DirectionEvent_H
