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
/// \file StandardDeviationStretchParameters.h

#ifndef QRT_StandardDeviationStretchParameters_H
#define QRT_StandardDeviationStretchParameters_H

// C++ API headers
#include "StretchParameters.h"

namespace QRTImpl { class StandardDeviationStretchParametersImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class StandardDeviationStretchParameters : public StretchParameters
  {
  public:
    StandardDeviationStretchParameters();
    StandardDeviationStretchParameters(double factor);

    StandardDeviationStretchParameters(const StandardDeviationStretchParameters& other);
    StandardDeviationStretchParameters(StandardDeviationStretchParameters&& other) noexcept;
    StandardDeviationStretchParameters(const StretchParameters& other);

    StandardDeviationStretchParameters& operator=(const StandardDeviationStretchParameters& other);
    StandardDeviationStretchParameters& operator=(StandardDeviationStretchParameters&& other) noexcept;

    ~StandardDeviationStretchParameters();

    bool isValid() const;

    double factor() const;
    void setFactor(double factor);

    /*! \internal */
    explicit StandardDeviationStretchParameters(const std::shared_ptr<QRTImpl::StandardDeviationStretchParametersImpl>& impl);
    std::shared_ptr<QRTImpl::StandardDeviationStretchParametersImpl> getImpl() const;
  };

  /*! \internal */
  template<>
  inline StandardDeviationStretchParameters stretch_parameters_cast<StandardDeviationStretchParameters>(const StretchParameters& stretchParameters)
  {
    return stretchParameters.stretchParametersType() == StretchParametersType::StandardDeviationStretchParameters ?
      static_cast<StandardDeviationStretchParameters>(stretchParameters) : StandardDeviationStretchParameters();
  }

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_StandardDeviationStretchParameters_H
