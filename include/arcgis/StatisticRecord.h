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
/// \file StatisticRecord.h

#ifndef QRT_StatisticRecord_H
#define QRT_StatisticRecord_H

// C++ API headers
#include "Object.h"

// Qt headers
#include <QVariantMap>

namespace QRTImpl { class StatisticRecordImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class StatisticRecord : public Object
  {
    Q_OBJECT

  public:
    ~StatisticRecord();

    QVariantMap group() const;
    QVariantMap statistics() const;

    StatisticRecord(const std::shared_ptr<QRTImpl::StatisticRecordImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::StatisticRecordImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(StatisticRecord)

    std::shared_ptr<QRTImpl::StatisticRecordImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_StatisticRecord_H
