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
/// \file FeatureServiceCapabilities.h

#ifndef QRT_FeatureServiceCapabilities_H
#define QRT_FeatureServiceCapabilities_H

// STL headers
#include <memory>

namespace QRTImpl { class FeatureServiceCapabilitiesImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class FeatureServiceCapabilities
  {
  public:
    FeatureServiceCapabilities();
    FeatureServiceCapabilities(const FeatureServiceCapabilities& other);
    FeatureServiceCapabilities(FeatureServiceCapabilities&& other) noexcept;
    ~FeatureServiceCapabilities();

    FeatureServiceCapabilities& operator=(const FeatureServiceCapabilities& other);
    FeatureServiceCapabilities& operator=(FeatureServiceCapabilities&& other) noexcept;

    bool isEmpty() const;

    bool isSupportsCreate() const;
    bool isSupportsDelete() const;
    bool isSupportsEditing() const;
    bool isSupportsQuery() const;
    bool isSupportsSync() const;
    bool isSupportsUpdate() const;

    FeatureServiceCapabilities(const std::shared_ptr<QRTImpl::FeatureServiceCapabilitiesImpl>& impl);
    std::shared_ptr<QRTImpl::FeatureServiceCapabilitiesImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::FeatureServiceCapabilitiesImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_FeatureServiceCapabilities_H
