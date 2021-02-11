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
/// \file FeatureCollectionTable.h

#ifndef QRT_FeatureCollectionTable_H
#define QRT_FeatureCollectionTable_H

// C++ API headers
#include "ArcGISFeatureLayerInfo.h"
#include "FeatureSet.h"
#include "FeatureTable.h"
#include "Renderer.h"

namespace QRTImpl { class FeatureCollectionTableImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class FeatureLayer;

  class FeatureCollectionTable : public FeatureTable, public FeatureSet
  {
    Q_OBJECT

  public:
    FeatureCollectionTable(const QList<Field>& fields, Esri::ArcGISRuntime::GeometryType geometryType, const SpatialReference& spatialReference, QObject* parent = nullptr);
    FeatureCollectionTable(const QList<Field>& fields, Esri::ArcGISRuntime::GeometryType geometryType, const SpatialReference& spatialReference, bool hasZ, bool hasM, QObject* parent = nullptr);
    FeatureCollectionTable(const QList<GeoElement*>& geoElements, const QList<Field>& fields, QObject* parent = nullptr);
    explicit FeatureCollectionTable(FeatureSet* featureSet, QObject* parent = nullptr);

    ~FeatureCollectionTable();

    QString title() const;
    void setTitle(const QString& title);

    Renderer* renderer() const;
    void setRenderer(Renderer* renderer);

    ArcGISFeatureLayerInfo layerInfo();

    Symbol* symbolOverride(Feature* feature) const;
    void setSymbolOverride(Feature* feature, Symbol* symbol);

    // FeatureSet methods
    QList<Field> fields() const override;
    GeometryType geometryType() const override;
    SpatialReference spatialReference() const override;
    FeatureIterator iterator() const override;

    FeatureCollectionTable(const std::shared_ptr<QRTImpl::FeatureCollectionTableImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::FeatureCollectionTableImpl> getImpl() const;
    std::shared_ptr<QRTImpl::FeatureSetImpl> iGetImpl() const override;

  private:
    Q_DISABLE_COPY(FeatureCollectionTable)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_FeatureCollectionTable_H
