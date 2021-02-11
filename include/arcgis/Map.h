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
/// \file Map.h

#ifndef QRT_Map_H
#define QRT_Map_H

// C++ API headers
#include "Basemap.h"
#include "BookmarkListModel.h"
#include "FeatureTableListModel.h"
#include "Item.h"
#include "JsonSerializable.h"
#include "LayerListModel.h"
#include "LegendInfoListModel.h"
#include "LoadSettings.h"
#include "Loadable.h"
#include "Object.h"
#include "Portal.h"
#include "PortalFolder.h"
#include "PortalItem.h"
#include "SpatialReference.h"
#include "TransportationNetworkDataset.h"
#include "Viewpoint.h"

// Qt headers
#include <QUrl>
#include <QUuid>

namespace QRTImpl { class MapImpl; }

namespace Esri {
namespace ArcGISRuntime {

class Map : public Object, public Loadable, public JsonSerializable
{
  Q_OBJECT

public:
  explicit Map(QObject* parent = nullptr);
  explicit Map(const QUrl& url, QObject* parent = nullptr);
  explicit Map(Basemap* basemap, QObject* parent = nullptr);
  Map(BasemapType basemapType, double latitude, double longitude, int levelOfDetail, QObject* parent = nullptr);
  explicit Map(Item* item, QObject* parent = nullptr);
  explicit Map(const SpatialReference& spatialReference, QObject* parent = nullptr);
  ~Map();

  Viewpoint initialViewpoint() const;
  void setInitialViewpoint(const Viewpoint& viewpoint);

  Item* item() const;

  LoadSettings* loadSettings() const;
  void setLoadSettings(LoadSettings* settings);

  QString version() const;

  SpatialReference spatialReference() const;

  LayerListModel* operationalLayers() const;

  Basemap* basemap() const;
  void setBasemap(Basemap* basemap);

  BookmarkListModel* bookmarks() const;

  double maxScale() const;
  void setMaxScale(double scale);

  double minScale() const;
  void setMinScale(double scale);

  bool isAutoFetchLegendInfos() const;
  void setAutoFetchLegendInfos(bool autoFetchLegendInfos);

  LegendInfoListModel* legendInfos() const;

  QList<TransportationNetworkDataset*> transportationNetworks() const;

  FeatureTableListModel* tables() const;

  QUuid save(bool forceSaveToSupportedVersion);
  QUuid saveAs(Portal* portal,
               const QString& title,
               const QStringList& tags,
               bool forceSaveToSupportedVersion,
               const PortalFolder& folder = PortalFolder(),
               const QString& description = QString(),
               const QByteArray& thumbnailBytes = QByteArray());

  static Map* fromJson(const QString& json, QObject* parent = nullptr);
  QString toJson() const override;
  QJsonObject unknownJson() const override;
  QJsonObject unsupportedJson() const override;

  Error loadError() const override;
  LoadStatus loadStatus() const override;
  void cancelLoad() override;
  void load() override;
  void retryLoad() override;

  /*!
     \internal
   */
  Map(const std::shared_ptr<QRTImpl::MapImpl>& impl, QObject* parent = nullptr);
  std::shared_ptr<QRTImpl::MapImpl> getImpl() const;

signals:
  void basemapChanged(Esri::ArcGISRuntime::Basemap* oldBasemap);
  void saveCompleted(QUuid taskId, bool succeeded);
  void saveAsCompleted(QUuid taskId, bool succeeded);
  void doneLoading(Esri::ArcGISRuntime::Error loadError);
  void loadStatusChanged(Esri::ArcGISRuntime::LoadStatus loadStatus);

private:
  void connectSignals();
  Q_DISABLE_COPY(Map)

  std::shared_ptr<QRTImpl::MapImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_Map_H
