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
/// \file GeoprocessingString.h

#ifndef QRT_GeoprocessingString_H
#define QRT_GeoprocessingString_H

// C++ API headers
#include "GeoprocessingParameter.h"

// Qt headers
#include <QString>

namespace QRTImpl { class GeoprocessingStringImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class GeoprocessingString : public GeoprocessingParameter
  {
    Q_OBJECT

  public:
    explicit GeoprocessingString(QObject* parent = nullptr);
    explicit GeoprocessingString(const QString& value, QObject* parent = nullptr);
    ~GeoprocessingString();

    QString value() const;
    void setValue(const QString& value);

    /*!
       \internal
     */
    GeoprocessingString(const std::shared_ptr<QRTImpl::GeoprocessingStringImpl>& impl, QObject* parent = nullptr);

  private:
    Q_DISABLE_COPY(GeoprocessingString)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_GeoprocessingString_H

