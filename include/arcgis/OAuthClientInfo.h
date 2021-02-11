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
/// \file OAuthClientInfo.h

#ifndef QRT_OAuthClientInfo_H
#define QRT_OAuthClientInfo_H

// C++ API headers
#include "ArcGISQt_global.h"
#include "CoreTypes.h"
#include "JsonSerializable.h"

// STL headers
#include <memory>

namespace QRTImpl { class OAuthClientInfoImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class OAuthClientInfo : public JsonSerializable
  {
  public:
    OAuthClientInfo();
    OAuthClientInfo(const QString& clientId, OAuthMode mode);
    OAuthClientInfo(const QString& clientId, const QString& clientSecret, OAuthMode mode);
    OAuthClientInfo(const QString& clientId, const QString& clientSecret, const QString& redirectUri, OAuthMode mode);
    OAuthClientInfo(const OAuthClientInfo& other);
    OAuthClientInfo(OAuthClientInfo&& other) noexcept;
    ~OAuthClientInfo();

    OAuthClientInfo& operator=(const OAuthClientInfo& other);
    OAuthClientInfo& operator=(OAuthClientInfo&& other) noexcept;

    bool operator==(const OAuthClientInfo& other) const;

    bool isEmpty() const;
    void clear();

    OAuthMode oAuthMode() const;
    void setOAuthMode(OAuthMode mode);

    QString clientId() const;
    void setClientId(const QString& clientId);

    QString clientSecret() const;
    void setClientSecret(const QString& clientSecret);

    QString redirectUri() const;
    void setRedirectUri(const QString& redirectUri);

    QString toJson() const override;
    QJsonObject unknownJson() const override;
    QJsonObject unsupportedJson() const override;
    static OAuthClientInfo fromJson(const QString& json);

    OAuthClientInfo(const std::shared_ptr<QRTImpl::OAuthClientInfoImpl>& impl);
    std::shared_ptr<QRTImpl::OAuthClientInfoImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::OAuthClientInfoImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_OAuthClientInfo_H

