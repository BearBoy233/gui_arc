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
/// \file CostAttribute.h

#ifndef QRT_CostAttribute_H
#define QRT_CostAttribute_H

// C++ API headers
#include "NetworkAnalystTypes.h"

// Qt headers
#include <QVariantMap>

// STL headers
#include <memory>

namespace QRTImpl { class CostAttributeImpl; }

namespace Esri {
namespace ArcGISRuntime {

class CostAttribute
{
public:
  CostAttribute();
  CostAttribute(const CostAttribute& other);
  CostAttribute(CostAttribute&& other) noexcept;
  ~CostAttribute();

  CostAttribute& operator=(const CostAttribute& other);
  CostAttribute& operator=(CostAttribute&& other) noexcept;

  bool isEmpty() const;

  QVariantMap parameterValues() const;

  AttributeUnit attributeUnit() const;

  /*!
     \internal
   */
  CostAttribute(const std::shared_ptr<QRTImpl::CostAttributeImpl>& impl);
  std::shared_ptr<QRTImpl::CostAttributeImpl> getImpl() const;

private:
  std::shared_ptr<QRTImpl::CostAttributeImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_CostAttribute_H
