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
/// \file GeoprocessingParameter.h

#ifndef QRT_GeoprocessingParameter_H
#define QRT_GeoprocessingParameter_H

// C++ API headers
#include "GeoprocessingTypes.h"
#include "Object.h"

namespace QRTImpl { class GeoprocessingParameterImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class GeoprocessingParameter : public Object
  {
    Q_OBJECT

  public:
    ~GeoprocessingParameter();

    GeoprocessingParameterType parameterType() const;

    /*!
       \internal
     */
    GeoprocessingParameter(const std::shared_ptr<QRTImpl::GeoprocessingParameterImpl>& impl, QObject* parent = nullptr);

    std::shared_ptr<QRTImpl::GeoprocessingParameterImpl> getImpl() const;

  protected:
    std::shared_ptr<QRTImpl::GeoprocessingParameterImpl> m_impl;

  private:
    Q_DISABLE_COPY(GeoprocessingParameter)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_GeoprocessingParameter_H

