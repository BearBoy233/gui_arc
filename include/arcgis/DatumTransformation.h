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
/// \file DatumTransformation.h

#ifndef QRT_DatumTransformation_H
#define QRT_DatumTransformation_H

// C++ API headers
#include "GeometryTypes.h"
#include "Object.h"

namespace QRTImpl { class DatumTransformationImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class SpatialReference;

  class DatumTransformation : public Object
  {
    Q_OBJECT

  public:
    ~DatumTransformation();

    bool operator==(const DatumTransformation* other) const;
    bool operator!=(const DatumTransformation* other) const;

    QString name() const;

    SpatialReference inputSpatialReference() const;
    SpatialReference outputSpatialReference() const;

    DatumTransformation* inverse() const;

    bool isMissingProjectionEngineFiles() const;

    DatumTransformationType datumTransformationType() const;

    /*! \internal */
    explicit DatumTransformation(const std::shared_ptr<QRTImpl::DatumTransformationImpl>& impl, QObject* parent = nullptr);

    std::shared_ptr<QRTImpl::DatumTransformationImpl> getImpl() const;

  protected:
    std::shared_ptr<QRTImpl::DatumTransformationImpl> m_impl;

  private:
    Q_DISABLE_COPY(DatumTransformation)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_DatumTransformation_H
