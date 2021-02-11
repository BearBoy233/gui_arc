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
/// \file PortalQueryResultSetForGroups.h

#ifndef QRT_PortalQueryResultSetForGroups_H
#define QRT_PortalQueryResultSetForGroups_H

// C++ API headers
#include "Object.h"
#include "PortalQueryParametersForGroups.h"

namespace QRTImpl { class PortalQueryResultSetForGroupsImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class PortalGroupListModel;

  class PortalQueryResultSetForGroups : public Object
  {
    Q_OBJECT

  public:
    // constructor & destructor
    PortalQueryResultSetForGroups(QObject* parent = nullptr);
    ~PortalQueryResultSetForGroups();

    // properties
    PortalQueryParametersForGroups queryParameters() const;
    PortalQueryParametersForGroups nextQueryParameters() const;
    PortalGroupListModel* groupResults() const;
    int totalResults() const;

    // internal
    /*!
       \internal
     */
    explicit PortalQueryResultSetForGroups(const std::shared_ptr<QRTImpl::PortalQueryResultSetForGroupsImpl>& impl,
                                           QObject* parent = nullptr);

  private:
    /*!
       \internal
     */
    std::shared_ptr<QRTImpl::PortalQueryResultSetForGroupsImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_PortalQueryResultSetForGroups_H
