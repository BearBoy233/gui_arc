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
/// \file TimeReference.h

#ifndef QRT_TimeReference_H
#define QRT_TimeReference_H

// C++ API headers
#include "ArcGISQt_global.h"

// STL headers
#include <memory>

namespace QRTImpl {
  class TimeReferenceImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class TimeReference
  {
  public:
    TimeReference();
    ~TimeReference();
    TimeReference(const TimeReference& other);
    TimeReference(TimeReference&& other) noexcept;
    TimeReference& operator=(const TimeReference& other);
    TimeReference& operator=(TimeReference&& other) noexcept;

    bool isRespectsDaylightSavings() const;

    QString timeZone() const;

    explicit TimeReference(const std::shared_ptr<QRTImpl::TimeReferenceImpl>& impl);
    std::shared_ptr<QRTImpl::TimeReferenceImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::TimeReferenceImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_TimeReference_H
