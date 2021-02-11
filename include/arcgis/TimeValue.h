// COPYRIGHT 1995-2018 ESRI
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
/// \file TimeValue.h

#ifndef QRT_TimeValue_H
#define QRT_TimeValue_H

// C++ API headers
#include "ServiceTypes.h"

// STL headers
#include <memory>

namespace QRTImpl { class TimeValueImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class TimeValue
  {
  public:
    TimeValue();
    TimeValue(double duration, TimeUnit unit);
    TimeValue(const TimeValue& other);
    TimeValue(TimeValue&& other) noexcept;

    TimeValue& operator=(const TimeValue& other);
    TimeValue& operator=(TimeValue&& other) noexcept;

    bool isEmpty() const;

    double duration() const;
    TimeUnit unit() const;

    /*! \internal */
    explicit TimeValue(const std::shared_ptr<QRTImpl::TimeValueImpl>& impl);
    std::shared_ptr<QRTImpl::TimeValueImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::TimeValueImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_TimeValue_H
