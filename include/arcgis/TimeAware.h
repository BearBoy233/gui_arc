// COPYRIGHT 1995-2018 ESRI
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
/// \file TimeAware.h

#ifndef QRT_TimeAware_H
#define QRT_TimeAware_H

// C++ API headers
#include "TimeExtent.h"
#include "TimeValue.h"

// Qt headers
#include <QtGlobal>

namespace Esri {
namespace ArcGISRuntime {

  class TimeAware
  {
  public:
    virtual ~TimeAware();
    virtual TimeExtent fullTimeExtent() const = 0;
    virtual bool isTimeFilteringEnabled() const = 0;
    virtual void setTimeFilteringEnabled(bool timeFilteringEnabled) = 0;
    virtual bool isSupportsTimeFiltering() const = 0;
    virtual TimeValue timeInterval() const = 0;
    virtual TimeValue timeOffset() const = 0;
    virtual void setTimeOffset(const TimeValue& timeOffset) = 0;

  // All implementing classes include this signal:
  // void fullTimeExtentChanged();

  protected:
    TimeAware();

  private:
    Q_DISABLE_COPY(TimeAware)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_TimeAware_H
