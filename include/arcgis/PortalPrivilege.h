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
/// \file PortalPrivilege.h

#ifndef QRT_PortalPrivilege_H
#define QRT_PortalPrivilege_H

// C++ API headers
#include "PortalTypes.h"

// Qt headers
#include <QString>

// STL headers
#include <memory>

namespace QRTImpl { class PortalPrivilegeImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class PortalPrivilege
  {
  public:
    PortalPrivilege();
    PortalPrivilege(const PortalPrivilege& other);
    PortalPrivilege(PortalPrivilege&& other) noexcept;
    PortalPrivilege& operator=(const PortalPrivilege& other);
    PortalPrivilege& operator=(PortalPrivilege&& other) noexcept;
    ~PortalPrivilege();

    PortalPrivilegeRealm realm() const;

    PortalPrivilegeRole role() const;

    PortalPrivilegeType type() const;

    QString typeName() const;

    /*!
       \internal
     */
    explicit PortalPrivilege(const std::shared_ptr<QRTImpl::PortalPrivilegeImpl>& impl);

    std::shared_ptr<QRTImpl::PortalPrivilegeImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::PortalPrivilegeImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_PortalPrivilege_H
