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
/// \file GeoprocessingParameters.h

#ifndef QRT_GeoprocessingParameters_H
#define QRT_GeoprocessingParameters_H

// C++ API headers
#include "ArcGISQt_global.h"
#include "GeoprocessingParameter.h"
#include "GeoprocessingTypes.h"
#include "SpatialReference.h"

// Qt headers
#include <QMap>

namespace QRTImpl { class GeoprocessingParametersImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class GeoprocessingParameters
  {
  public:
    GeoprocessingParameters();
    explicit GeoprocessingParameters(GeoprocessingExecutionType type);
    GeoprocessingParameters(const GeoprocessingParameters& other);
    GeoprocessingParameters(GeoprocessingParameters&& other) noexcept;

    ~GeoprocessingParameters();

    GeoprocessingParameters& operator=(const GeoprocessingParameters& other);
    GeoprocessingParameters& operator=(GeoprocessingParameters&& other) noexcept;

    GeoprocessingExecutionType executionType() const;
    void setExecutionType(GeoprocessingExecutionType type);

    QMap<QString, GeoprocessingParameter*> inputs(QObject* parent = nullptr) const;
    void setInputs(const QMap<QString, GeoprocessingParameter*>& inputs);

    SpatialReference outputSpatialReference() const;
    void setOutputSpatialReference(const SpatialReference& spatialReference);

    SpatialReference processSpatialReference() const;
    void setProcessSpatialReference(const SpatialReference& spatialReference);

    bool isReturnM() const;
    void setReturnM(bool returnM);

    bool isReturnZ() const;
    void setReturnZ(bool returnZ);

    /*! \internal */
    GeoprocessingParameters(const std::shared_ptr<QRTImpl::GeoprocessingParametersImpl>& impl);
    /*! \internal */
    std::shared_ptr<QRTImpl::GeoprocessingParametersImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::GeoprocessingParametersImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_GeoprocessingParameters_H
