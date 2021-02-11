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
/// \file GeoPackageFeatureTable.h

#ifndef QRT_GeoPackageFeatureTable_H
#define QRT_GeoPackageFeatureTable_H

// C++ API headers
#include "FeatureTable.h"

namespace QRTImpl { class GeoPackageFeatureTableImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class GeoPackage;

  class GeoPackageFeatureTable : public FeatureTable
  {
    Q_OBJECT

  public:
    ~GeoPackageFeatureTable();

    QString description() const;

    GeoPackage* geoPackage() const;

    /*! \internal */
    GeoPackageFeatureTable(const std::shared_ptr<QRTImpl::GeoPackageFeatureTableImpl>& impl, QObject* parent = nullptr);

  private:
    GeoPackageFeatureTable() = delete;
    Q_DISABLE_COPY(GeoPackageFeatureTable)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_GeoPackageFeatureTable_H
