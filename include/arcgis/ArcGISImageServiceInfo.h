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
/// \file ArcGISImageServiceInfo.h

#ifndef QRT_ArcGISImageServiceInfo_H
#define QRT_ArcGISImageServiceInfo_H

// C++ API headers
#include "Envelope.h"
#include "Field.h"
#include "LayerTimeInfo.h"
#include "Object.h"
#include "RasterTypes.h"
#include "RenderingRuleInfo.h"

// STL headers
#include <memory>

namespace QRTImpl {
  class ArcGISImageServiceInfoImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class ArcGISImageServiceInfo
  {

  public:
    ArcGISImageServiceInfo();

    ArcGISImageServiceInfo(const ArcGISImageServiceInfo& other);
    ArcGISImageServiceInfo(ArcGISImageServiceInfo&& other) noexcept;

    ~ArcGISImageServiceInfo();

    ArcGISImageServiceInfo& operator=(const ArcGISImageServiceInfo& other);
    ArcGISImageServiceInfo& operator=(ArcGISImageServiceInfo&& other) noexcept;

    bool isEmpty() const;

    QString attribution() const;

    QString currentVersion() const;

    Envelope fullExtent() const;

    QList<Field> fields() const;

    double maxScale() const;

    double minScale() const;

    QString name() const;

    SpatialReference spatialReference() const;

    PixelType pixelType() const;

    QList<RenderingRuleInfo> renderingRuleInfos() const;

    LayerTimeInfo timeInfo() const;

    QUrl url() const;

    /*! \internal */
    explicit ArcGISImageServiceInfo(const std::shared_ptr<QRTImpl::ArcGISImageServiceInfoImpl>& impl);
    std::shared_ptr<QRTImpl::ArcGISImageServiceInfoImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::ArcGISImageServiceInfoImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ArcGISImageServiceInfo_H
