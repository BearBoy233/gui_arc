// COPYRIGHT 1995-2018 ESRI
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
/// \file KmlLayer.h

#ifndef QRT_KmlLayer_H
#define QRT_KmlLayer_H

// C++ API headers
#include "Item.h"
#include "KmlDataset.h"
#include "Layer.h"
#include "TimeAware.h"

namespace QRTImpl { class KmlLayerImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class KmlLayer : public Layer, public TimeAware
  {
    Q_OBJECT

  public:
    explicit KmlLayer(Item* item, QObject* parent = nullptr);
    explicit KmlLayer(KmlDataset* dataset, QObject* parent = nullptr);
    ~KmlLayer();

    KmlDataset* dataset() const;

    // TimeAware interface methods
    TimeExtent fullTimeExtent() const override;
    bool isTimeFilteringEnabled() const override;
    void setTimeFilteringEnabled(bool timeFilteringEnabled) override;
    bool isSupportsTimeFiltering() const override;
    TimeValue timeInterval() const override;
    TimeValue timeOffset() const override;
    void setTimeOffset(const TimeValue& timeOffset) override;

    /*! \internal */
    explicit KmlLayer(const std::shared_ptr<QRTImpl::KmlLayerImpl>& impl, QObject* parent = nullptr);

  signals:
    void fullTimeExtentChanged();

  private:
    Q_DISABLE_COPY(KmlLayer)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_KmlLayer_H
