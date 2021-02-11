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
/// \file ArcGISMapServiceSublayerInfo.h

#ifndef QRT_ArcGISMapServiceSublayerInfo_H
#define QRT_ArcGISMapServiceSublayerInfo_H

// C++ API headers
#include "DrawingInfo.h"
#include "Envelope.h"
#include "FeatureSubtype.h"
#include "FeatureType.h"
#include "IdInfo.h"
#include "LayerTimeInfo.h"
#include "MapServiceCapabilities.h"
#include "MapTypes.h"
#include "OwnershipBasedAccessControlInfo.h"
#include "RelationshipInfo.h"

namespace QRTImpl { class ArcGISMapServiceSublayerInfoImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class ArcGISMapServiceSublayerInfo
  {
  public:
    ArcGISMapServiceSublayerInfo();
    ArcGISMapServiceSublayerInfo(const ArcGISMapServiceSublayerInfo& other);
    ArcGISMapServiceSublayerInfo(ArcGISMapServiceSublayerInfo&& other) noexcept;
    ~ArcGISMapServiceSublayerInfo();

    ArcGISMapServiceSublayerInfo& operator=(const ArcGISMapServiceSublayerInfo& other);
    ArcGISMapServiceSublayerInfo& operator=(ArcGISMapServiceSublayerInfo&& other) noexcept;

    bool isEmpty() const;

    QUrl url() const;

    QString attribution() const;

    bool canModifyLayer() const;

    bool canScaleSymbols() const;

    MapServiceCapabilities capabilities() const;

    QVariant defaultSubtypeCode() const;

    bool isDefaultVisible() const;

    QString definitionExpression() const;

    QString description() const;

    QString displayFieldName() const;

    DrawingInfo drawingInfo() const;

    double effectiveMaxScale() const;

    double effectiveMinScale() const;

    Envelope extent() const;

    QList<FeatureType> featureTypes() const;

    QList<FeatureSubtype> featureSubtypes() const;

    QList<Field> fields() const;

    GeometryType geometryType() const;

    bool hasAttachments() const;

    bool hasLabels() const;

    bool hasM() const;

    bool hasZ() const;

    bool isDataVersioned() const;

    qint64 maxRecordCount() const;

    double maxScale() const;

    double minScale() const;

    OwnershipBasedAccessControlInfo ownershipBasedAccessControl() const;

    IdInfo parentLayerInfo() const;

    qint64 serviceLayerId() const;

    QString serviceLayerName() const;

    QList<RelationshipInfo> relationshipInfos() const;

    ArcGISMapServiceSublayerType sublayerType() const;

    QList<IdInfo> sublayerInfos() const;

    QString subtypeField() const;

    bool isSupportsAdvancedQueries() const;

    bool isSupportsStatistics() const;

    LayerTimeInfo timeInfo() const;

    QString typeIdFieldName() const;

    bool isUseStandardizedQueries() const;

    QString version() const;

    Field field(const QString& fieldName) const;

    /*!
       \internal
     */
    ArcGISMapServiceSublayerInfo(const std::shared_ptr<QRTImpl::ArcGISMapServiceSublayerInfoImpl>& impl);
    std::shared_ptr<QRTImpl::ArcGISMapServiceSublayerInfoImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::ArcGISMapServiceSublayerInfoImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ArcGISMapServiceSublayerInfo_H
