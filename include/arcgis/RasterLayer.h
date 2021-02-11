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
/// \file RasterLayer.h

#ifndef QRT_RasterLayer_H
#define QRT_RasterLayer_H

// C++ API headers
#include "ImageAdjustmentLayer.h"
#include "PopupDefinition.h"
#include "PopupSource.h"
#include "Raster.h"
#include "RasterRenderer.h"
#include "TimeAware.h"

namespace QRTImpl { class RasterLayerImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class RasterLayer : public ImageAdjustmentLayer, public PopupSource, public TimeAware
  {
    Q_OBJECT

  public:
    explicit RasterLayer(Raster* raster, QObject* parent = nullptr);
    explicit RasterLayer(Item* item, QObject* parent = nullptr);
    ~RasterLayer();

    Raster* raster() const;

    RasterRenderer* renderer() const;
    void setRenderer(RasterRenderer* renderer);

    // PopupSource interface methods
    bool isPopupEnabled() const override;
    void setPopupEnabled(bool popupEnabled) override;
    PopupDefinition* popupDefinition() const override;
    void setPopupDefinition(PopupDefinition* popupDefinition) override;

    // TimeAware interface methods
    TimeExtent fullTimeExtent() const override;
    bool isTimeFilteringEnabled() const override;
    void setTimeFilteringEnabled(bool timeFilteringEnabled) override;
    bool isSupportsTimeFiltering() const override;
    TimeValue timeInterval() const override;
    TimeValue timeOffset() const override;
    void setTimeOffset(const TimeValue& timeOffset) override;

    /*! \internal */
    explicit RasterLayer(const std::shared_ptr<QRTImpl::RasterLayerImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::RasterLayerImpl> getImpl() const;

  signals:
    void fullTimeExtentChanged();

  private:
    Q_DISABLE_COPY(RasterLayer)

    RasterLayer() = delete;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_RasterLayer_H
