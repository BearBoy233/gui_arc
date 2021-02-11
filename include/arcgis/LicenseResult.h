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
/// \file LicenseResult.h

#ifndef QRT_LicenseResult_H
#define QRT_LicenseResult_H

// C++ API headers
#include "CoreTypes.h"

// Qt headers
#include <QMap>

// STL headers
#include <memory>

namespace QRTImpl { class LicenseResultImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class LicenseResult
  {
  public:
    LicenseResult();
    LicenseResult(const LicenseResult& other);
    LicenseResult(LicenseResult&& other) noexcept;
    ~LicenseResult();

    LicenseResult& operator=(const LicenseResult& other);
    LicenseResult& operator=(LicenseResult&& other) noexcept;

    bool isEmpty() const;

    LicenseStatus licenseStatus() const;

    QMap<QString, LicenseStatus> extensionsStatus() const;
    QMap<QString, LicenseStatus> extentionsStatus() const; // deprecated

    /*! \internal */
    LicenseResult(const std::shared_ptr<QRTImpl::LicenseResultImpl>& impl);
    std::shared_ptr<QRTImpl::LicenseResultImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::LicenseResultImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_LicenseResult_H
