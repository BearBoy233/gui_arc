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
/// \file AttributeParameterValue.h

#ifndef QRT_AttributeParameterValue_H
#define QRT_AttributeParameterValue_H

// C++ API headers
#include "NetworkAnalystTypes.h"

// Qt headers
#include <QVariant>

// STL headers
#include <memory>

namespace QRTImpl { class AttributeParameterValueImpl; }

namespace Esri {
namespace ArcGISRuntime {

class AttributeParameterValue
{

public:
  AttributeParameterValue();
  AttributeParameterValue(const AttributeParameterValue& other);
  AttributeParameterValue(AttributeParameterValue&& other) noexcept;
  ~AttributeParameterValue();

  AttributeParameterValue& operator=(const AttributeParameterValue& other);
  AttributeParameterValue& operator=(AttributeParameterValue&& other) noexcept;

  QString attributeName() const;
  void setAttributeName(const QString& attributeName);

  QString parameterName() const;
  void setParameterName(const QString& parameterName);

  QVariant parameterValue() const;
  void setParameterValue(const QVariant& parameterValue);

  /*!
     \internal
   */
  AttributeParameterValue(const std::shared_ptr<QRTImpl::AttributeParameterValueImpl>& impl);
  std::shared_ptr<QRTImpl::AttributeParameterValueImpl> getImpl() const;

private:
  std::shared_ptr<QRTImpl::AttributeParameterValueImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_AttributeParameterValue_H
