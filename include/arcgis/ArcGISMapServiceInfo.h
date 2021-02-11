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
/// \file ArcGISMapServiceInfo.h

#ifndef QRT_ArcGISMapServiceInfo_H
#define QRT_ArcGISMapServiceInfo_H

// C++ API headers
#include "Envelope.h"
#include "IdInfo.h"
#include "JsonSerializable.h"
#include "MapServiceCapabilities.h"
#include "Object.h"
#include "ServiceDocumentInfo.h"
#include "ServiceTimeInfo.h"
#include "TileInfo.h"
#include "Unit.h"

// Qt headers
#include <QStringList>

// STL headers
#include <memory>

namespace QRTImpl {
  class ArcGISMapServiceInfoImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class ArcGISMapServiceInfo : public JsonSerializable
  {

  public:
    ArcGISMapServiceInfo();

    ArcGISMapServiceInfo(const ArcGISMapServiceInfo& other);
    ArcGISMapServiceInfo(ArcGISMapServiceInfo&& other) noexcept;

    ~ArcGISMapServiceInfo();

    ArcGISMapServiceInfo& operator=(const ArcGISMapServiceInfo& other);
    ArcGISMapServiceInfo& operator=(ArcGISMapServiceInfo&& other) noexcept;

    bool isEmpty() const;

    QUrl url() const;

    QString attribution() const;

    MapServiceCapabilities capabilities() const;

    QString currentVersion() const;

    QString description() const;

    ServiceDocumentInfo documentInfo() const;

    bool isExportTilesAllowed() const;

    Envelope fullExtent() const;

    Envelope initialExtent() const;

    QList<IdInfo> layerInfos() const;

    QString mapName() const;

    int maxExportTilesCount() const;

    int maxImageHeight() const;

    int maxImageWidth() const;

    int maxRecordCount() const;

    double maxScale() const;

    double minScale() const;

    QString serviceDescription() const;

    ServiceType serviceSourceType() const;

    bool isSingleFusedMapCache() const;

    SpatialReference spatialReference() const;

    QStringList supportedImageFormatTypes() const;

    bool isSupportsDynamicLayers() const;

    QList<IdInfo> tableInfos() const;

    TileInfo tileInfo() const;

    QStringList tileServers() const;

    ServiceTimeInfo timeInfo() const;

    Unit unit() const;

    // JsonSerializable Interface methods
    static ArcGISMapServiceInfo fromJson(const QString& json);
    QString toJson() const override;
    QJsonObject unknownJson() const override;
    QJsonObject unsupportedJson() const override;

    ArcGISMapServiceInfo(const std::shared_ptr<QRTImpl::ArcGISMapServiceInfoImpl>& impl);
    std::shared_ptr<QRTImpl::ArcGISMapServiceInfoImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::ArcGISMapServiceInfoImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ArcGISMapServiceInfo_H
