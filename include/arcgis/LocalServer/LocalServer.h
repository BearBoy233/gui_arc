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
/// \file LocalServer.h

#ifndef QRT_LocalServer_H
#define QRT_LocalServer_H

// C++ API headers
#include "Object.h"

#ifndef LOCALSERVER_SUPPORTED
#error "Local Server is not supported on this platform."
#endif

#include "LocalServerTypes.h"
#include "LocalService.h"

namespace QRTImpl {
  class LocalServerImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class LocalServer : public Object
  {
    Q_OBJECT

  public:
    ~LocalServer();

    static LocalServer* instance();

    static void start();

    static void stop();

    static QUrl url();

    static bool isInstallValid();

    static QString installPath();
    static void setInstallPath(const QString& installPath);

    static QString appDataPath();
    static void setAppDataPath(const QString& appDataPath);

    static QString tempDataPath();
    static void setTempDataPath(const QString& tempDataPath);

    static bool isFilterWebContent();
    static void setFilterWebContent(bool enableFilterWebContent);

    static QList<LocalService*> services();

    static Esri::ArcGISRuntime::LocalServerStatus status();

  signals:
    void statusChanged();

  private:
    LocalServer();
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_LocalServer_H
