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
/// \file GeoprocessingResult.h

#ifndef QRT_GeoprocessingResult_H
#define QRT_GeoprocessingResult_H

// C++ API headers
#include "ArcGISMapImageLayer.h"
#include "GeoprocessingParameter.h"
#include "Object.h"

// Qt headers
#include <QMap>

namespace QRTImpl { class GeoprocessingResultImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class GeoprocessingResult : public Object
  {
    Q_OBJECT

  public:
    ~GeoprocessingResult();

    QMap<QString, GeoprocessingParameter*> outputs() const;

    ArcGISMapImageLayer* mapImageLayer() const;

    /*!
       \internal
     */
    GeoprocessingResult(const std::shared_ptr<QRTImpl::GeoprocessingResultImpl>& impl, QObject* parent = nullptr);

    std::shared_ptr<QRTImpl::GeoprocessingResultImpl> getImpl() const;

  private:
    GeoprocessingResult() = delete;
    std::shared_ptr<QRTImpl::GeoprocessingResultImpl> m_impl;
    Q_DISABLE_COPY(GeoprocessingResult)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_GeoprocessingResult_H

