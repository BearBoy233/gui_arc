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
/// \file ArcGISFeatureTable.h

#ifndef QRT_ArcGISFeatureTable_H
#define QRT_ArcGISFeatureTable_H

// C++ API headers
#include "ArcGISFeature.h"
#include "ArcGISFeatureLayerInfo.h"
#include "FeatureSubtype.h"
#include "FeatureTable.h"
#include "FeatureTemplate.h"
#include "FeatureType.h"
#include "RelatedFeatureQueryResult.h"
#include "RelatedQueryParameters.h"
#include "RelationshipInfo.h"

namespace QRTImpl { class ArcGISFeatureTableImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class ArcGISFeatureTable : public FeatureTable
  {
    Q_OBJECT

  public:
    ~ArcGISFeatureTable();

    QList<FeatureTemplate> featureTemplates() const;
    FeatureTemplate featureTemplate(const QString& name) const;

    QList<FeatureType> featureTypes() const;
    FeatureType featureType(const QString& name) const;

    QList<FeatureSubtype> featureSubtypes() const;

    QString globalIdField() const;

    bool hasAttachments() const;

    QString objectIdField() const;

    QString typeIdField() const;

    QVariant defaultSubtypeCode() const;

    QString subtypeField() const;

    bool isUseAdvancedSymbology() const;
    void setUseAdvancedSymbology(bool advancedSymbology);

    ArcGISFeature* createFeatureWithTemplate(const FeatureTemplate& featureTemplate, QObject* parent = nullptr) const;
    ArcGISFeature* createFeatureWithTemplate(const FeatureTemplate& featureTemplate, const Geometry& geometry, QObject* parent = nullptr) const;
    ArcGISFeature* createFeatureWithType(const FeatureType& featureType, QObject* parent = nullptr) const;
    ArcGISFeature* createFeatureWithType(const FeatureType& featureType, const Geometry& geometry, QObject* parent = nullptr) const;
    ArcGISFeature* createFeatureWithSubtype(const FeatureSubtype& featureSubtype, QObject* parent = nullptr) const;
    ArcGISFeature* createFeatureWithSubtype(const FeatureSubtype& featureSubtype, const Geometry& geometry, QObject* parent = nullptr) const;

    qint64 serviceLayerId() const;
    ArcGISFeatureLayerInfo layerInfo() const;

    QList<Field> editableAttributeFields() const;

    QList<ArcGISFeatureTable*> relatedTables(const RelationshipInfo& relationshipInfo) const;
    QList<ArcGISFeatureTable*> relatedTables() const;

    TaskWatcher queryRelatedFeatures(ArcGISFeature* feature);
    TaskWatcher queryRelatedFeatures(ArcGISFeature* feature, const RelatedQueryParameters& relatedQueryParameters);
    TaskWatcher queryRelatedFeatureCount(ArcGISFeature* feature);
    TaskWatcher queryRelatedFeatureCount(ArcGISFeature* feature, const RelatedQueryParameters& relatedQueryParameters);
    TaskWatcher validateRelationshipConstraints(ArcGISFeature* feature);

    TaskWatcher addedFeatures();
    TaskWatcher addedFeaturesCount();

    TaskWatcher deletedFeatures();
    TaskWatcher deletedFeaturesCount();

    TaskWatcher updatedFeatures();
    TaskWatcher updatedFeaturesCount();

    /*! \internal */
    ArcGISFeatureTable(const std::shared_ptr<QRTImpl::ArcGISFeatureTableImpl>& impl, QObject* parent = nullptr);
    /*! \internal */
    std::shared_ptr<QRTImpl::ArcGISFeatureTableImpl> getImpl() const;

  signals:
    void addedFeaturesCompleted(QUuid taskId, Esri::ArcGISRuntime::FeatureQueryResult* featureQueryResult);
    void addedFeaturesCountCompleted(QUuid taskId, qint64 count);
    void deletedFeaturesCompleted(QUuid taskId, Esri::ArcGISRuntime::FeatureQueryResult* featureQueryResult);
    void deletedFeaturesCountCompleted(QUuid taskId, qint64 count);
    void updatedFeaturesCompleted(QUuid taskId, Esri::ArcGISRuntime::FeatureQueryResult* featureQueryResult);
    void updatedFeaturesCountCompleted(QUuid taskId, qint64 count);
    void queryRelatedFeaturesCompleted(QUuid taskId, QList<Esri::ArcGISRuntime::RelatedFeatureQueryResult*> relatedFeatureQueryResults);
    void queryRelatedFeatureCountCompleted(QUuid taskId, quint64 count);
    void validateRelationshipConstraintsCompleted(QUuid taskId, Esri::ArcGISRuntime::RelationshipConstraintViolationType relationshipConstraintViolationType);

  private:
    Q_DISABLE_COPY(ArcGISFeatureTable)

    ArcGISFeatureTable() = delete;

    void connectSignals();
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ArcGISFeatureTable_H
