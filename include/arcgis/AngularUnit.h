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
/// \file AngularUnit.h

#ifndef QRT_AngularUnit_H
#define QRT_AngularUnit_H

// C++ API headers
#include "Unit.h"

namespace QRTImpl { class AngularUnitImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class AngularUnit : public Unit
  {
  public:
    AngularUnit();

    AngularUnit(AngularUnitId angularUnitId);

    AngularUnit(const AngularUnit& other);
    AngularUnit(AngularUnit&& other) noexcept;
    AngularUnit(const Unit& other);

    AngularUnit& operator=(const AngularUnit& other);
    AngularUnit& operator=(AngularUnit&& other) noexcept;

    ~AngularUnit();

    bool isValid() const;

    AngularUnitId angularUnitId() const;

    double convertFrom(const AngularUnit& fromUnit, double angle) const;
    double convertTo(const AngularUnit& toUnit, double angle) const;

    double convertFromRadians(double radians) const;
    double convertToRadians(double thisUnitValue) const;

    static AngularUnit degrees();
    static AngularUnit radians();

    /*! \internal */
    explicit AngularUnit(const std::shared_ptr<QRTImpl::AngularUnitImpl>& impl);
    std::shared_ptr<QRTImpl::AngularUnitImpl> getImpl() const;
  };

  /*! \internal */
  template<>
  inline AngularUnit unit_cast<AngularUnit>(const Unit& unit)
  {
    return unit.unitType() == UnitType::AngularUnit ? static_cast<AngularUnit>(unit) : AngularUnit();
  }

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_AngularUnit_H
