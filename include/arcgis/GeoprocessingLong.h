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
/// \file GeoprocessingLong.h

#ifndef QRT_GeoprocessingLong_H
#define QRT_GeoprocessingLong_H

// C++ API headers
#include "GeoprocessingParameter.h"

namespace QRTImpl { class GeoprocessingLongImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class GeoprocessingLong : public GeoprocessingParameter
  {
    Q_OBJECT

  public:
    explicit GeoprocessingLong(QObject* parent = nullptr);
    explicit GeoprocessingLong(int value, QObject* parent = nullptr);
    ~GeoprocessingLong();

    int value() const;
    void setValue(int value);

    /*!
       \internal
     */
    GeoprocessingLong(const std::shared_ptr<QRTImpl::GeoprocessingLongImpl>& impl, QObject* parent = nullptr);

  private:
    Q_DISABLE_COPY(GeoprocessingLong)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_GeoprocessingLong_H

