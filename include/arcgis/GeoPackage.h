// COPYRIGHT 1995-2017 ESRI
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
/// \file GeoPackage.h

#ifndef QRT_GeoPackage_H
#define QRT_GeoPackage_H

// C++ API headers
#include "Loadable.h"
#include "Object.h"

namespace QRTImpl { class GeoPackageImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class GeoPackageRaster;
  class GeoPackageFeatureTable;

  class GeoPackage : public Object, public Loadable
  {
    Q_OBJECT

  public:
    explicit GeoPackage(const QString& path, QObject* parent = nullptr);
    ~GeoPackage();

    QString path() const;

    void close();

    QList<GeoPackageRaster*> geoPackageRasters() const;

    QList<GeoPackageFeatureTable*> geoPackageFeatureTables() const;

    // Loadable Interface methods
    Error loadError() const override;
    LoadStatus loadStatus() const override;
    void cancelLoad() override;
    void load() override;
    void retryLoad() override;

    /*!
       \internal
     */
    explicit GeoPackage(const std::shared_ptr<QRTImpl::GeoPackageImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::GeoPackageImpl> getImpl() const;

  signals:
    void doneLoading(Esri::ArcGISRuntime::Error loadError);
    void loadStatusChanged(Esri::ArcGISRuntime::LoadStatus loadStatus);

  private:
    GeoPackage() = delete;
    Q_DISABLE_COPY(GeoPackage)

    void connectSignals();

    std::shared_ptr<QRTImpl::GeoPackageImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_GeoPackage_H
