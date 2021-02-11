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
/// \file LinearUnit.h

#ifndef QRT_LinearUnit_H
#define QRT_LinearUnit_H

// C++ API headers
#include "Unit.h"

namespace QRTImpl { class LinearUnitImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class AreaUnit;

  class LinearUnit : public Unit
  {
  public:
    LinearUnit();
    LinearUnit(const AreaUnit& areaUnit);
    LinearUnit(LinearUnitId linearUnitId);

    LinearUnit(const LinearUnit& other);
    LinearUnit(LinearUnit&& other) noexcept;
    LinearUnit(const Unit& other);

    LinearUnit& operator=(const LinearUnit& other);
    LinearUnit& operator=(LinearUnit&& other) noexcept;

    ~LinearUnit();

    bool isValid() const;

    LinearUnitId linearUnitId() const;

    double convertFrom(const LinearUnit& fromUnit, double value) const;

    double convertTo(const LinearUnit& toUnit, double value) const;

    double convertFromMeters(double meters) const;

    double convertToMeters(double thisUnitValue) const;

    static LinearUnit meters();

    static LinearUnit feet();

    static LinearUnit miles();

    static LinearUnit kilometers();

    /*! \internal */
    explicit LinearUnit(const std::shared_ptr<QRTImpl::LinearUnitImpl>& impl);
    std::shared_ptr<QRTImpl::LinearUnitImpl> getImpl() const;
  };

  /*! \internal */
  template<>
  inline LinearUnit unit_cast<LinearUnit>(const Unit& unit)
  {
    return unit.unitType() == UnitType::LinearUnit ? static_cast<LinearUnit>(unit) : LinearUnit();
  }

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_LinearUnit_H
