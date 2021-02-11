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
/// \file StatisticsQueryResult.h

#ifndef QRT_StatisticsQueryResult_H
#define QRT_StatisticsQueryResult_H

// C++ API headers
#include "Object.h"
#include "StatisticRecordIterator.h"

namespace QRTImpl {
  class StatisticsQueryResultImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class StatisticsQueryResult : public Object
  {
    Q_OBJECT

  public:
    ~StatisticsQueryResult();

    StatisticRecordIterator iterator() const;

    StatisticsQueryResult(const std::shared_ptr<QRTImpl::StatisticsQueryResultImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::StatisticsQueryResultImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(StatisticsQueryResult)

    std::shared_ptr<QRTImpl::StatisticsQueryResultImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_StatisticsQueryResult_H
