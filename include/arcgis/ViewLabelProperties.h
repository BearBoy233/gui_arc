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
/// \file ViewLabelProperties.h

#ifndef QRT_ViewLabelProperties_H
#define QRT_ViewLabelProperties_H

// C++ API headers
#include "ArcGISQt_global.h"

// STL headers
#include <memory>

namespace QRTImpl { class ViewLabelPropertiesImpl; }

namespace Esri {
namespace ArcGISRuntime {

class ViewLabelProperties
{
public:
  ViewLabelProperties();
  ViewLabelProperties(bool animationEnabled, bool labelingEnabled);
  ViewLabelProperties(const ViewLabelProperties& other);
  ViewLabelProperties(ViewLabelProperties&& other) noexcept;
  ViewLabelProperties& operator=(const ViewLabelProperties& other);
  ViewLabelProperties& operator=(ViewLabelProperties&& other) noexcept;
  ~ViewLabelProperties();

  bool isAnimationEnabled() const;
  void setAnimationEnabled(bool enabled);
  bool isLabelingEnabled() const;
  void setLabelingEnabled(bool enabled);

  ViewLabelProperties(const std::shared_ptr<QRTImpl::ViewLabelPropertiesImpl>& impl);
  std::shared_ptr<QRTImpl::ViewLabelPropertiesImpl> getImpl() const;

private:
  std::shared_ptr<QRTImpl::ViewLabelPropertiesImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ViewLabelProperties_H
