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
/// \file GeoprocessingMultiValue.h

#ifndef QRT_GeoprocessingMultiValue_H
#define QRT_GeoprocessingMultiValue_H

// C++ API headers
#include "GeoprocessingParameter.h"

namespace QRTImpl { class GeoprocessingMultiValueImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class GeoprocessingMultiValue : public GeoprocessingParameter
  {
    Q_OBJECT

  public:
    explicit GeoprocessingMultiValue(QObject* parent = nullptr);
    explicit GeoprocessingMultiValue(GeoprocessingParameterType valueParameterType,
                                     QObject* parent = nullptr);
    GeoprocessingMultiValue(GeoprocessingParameterType valueParameterType,
                            const QList<GeoprocessingParameter*>& values,
                            QObject* parent = nullptr);
    ~GeoprocessingMultiValue();

    GeoprocessingParameterType valueParameterType() const;
    void setValueParameterType(GeoprocessingParameterType valueParameterType);

    QList<GeoprocessingParameter*> values() const;
    void setValues(const QList<GeoprocessingParameter*>& values);

    /*!
       \internal
     */
    GeoprocessingMultiValue(const std::shared_ptr<QRTImpl::GeoprocessingMultiValueImpl>& impl, QObject* parent = nullptr);

  private:
    Q_DISABLE_COPY(GeoprocessingMultiValue)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_GeoprocessingMultiValue_H

