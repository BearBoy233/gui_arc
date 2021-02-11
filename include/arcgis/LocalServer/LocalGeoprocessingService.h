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
/// \file LocalGeoprocessingService.h

#ifndef QRT_LocalGeoprocessingService_H
#define QRT_LocalGeoprocessingService_H

// C++ API headers
#include "Object.h"

#ifndef LOCALSERVER_SUPPORTED
#error "Local Server is not supported on this platform."
#endif

#include "LocalService.h"
#include "LocalServerTypes.h"

namespace QRTImpl {
  class LocalGeoprocessingServiceImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class LocalGeoprocessingService : public LocalService
  {
    Q_OBJECT

  public:
    LocalGeoprocessingService(const QString& packagePath, QObject* parent = nullptr);

    ~LocalGeoprocessingService();

    int maximumRecords() const;
    void setMaximumRecords(int maxRecords);

    GeoprocessingServiceType serviceType() const;
    void setServiceType(GeoprocessingServiceType serviceType);

    /*! \internal */
    LocalGeoprocessingService(const std::shared_ptr<QRTImpl::LocalGeoprocessingServiceImpl>& impl, QObject* parent = nullptr);

  private:
    Q_DISABLE_COPY(LocalGeoprocessingService)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_LocalGeoprocessingService_H
