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
/// \file WmtsLayerInfo.h

#ifndef QRT_WmtsLayerInfo_H
#define QRT_WmtsLayerInfo_H

// C++ API headers
#include "ArcGISQt_global.h"
#include "Envelope.h"
#include "ServiceTypes.h"
#include "WmtsTileMatrixSet.h"

// Qt headers
#include <QList>

// STL headers
#include <memory>

namespace QRTImpl {
  class WmtsLayerInfoImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class WmtsLayerInfo
  {
  public:
    WmtsLayerInfo();
    WmtsLayerInfo(const WmtsLayerInfo& other);
    WmtsLayerInfo(WmtsLayerInfo&& other) noexcept;
    ~WmtsLayerInfo();

    WmtsLayerInfo& operator=(const WmtsLayerInfo& other);
    WmtsLayerInfo& operator=(WmtsLayerInfo&& other) noexcept;

    bool isEmpty() const;

    QString description() const;

    QList<TileImageFormat> imageFormats() const;

    QString wmtsLayerId() const;

    QStringList keywords() const;

    QStringList styles() const;

    QList<WmtsTileMatrixSet> tileMatrixSets() const;

    QString title() const;

    /*! \internal */
    explicit WmtsLayerInfo(const std::shared_ptr<QRTImpl::WmtsLayerInfoImpl>& impl);
    std::shared_ptr<QRTImpl::WmtsLayerInfoImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::WmtsLayerInfoImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_WmtsLayerInfo_H
