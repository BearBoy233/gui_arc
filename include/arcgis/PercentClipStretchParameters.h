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
/// \file PercentClipStretchParameters.h

#ifndef QRT_PercentClipStretchParameters_H
#define QRT_PercentClipStretchParameters_H

// C++ API headers
#include "StretchParameters.h"

namespace QRTImpl { class PercentClipStretchParametersImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class PercentClipStretchParameters : public StretchParameters
  {
  public:
    PercentClipStretchParameters();
    PercentClipStretchParameters(double min, double max);

    PercentClipStretchParameters(const PercentClipStretchParameters& other);
    PercentClipStretchParameters(PercentClipStretchParameters&& other) noexcept;
    PercentClipStretchParameters(const StretchParameters& other);

    PercentClipStretchParameters& operator=(const PercentClipStretchParameters& other);
    PercentClipStretchParameters& operator=(PercentClipStretchParameters&& other) noexcept;

    ~PercentClipStretchParameters();

    bool isValid() const;

    double min() const;
    void setMin(double min);

    double max() const;
    void setMax(double max);

    /*! \internal */
    explicit PercentClipStretchParameters(const std::shared_ptr<QRTImpl::PercentClipStretchParametersImpl>& impl);
    std::shared_ptr<QRTImpl::PercentClipStretchParametersImpl> getImpl() const;
  };

  /*! \internal */
  template<>
  inline PercentClipStretchParameters stretch_parameters_cast<PercentClipStretchParameters>(const StretchParameters& stretchParameters)
  {
    return stretchParameters.stretchParametersType() == StretchParametersType::PercentClipStretchParameters ?
      static_cast<PercentClipStretchParameters>(stretchParameters) : PercentClipStretchParameters();
  }

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_PercentClipStretchParameters_H
