// COPYRIGHT 1995-2017 ESRI
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
/// \file GeographicTransformation.h

#ifndef QRT_GeographicTransformation_H
#define QRT_GeographicTransformation_H

// C++ API headers
#include "DatumTransformation.h"

namespace QRTImpl { class GeographicTransformationImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class GeographicTransformationStep;

  class GeographicTransformation : public DatumTransformation
  {
    Q_OBJECT

  public:
    explicit GeographicTransformation(const GeographicTransformationStep& step, QObject* parent = nullptr);
    explicit GeographicTransformation(const QList<GeographicTransformationStep>& steps, QObject* parent = nullptr);
    ~GeographicTransformation();

    QList<GeographicTransformationStep> steps() const;

    /*! \internal */
    explicit GeographicTransformation(const std::shared_ptr<QRTImpl::GeographicTransformationImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::GeographicTransformationImpl> getImpl() const;

  protected:
    Q_DISABLE_COPY(GeographicTransformation)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_GeographicTransformation_H
