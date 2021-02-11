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
/// \file WmsLayerInfo.h

#ifndef QRT_WmsLayerInfo_H
#define QRT_WmsLayerInfo_H

// C++ API headers
#include "Envelope.h"
#include "ServiceTypes.h"
#include "SpatialReference.h"

// Qt headers
#include <QList>

// STL headers
#include <memory>

namespace QRTImpl {
  class WmsLayerInfoImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class WmsLayerInfo
  {
  public:
    WmsLayerInfo();
    WmsLayerInfo(const WmsLayerInfo& other);
    WmsLayerInfo(WmsLayerInfo&& other) noexcept;
    ~WmsLayerInfo();

    WmsLayerInfo& operator=(const WmsLayerInfo& other);
    WmsLayerInfo& operator=(WmsLayerInfo&& other) noexcept;

    bool isEmpty() const;

    QString description() const;

    Envelope extent() const;

    int fixedImageHeight() const;

    int fixedImageWidth() const;

    QStringList keywords() const;

    QString name() const;

    bool isOpaque() const;

    bool isQueryable() const;

    QList<SpatialReference> spatialReferences() const;

    QStringList styles() const;

    QList<WmsLayerInfo> sublayerInfos() const;

    QString title() const;

    /*! \internal */
    explicit WmsLayerInfo(const std::shared_ptr<QRTImpl::WmsLayerInfoImpl>& impl);
    std::shared_ptr<QRTImpl::WmsLayerInfoImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::WmsLayerInfoImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_WmsLayerInfo_H
