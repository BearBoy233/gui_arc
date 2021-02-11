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
/// \file Scene.h

#ifndef QRT_Scene_H
#define QRT_Scene_H

// C++ API headers
#include "Basemap.h"
#include "BookmarkListModel.h"
#include "FeatureTableListModel.h"
#include "Item.h"
#include "LoadSettings.h"
#include "Loadable.h"
#include "Object.h"
#include "SceneViewTypes.h"
#include "Surface.h"
#include "Viewpoint.h"

namespace QRTImpl { class SceneImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class Scene : public Object, public Loadable
  {
    Q_OBJECT

  public:
    explicit Scene(QObject* parent = nullptr);
    explicit Scene(Surface* baseSurface, QObject* parent = nullptr);
    explicit Scene(Basemap* basemap, QObject* parent = nullptr);
    explicit Scene(BasemapType basemapType, QObject* parent = nullptr);
    explicit Scene(SceneViewTilingScheme sceneViewTilingScheme, QObject* parent = nullptr);
    explicit Scene(const QUrl& url, QObject* parent = nullptr);
    explicit Scene(Item* item, QObject* parent = nullptr);
    ~Scene();

    Item* item() const;

    QString version() const;

    Viewpoint initialViewpoint() const;
    void setInitialViewpoint(const Viewpoint& viewpoint);

    SpatialReference spatialReference() const;
    LayerListModel* operationalLayers() const;

    Surface* baseSurface() const;
    void setBaseSurface(Surface* surface);

    Basemap* basemap() const;
    void setBasemap(Basemap* basemap);

    BookmarkListModel* bookmarks() const;

    LoadSettings* loadSettings() const;
    void setLoadSettings(LoadSettings* settings);

    bool isAutoFetchLegendInfos() const;
    void setAutoFetchLegendInfos(bool autoFetchLegendInfos);

    LegendInfoListModel* legendInfos() const;

    SceneViewTilingScheme sceneViewTilingScheme() const;
    void setSceneViewTilingScheme(SceneViewTilingScheme sceneViewTilingScheme);

    FeatureTableListModel* tables() const;

    // Loadable Interface methods
    Error loadError() const override;
    LoadStatus loadStatus() const override;
    void cancelLoad() override;
    void load() override;
    void retryLoad() override;

    static Scene* fromJson(const QString& json, QObject* parent = nullptr);
    QJsonObject unknownJson() const;
    QJsonObject unsupportedJson() const;

    /*!
       \internal
     */
    Scene(const std::shared_ptr<QRTImpl::SceneImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::SceneImpl> getImpl() const;

  signals:
    void basemapChanged(Esri::ArcGISRuntime::Basemap* oldBasemap);
    void doneLoading(Esri::ArcGISRuntime::Error loadError);
    void loadStatusChanged(Esri::ArcGISRuntime::LoadStatus loadStatus);

  private:
    Q_DISABLE_COPY(Scene)

    void connectSignals();

    std::shared_ptr<QRTImpl::SceneImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_Scene_H
