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
/// \file ExtensionLicense.h

#ifndef QRT_ExtensionLicense_H
#define QRT_ExtensionLicense_H

// C++ API headers
#include "CoreTypes.h"

// Qt headers
#include <QDateTime>

// STL headers
#include <memory>

namespace QRTImpl { class ExtensionLicenseImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class ExtensionLicense
  {
  public:
    ExtensionLicense();
    ExtensionLicense(const ExtensionLicense& other);
    ExtensionLicense(ExtensionLicense&& other) noexcept;
    ~ExtensionLicense();

    ExtensionLicense& operator=(const ExtensionLicense& other);
    ExtensionLicense& operator=(ExtensionLicense&& other) noexcept;

    QDateTime expiry() const;

    bool isPermanent() const;

    LicenseStatus licenseStatus() const;

    QString name() const;

    /*! \internal */
    ExtensionLicense(const std::shared_ptr<QRTImpl::ExtensionLicenseImpl>& impl);
    std::shared_ptr<QRTImpl::ExtensionLicenseImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::ExtensionLicenseImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ExtensionLicense_H
