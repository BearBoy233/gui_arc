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
/// \file RestrictionAttribute.h

#ifndef QRT_RestrictionAttribute_H
#define QRT_RestrictionAttribute_H

// C++ API headers
#include "NetworkAnalystTypes.h"

// Qt headers
#include <QVariantMap>

// STL headers
#include <memory>

namespace QRTImpl { class RestrictionAttributeImpl; }

namespace Esri {
namespace ArcGISRuntime {

class RestrictionAttribute
{
public:
  RestrictionAttribute();
  RestrictionAttribute(const RestrictionAttribute& other);
  RestrictionAttribute(RestrictionAttribute&& other) noexcept;
  ~RestrictionAttribute();

  RestrictionAttribute& operator=(const RestrictionAttribute& other);
  RestrictionAttribute& operator=(RestrictionAttribute&& other) noexcept;

  bool isEmpty() const;

  QVariantMap parameterValues() const;

  QString restrictionUsageParameterName() const;

  /*!
     \internal
   */
  RestrictionAttribute(const std::shared_ptr<QRTImpl::RestrictionAttributeImpl>& impl);
  std::shared_ptr<QRTImpl::RestrictionAttributeImpl> getImpl() const;

private:
  std::shared_ptr<QRTImpl::RestrictionAttributeImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_RestrictionAttribute_H
