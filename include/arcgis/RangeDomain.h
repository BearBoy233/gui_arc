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
/// \file RangeDomain.h

#ifndef QRT_RangeDomain_H
#define QRT_RangeDomain_H

// C++ API headers
#include "Domain.h"

// Qt headers
#include <QVariant>

namespace QRTImpl {
  class RangeDomainImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class RangeDomain : public Domain
  {
  public:
    RangeDomain();

    RangeDomain(const RangeDomain& other);
    RangeDomain(RangeDomain&& other) noexcept;
    RangeDomain(const Domain& other);

    RangeDomain& operator=(const RangeDomain& other);
    RangeDomain& operator=(RangeDomain&& other) noexcept;

    ~RangeDomain();

    bool isValid() const;

    QVariant minValue() const;
    QVariant maxValue() const;

    /*!
       \internal
     */
    explicit RangeDomain(const std::shared_ptr<QRTImpl::RangeDomainImpl>& impl);
    std::shared_ptr<QRTImpl::RangeDomainImpl> getImpl() const;
  };

  /*! \internal */
  template<>
  inline RangeDomain domain_cast<RangeDomain>(const Domain& domain)
  {
    return domain.domainType() == DomainType::RangeDomain ? static_cast<RangeDomain>(domain) : RangeDomain();
  }

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_RangeDomain_H
