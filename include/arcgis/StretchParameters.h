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
/// \file StretchParameters.h

#ifndef QRT_StretchParameters_H
#define QRT_StretchParameters_H

// C++ API headers
#include "RasterTypes.h"

// STL headers
#include <memory>

namespace QRTImpl { class StretchParametersImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class StretchParameters
  {
  public:
    StretchParameters();

    StretchParameters(const StretchParameters& other);
    StretchParameters(StretchParameters&& other) noexcept;

    StretchParameters& operator=(const StretchParameters& other);
    StretchParameters& operator=(StretchParameters&& other) noexcept;

    virtual ~StretchParameters();

    StretchParametersType stretchParametersType() const;

    bool isEmpty() const;

    /*!
       \internal
     */
    explicit StretchParameters(const std::shared_ptr<QRTImpl::StretchParametersImpl>& impl);
    std::shared_ptr<QRTImpl::StretchParametersImpl> getImpl() const;

  protected:
    std::shared_ptr<QRTImpl::StretchParametersImpl> m_impl;
  };

  /*!
    \brief Type-safe cast helper for stretch parameters types.

    Cast StretchParameters-derived class to \l StretchParameters is always valid.

    \code
    MinMaxStretchParameters minMaxStretchParameters(minValues, maxValues);
    StretchParameters stretchParameters = stretch_parameters_cast<StretchParameters>(minMaxStretchParameters);
    \endcode

    But cast from StretchParameters to StretchParameters-derived class is valid only if stretchParametersType
    is the same type as target type.

    \code
    StretchParameters stretchParameters = stretchRenderer->stretchParameters();
    MinMaxStretchParameters minMaxStretchParameters = stretch_parameters_cast<MinMaxStretchParameters>(stretchParameters);
    QASSERT(mapServiceLayerIdInfo.isValid());

    StretchParameters invalidStretchParameters = invalidStretchRenderer->stretchParameters();
    MinMaxStretchParameters invalidMinMaxStretchParameters = stretch_parameters_cast<MinMaxStretchParameters>(invalidStretchParameters);
    QASSERT(!invalidMinMaxStretchParameters.isValid());
    \endcode

    \since Esri::ArcGISRuntime 100.2
  */
  template<typename T>
  T stretch_parameters_cast(const StretchParameters&)
  {
    return StretchParameters();
  }

  /*! \internal */
  template<>
  inline StretchParameters stretch_parameters_cast<StretchParameters>(const StretchParameters& stretchParameters)
  {
    return stretchParameters;
  }

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_StretchParameters_H
