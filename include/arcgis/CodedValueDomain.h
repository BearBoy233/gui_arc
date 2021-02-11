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
/// \file CodedValueDomain.h

#ifndef QRT_CodedValueDomain_H
#define QRT_CodedValueDomain_H

// C++ API headers
#include "Domain.h"

// Qt headers
#include <QVariant>

namespace QRTImpl {
  class CodedValueDomainImpl;
  class CodedValueImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class CodedValue
  {
  public:
    CodedValue();

    CodedValue(const CodedValue& other);
    CodedValue(CodedValue&& other) noexcept;

    CodedValue& operator=(const CodedValue& other);
    CodedValue& operator=(CodedValue&& other) noexcept;

    ~CodedValue();

    bool isEmpty() const;

    QVariant code() const;

    QString name() const;

    /*!
       \internal
     */
    CodedValue(const std::shared_ptr<QRTImpl::CodedValueImpl>& impl);
    std::shared_ptr<QRTImpl::CodedValueImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::CodedValueImpl> m_impl;
  };

  class CodedValueDomain : public Domain
  {
  public:
    CodedValueDomain();

    CodedValueDomain(const CodedValueDomain& other);
    CodedValueDomain(CodedValueDomain&& other) noexcept;
    CodedValueDomain(const Domain& other);

    CodedValueDomain& operator=(const CodedValueDomain& other);
    CodedValueDomain& operator=(CodedValueDomain&& other) noexcept;
    
    ~CodedValueDomain();

    bool isValid() const;

    QList<CodedValue> codedValues() const;

    /*! \internal */
    explicit CodedValueDomain(const std::shared_ptr<QRTImpl::CodedValueDomainImpl>& impl);
    std::shared_ptr<QRTImpl::CodedValueDomainImpl> getImpl() const;
  };

  /*! \internal */
  template<>
  inline CodedValueDomain domain_cast<CodedValueDomain>(const Domain& domain)
  {
    return domain.domainType() == DomainType::CodedValueDomain ? static_cast<CodedValueDomain>(domain) : CodedValueDomain();
  }

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_CodedValueDomain_H
