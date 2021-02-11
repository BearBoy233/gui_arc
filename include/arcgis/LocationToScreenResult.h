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
/// \file LocationToScreenResult.h

#ifndef QRT_LocationToScreenResult_H
#define QRT_LocationToScreenResult_H

// C++ API headers
#include "SceneViewTypes.h"

// Qt headers
#include <QPointF>

// STL headers
#include <memory>

namespace QRTImpl { class LocationToScreenResultImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class LocationToScreenResult
  {
  public:
    LocationToScreenResult();
    LocationToScreenResult(const LocationToScreenResult& other);
    LocationToScreenResult(LocationToScreenResult&& other) noexcept;
    ~LocationToScreenResult();

    LocationToScreenResult& operator=(const LocationToScreenResult& other);
    LocationToScreenResult& operator=(LocationToScreenResult&& other) noexcept;

    bool isEmpty() const;

    QPointF screenPoint() const;
    SceneLocationVisibility visibility() const;

    /*!
       \internal
     */
    LocationToScreenResult(const std::shared_ptr<QRTImpl::LocationToScreenResultImpl>& impl);
    std::shared_ptr<QRTImpl::LocationToScreenResultImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::LocationToScreenResultImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_LocationToScreenResult_H
