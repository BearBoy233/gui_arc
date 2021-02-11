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
/// \file License.h

#ifndef QRT_License_H
#define QRT_License_H

// C++ API headers
#include "CoreTypes.h"
#include "ExtensionLicense.h"
#include "Object.h"

// Qt headers
#include <QDateTime>

namespace QRTImpl { class LicenseImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class License : public Object
  {
    Q_OBJECT

  public:
    ~License();

    QDateTime expiry() const;

    bool isPermanent() const;

    LicenseLevel licenseLevel() const;

    LicenseStatus licenseStatus() const;

    LicenseType licenseType() const;

    QList<ExtensionLicense> extensions() const;

    /*! \internal */
    License(const std::shared_ptr<QRTImpl::LicenseImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::LicenseImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(License)
    License() = delete;

    std::shared_ptr<QRTImpl::LicenseImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_License_H
