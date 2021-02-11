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
/// \file ArcGISMapImageLayer.h

#ifndef QRT_ArcGISMapImageLayer_H
#define QRT_ArcGISMapImageLayer_H

// C++ API headers
#include "ArcGISMapServiceInfo.h"
#include "ArcGISSublayerListModel.h"
#include "Credential.h"
#include "ImageAdjustmentLayer.h"
#include "Item.h"
#include "MapTypes.h"
#include "RemoteResource.h"
#include "ServiceFeatureTable.h"
#include "TaskWatcher.h"
#include "TimeAware.h"
#include "TimeExtent.h"
#include "TimeValue.h"

// Qt headers
#include <QUrl>

namespace QRTImpl {
  class ArcGISMapImageLayerImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class ArcGISMapImageLayer : public ImageAdjustmentLayer, public RemoteResource, public TimeAware
  {
    Q_OBJECT

  public:
    explicit ArcGISMapImageLayer(const QUrl& url, QObject* parent = nullptr);
    explicit ArcGISMapImageLayer(Item* item, QObject* parent = nullptr);
    ArcGISMapImageLayer(const QUrl& url, Credential* credential, QObject* parent = nullptr);
    ~ArcGISMapImageLayer();

    QString geodatabaseVersion() const;
    void setGeodatabaseVersion(const QString& geodatabaseVersion);

    MapServiceImageFormat imageFormat() const;
    void setImageFormat(MapServiceImageFormat imageFormat);

    ArcGISSublayerListModel* mapImageSublayers() const;

    ArcGISMapServiceInfo mapServiceInfo() const;

    void resetSublayers();

    quint64 refreshInterval() const;
    void setRefreshInterval(quint64 milliseconds);

    explicit ArcGISMapImageLayer(const std::shared_ptr<QRTImpl::ArcGISMapImageLayerImpl>& impl, QObject* parent = nullptr);

    // RemoteResource interface methods
    QUrl url() const override;
    Credential* credential() const override;
    RequestConfiguration requestConfiguration() const override;
    void setRequestConfiguration(const RequestConfiguration& requestConfiguration) override;

    // TimeAware interface methods
    TimeExtent fullTimeExtent() const override;
    bool isTimeFilteringEnabled() const override;
    void setTimeFilteringEnabled(bool timeFilteringEnabled) override;
    bool isSupportsTimeFiltering() const override;
    TimeValue timeInterval() const override;
    TimeValue timeOffset() const override;
    void setTimeOffset(const TimeValue& timeOffset) override;

    QList<ServiceFeatureTable*> tables() const;
    TaskWatcher loadTablesAndLayers();

  signals:
    void fullTimeExtentChanged();
    void loadTablesAndLayersCompleted(QUuid taskId);

  private:
    void connectSignals();

    Q_DISABLE_COPY(ArcGISMapImageLayer)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ArcGISMapImageLayer_H
