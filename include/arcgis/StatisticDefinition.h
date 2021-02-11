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
/// \file StatisticDefinition.h

#ifndef QRT_StatisticDefinition_H
#define QRT_StatisticDefinition_H

// Qt headers
#include <QString>

// STL headers
#include <CoreTypes.h>
#include <memory>

namespace QRTImpl { class StatisticDefinitionImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class StatisticDefinition
  {
  public:
    StatisticDefinition();
    StatisticDefinition(const QString& onFieldName, StatisticType statisticType, const QString& outputAlias);
    StatisticDefinition(const StatisticDefinition& other);
    StatisticDefinition(StatisticDefinition&& other) noexcept;
    ~StatisticDefinition();

    StatisticDefinition& operator=(const StatisticDefinition& other);
    StatisticDefinition& operator=(StatisticDefinition&& other) noexcept;

    bool isEmpty() const;
    void clear();

    QString onFieldName() const;
    void setOnFieldName(const QString& onFieldName);

    QString outputAlias() const;
    void setOutputAlias(const QString& outputAlias);

    StatisticType statisticType() const;
    void setStatisticType(StatisticType statisticType);

    StatisticDefinition(const std::shared_ptr<QRTImpl::StatisticDefinitionImpl>& impl);
    std::shared_ptr<QRTImpl::StatisticDefinitionImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::StatisticDefinitionImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_StatisticDefinition_H
