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
/// \file AreaUnit.h

#ifndef QRT_AreaUnit_H
#define QRT_AreaUnit_H

// C++ API headers
#include "Unit.h"

namespace QRTImpl { class AreaUnitImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class AreaUnit : public Unit
  {
  public:
    AreaUnit();
    AreaUnit(AreaUnitId areaUnitId);

    AreaUnit(const AreaUnit& other);
    AreaUnit(AreaUnit&& other) noexcept;
    AreaUnit(const Unit& other);

    AreaUnit& operator=(const AreaUnit& other);
    AreaUnit& operator=(AreaUnit&& other) noexcept;

    ~AreaUnit();

    bool isValid() const;

    AreaUnitId areaUnitId() const;

    double convertFrom(const AreaUnit& fromUnit, double area) const;
    double convertTo(const AreaUnit& toUnit, double area) const;

    double convertFromSquareMeters(double squareMeters) const;
    double convertToSquareMeters(double thisUnitValue) const;

    static AreaUnit squareMeters();
    static AreaUnit squareFeet();
    static AreaUnit squareMiles();
    static AreaUnit squareKilometers();

    /*! \internal */
    explicit AreaUnit(const std::shared_ptr<QRTImpl::AreaUnitImpl>& impl);
    std::shared_ptr<QRTImpl::AreaUnitImpl> getImpl() const;
  };

  /*! \internal */
  template<>
  inline AreaUnit unit_cast<AreaUnit>(const Unit& unit)
  {
    return unit.unitType() == UnitType::AreaUnit ? static_cast<AreaUnit>(unit) : AreaUnit();
  }

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_AreaUnit_H
