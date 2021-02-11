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
/// \file TimeExtent.h

#ifndef QRT_TimeExtent_H
#define QRT_TimeExtent_H

// Qt headers
#include <QDateTime>

// STL headers
#include <memory>

namespace QRTImpl {
  class TimeExtentImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class TimeExtent
  {
  public:
    TimeExtent();
    explicit TimeExtent(const QDateTime& timeInstant);
    TimeExtent(const QDateTime& startTime, const QDateTime& endTime);
    TimeExtent(const TimeExtent& other);
    TimeExtent(TimeExtent&& other) noexcept;
    ~TimeExtent();

    TimeExtent& operator=(const TimeExtent& other);
    TimeExtent& operator=(TimeExtent&& other) noexcept;

    bool isEmpty() const;

    QDateTime startTime() const;
    QDateTime endTime() const;

    /*! \internal */
    explicit TimeExtent(const std::shared_ptr<QRTImpl::TimeExtentImpl>& impl);
    std::shared_ptr<QRTImpl::TimeExtentImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::TimeExtentImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_TimeExtent_H
