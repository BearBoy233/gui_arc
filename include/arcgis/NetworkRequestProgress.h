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
/// \file NetworkRequestProgress.h

#ifndef QRT_NetworkRequestProgress_H
#define QRT_NetworkRequestProgress_H

// Qt headers
#include <QDateTime>

// STL headers
#include <memory>

namespace QRTImpl { class NetworkRequestProgressImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class NetworkRequestProgress
  {
  public:
    NetworkRequestProgress();
    NetworkRequestProgress(const NetworkRequestProgress& other);
    NetworkRequestProgress(NetworkRequestProgress&& other) noexcept;
    ~NetworkRequestProgress();

    NetworkRequestProgress& operator=(const NetworkRequestProgress& other);
    NetworkRequestProgress& operator=(NetworkRequestProgress&& other) noexcept;

    qint64 bytesReceived() const;

    qint64 bytesSent() const;

    QDateTime estimatedFinishTime() const;

    int progressPercentage() const;

    QDateTime startTime() const;

    qint64 totalBytesToReceive() const;

    qint64 totalBytesToSend() const;

    /*!
       \internal
     */
    NetworkRequestProgress(const std::shared_ptr<QRTImpl::NetworkRequestProgressImpl>& impl);
    std::shared_ptr<QRTImpl::NetworkRequestProgressImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::NetworkRequestProgressImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_NetworkRequestProgress_H
