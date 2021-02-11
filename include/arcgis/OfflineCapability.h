// COPYRIGHT 1995-2017 ESRI
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
/// \file OfflineCapability.h

#ifndef QRT_OfflineCapability_H
#define QRT_OfflineCapability_H

// C++ API headers
#include "ArcGISQt_global.h"
#include "Error.h"

// STL headers
#include <memory>

namespace QRTImpl { class OfflineCapabilityImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class OfflineCapability
  {
  public:
    OfflineCapability();
    OfflineCapability(const OfflineCapability& other);
    OfflineCapability(OfflineCapability&& other) noexcept;
    ~OfflineCapability();

    OfflineCapability& operator=(const OfflineCapability& other);
    OfflineCapability& operator=(OfflineCapability&& other) noexcept;

    bool isEmpty() const;

    Error error() const;

    bool isSupportsOffline() const;

    /*!
       \internal
     */
    OfflineCapability(const std::shared_ptr<QRTImpl::OfflineCapabilityImpl>& impl);

  private:
    std::shared_ptr<QRTImpl::OfflineCapabilityImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_OfflineCapability_H
