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
/// \file SyncCapabilities.h

#ifndef QRT_SyncCapabilities_H
#define QRT_SyncCapabilities_H

// STL headers
#include <memory>

namespace QRTImpl { class SyncCapabilitiesImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class SyncCapabilities
  {
  public:
    SyncCapabilities();
    SyncCapabilities(const SyncCapabilities& other);
    SyncCapabilities(SyncCapabilities&& other) noexcept;
    ~SyncCapabilities();

    SyncCapabilities& operator=(const SyncCapabilities& other);
    SyncCapabilities& operator=(SyncCapabilities&& other) noexcept;

    bool isEmpty() const;

    bool isSupportsAsync() const;
    bool isSupportsRegisteringExistingData() const;
    bool isSupportsRollbackOnFailure() const;
    bool isSupportsSyncDirectionControl() const;
    bool isSupportsSyncModelGeodatabase() const;
    bool isSupportsSyncModelLayer() const;
    bool isSupportsSyncModelNone() const;
    bool isSupportsAttachmentsSyncDirection() const;

    SyncCapabilities(const std::shared_ptr<QRTImpl::SyncCapabilitiesImpl>& impl);
    std::shared_ptr<QRTImpl::SyncCapabilitiesImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::SyncCapabilitiesImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_SyncCapabilities_H
