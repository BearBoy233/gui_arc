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
/// \file WmsServiceInfo.h

#ifndef QRT_WmsServiceInfo_H
#define QRT_WmsServiceInfo_H

// C++ API headers
#include "ArcGISQt_global.h"
#include "MapTypes.h"
#include "WmsLayerInfo.h"

// Qt headers
#include <QList>
#include <QUrl>

// STL headers
#include <memory>

namespace QRTImpl { class WmsServiceInfoImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class WmsServiceInfo
  {
  public:
    WmsServiceInfo();
    WmsServiceInfo(const WmsServiceInfo& other);
    WmsServiceInfo(WmsServiceInfo&& other) noexcept;
    ~WmsServiceInfo();
    WmsServiceInfo& operator=(const WmsServiceInfo& other);
    WmsServiceInfo& operator=(WmsServiceInfo&& other) noexcept;

    bool isEmpty() const;

    QString description() const;

    QStringList keywords() const;

    QList<WmsLayerInfo> layerInfos() const;

    QString title() const;

    QString name() const;

    QList<MapServiceImageFormat> imageFormats() const;

    /*!
       \internal
     */
    WmsServiceInfo(const std::shared_ptr<QRTImpl::WmsServiceInfoImpl>& impl);
    std::shared_ptr<QRTImpl::WmsServiceInfoImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::WmsServiceInfoImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_WmsServiceInfo_H
