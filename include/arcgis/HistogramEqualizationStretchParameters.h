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
/// \file HistogramEqualizationStretchParameters.h

#ifndef QRT_HistogramEqualizationStretchParameters_H
#define QRT_HistogramEqualizationStretchParameters_H

// C++ API headers
#include "RasterTypes.h"
#include "StretchParameters.h"

namespace QRTImpl { class HistogramEqualizationStretchParametersImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class HistogramEqualizationStretchParameters : public StretchParameters
  {
  public:
    HistogramEqualizationStretchParameters();

    HistogramEqualizationStretchParameters(const HistogramEqualizationStretchParameters& other);
    HistogramEqualizationStretchParameters(HistogramEqualizationStretchParameters&& other) noexcept;
    HistogramEqualizationStretchParameters(const StretchParameters& other);

    HistogramEqualizationStretchParameters& operator=(const HistogramEqualizationStretchParameters& other);
    HistogramEqualizationStretchParameters& operator=(HistogramEqualizationStretchParameters&& other) noexcept;

    ~HistogramEqualizationStretchParameters();

    bool isValid() const;

    /*! \internal */
    HistogramEqualizationStretchParameters(const std::shared_ptr<QRTImpl::HistogramEqualizationStretchParametersImpl>& impl);
    std::shared_ptr<QRTImpl::HistogramEqualizationStretchParametersImpl> getImpl() const;
  };

  /*! \internal */
  template<>
  inline HistogramEqualizationStretchParameters stretch_parameters_cast<HistogramEqualizationStretchParameters>(const StretchParameters& stretchParameters)
  {
    return stretchParameters.stretchParametersType() == StretchParametersType::HistogramEqualizationStretchParameters ?
      static_cast<HistogramEqualizationStretchParameters>(stretchParameters) : HistogramEqualizationStretchParameters();
  }

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_HistogramEqualizationStretchParameters_H
