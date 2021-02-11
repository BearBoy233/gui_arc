// COPYRIGHT 1995-2018 ESRI
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
/// \file LocationDistanceMeasurement.h

#ifndef QRT_LocationDistanceMeasurement_H
#define QRT_LocationDistanceMeasurement_H

// C++ API headers
#include "Analysis.h"
#include "CoreTypes.h"
#include "Distance.h"
#include "Point.h"

// Qt headers
#include <QColor>

namespace QRTImpl { class LocationDistanceMeasurementImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class LocationDistanceMeasurement : public Analysis
  {
    Q_OBJECT

  public:
    LocationDistanceMeasurement(const Point& startLocation, const Point& endLocation, QObject* parent = nullptr);
    ~LocationDistanceMeasurement();

    Point startLocation() const;
    void setStartLocation(const Point& startLocation);

    Point endLocation() const;
    void setEndLocation(const Point& endLocation);

    UnitSystem unitSystem() const;
    void setUnitSystem(UnitSystem unitSystem);

    Distance directDistance() const;
    Distance horizontalDistance() const;
    Distance verticalDistance() const;

    /*! \internal */
    explicit LocationDistanceMeasurement(const std::shared_ptr<QRTImpl::LocationDistanceMeasurementImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::LocationDistanceMeasurementImpl> getImpl() const;

  signals:
    void measurementChanged(const Esri::ArcGISRuntime::Distance& directDistance,
                            const Esri::ArcGISRuntime::Distance& horizontalDistance,
                            const Esri::ArcGISRuntime::Distance& verticalDistance);

  private:
    Q_DISABLE_COPY(LocationDistanceMeasurement)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_LocationDistanceMeasurement_H
