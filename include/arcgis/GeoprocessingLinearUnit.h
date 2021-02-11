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
/// \file GeoprocessingLinearUnit.h

#ifndef QRT_GeoprocessingLinearUnit_H
#define QRT_GeoprocessingLinearUnit_H

// C++ API headers
#include "GeoprocessingParameter.h"
#include "GeoprocessingTypes.h"
#include "LinearUnit.h"

namespace QRTImpl { class GeoprocessingLinearUnitImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class GeoprocessingLinearUnit : public GeoprocessingParameter
  {
    Q_OBJECT

  public:
    explicit GeoprocessingLinearUnit(QObject* parent = nullptr);
    explicit GeoprocessingLinearUnit(double distance, QObject* parent = nullptr);
    GeoprocessingLinearUnit(double distance, GeoprocessingLinearUnits geoprocessingUnit, QObject* parent = nullptr);
    GeoprocessingLinearUnit(double distance, const LinearUnit& unit, QObject* parent = nullptr);
    GeoprocessingLinearUnit(double distance, LinearUnitId unitId, QObject* parent = nullptr);
    ~GeoprocessingLinearUnit();

    double distance() const;
    void setDistance(double distance);

    GeoprocessingLinearUnits unit() const;
    void setUnit(GeoprocessingLinearUnits unit);

    LinearUnit linearUnit() const;

    /*!
       \internal
     */
    GeoprocessingLinearUnit(const std::shared_ptr<QRTImpl::GeoprocessingLinearUnitImpl>& impl, QObject* parent = nullptr);

  private:
    Q_DISABLE_COPY(GeoprocessingLinearUnit)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_GeoprocessingLinearUnit_H

