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
/// \file Distance.h

#ifndef QRT_Distance_H
#define QRT_Distance_H

// C++ API headers
#include "LinearUnit.h"

// STL headers
#include <memory>

namespace QRTImpl { class DistanceImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class Distance
  {
  public:
    Distance();
    Distance(const Distance& other);
    Distance(Distance&& other) noexcept;
    ~Distance();

    Distance& operator=(const Distance& other);
    Distance& operator=(Distance&& other) noexcept;

    bool isEmpty() const;

    LinearUnit unit() const;
    double value() const;

    /*! \internal */
    explicit Distance(const std::shared_ptr<QRTImpl::DistanceImpl>& impl);
    std::shared_ptr<QRTImpl::DistanceImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::DistanceImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_Distance_H
