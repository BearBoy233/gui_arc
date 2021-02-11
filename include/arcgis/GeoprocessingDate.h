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
/// \file GeoprocessingDate.h

#ifndef QRT_GeoprocessingDate_H
#define QRT_GeoprocessingDate_H

// C++ API headers
#include "GeoprocessingParameter.h"

// Qt headers
#include <QDateTime>

namespace QRTImpl { class GeoprocessingDateImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class GeoprocessingDate : public GeoprocessingParameter
  {
    Q_OBJECT

  public:
    explicit GeoprocessingDate(QObject* parent = nullptr);
    explicit GeoprocessingDate(const QDateTime& value, QObject* parent = nullptr);
    ~GeoprocessingDate();

    QDateTime value() const;
    void setValue(const QDateTime& value);

    /*!
       \internal
     */
    GeoprocessingDate(const std::shared_ptr<QRTImpl::GeoprocessingDateImpl>& impl, QObject* parent = nullptr);

  private:
    Q_DISABLE_COPY(GeoprocessingDate)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_GeoprocessingDate_H

