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
/// \file EditorTrackingInfo.h

#ifndef QRT_EditorTrackingInfo_H
#define QRT_EditorTrackingInfo_H

// STL headers
#include <memory>

namespace QRTImpl { class EditorTrackingInfoImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class EditorTrackingInfo
  {
  public:
    EditorTrackingInfo();
    EditorTrackingInfo(const EditorTrackingInfo& other);
    EditorTrackingInfo(EditorTrackingInfo&& other) noexcept;
    ~EditorTrackingInfo();

    EditorTrackingInfo& operator=(const EditorTrackingInfo& other);
    EditorTrackingInfo& operator=(EditorTrackingInfo&& other) noexcept;

    bool isEmpty() const;

    bool isAllowAnonymousToDelete() const;
    bool isAllowAnonymousToUpdate() const;
    bool isAllowOthersToDelete() const;
    bool isAllowOthersToUpdate() const;
    bool isEditorTrackingEnabled() const;
    bool isOwnershipBasedAccessControlEnabled() const;

    EditorTrackingInfo(const std::shared_ptr<QRTImpl::EditorTrackingInfoImpl>& impl);
    std::shared_ptr<QRTImpl::EditorTrackingInfoImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::EditorTrackingInfoImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_EditorTrackingInfo_H
