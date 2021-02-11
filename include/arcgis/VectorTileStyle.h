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
/// \file VectorTileStyle.h

#ifndef QRT_VectorTileStyle_H
#define QRT_VectorTileStyle_H

// C++ API headers
#include "ArcGISQt_global.h"

// Qt headers
#include <QUrl>

// STL headers
#include <memory>

namespace QRTImpl {
  class VectorTileStyleImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class VectorTileStyle
  {
  public:
    VectorTileStyle();
    VectorTileStyle(const VectorTileStyle& other);
    VectorTileStyle(VectorTileStyle&& other) noexcept;
    ~VectorTileStyle();

    VectorTileStyle& operator=(const VectorTileStyle& other);
    VectorTileStyle& operator=(VectorTileStyle&& other) noexcept;

    bool isEmpty() const;

    QUrl url() const;

    QString version() const;

    /*!
      \internal
     */
    VectorTileStyle(const std::shared_ptr<QRTImpl::VectorTileStyleImpl>& impl);
    std::shared_ptr<QRTImpl::VectorTileStyleImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::VectorTileStyleImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_VectorTileStyle_H
