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
/// \file GeoprocessingFeatures.h

#ifndef QRT_GeoprocessingFeatures_H
#define QRT_GeoprocessingFeatures_H

// C++ API headers
#include "FeatureSet.h"
#include "GeoprocessingParameter.h"
#include "RemoteResource.h"
#include "TaskWatcher.h"

// Qt headers
#include <QUrl>

namespace QRTImpl { class GeoprocessingFeaturesImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class GeoprocessingFeatures : public GeoprocessingParameter, public RemoteResource
  {
    Q_OBJECT

  public:
    explicit GeoprocessingFeatures(QObject* parent = nullptr);
    explicit GeoprocessingFeatures(const QUrl& url, QObject* parent = nullptr);
    explicit GeoprocessingFeatures(const QUrl& url, Credential* credential, QObject* parent = nullptr);
    explicit GeoprocessingFeatures(FeatureSet* features, QObject* parent = nullptr);
    ~GeoprocessingFeatures();

    void setUrl(const QUrl& url);

    FeatureSet* features() const;
    void setFeatures(FeatureSet* featureSet);

    bool canFetchOutputFeatures() const;

    TaskWatcher fetchOutputFeatures();

    // RemoteResource interface methods
    QUrl url() const override;
    Credential* credential() const override;
    RequestConfiguration requestConfiguration() const override;
    void setRequestConfiguration(const RequestConfiguration& requestConfiguration) override;

    /*!
       \internal
     */
    GeoprocessingFeatures(const std::shared_ptr<QRTImpl::GeoprocessingFeaturesImpl>& impl, QObject* parent = nullptr);

  signals:
    void fetchOutputFeaturesCompleted(QUuid taskId);

  private:
    Q_DISABLE_COPY(GeoprocessingFeatures)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_GeoprocessingFeatures_H

