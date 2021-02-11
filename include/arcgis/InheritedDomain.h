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
/// \file InheritedDomain.h

#ifndef QRT_InheritedDomain_H
#define QRT_InheritedDomain_H

// C++ API headers
#include "Domain.h"

namespace QRTImpl {
  class InheritedDomainImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class InheritedDomain : public Domain
  {
  public:
    InheritedDomain();

    InheritedDomain(const InheritedDomain& other);
    InheritedDomain(InheritedDomain&& other) noexcept;
    InheritedDomain(const Domain& other);

    InheritedDomain& operator=(const InheritedDomain& other);
    InheritedDomain& operator=(InheritedDomain&& other) noexcept;

    ~InheritedDomain();

    bool isValid() const;

    /*!
       \internal
     */
    explicit InheritedDomain(const std::shared_ptr<QRTImpl::InheritedDomainImpl>& impl);
    std::shared_ptr<QRTImpl::InheritedDomainImpl> getImpl() const;
  };

  /*! \internal */
  template<>
  inline InheritedDomain domain_cast<InheritedDomain>(const Domain& domain)
  {
    return domain.domainType() == DomainType::InheritedDomain ? static_cast<InheritedDomain>(domain) : InheritedDomain();
  }

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_InheritedDomain_H
