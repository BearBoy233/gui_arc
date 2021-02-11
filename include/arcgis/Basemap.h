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
/// \file Basemap.h

#ifndef QRT_Basemap_H
#define QRT_Basemap_H

// C++ API headers
#include "Item.h"
#include "JsonSerializable.h"
#include "Layer.h"
#include "LayerListModel.h"
#include "Loadable.h"
#include "MapTypes.h"
#include "Object.h"

// Qt headers
#include <QUrl>

namespace QRTImpl { class BasemapImpl; }

namespace Esri {
namespace ArcGISRuntime {

class Basemap : public Object, public Loadable, public JsonSerializable
{
  Q_OBJECT

public:
  explicit Basemap(QObject* parent = nullptr);

  Basemap(Item* item, QObject* parent = nullptr);
    
  explicit Basemap(const QUrl& url, QObject* parent = nullptr);

  explicit Basemap(Layer* baseLayer, QObject* parent = nullptr);

  Basemap(const QList<Layer*>& baseLayers, const QList<Layer*>& referenceLayers, QObject* parent = nullptr);

  ~Basemap();

  LayerListModel* baseLayers() const;

  LayerListModel* referenceLayers() const;

  QUrl url() const;

  QString name() const;

  void setName(const QString& name);

  Item* item() const;

  static Basemap* nationalGeographic(QObject* parent = nullptr);

  static Basemap* oceans(QObject* parent = nullptr);

  static Basemap* openStreetMap(QObject* parent = nullptr);

  static Basemap* imagery(QObject* parent = nullptr);

  static Basemap* imageryWithLabels(QObject* parent = nullptr);

  static Basemap* lightGrayCanvas(QObject* parent = nullptr);

  static Basemap* streets(QObject* parent = nullptr);

  static Basemap* terrainWithLabels(QObject* parent = nullptr);

  static Basemap* topographic(QObject* parent = nullptr);

  static Basemap* imageryWithLabelsVector(QObject* parent = nullptr);

  static Basemap* streetsVector(QObject* parent = nullptr);

  static Basemap* topographicVector(QObject* parent = nullptr);

  static Basemap* terrainWithLabelsVector(QObject* parent = nullptr);

  static Basemap* lightGrayCanvasVector(QObject* parent = nullptr);

  static Basemap* navigationVector(QObject* parent = nullptr);

  static Basemap* streetsNightVector(QObject* parent = nullptr);

  static Basemap* streetsWithReliefVector(QObject* parent = nullptr);

  static Basemap* darkGrayCanvasVector(QObject* parent = nullptr);

  // JsonSerializable Interface methods
  static Basemap* fromJson(const QString& json, QObject* parent = nullptr);
  QString toJson() const override;
  QJsonObject unknownJson() const override;
  QJsonObject unsupportedJson() const override;

  // Loadable Interface methods
  Error loadError() const override;
  LoadStatus loadStatus() const override;
  void cancelLoad() override;
  void load() override;
  void retryLoad() override;

  /*!
     \internal
   */
  Basemap(const std::shared_ptr<QRTImpl::BasemapImpl>& impl, QObject* parent = nullptr);
  std::shared_ptr<QRTImpl::BasemapImpl> getImpl() const;

signals:
  void doneLoading(Esri::ArcGISRuntime::Error loadError);
  void loadStatusChanged(Esri::ArcGISRuntime::LoadStatus loadStatus);

private:
  Q_DISABLE_COPY(Basemap)

  void connectSignals();

  std::shared_ptr<QRTImpl::BasemapImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_Basemap_H
