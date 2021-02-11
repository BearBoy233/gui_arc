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
/// \file WmtsServiceInfo.h

#ifndef QRT_WmtsServiceInfo_H
#define QRT_WmtsServiceInfo_H

// C++ API headers
#include "ArcGISQt_global.h"
#include "WmtsLayerInfo.h"
#include "WmtsTileMatrixSet.h"

// Qt headers
#include <QList>
#include <QUrl>

// STL headers
#include <memory>

namespace QRTImpl { class WmtsServiceInfoImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class WmtsServiceInfo
  {
  public:
    WmtsServiceInfo();
    WmtsServiceInfo(const WmtsServiceInfo& other);
    WmtsServiceInfo(WmtsServiceInfo&& other) noexcept;
    ~WmtsServiceInfo();
    WmtsServiceInfo& operator=(const WmtsServiceInfo& other);
    WmtsServiceInfo& operator=(WmtsServiceInfo&& other) noexcept;

    bool isEmpty() const;

    QString description() const;

    QStringList keywords() const;

    QList<WmtsLayerInfo> layerInfos() const;

    QList<WmtsTileMatrixSet> tileMatrixSets() const;

    QString title() const;

    QString version() const;

    /*!
       \internal
     */
    WmtsServiceInfo(const std::shared_ptr<QRTImpl::WmtsServiceInfoImpl>& impl);
    std::shared_ptr<QRTImpl::WmtsServiceInfoImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::WmtsServiceInfoImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_WmtsServiceInfo_H
