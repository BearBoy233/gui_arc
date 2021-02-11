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
/// \file LocatorAttribute.h

#ifndef QRT_LocatorAttribute_H
#define QRT_LocatorAttribute_H

// C++ API headers
#include "ArcGISQt_global.h"

// Qt headers
#include <QVariant>

// STL headers
#include <memory>

namespace QRTImpl { class LocatorAttributeImpl; }

namespace Esri {
namespace ArcGISRuntime {

class LocatorAttribute
{
public:
  LocatorAttribute();
  LocatorAttribute(const LocatorAttribute& other);
  LocatorAttribute(LocatorAttribute&& other) noexcept;
  LocatorAttribute& operator=(const LocatorAttribute& other);
  LocatorAttribute& operator=(LocatorAttribute&& other) noexcept;
  ~LocatorAttribute();

  QString displayName() const;

  QString name() const;

  QVariant::Type type() const;

  bool isRequired() const;

  bool isEmpty() const;

  /*!
     \internal
   */
  LocatorAttribute(const std::shared_ptr<QRTImpl::LocatorAttributeImpl>& impl);
  std::shared_ptr<QRTImpl::LocatorAttributeImpl> getImpl() const;

private:
  std::shared_ptr<QRTImpl::LocatorAttributeImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_LocatorAttribute_H
