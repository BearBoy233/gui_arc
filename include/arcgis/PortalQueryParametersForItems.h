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
/// \file PortalQueryParametersForItems.h

#ifndef QRT_PortalQueryParametersForItems_H
#define QRT_PortalQueryParametersForItems_H

// C++ API headers
#include "PortalQueryParameters.h"

namespace QRTImpl { class PortalQueryParametersForItemsImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class Envelope;

  class PortalQueryParametersForItems : public PortalQueryParameters
  {
  public:
    explicit PortalQueryParametersForItems();
    explicit PortalQueryParametersForItems(const QString& query);
    explicit PortalQueryParametersForItems(const QString& query, int limit);
    explicit PortalQueryParametersForItems(const Envelope& boundingBox);
    explicit PortalQueryParametersForItems(const QString& query, const Envelope& boundingBox);

    PortalQueryParametersForItems(const PortalQueryParametersForItems& other);
    PortalQueryParametersForItems(PortalQueryParametersForItems&& other) noexcept;
    explicit PortalQueryParametersForItems(const PortalQueryParameters& other);

    PortalQueryParametersForItems& operator=(const PortalQueryParametersForItems& other);
    PortalQueryParametersForItems& operator=(PortalQueryParametersForItems&& other) noexcept;
    PortalQueryParametersForItems& operator=(const PortalQueryParameters& other);

    ~PortalQueryParametersForItems();

    static PortalQueryParametersForItems withId(const QString& ItemId);
    static PortalQueryParametersForItems withOwner(const QString& owner);
    static PortalQueryParametersForItems inGroup(const QString& groupId);

    static PortalQueryParametersForItems forItemType(PortalItemType type, const QString& searchString = QString());
    static PortalQueryParametersForItems forItemTypeInGroup(PortalItemType type, const QString& groupId, const QString& searchString = QString());
    static PortalQueryParametersForItems forItemTypeWithOwner(PortalItemType type, const QString& owner, const QString& searchString = QString());

    static PortalQueryParametersForItems forItemTypes(QList<PortalItemType> types, const QString& owner, const QString& groupId, const QString& searchString);

    QString groupId() const;
    void setGroupId(const QString& groupId);

    QString itemId() const;
    void setItemId(const QString& itemId);

    QString owner() const;
    void setOwner(const QString& owner);

    QString searchString() const;
    void setSearchString(const QString& searchString);

    QList<PortalItemType> types() const;
    void setTypes(const QList<PortalItemType>& types);

    /*! \internal */
    explicit PortalQueryParametersForItems(const std::shared_ptr<QRTImpl::PortalQueryParametersForItemsImpl>& impl);

    /*! \internal */
    std::shared_ptr<QRTImpl::PortalQueryParametersForItemsImpl> getImpl() const;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_PortalQueryParametersForItems_H
