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
/// \file MinMaxStretchParameters.h

#ifndef QRT_MinMaxStretchParameters_H
#define QRT_MinMaxStretchParameters_H

// C++ API headers
#include "StretchParameters.h"

// Qt headers
#include <QList>

namespace QRTImpl { class MinMaxStretchParametersImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class MinMaxStretchParameters : public StretchParameters
  {
  public:
    MinMaxStretchParameters();

    MinMaxStretchParameters(const QList<double>& minValues, const QList<double>& maxValues);

    MinMaxStretchParameters(const MinMaxStretchParameters& other);
    MinMaxStretchParameters(MinMaxStretchParameters&& other) noexcept;
    MinMaxStretchParameters(const StretchParameters& other);

    MinMaxStretchParameters& operator=(const MinMaxStretchParameters& other);
    MinMaxStretchParameters& operator=(MinMaxStretchParameters&& other) noexcept;

    ~MinMaxStretchParameters();

    bool isValid() const;

    QList<double> minValues() const;
    void setMinValues(const QList<double>& minValues);

    QList<double> maxValues() const;
    void setMaxValues(const QList<double>& maxValues);

    /*! \internal */
    explicit MinMaxStretchParameters(const std::shared_ptr<QRTImpl::MinMaxStretchParametersImpl>& impl);
    std::shared_ptr<QRTImpl::MinMaxStretchParametersImpl> getImpl() const;
  };

  /*! \internal */
  template<>
  inline MinMaxStretchParameters stretch_parameters_cast<MinMaxStretchParameters>(const StretchParameters& stretchParameters)
  {
    return stretchParameters.stretchParametersType() == StretchParametersType::MinMaxStretchParameters ?
      static_cast<MinMaxStretchParameters>(stretchParameters) : MinMaxStretchParameters();
  }

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_MinMaxStretchParameters_H
