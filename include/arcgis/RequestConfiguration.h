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
/// \file RequestConfiguration.h

#ifndef QRT_RequestConfiguration_H
#define QRT_RequestConfiguration_H

// C++ API headers
#include "Object.h"

// Qt headers
#include <QMap>

namespace QRTImpl {
  class RequestConfigurationImpl;
}

namespace Esri {
namespace ArcGISRuntime {
  class RequestConfiguration
  {
  public:
    RequestConfiguration();
    RequestConfiguration(int timeoutInterval, int maxNumberOfAttempts, bool forcePost, bool issueAuthenticationChallenge, const QMap<QString, QString>& userHeaders = QMap<QString, QString>());
    RequestConfiguration(const RequestConfiguration& other);
    RequestConfiguration(RequestConfiguration&& other) noexcept;
    ~RequestConfiguration();

    RequestConfiguration& operator=(const RequestConfiguration& other);
    RequestConfiguration& operator=(RequestConfiguration&& other) noexcept;

    bool isEmpty() const;

    int timeoutInterval() const;
    void setTimeoutInterval(int timeoutInterval);

    int maxNumberOfAttempts() const;
    void setMaxNumberOfAttempts(int attempts);

    bool isForcePost() const;
    void setForcePost(bool forcePost);

    bool isIssueAuthenticationChallenge() const;
    void setIssueAuthenticationChallenge(bool issueAuthenticationChallenge);

    QMap<QString, QString> userHeaders() const;
    void setUserHeaders(const QMap<QString, QString>& userHeaders);

    static RequestConfiguration globalRequestConfiguration();
    static void setGlobalRequestConfiguration(const RequestConfiguration& globalRequestConfiguration);
    static QString additionalUserAgentInfo();
    static void setAdditionalUserAgentInfo(const QString& additionalUserAgentInfo);

    /*!
       \internal
     */
    explicit RequestConfiguration(const std::shared_ptr<QRTImpl::RequestConfigurationImpl>& impl);
    std::shared_ptr<QRTImpl::RequestConfigurationImpl> getImpl() const;

  private:

    std::shared_ptr<QRTImpl::RequestConfigurationImpl> m_impl;

  };
}
}
#endif // QRT_RequestConfigurationImpl_H
