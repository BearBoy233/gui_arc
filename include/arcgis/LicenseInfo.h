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
/// \file LicenseInfo.h

#ifndef QRT_LicenseInfo_H
#define QRT_LicenseInfo_H

// C++ API headers
#include "JsonSerializable.h"

// STL headers
#include <memory>

namespace QRTImpl { class LicenseInfoImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class LicenseInfo : public JsonSerializable
  {
  public:
    LicenseInfo();
    LicenseInfo(const LicenseInfo& other);
    LicenseInfo(LicenseInfo&& other) noexcept;
    ~LicenseInfo();

    LicenseInfo& operator= (const LicenseInfo& other);
    LicenseInfo& operator= (LicenseInfo&& other) noexcept;

    bool isEmpty() const;

    QString toJson() const override;
    QJsonObject unknownJson() const override;
    QJsonObject unsupportedJson() const override;
    static LicenseInfo fromJson(const QString& json);

    /*! \internal */
    LicenseInfo(const std::shared_ptr<QRTImpl::LicenseInfoImpl>& impl);
    std::shared_ptr<QRTImpl::LicenseInfoImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::LicenseInfoImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_LicenseInfo_H

