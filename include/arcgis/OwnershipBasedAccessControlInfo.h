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
/// \file OwnershipBasedAccessControlInfo.h

#ifndef QRT_OwnershipBasedAccessControlInfo_H
#define QRT_OwnershipBasedAccessControlInfo_H

// STL headers
#include <memory>

namespace QRTImpl { class OwnershipBasedAccessControlInfoImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class OwnershipBasedAccessControlInfo
  {
  public:
    OwnershipBasedAccessControlInfo();
    OwnershipBasedAccessControlInfo(const OwnershipBasedAccessControlInfo& other);
    OwnershipBasedAccessControlInfo(OwnershipBasedAccessControlInfo&& other) noexcept;
    ~OwnershipBasedAccessControlInfo();

    OwnershipBasedAccessControlInfo& operator=(const OwnershipBasedAccessControlInfo& other);
    OwnershipBasedAccessControlInfo& operator=(OwnershipBasedAccessControlInfo&& other) noexcept;

    bool isEmpty() const;

    bool isAllowAnonymousToDelete() const;
    bool isAllowAnonymousToUpdate() const;
    bool isAllowOthersToDelete() const;
    bool isAllowOthersToQuery() const;
    bool isAllowOthersToUpdate() const;

    OwnershipBasedAccessControlInfo(const std::shared_ptr<QRTImpl::OwnershipBasedAccessControlInfoImpl>& impl);
    std::shared_ptr<QRTImpl::OwnershipBasedAccessControlInfoImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::OwnershipBasedAccessControlInfoImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_OwnershipBasedAccessControlInfo_H
