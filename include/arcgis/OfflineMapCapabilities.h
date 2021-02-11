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
/// \file OfflineMapCapabilities.h

#ifndef QRT_OfflineMapCapabilities_H
#define QRT_OfflineMapCapabilities_H

// C++ API headers
#include "ArcGISQt_global.h"
#include "Error.h"
#include "FeatureTable.h"
#include "Layer.h"
#include "OfflineCapability.h"

// STL headers
#include <memory>

namespace QRTImpl { class OfflineMapCapabilitiesImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class OfflineMapCapabilities
  {
  public:
    OfflineMapCapabilities();
    OfflineMapCapabilities(const OfflineMapCapabilities& other);
    OfflineMapCapabilities(OfflineMapCapabilities&& other) noexcept;
    ~OfflineMapCapabilities();

    OfflineMapCapabilities& operator=(const OfflineMapCapabilities& other);
    OfflineMapCapabilities& operator=(OfflineMapCapabilities&& other) noexcept;

    bool isEmpty() const;

    bool hasErrors() const;

    QMap<Layer*, OfflineCapability> layerCapabilities(QObject* parent = nullptr) const;

    QMap<FeatureTable*, OfflineCapability> tableCapabilities(QObject* parent = nullptr) const;

    /*!
       \internal
     */
    OfflineMapCapabilities(const std::shared_ptr<QRTImpl::OfflineMapCapabilitiesImpl>& impl);

  private:
    std::shared_ptr<QRTImpl::OfflineMapCapabilitiesImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_OfflineMapCapabilities_H
