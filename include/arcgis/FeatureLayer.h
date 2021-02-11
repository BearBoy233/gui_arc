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
/// \file FeatureLayer.h

#ifndef QRT_FeatureLayer_H
#define QRT_FeatureLayer_H

// C++ API headers
#include "FeatureQueryResult.h"
#include "FeatureTable.h"
#include "LabelDefinitionListModel.h"
#include "Layer.h"
#include "LayerSceneProperties.h"
#include "PopupDefinition.h"
#include "PopupSource.h"
#include "QueryParameters.h"
#include "Renderer.h"
#include "TaskWatcher.h"
#include "TimeAware.h"
#include "TimeExtent.h"
#include "TimeValue.h"

// Qt headers
#include <QColor>

namespace QRTImpl { class FeatureLayerImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class FeatureLayer : public Layer, public PopupSource, public TimeAware
  {
    Q_OBJECT

  public:
    explicit FeatureLayer(FeatureTable* featureTable, QObject* parent = nullptr);
    FeatureLayer(Item* item, qint64 serviceLayerId, QObject* parent = nullptr);
    ~FeatureLayer();

    QString definitionExpression() const;
    void setDefinitionExpression(const QString& expression);

    FeatureTable* featureTable() const;
    qint64 serviceLayerId() const;

    bool isLabelsEnabled() const;
    void setLabelsEnabled(bool enabled);

    Renderer* renderer() const;
    void setRenderer(Renderer* renderer);
    void resetRenderer();

    FeatureRenderingMode renderingMode() const;
    void setRenderingMode(FeatureRenderingMode renderingMode);

    LayerSceneProperties sceneProperties() const;
    void setSceneProperties(const LayerSceneProperties& sceneProperties);

    QColor selectionColor() const;
    void setSelectionColor(const QColor& selectionColor);

    double selectionWidth() const;
    void setSelectionWidth(double selectionWidth);

    void clearSelection();

    TaskWatcher selectedFeatures();

    void setFeatureVisible(Feature* feature, bool visible);
    void setFeaturesVisible(const QList<Feature*>& features, bool visible);
    void resetFeaturesVisible();

    void selectFeature(Feature* feature);
    void selectFeatures(const QList<Feature*>& features);
    TaskWatcher selectFeatures(const QueryParameters& parameters, SelectionMode mode);

    void unselectFeature(Feature* feature);
    void unselectFeatures(const QList<Feature*>& features);

    quint64 refreshInterval() const;
    void setRefreshInterval(quint64 milliseconds);

    LabelDefinitionListModel* labelDefinitions() const;

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
    explicit FeatureLayer(const std::shared_ptr<QRTImpl::FeatureLayerImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::FeatureLayerImpl> getImpl() const;

  signals:
    void selectedFeaturesCompleted(QUuid taskId, Esri::ArcGISRuntime::FeatureQueryResult* featureQueryResult);
    void selectFeaturesCompleted(QUuid taskId, Esri::ArcGISRuntime::FeatureQueryResult* featureQueryResult);
    void fullTimeExtentChanged();

  private:
    Q_DISABLE_COPY(FeatureLayer)

    FeatureLayer() = delete;

    void connectSignals();
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_FeatureLayer_H
