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
/// \file RenderingRule.h

#ifndef QRT_RenderingRule_H
#define QRT_RenderingRule_H

// C++ API headers
#include "ArcGISQt_global.h"
#include "Object.h"
#include "RenderingRuleInfo.h"

// Qt headers
#include <QVariantMap>

// STL headers
#include <memory>

namespace QRTImpl {
  class RenderingRuleImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class RenderingRule: public Object
  {
    Q_OBJECT
  public:
    explicit RenderingRule(const QString& renderingRuleJson, QObject* parent = nullptr);
    explicit RenderingRule(const RenderingRuleInfo& renderingRuleInfo, QObject* parent = nullptr);
    ~RenderingRule();

    RenderingRuleInfo renderingRuleInfo() const;

    QString renderingRuleJson() const;

    /*! \internal */
    explicit RenderingRule(const std::shared_ptr<QRTImpl::RenderingRuleImpl>& impl);
    std::shared_ptr<QRTImpl::RenderingRuleImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::RenderingRuleImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_RenderingRule_H
