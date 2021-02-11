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
/// \file BaseStretchRenderer.h

#ifndef QRT_BaseStretchRenderer_H
#define QRT_BaseStretchRenderer_H

// C++ API headers
#include "RasterRenderer.h"
#include "StretchParameters.h"

namespace QRTImpl { class BaseStretchRendererImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class BaseStretchRenderer : public RasterRenderer
  {
    Q_OBJECT

  public:
    ~BaseStretchRenderer();

    BaseStretchRenderer(const std::shared_ptr<QRTImpl::BaseStretchRendererImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::BaseStretchRendererImpl> getImpl() const;

    StretchParameters stretchParameters() const;
    bool isEstimateStatistics() const;
    QList<double> gammas() const;

  private:
    Q_DISABLE_COPY(BaseStretchRenderer)
    BaseStretchRenderer() = delete;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_BaseStretchRenderer_H
