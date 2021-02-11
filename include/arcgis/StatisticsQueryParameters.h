// COPYRIGHT 1995-2017 ESRI
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
/// \file StatisticsQueryParameters.h

#ifndef QRT_StatisticsQueryParameters_H
#define QRT_StatisticsQueryParameters_H

// C++ API headers
#include "Geometry.h"
#include "OrderBy.h"
#include "TimeExtent.h"

// Qt headers
#include <QStringList>

// STL headers
#include <memory>

namespace QRTImpl {
  class StatisticsQueryParametersImpl;
}

namespace Esri {
namespace ArcGISRuntime {
    class StatisticDefinition;

  class StatisticsQueryParameters
  {
  public:
    StatisticsQueryParameters();
    StatisticsQueryParameters(const QList<StatisticDefinition>& statisticDefinitions);
    StatisticsQueryParameters(const StatisticsQueryParameters& other);
    StatisticsQueryParameters(StatisticsQueryParameters&& other) noexcept;
    ~StatisticsQueryParameters();

    StatisticsQueryParameters& operator=(const StatisticsQueryParameters& other);
    StatisticsQueryParameters& operator=(StatisticsQueryParameters&& other) noexcept;

    bool isEmpty() const;
    void clear();

    Geometry geometry() const;
    void setGeometry(const Geometry& geometry);

    QStringList groupByFieldNames() const;
    void setGroupByFieldNames(const QStringList& groupByFieldNames);

    QList<OrderBy> orderByFields() const;
    void setOrderByFields(const QList<OrderBy>& orderByFields);

    SpatialRelationship spatialRelationship() const;
    void setSpatialRelationship(SpatialRelationship relationship);

    QList<StatisticDefinition> statisticDefinitions() const;
    void setStatisticDefinitions(const QList<StatisticDefinition>& statisticDefinitions);

    QString whereClause() const;
    void setWhereClause(const QString& whereClause);

    TimeExtent timeExtent() const;
    void setTimeExtent(const TimeExtent& timeExtent);

    StatisticsQueryParameters(const std::shared_ptr<QRTImpl::StatisticsQueryParametersImpl>& impl);
    std::shared_ptr<QRTImpl::StatisticsQueryParametersImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::StatisticsQueryParametersImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_StatisticsQueryParameters_H
