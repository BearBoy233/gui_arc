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
/// \file GeoprocessingDouble.h

#ifndef QRT_GeoprocessingDouble_H
#define QRT_GeoprocessingDouble_H

// C++ API headers
#include "GeoprocessingParameter.h"

namespace QRTImpl { class GeoprocessingDoubleImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class GeoprocessingDouble : public GeoprocessingParameter
  {
    Q_OBJECT

  public:
    explicit GeoprocessingDouble(QObject* parent = nullptr);
    explicit GeoprocessingDouble(double value, QObject* parent = nullptr);
    ~GeoprocessingDouble();

    double value() const;
    void setValue(double value);

    /*!
       \internal
     */
    GeoprocessingDouble(const std::shared_ptr<QRTImpl::GeoprocessingDoubleImpl>& impl, QObject* parent = nullptr);

  private:
    Q_DISABLE_COPY(GeoprocessingDouble)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_GeoprocessingDouble_H

