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
/// \file FeatureCollection.h

#ifndef QRT_FeatureCollection_H
#define QRT_FeatureCollection_H

// C++ API headers
#include "FeatureCollectionTable.h"
#include "FeatureCollectionTableListModel.h"
#include "Item.h"
#include "JsonSerializable.h"
#include "Loadable.h"
#include "Object.h"
#include "Portal.h"
#include "PortalFolder.h"

namespace QRTImpl { class FeatureCollectionImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class FeatureCollection : public Object, public Loadable, public JsonSerializable
  {
    Q_OBJECT

  public:
    explicit FeatureCollection(QObject* parent = nullptr);
    FeatureCollection(Item* item, QObject* parent = nullptr);
    FeatureCollection(const QList<FeatureCollectionTable*>& featureCollectionTables, QObject* parent = nullptr);

    ~FeatureCollection();

    Item* item() const;

    FeatureCollectionTableListModel* tables() const;

    QUuid save();
    QUuid saveAs(Portal* portal,
                 const QString& title,
                 const QStringList& tags,
                 const PortalFolder& folder = PortalFolder(),
                 const QString& description = QString(),
                 const QByteArray& thumbnailBytes = QByteArray());

    // Loadable Interface methods
    Error loadError() const override;
    LoadStatus loadStatus() const override;
    void cancelLoad() override;
    void load() override;
    void retryLoad() override;

    static FeatureCollection* fromJson(const QString& json, QObject* parent = nullptr);
    QString toJson() const override;
    QJsonObject unknownJson() const override;
    QJsonObject unsupportedJson() const override;

    FeatureCollection(const std::shared_ptr<QRTImpl::FeatureCollectionImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::FeatureCollectionImpl> getImpl() const;

  signals:
    void doneLoading(Esri::ArcGISRuntime::Error loadError);
    void loadStatusChanged(Esri::ArcGISRuntime::LoadStatus loadStatus);
    void saveCompleted(QUuid taskId, bool succeeded);
    void saveAsCompleted(QUuid taskId, bool succeeded);

  private:
    std::shared_ptr<QRTImpl::FeatureCollectionImpl> m_impl;

    void connectSignals();

    Q_DISABLE_COPY(FeatureCollection)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_FeatureCollection_H
