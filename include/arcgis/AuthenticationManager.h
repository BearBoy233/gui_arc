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
/// \file AuthenticationManager.h

#ifndef QRT_AuthenticationManager_H
#define QRT_AuthenticationManager_H

// C++ API headers
#include "AuthenticationChallenge.h"
#include "CredentialCache.h"
#include "Object.h"

namespace Esri {
namespace ArcGISRuntime {

  class AuthenticationManager : public Object
  {
    Q_OBJECT

    Q_PROPERTY(QStringList clientCertificateInfos READ clientCertificateInfos NOTIFY clientCertificateInfosChanged)

  public:
    ~AuthenticationManager();

    static AuthenticationManager* instance();

    static bool isCredentialCacheEnabled();
    static void setCredentialCacheEnabled(bool enabled);

    static CredentialCache* credentialCache();

    static QStringList clientCertificateInfos();

    Q_INVOKABLE static bool addClientCertificate(const QUrl& clientCertificate, const QString& password = QString());

    static void fetchLoginTypeForUrl(const QUrl& url);

  signals:
    void authenticationChallenge(Esri::ArcGISRuntime::AuthenticationChallenge* challenge);
    void clientCertificateInfosChanged();
    void clientCertificatePasswordRequired(const QUrl& certificate);
    void fetchLoginTypeForUrlCompleted(Esri::ArcGISRuntime::LoginType loginType);

  protected:
    void connectNotify(const QMetaMethod& signal) override;
    void disconnectNotify(const QMetaMethod& signal) override;

  private:
    Q_DISABLE_COPY(AuthenticationManager)

    AuthenticationManager(QObject* parent = nullptr);

    QMetaObject::Connection m_authChallengeConn;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_AuthenticationManager_H
