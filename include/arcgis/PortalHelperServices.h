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
/// \file PortalInfo.h

#ifndef QRT_PortalHelperServices_H
#define QRT_PortalHelperServices_H

// C++ API headers
#include "Object.h"

namespace QRTImpl { class PortalHelperServicesImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class PortalHelperServices : public Object
  {
    Q_OBJECT

  public:
    ~PortalHelperServices();

    QString toJson() const;

    QUrl analysisServiceUrl() const;
    QUrl asyncClosestFacilityServiceUrl() const;
    QUrl asyncLocationAllocationServiceUrl() const;
    QUrl asyncODCostMatrixServiceUrl() const;
    QUrl asyncServiceAreaServiceUrl() const;
    QUrl asyncVRPServiceUrl() const;
    QUrl closestFacilityServiceUrl() const;
    QUrl elevationServiceUrl() const;
    QUrl elevation3DServiceUrl() const;
    QUrl elevationSyncServiceUrl() const;
    QList<QUrl> geocodeServiceUrls() const;
    QUrl geoenrichmentServiceUrl() const;
    QUrl geometryServiceUrl() const;
    QUrl hydrologyServiceUrl() const;
    QUrl printTaskUrl() const;
    QUrl routeServiceUrl() const;
    QUrl serviceAreaServiceUrl() const;
    QUrl syncVRPServiceUrl() const;
    QUrl trafficServiceUrl() const;

  private:
    friend class PortalInfo;
    explicit PortalHelperServices(const std::shared_ptr<QRTImpl::PortalHelperServicesImpl>& impl, QObject* parent);

    std::shared_ptr<QRTImpl::PortalHelperServicesImpl> m_rtPortalHelperServicesImpl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_PortalHelperServices_H

