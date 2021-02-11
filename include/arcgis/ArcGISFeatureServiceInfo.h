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
/// \file ArcGISFeatureServiceInfo.h

#ifndef QRT_ArcGISFeatureServiceInfo_H
#define QRT_ArcGISFeatureServiceInfo_H

// C++ API headers
#include "EditorTrackingInfo.h"
#include "Envelope.h"
#include "FeatureServiceCapabilities.h"
#include "IdInfo.h"
#include "ServiceDocumentInfo.h"
#include "SpatialReference.h"
#include "SyncCapabilities.h"
#include "Unit.h"

// Qt headers
#include <QUrl>

namespace QRTImpl { class ArcGISFeatureServiceInfoImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class ArcGISFeatureServiceInfo
  {

  public:
    ArcGISFeatureServiceInfo();

    ArcGISFeatureServiceInfo(const ArcGISFeatureServiceInfo& other);
    ArcGISFeatureServiceInfo(ArcGISFeatureServiceInfo&& other) noexcept;

    ~ArcGISFeatureServiceInfo();

    ArcGISFeatureServiceInfo& operator=(const ArcGISFeatureServiceInfo& other);
    ArcGISFeatureServiceInfo& operator=(ArcGISFeatureServiceInfo&& other) noexcept;

    bool isEmpty() const;

    QUrl url() const;

    bool isAllowGeometryUpdates() const;

    QString attribution() const;

    QString description() const;

    ServiceDocumentInfo documentInfo() const;

    EditorTrackingInfo editorTrackingInfo() const;

    QList<IdInfo> layerInfos() const;

    FeatureServiceCapabilities featureServiceCapabilities() const;

    Envelope fullExtent() const;

    bool hasStaticData() const;

    bool hasVersionedData() const;

    Envelope initialExtent() const;

    qint64 maxRecordCount() const;

    QString serviceDescription() const;

    SpatialReference spatialReference() const;

    bool isSupportsDisconnectedEditing() const;

    SyncCapabilities syncCapabilities() const;

    bool isSyncEnabled() const;

    QList<IdInfo> tableInfos() const;

    QString version() const;

    double zDefault() const;

    bool isZDefaultsEnabled() const;

    Unit unit() const;

    /*!
       \internal
     */
    ArcGISFeatureServiceInfo(const std::shared_ptr<QRTImpl::ArcGISFeatureServiceInfoImpl>& impl);
    std::shared_ptr<QRTImpl::ArcGISFeatureServiceInfoImpl> getImpl() const;

  private:

    std::shared_ptr<QRTImpl::ArcGISFeatureServiceInfoImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ArcGISFeatureServiceInfo_H
