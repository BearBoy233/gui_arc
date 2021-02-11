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
/// \file ServiceTimeInfo.h

#ifndef QRT_ServiceTimeInfo_H
#define QRT_ServiceTimeInfo_H

// C++ API headers
#include "ArcGISQt_global.h"
#include "ServiceTypes.h"
#include "TimeExtent.h"
#include "TimeReference.h"
#include "TimeValue.h"

// STL headers
#include <memory>

namespace QRTImpl {
  class ServiceTimeInfoImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class ServiceTimeInfo
  {
  public:
    ServiceTimeInfo();
    ~ServiceTimeInfo();
    ServiceTimeInfo(const ServiceTimeInfo& other);
    ServiceTimeInfo(ServiceTimeInfo&& other) noexcept;
    ServiceTimeInfo& operator=(const ServiceTimeInfo& other);
    ServiceTimeInfo& operator=(ServiceTimeInfo&& other) noexcept;

    int defaultTimeInterval() const;

    TimeUnit defaultTimeIntervalUnit() const;

    int defaultTimeWindow() const;

    bool hasLiveData() const;

    TimeReference timeReference() const;

    TimeRelation timeRelation() const;

    TimeExtent timeExtent() const;

    TimeValue defaultInterval() const;

    explicit ServiceTimeInfo(const std::shared_ptr<QRTImpl::ServiceTimeInfoImpl>& impl);
    std::shared_ptr<QRTImpl::ServiceTimeInfoImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::ServiceTimeInfoImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ServiceTimeInfo_H
