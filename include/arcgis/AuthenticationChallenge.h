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
/// \file AuthenticationChallenge.h

#ifndef QRT_AuthenticationChallenge_H
#define QRT_AuthenticationChallenge_H

// C++ API headers
#include "CoreTypes.h"
#include "Credential.h"
#include "Error.h"
#include "Object.h"

// Qt headers
#include <QNetworkReply>
#include <QSslError>

namespace QRTImpl { class AuthenticationChallengeImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class AuthenticationChallenge : public Object
  {
    Q_OBJECT

    Q_ENUM(AuthenticationChallengeType)

  public:
    Q_PROPERTY(Esri::ArcGISRuntime::AuthenticationChallengeType authenticationChallengeType READ authenticationChallengeType CONSTANT)
    Q_PROPERTY(int failureCount READ failureCount CONSTANT)
    Q_PROPERTY(QUrl requestUrl READ requestUrl CONSTANT)
    Q_PROPERTY(QUrl authenticatingHost READ authenticatingHost CONSTANT)
    Q_PROPERTY(QUrl authorizationUrl READ authorizationUrl CONSTANT)

  public:
    ~AuthenticationChallenge();

    AuthenticationChallengeType authenticationChallengeType() const;

    int failureCount() const;

    Credential* proposedCredential() const;

    Error error() const;

    QUrl requestUrl() const;

    QUrl authenticatingHost() const;

    QUrl authorizationUrl() const;

    QList<QSslError> sslErrors() const;

    void continueWithCredential(Credential* credential);
    Q_INVOKABLE void continueWithUsernamePassword(const QString& username, const QString& password);
    Q_INVOKABLE void continueWithOAuthAuthorizationCode(const QString& oAuthAuthorizationCode);
    Q_INVOKABLE void continueWithClientCertificate(int clientCertificateIndex);
    Q_INVOKABLE void continueWithSslHandshake(bool trust, bool remember);

    Q_INVOKABLE void cancel();

    /*!
       \internal
     */
    AuthenticationChallenge(const std::shared_ptr<QRTImpl::AuthenticationChallengeImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::AuthenticationChallengeImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(AuthenticationChallenge)
    AuthenticationChallenge() = delete;

    std::shared_ptr<QRTImpl::AuthenticationChallengeImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_AuthenticationChallenge_H

