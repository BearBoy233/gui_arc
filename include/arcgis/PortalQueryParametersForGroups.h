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
/// \file PortalQueryParametersForGroups.h

#ifndef QRT_PortalQueryParametersForGroups_H
#define QRT_PortalQueryParametersForGroups_H

// C++ API headers
#include "PortalQueryParameters.h"

namespace QRTImpl { class PortalQueryParametersForGroupsImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class PortalQueryParametersForGroups : public PortalQueryParameters
  {
  public:
    explicit PortalQueryParametersForGroups();

    explicit PortalQueryParametersForGroups(const QString& query);
    explicit PortalQueryParametersForGroups(const QString& query, int limit);
    explicit PortalQueryParametersForGroups(const Envelope& boundingBox);
    explicit PortalQueryParametersForGroups(const QString& query, const Envelope& boundingBox);
    explicit PortalQueryParametersForGroups(const QString& owner, const QString& title);

    PortalQueryParametersForGroups(const PortalQueryParametersForGroups& other);
    PortalQueryParametersForGroups(PortalQueryParametersForGroups&& other) noexcept;
    explicit PortalQueryParametersForGroups(const PortalQueryParameters& other);

    PortalQueryParametersForGroups& operator=(const PortalQueryParametersForGroups& other);
    PortalQueryParametersForGroups& operator=(PortalQueryParametersForGroups&& other) noexcept;
    PortalQueryParametersForGroups& operator=(const PortalQueryParameters& other);

    ~PortalQueryParametersForGroups();

    QString owner() const;
    void setOwner(const QString& owner);

    QString title() const;
    void setTitle(const QString& title);

    /*!
       \internal
     */
    explicit PortalQueryParametersForGroups(const std::shared_ptr<QRTImpl::PortalQueryParametersForGroupsImpl>& impl);
    std::shared_ptr<QRTImpl::PortalQueryParametersForGroupsImpl> getImpl() const;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_PortalQueryParametersForGroups_H
