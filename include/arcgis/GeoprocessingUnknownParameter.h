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
/// \file GeoprocessingUnknownParameter.h

#ifndef QRT_GeoprocessingUnknownParameter_H
#define QRT_GeoprocessingUnknownParameter_H

// C++ API headers
#include "GeoprocessingParameter.h"

namespace QRTImpl { class GeoprocessingUnknownParameterImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class GeoprocessingUnknownParameter : public GeoprocessingParameter
  {
    Q_OBJECT

  public:
    ~GeoprocessingUnknownParameter();

    /*! \internal */
    GeoprocessingUnknownParameter(const std::shared_ptr<QRTImpl::GeoprocessingUnknownParameterImpl>& impl, QObject* parent = nullptr);

  private:
    Q_DISABLE_COPY(GeoprocessingUnknownParameter)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_GeoprocessingUnknownParameter_H

