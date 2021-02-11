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
/// \file WmsLayer.h

#ifndef QRT_WmsLayer_H
#define QRT_WmsLayer_H

// C++ API headers
#include "ImageAdjustmentLayer.h"
#include "MapTypes.h"
#include "RemoteResource.h"
#include "ServiceTypes.h"
#include "TimeAware.h"
#include "WmsLayerInfo.h"
#include "WmsSublayer.h"

// Qt headers
#include <QUrl>

namespace QRTImpl {
  class WmsLayerImpl;
}

namespace Esri {
  namespace ArcGISRuntime {

  class WmsLayer : public ImageAdjustmentLayer, public RemoteResource, public TimeAware
  {
    Q_OBJECT

  public:
    WmsLayer(const QUrl& url,
             const QStringList& layerNames,
             QObject* parent = nullptr);

    WmsLayer(const QUrl& url,
             const QStringList& layerNames,
             Credential* credential,
             QObject* parent = nullptr);

    explicit WmsLayer(const QList<WmsLayerInfo>& layerInfos,
                      QObject* parent = nullptr);

    explicit WmsLayer(Item* item, QObject* parent = nullptr);

    ~WmsLayer();

    Esri::ArcGISRuntime::MapServiceImageFormat preferredImageFormat() const;
    void setPreferredImageFormat(Esri::ArcGISRuntime::MapServiceImageFormat preferredImageFormat);

    QStringList layerNames() const;

    QList<WmsLayerInfo> layerInfos() const;

    QList<WmsSublayer*> subLayers() const;

    WmsVersion version() const;

    QMap<QString, QString> customParameters() const;
    void setCustomParameters(const QMap<QString, QString>& customParameters);

    quint64 refreshInterval() const;
    void setRefreshInterval(quint64 milliseconds);

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

    /*! \internal */
    explicit WmsLayer(const std::shared_ptr<QRTImpl::WmsLayerImpl>& impl, QObject* parent = nullptr);

  signals:
    void fullTimeExtentChanged();

  private:
    Q_DISABLE_COPY(WmsLayer)
  };

  } // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_WmsLayer_H
