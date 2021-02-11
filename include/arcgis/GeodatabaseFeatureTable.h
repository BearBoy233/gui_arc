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
/// \file GeodatabaseFeatureTable.h

#ifndef QRT_GeodatabaseFeatureTable_H
#define QRT_GeodatabaseFeatureTable_H

// C++ API headers
#include "ArcGISFeatureTable.h"

namespace QRTImpl { class GeodatabaseFeatureTableImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class Geodatabase;

  class GeodatabaseFeatureTable : public ArcGISFeatureTable
  {
    Q_OBJECT

  public:
    GeodatabaseFeatureTable(GeodatabaseFeatureTable* table, const RelationshipInfo& relationshipInfo, QObject* parent = nullptr);

    ~GeodatabaseFeatureTable();

    Geodatabase* geodatabase() const;

    bool hasLocalEditsSince(const QDateTime& date) const;

    /*!
       \internal
     */
    GeodatabaseFeatureTable(const std::shared_ptr<QRTImpl::GeodatabaseFeatureTableImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::GeodatabaseFeatureTableImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(GeodatabaseFeatureTable)

    GeodatabaseFeatureTable() = delete;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_GeodatabaseFeatureTable_H
