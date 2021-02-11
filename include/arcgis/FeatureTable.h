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
/// \file FeatureTable.h

#ifndef QRT_FeatureTable_H
#define QRT_FeatureTable_H

// C++ API headers
#include "Envelope.h"
#include "Error.h"
#include "Feature.h"
#include "FeatureQueryResult.h"
#include "Loadable.h"
#include "Object.h"
#include "PopupDefinition.h"
#include "PopupSource.h"
#include "QueryParameters.h"
#include "StatisticsQueryParameters.h"
#include "StatisticsQueryResult.h"
#include "TaskWatcher.h"

// Qt headers
#include <QUuid>

namespace QRTImpl { class FeatureTableImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class FeatureLayer;

  class FeatureTable : public Object, public Loadable,
                       public PopupSource
  {
    Q_OBJECT

  public:
    ~FeatureTable();

    Envelope extent() const;

    QList<Field> fields() const;
    Field field(const QString& fieldName) const;

    GeometryType geometryType() const;

    bool hasM() const;

    bool hasZ() const;

    bool hasGeometry() const;

    bool isEditable() const;

    qint64 numberOfFeatures() const;

    FeatureTableType featureTableType() const;

    SpatialReference spatialReference() const;

    QString tableName() const;

    QString displayName() const;
    void setDisplayName(const QString& displayName);

    FeatureLayer* featureLayer() const;

    Feature* createFeature(QObject* parent = nullptr) const;
    Feature* createFeature(const QVariantMap& attributes, const Geometry& geometry, QObject* parent = nullptr) const;

    bool canAdd() const;
    bool canDelete(Feature* feature) const;
    bool canUpdate(Feature* feature) const;
    bool canEditGeometry() const;

    TaskWatcher addFeature(Feature* feature);
    TaskWatcher addFeatures(const QList<Feature*>& features);
    TaskWatcher deleteFeature(Feature* feature);
    TaskWatcher deleteFeatures(const QList<Feature*>& features);
    TaskWatcher updateFeature(Feature* feature);
    TaskWatcher updateFeatures(const QList<Feature*>& features);
    TaskWatcher queryExtent(const QueryParameters& parameters);
    TaskWatcher queryFeatureCount(const QueryParameters& parameters);
    TaskWatcher queryFeatures(const QueryParameters& parameters);
    TaskWatcher queryStatistics(const StatisticsQueryParameters& parameters);

    // Loadable Interface methods
    Error loadError() const override;
    LoadStatus loadStatus() const override;
    void cancelLoad() override;
    void load() override;
    void retryLoad() override;

    // PopupSource interface methods
    bool isPopupEnabled() const override;
    void setPopupEnabled(bool popupEnabled) override;
    PopupDefinition* popupDefinition() const override;
    void setPopupDefinition(PopupDefinition* popupDefinition) override;

    FeatureTable(const std::shared_ptr<QRTImpl::FeatureTableImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::FeatureTableImpl> getImpl() const;

  signals:
    void addFeatureCompleted(QUuid taskId, bool success);
    void addFeaturesCompleted(QUuid taskId, bool success);
    void deleteFeatureCompleted(QUuid taskId, bool success);
    void deleteFeaturesCompleted(QUuid taskId, bool success);
    void updateFeatureCompleted(QUuid taskId, bool success);
    void updateFeaturesCompleted(QUuid taskId, bool success);
    void queryExtentCompleted(QUuid taskId, const Esri::ArcGISRuntime::Envelope& envelope);
    void queryFeatureCountCompleted(QUuid taskId, quint64 count);
    void queryFeaturesCompleted(QUuid taskId, Esri::ArcGISRuntime::FeatureQueryResult* featureQueryResult);
    void queryStatisticsCompleted(QUuid taskId, Esri::ArcGISRuntime::StatisticsQueryResult* statisticsQueryResult);

    void doneLoading(Esri::ArcGISRuntime::Error loadError);
    void loadStatusChanged(Esri::ArcGISRuntime::LoadStatus loadStatus);

  protected:
    std::shared_ptr<QRTImpl::FeatureTableImpl> m_impl;

  private:
    Q_DISABLE_COPY(FeatureTable)

    FeatureTable() = delete;

    void connectSignals();
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_FeatureTable_H
