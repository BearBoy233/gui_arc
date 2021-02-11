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
/// \file Credential.h

#ifndef QRT_Credential_H
#define QRT_Credential_H

// C++ API headers
#include "CoreTypes.h"
#include "OAuthClientInfo.h"
#include "Object.h"

// Qt headers
#include <QDateTime>
#include <QSslConfiguration>

namespace QRTImpl { class CredentialImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class Credential : public Object
  {
    Q_OBJECT

  public:
    explicit Credential(QObject* parent = nullptr);
    Credential(const QString& username, const QString& password, QObject* parent = nullptr);
    Credential(const OAuthClientInfo& clientInfo, QObject* parent = nullptr);
    Credential(const QSslConfiguration& sslConfig, QObject* parent = nullptr);
    ~Credential();

    Credential* clone(QObject* parent = nullptr) const;

    bool operator== (const Credential& other) const;

    AuthenticationType authenticationType() const;

    QString username() const;
    QString password() const;
    void setUserAccount(const QString& username, const QString& password);

    OAuthClientInfo oAuthClientInfo() const;
    void setOAuthClientInfo(const OAuthClientInfo& clientInfo);

    QSslConfiguration sslConfiguration() const;
    void setSslConfiguration(const QSslConfiguration& sslConfig);

    QString oAuthAuthorizationCode() const;
    void setOAuthAuthorizationCode(const QString& oAuthAuthorizationCode);

    QString oAuthRefreshToken() const;
    void setOAuthRefreshToken(const QString& oAuthRefreshToken);

    QString token() const;
    QDateTime tokenExpiry() const;
    void setUserToken(const QString& token, const QString& referer, const QDateTime& tokenExpiry = QDateTime());

    QUrl tokenServiceUrl() const;
    void setTokenServiceUrl(const QUrl& tokenServiceUrl);

    QString referer() const;

    bool isSslRequired() const;

    QUrl authenticatingHost() const;

    Credential(const std::shared_ptr<QRTImpl::CredentialImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::CredentialImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(Credential)

    std::shared_ptr<QRTImpl::CredentialImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_Credential_H

