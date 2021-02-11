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
/// \file PortalQueryResultSetForItems.h

#ifndef QRT_PortalQueryResultSetForItems_H
#define QRT_PortalQueryResultSetForItems_H

// C++ API headers
#include "Object.h"
#include "PortalQueryParametersForItems.h"

namespace QRTImpl { class PortalQueryResultSetForItemsImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class PortalItemListModel;

  class PortalQueryResultSetForItems : public Object
  {
    Q_OBJECT

  public:
    // constructor & destructor
    PortalQueryResultSetForItems(QObject* parent = nullptr);
    ~PortalQueryResultSetForItems();

    // properties
    PortalQueryParametersForItems queryParameters() const;
    PortalQueryParametersForItems nextQueryParameters() const;
    PortalItemListModel* itemResults() const;
    int totalResults() const;

    // internal
    /*!
       \internal
     */
    explicit PortalQueryResultSetForItems(const std::shared_ptr<QRTImpl::PortalQueryResultSetForItemsImpl>& impl,
                                          QObject* parent = nullptr);

  private:
    /*!
       \internal
     */
    std::shared_ptr<QRTImpl::PortalQueryResultSetForItemsImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_PortalQueryResultSetForItems_H
