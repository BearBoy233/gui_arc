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
/// \file RenderingRuleInfo.h

#ifndef QRT_RenderingRuleInfo_H
#define QRT_RenderingRuleInfo_H

// C++ API headers
#include "ArcGISQt_global.h"

// STL headers
#include <memory>

namespace QRTImpl {
  class RenderingRuleInfoImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class RenderingRuleInfo
  {
  public:
    RenderingRuleInfo();
    explicit RenderingRuleInfo(const QString& name);
    RenderingRuleInfo(const RenderingRuleInfo& other);
    RenderingRuleInfo(RenderingRuleInfo&& other) noexcept;
    ~RenderingRuleInfo();

    RenderingRuleInfo& operator=(const RenderingRuleInfo& other);
    RenderingRuleInfo& operator=(RenderingRuleInfo&& other) noexcept;

    bool isEmpty() const;

    QString description() const;

    QString help() const;

    QString name() const;

    explicit RenderingRuleInfo(const std::shared_ptr<QRTImpl::RenderingRuleInfoImpl>& impl);
    std::shared_ptr<QRTImpl::RenderingRuleInfoImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::RenderingRuleInfoImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_RenderingRuleInfo_H
