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
/// \file ServiceFeatureTable.h

#ifndef QRT_ServiceFeatureTable_H
#define QRT_ServiceFeatureTable_H

// C++ API headers
#include "ArcGISFeatureTable.h"
#include "Credential.h"
#include "Feature.h"
#include "FeatureEditResult.h"
#include "Item.h"
#include "RemoteResource.h"
#include "TaskWatcher.h"

// Qt headers
#include <QStringList>
#include <QUuid>

namespace QRTImpl { class ServiceFeatureTableImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class ServiceFeatureTable : public ArcGISFeatureTable, public RemoteResource
  {
    Q_OBJECT

  public:
    ServiceFeatureTable(const QUrl& url, QObject* parent = nullptr);
    ServiceFeatureTable(ServiceFeatureTable* table, const RelationshipInfo& relationshipInfo, QObject* parent = nullptr);
    ServiceFeatureTable(const QUrl& url, Credential* credential, QObject* parent = nullptr);
    ServiceFeatureTable(Item* item, qint64 layerId, QObject* parent = nullptr);
    ~ServiceFeatureTable();

    double bufferFactor() const;
    void setBufferFactor(double buffer);

    QString definitionExpression() const;
    void setDefinitionExpression(const QString& expression);

    FeatureRequestMode featureRequestMode() const;
    void setFeatureRequestMode(FeatureRequestMode mode);

    QString geodatabaseVersion() const;
    void setGeodatabaseVersion(const QString& version);

    void clearCache(bool keepLocalEdits = true);

    TaskWatcher applyEdits();

    TaskWatcher loadOrRefreshFeatures(const QList<Feature*>& features);

    TaskWatcher populateFromService(const QueryParameters& parameters,
                                    bool clearCache,
                                    const QStringList& outFields);

    TaskWatcher undoLocalEdits();

    using FeatureTable::queryFeatures;
    TaskWatcher queryFeatures(const QueryParameters& parameters, QueryFeatureFields queryFeatureFields);
    using ArcGISFeatureTable::queryRelatedFeatures;
    TaskWatcher queryRelatedFeatures(ArcGISFeature* originFeature, const RelatedQueryParameters& relatedQueryParameters, QueryFeatureFields queryFeatureFields);

    // RemoteResource interface methods
    QUrl url() const override;
    Credential* credential() const override;
    RequestConfiguration requestConfiguration() const override;
    void setRequestConfiguration(const RequestConfiguration& requestConfiguration) override;

    ServiceFeatureTable(const std::shared_ptr<QRTImpl::ServiceFeatureTableImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::ServiceFeatureTableImpl> getImpl() const;

  signals:
    void applyEditsCompleted(QUuid taskId, const QList<Esri::ArcGISRuntime::FeatureEditResult*>& featureEditResults);
    void populateFromServiceCompleted(QUuid taskId, Esri::ArcGISRuntime::FeatureQueryResult* featureQueryResult);
    void undoLocalEditsCompleted(QUuid taskId);
    void loadOrRefreshFeaturesCompleted(QUuid taskId);

  private:
    Q_DISABLE_COPY(ServiceFeatureTable)

    ServiceFeatureTable() = delete;

    void connectSignals();
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ServiceFeatureTable_H
