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
/// \file ArcGISFeatureLayerInfo.h

#ifndef QRT_ArcGISFeatureLayerInfo_H
#define QRT_ArcGISFeatureLayerInfo_H

// C++ API headers
#include "DrawingInfo.h"
#include "EditFieldsInfo.h"
#include "Envelope.h"
#include "FeatureServiceCapabilities.h"
#include "FeatureSubtype.h"
#include "FeatureTemplate.h"
#include "FeatureType.h"
#include "Field.h"
#include "LayerTimeInfo.h"
#include "MapTypes.h"
#include "OwnershipBasedAccessControlInfo.h"
#include "RelationshipInfo.h"

namespace QRTImpl { class ArcGISFeatureLayerInfoImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class ArcGISFeatureLayerInfo
  {

  public:
    ArcGISFeatureLayerInfo();

    ArcGISFeatureLayerInfo(const ArcGISFeatureLayerInfo& other);
    ArcGISFeatureLayerInfo(ArcGISFeatureLayerInfo&& other) noexcept;

    ~ArcGISFeatureLayerInfo();

    ArcGISFeatureLayerInfo& operator=(const ArcGISFeatureLayerInfo& other);
    ArcGISFeatureLayerInfo& operator=(ArcGISFeatureLayerInfo&& other) noexcept;

    bool isEmpty() const;

    QString cimVersion() const;

    QUrl url() const;

    bool isAllowGeometryUpdates() const;

    FeatureServiceCapabilities capabilities() const;

    QString attribution() const;

    bool isDataVersioned() const;

    QVariant defaultSubtypeCode() const;

    bool isDefaultVisible() const;

    QString description() const;

    QString displayFieldName() const;

    DrawingInfo drawingInfo() const;

    EditFieldsInfo editFieldsInfo() const;

    double effectiveMaxScale() const;

    double effectiveMinScale() const;

    Envelope extent() const;

    QList<FeatureTemplate> featureTemplates() const;

    QList<FeatureType> featureTypes() const;

    QList<FeatureSubtype> featureSubtypes() const;

    QList<Field> fields() const;

    GeometryType geometryType() const;

    QString globalIdFieldName() const;

    bool hasAttachments() const;

    bool hasM() const;

    bool hasZ() const;

    ArcGISFeatureLayerInfoServiceType serviceType() const;

    qint64 maxRecordCount() const;

    double maxScale() const;

    double minScale() const;

    QString objectIdFieldName() const;

    OwnershipBasedAccessControlInfo ownershipBasedAccessControl() const;

    qint64 serviceLayerId() const;

    QString serviceLayerName() const;

    ServiceType serviceSourceType() const;

    QString subtypeField() const;

    bool isSupportsAdvancedQueries() const;

    bool isSupportsRollbackOnFailureParameter() const;

    bool isSupportsStatistics() const;

    bool isSupportsOBACForAnonymousUsers() const;

    bool isSupportsPagination() const;

    bool isSupportsQueryExtent() const;

    LayerTimeInfo timeInfo() const;

    QString typeIdFieldName() const;

    QString version() const;

    double zDefault() const;

    bool isZDefaultsEnabled() const;

    FeatureType featureType(const QString& name) const;

    Field field(const QString& fieldName) const;

    QList<RelationshipInfo> relationshipInfos() const;

    /*!
       \internal
     */
    ArcGISFeatureLayerInfo(const std::shared_ptr<QRTImpl::ArcGISFeatureLayerInfoImpl>& impl);
    std::shared_ptr<QRTImpl::ArcGISFeatureLayerInfoImpl> getImpl() const;

  private:

    std::shared_ptr<QRTImpl::ArcGISFeatureLayerInfoImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ArcGISFeatureLayerInfo_H
