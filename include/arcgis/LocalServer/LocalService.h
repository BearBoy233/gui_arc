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
/// \file LocalService.h

#ifndef QRT_LocalService_H
#define QRT_LocalService_H

// C++ API headers
#include "Object.h"

// Qt headers
#include <QUrl>

#ifndef LOCALSERVER_SUPPORTED
#error "Local Server is not supported on this platform."
#endif

#include "LocalServerTypes.h"

namespace QRTImpl {
  class LocalServiceImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class LocalService : public Object
  {
    Q_OBJECT

  public:
    ~LocalService();

    void start();

    void stop();

    virtual QUrl url() const;

    LocalServerStatus status() const;

    QString name() const;

    QString packagePath() const;

    /*!
      \internal
    */
    LocalService(const std::shared_ptr<QRTImpl::LocalServiceImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::LocalServiceImpl> getImpl() const;

  signals:
    void statusChanged();

  protected:
    std::shared_ptr<QRTImpl::LocalServiceImpl> m_impl;

  private:
    Q_DISABLE_COPY(LocalService)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_LocalService_H
