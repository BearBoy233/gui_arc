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
/// \file WmtsTileMatrixSet.h

#ifndef QRT_WmtsTileMatrixSet_H
#define QRT_WmtsTileMatrixSet_H

// C++ API headers
#include "ArcGISQt_global.h"
#include "Envelope.h"
#include "SpatialReference.h"
#include "WmtsTileMatrix.h"

// Qt headers
#include <QList>

// STL headers
#include <memory>

namespace QRTImpl {
  class WmtsTileMatrixSetImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class WmtsTileMatrixSet
  {
  public:
    WmtsTileMatrixSet();
    WmtsTileMatrixSet(const WmtsTileMatrixSet& other);
    WmtsTileMatrixSet(WmtsTileMatrixSet&& other) noexcept;
    ~WmtsTileMatrixSet();

    WmtsTileMatrixSet& operator=(const WmtsTileMatrixSet& other);
    WmtsTileMatrixSet& operator=(WmtsTileMatrixSet&& other) noexcept;

    bool isEmpty() const;

    QString description() const;

    Envelope extent() const;

    QString id() const;

    QStringList keywords() const;

    SpatialReference spatialReference() const;

    QList<WmtsTileMatrix> tileMatrices() const;

    QString title() const;

    QString wellKnownScaleSetId() const;

    /*! \internal */
    explicit WmtsTileMatrixSet(const std::shared_ptr<QRTImpl::WmtsTileMatrixSetImpl>& impl);
    std::shared_ptr<QRTImpl::WmtsTileMatrixSetImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::WmtsTileMatrixSetImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_WmtsTileMatrixSet_H
