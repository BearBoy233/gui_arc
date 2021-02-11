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
/// \file Unit.h

#ifndef QRT_Unit_H
#define QRT_Unit_H

// C++ API headers
#include "ArcGISQt_global.h"
#include "GeometryTypes.h"
#include "Object.h"

// Qt headers
#include <QList>

namespace QRTImpl { class UnitImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class Unit
  {
  public:
    Unit();

    Unit(const Unit& other);
    Unit(Unit&& other) noexcept;

    Unit& operator=(const Unit& other);
    Unit& operator=(Unit&& other) noexcept;

    virtual ~Unit();

    QString name() const;

    QString abbreviation() const;

    QString displayName() const;

    QString pluralDisplayName() const;

    UnitType unitType() const;

    int unitId() const;

    bool isEmpty() const;

    static Unit fromUnitId(int unitId);

  protected:
    /*!
       \internal
     */
    explicit Unit(const std::shared_ptr<QRTImpl::UnitImpl>& impl);
    std::shared_ptr<QRTImpl::UnitImpl> getImpl() const;

  protected:
    std::shared_ptr<QRTImpl::UnitImpl> m_impl;
  };

  /*!
    \brief Type-safe cast helper for unit types.

    Cast Unit-derived class to Unit is always valid.

    \code
    LinearUnit linearUnit(LinearUnitId::Meters);
    Unit unit = unit_cast<Unit>(linearUnit);
    \endcode

    But cast from Unit to Unit-derived class is valid only if unitType
    is the same type as target type.

    \code
    const int linearUnitId = static_cast<int>(LinearUnitId::Meters);
    Unit unit = Unit::fromUnitId(linearUnitId);
    LinearUnit linearUnit = unit_cast<LinearUnit>(unit);
    QASSERT(linearUnit.isValid());

    const int angularUnitId = static_cast<int>(AngularUnitId::Degrees);
    Unit unit = Unit::fromUnitId(angularUnitId);
    LinearUnit invalidLinearUnit = unit_cast<LinearUnit>(unit);
    QASSERT(!invalidLinearUnit.isValid());
    \endcode

    \since Esri::ArcGISRuntime 100.2
  */
  template<typename T>
  T unit_cast(const Unit&)
  {
    return Unit();
  }

  /*! \internal */
  template<>
  inline Unit unit_cast<Unit>(const Unit& unit)
  {
    return unit;
  }

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_Unit_H
