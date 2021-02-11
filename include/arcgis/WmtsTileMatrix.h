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
/// \file WmtsTileMatrix.h

#ifndef QRT_WmtsTileMatrix_H
#define QRT_WmtsTileMatrix_H

// C++ API headers
#include "ArcGISQt_global.h"

// STL headers
#include <memory>

namespace QRTImpl {
  class WmtsTileMatrixImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class WmtsTileMatrix
  {
  public:
    WmtsTileMatrix();
    WmtsTileMatrix(const WmtsTileMatrix& other);
    WmtsTileMatrix(WmtsTileMatrix&& other) noexcept;
    ~WmtsTileMatrix();

    WmtsTileMatrix& operator=(const WmtsTileMatrix& other);
    WmtsTileMatrix& operator=(WmtsTileMatrix&& other) noexcept;

    bool isEmpty() const;

    QString id() const;

    double scaleDenominator() const;

    /*! \internal */
    explicit WmtsTileMatrix(const std::shared_ptr<QRTImpl::WmtsTileMatrixImpl>& impl);
    std::shared_ptr<QRTImpl::WmtsTileMatrixImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::WmtsTileMatrixImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_WmtsTileMatrix_H
