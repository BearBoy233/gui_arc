// COPYRIGHT 1995-2017 ESRI
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
/// \file EncDisplaySettings.h

#ifndef QRT_EncDisplaySettings_H
#define QRT_EncDisplaySettings_H

// C++ API headers
#include "EncMarinerSettings.h"
#include "EncTextGroupVisibilitySettings.h"
#include "EncViewingGroupSettings.h"
#include "Object.h"

// STL headers
#include <memory>

namespace QRTImpl { class EncDisplaySettingsImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class EncDisplaySettings : public Object
  {
    Q_OBJECT

  public:
    ~EncDisplaySettings();

    EncMarinerSettings* marinerSettings() const;
    EncTextGroupVisibilitySettings* textGroupVisibilitySettings() const;
    EncViewingGroupSettings* viewingGroupSettings() const;

    /*! \internal */
    explicit EncDisplaySettings(const std::shared_ptr<QRTImpl::EncDisplaySettingsImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::EncDisplaySettingsImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(EncDisplaySettings)
    std::shared_ptr<QRTImpl::EncDisplaySettingsImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_EncDisplaySettings_H
