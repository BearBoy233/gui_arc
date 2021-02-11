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
/// \file LocalMapService.h

#ifndef QRT_LocalMapService_H
#define QRT_LocalMapService_H

// C++ API headers
#include "Object.h"

#ifndef LOCALSERVER_SUPPORTED
#error "Local Server is not supported on this platform."
#endif

#include "LocalService.h"
#include "DynamicWorkspace.h"

namespace QRTImpl {
  class LocalMapServiceImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class LocalMapService : public LocalService
  {
    Q_OBJECT

  public:
    LocalMapService(const QString& packagePath, QObject* parent = nullptr);

    ~LocalMapService();

    int maximumRecords() const;
    void setMaximumRecords(int maxRecords);

    QList<DynamicWorkspace*> dynamicWorkspaces() const;
    void setDynamicWorkspaces(const QList<DynamicWorkspace*>& dynamicWorkspaces);

    /*! \internal */
    LocalMapService(const std::shared_ptr<QRTImpl::LocalMapServiceImpl>& impl, QObject* parent = nullptr);

  private:
    Q_DISABLE_COPY(LocalMapService)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_LocalMapService_H
