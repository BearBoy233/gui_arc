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
/// \file Domain.h

#ifndef QRT_Domain_H
#define QRT_Domain_H

// C++ API headers
#include "ArcGISQt_global.h"
#include "ServiceTypes.h"

// STL headers
#include <memory>

namespace QRTImpl { class DomainImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class Domain
  {
  public:
    Domain();

    Domain(const Domain& other);
    Domain(Domain&& other) noexcept;

    Domain& operator=(const Domain& other);
    Domain& operator=(Domain&& other) noexcept;

    ~Domain();

    DomainType domainType() const;

    bool isEmpty() const;

    QString name() const;

    /*! \internal */
    explicit Domain(const std::shared_ptr<QRTImpl::DomainImpl>& impl);
    std::shared_ptr<QRTImpl::DomainImpl> getImpl() const;

  protected:
    std::shared_ptr<QRTImpl::DomainImpl> m_impl;
  };

  /*! \internal */
  template<typename T>
  T domain_cast(const Domain&)
  {
    return Domain();
  }

  template<>
  inline Domain domain_cast<Domain>(const Domain& domain)
  {
    return domain;
  }

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_Domain_H
