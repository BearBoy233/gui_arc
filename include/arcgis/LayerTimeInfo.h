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
/// \file LayerTimeInfo.h

#ifndef QRT_LayerTimeInfo_H
#define QRT_LayerTimeInfo_H

// C++ API headers
#include "ServiceTypes.h"
#include "TimeExtent.h"
#include "TimeReference.h"
#include "TimeValue.h"

namespace QRTImpl { class LayerTimeInfoImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class LayerTimeInfo
  {
  public:
    LayerTimeInfo();
    LayerTimeInfo(const LayerTimeInfo& other);
    LayerTimeInfo(LayerTimeInfo&& other) noexcept;
    ~LayerTimeInfo();

    LayerTimeInfo& operator=(const LayerTimeInfo& other);
    LayerTimeInfo& operator=(LayerTimeInfo&& other) noexcept;

    bool isEmpty() const;

    QString endTimeField() const;

    bool hasLiveData() const;

    QString startTimeField() const;

    qint64 timeInterval() const;

    TimeReference timeReference() const;

    TimeUnit timeUnit() const;

    QString trackIdField() const;

    TimeExtent timeExtent() const;

    TimeValue interval() const;

    LayerTimeInfo(const std::shared_ptr<QRTImpl::LayerTimeInfoImpl>& impl);
    std::shared_ptr<QRTImpl::LayerTimeInfoImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::LayerTimeInfoImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_LayerTimeInfo_H
