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
/// \file ArcGISSceneLayer.h

#ifndef QRT_ArcGISSceneLayer_H
#define QRT_ArcGISSceneLayer_H

// C++ API headers
#include "Credential.h"
#include "Feature.h"
#include "FeatureQueryResult.h"
#include "FeatureTable.h"
#include "Layer.h"
#include "RemoteResource.h"
#include "TaskWatcher.h"

// Qt headers
#include <QList>
#include <QUrl>
#include <QUuid>

namespace QRTImpl { class ArcGISSceneLayerImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class ArcGISSceneLayer : public Layer, public RemoteResource
  {
    Q_OBJECT

  public:
    explicit ArcGISSceneLayer(const QUrl& url, QObject* parent = nullptr);
    ArcGISSceneLayer(const QUrl& url, Credential* credential, QObject* parent = nullptr);
    explicit ArcGISSceneLayer(Item* item, QObject* parent = nullptr);
    ~ArcGISSceneLayer();

    FeatureTable* featureTable() const;

    void clearSelection();

    TaskWatcher selectedFeatures();

    void selectFeature(Feature* feature);
    void selectFeatures(const QList<Feature*>& features);

    void unselectFeature(Feature* feature);
    void unselectFeatures(const QList<Feature*>& features);

    // RemoteResource interface methods
    QUrl url() const override;
    Credential* credential() const override;
    RequestConfiguration requestConfiguration() const override;
    void setRequestConfiguration(const RequestConfiguration& requestConfiguration) override;

    /*! \internal */
    explicit ArcGISSceneLayer(const std::shared_ptr<QRTImpl::ArcGISSceneLayerImpl>& impl, QObject* parent = nullptr);
    /*! \internal */
    std::shared_ptr<QRTImpl::ArcGISSceneLayerImpl> getImpl() const;

  signals:
    void selectedFeaturesCompleted(QUuid taskId, Esri::ArcGISRuntime::FeatureQueryResult* featureQueryResult);

  private:
    Q_DISABLE_COPY(ArcGISSceneLayer)

    ArcGISSceneLayer() = delete;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ArcGISSceneLayer_H
