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
/// \file ImageServiceRaster.h

#ifndef QRT_ImageServiceRaster_H
#define QRT_ImageServiceRaster_H

// C++ API headers
#include "ArcGISImageServiceInfo.h"
#include "Credential.h"
#include "Raster.h"
#include "RemoteResource.h"
#include "RenderingRule.h"

namespace QRTImpl { class ImageServiceRasterImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class ImageServiceRaster : public Raster, public RemoteResource
  {
    Q_OBJECT

  public:

    explicit ImageServiceRaster(const QUrl& url, QObject* parent = nullptr);
    ImageServiceRaster(const QUrl& url, Credential* credential, QObject* parent =  nullptr);
    ~ImageServiceRaster();

    RenderingRule* renderingRule() const;
    void setRenderingRule(RenderingRule* renderingRule);

    ArcGISImageServiceInfo serviceInfo() const;

    // RemoteResource interface methods
    QUrl url() const override;
    Credential* credential() const override;
    RequestConfiguration requestConfiguration() const override;
    void setRequestConfiguration(const RequestConfiguration& requestConfiguration) override;

    explicit ImageServiceRaster(const std::shared_ptr<QRTImpl::ImageServiceRasterImpl>& impl, QObject* parent = nullptr);

  private:
    Q_DISABLE_COPY(ImageServiceRaster)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ImageServiceRaster_H
