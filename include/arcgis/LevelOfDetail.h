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
/// \file LevelOfDetail.h

#ifndef QRT_LevelOfDetail_H
#define QRT_LevelOfDetail_H

// C++ API headers
#include "ArcGISQt_global.h"

// STL headers
#include <memory>

namespace QRTImpl {
  class LevelOfDetailImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class LevelOfDetail
  {
  public:
    LevelOfDetail();
    LevelOfDetail(int level, double resolution, double scale);
    ~LevelOfDetail();
    LevelOfDetail(const LevelOfDetail& other);
    LevelOfDetail(LevelOfDetail&& other) noexcept;
    LevelOfDetail& operator=(const LevelOfDetail& other);
    LevelOfDetail& operator=(LevelOfDetail&& other) noexcept;

    int level() const;

    double resolution() const;

    double scale() const;

    /*!
       \internal
     */
    LevelOfDetail(const std::shared_ptr<QRTImpl::LevelOfDetailImpl>& impl);
    std::shared_ptr<QRTImpl::LevelOfDetailImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::LevelOfDetailImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_LevelOfDetail_H
