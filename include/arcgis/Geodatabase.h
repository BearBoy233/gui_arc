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
/// \file Geodatabase.h

#ifndef QRT_Geodatabase_H
#define QRT_Geodatabase_H

// C++ API headers
#include "Loadable.h"
#include "Object.h"
#include "TaskTypes.h"

namespace QRTImpl { class GeodatabaseImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class GeodatabaseFeatureTable;
  class Envelope;

  class Geodatabase : public Object, public Loadable
  {
    Q_OBJECT

  public:
    explicit Geodatabase(const QString& path, QObject* parent = nullptr);
    ~Geodatabase();

    QString path() const;
    QList<GeodatabaseFeatureTable*> geodatabaseFeatureTables() const;
    QUrl serviceUrl() const;
    QUuid syncId() const;
    SyncModel syncModel() const;
    GeodatabaseFeatureTable* geodatabaseFeatureTable(const QString& tableName) const;
    GeodatabaseFeatureTable* geodatabaseFeatureTable(qint64 serviceLayerId) const;
    bool hasLocalEdits() const;
    bool isSyncEnabled() const;
    Envelope generateGeodatabaseExtent() const;
    bool isInTransaction() const;
    void close();
    void beginTransaction();
    void commitTransaction();
    void rollbackTransaction();

    // Loadable Interface methods
    Error loadError() const override;
    LoadStatus loadStatus() const override;
    void cancelLoad() override;
    void load() override;
    void retryLoad() override;

    /*!
       \internal
     */
    Geodatabase(const std::shared_ptr<QRTImpl::GeodatabaseImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::GeodatabaseImpl> getImpl() const;

  signals:
    void transactionStatusChanged(bool isInTransaction);
    void doneLoading(Esri::ArcGISRuntime::Error loadError);
    void loadStatusChanged(Esri::ArcGISRuntime::LoadStatus loadStatus);

  private:
    Q_DISABLE_COPY(Geodatabase)

    Geodatabase() = delete;

    void connectSignals();

    std::shared_ptr<QRTImpl::GeodatabaseImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_Geodatabase_H
