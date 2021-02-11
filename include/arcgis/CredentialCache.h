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
/// \file CredentialCache.h

#ifndef QRT_CredentialCache_H
#define QRT_CredentialCache_H

// C++ API headers
#include "Credential.h"
#include "Object.h"

namespace QRTImpl { class CredentialCacheImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class CredentialCache : public Object
  {
    Q_OBJECT

  public:
    ~CredentialCache();

    void removeAllCredentials();

    bool setCredential(Credential* credential, const QUrl& url);

    Credential* credential(const QUrl& url) const;

    bool removeCredential(const QUrl& url);

    bool removeCredential(const Credential* credential);
    /*!
       \internal
     */
    CredentialCache(const std::shared_ptr<QRTImpl::CredentialCacheImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::CredentialCacheImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(CredentialCache)

    CredentialCache(QObject* parent = nullptr);

    std::shared_ptr<QRTImpl::CredentialCacheImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_CredentialCache_H

