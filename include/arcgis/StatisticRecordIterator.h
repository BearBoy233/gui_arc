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
/// \file StatisticRecordIterator.h

#ifndef QRT_StatisticRecordIterator_H
#define QRT_StatisticRecordIterator_H

// C++ API headers
#include "Object.h"
#include "StatisticRecord.h"

namespace QRTImpl {
  class StatisticRecordIteratorImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class StatisticRecordIterator
  {
  public:
    StatisticRecordIterator();
    StatisticRecordIterator(const StatisticRecordIterator& other);
    StatisticRecordIterator(StatisticRecordIterator&& other) noexcept;
    ~StatisticRecordIterator();

    StatisticRecordIterator& operator=(const StatisticRecordIterator& other);
    StatisticRecordIterator& operator=(StatisticRecordIterator&& other) noexcept;

    bool isEmpty() const;

    bool hasNext() const;

    StatisticRecord* next(QObject* parent = nullptr) const;

    void reset();

    QList<StatisticRecord*> statisticRecords(QObject* parent = nullptr) const;

    /*! \internal */
    StatisticRecordIterator(const std::shared_ptr<QRTImpl::StatisticRecordIteratorImpl>& impl);
    std::shared_ptr<QRTImpl::StatisticRecordIteratorImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::StatisticRecordIteratorImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_StatisticRecordIterator_H
