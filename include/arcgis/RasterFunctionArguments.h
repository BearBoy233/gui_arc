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
/// \file RasterFunctionArguments.h

#ifndef QRT_RasterFunctionArguments_H
#define QRT_RasterFunctionArguments_H

// C++ API headers
#include "Object.h"

namespace QRTImpl { class RasterFunctionArgumentsImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class Raster;
  class RasterFunctionArguments : public Object
  {
    Q_OBJECT

  public:
    ~RasterFunctionArguments();

    QStringList argumentNames() const;
    QStringList rasterNames() const;

    void setArgument(const QString& name, const QString& value);
    void setRaster(const QString& rasterName, Raster* raster);

    RasterFunctionArguments(const std::shared_ptr<QRTImpl::RasterFunctionArgumentsImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::RasterFunctionArgumentsImpl> getImpl() const;

  private:
    RasterFunctionArguments() = delete;
    std::shared_ptr<QRTImpl::RasterFunctionArgumentsImpl> m_impl;

    Q_DISABLE_COPY(RasterFunctionArguments)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_RasterFunctionArguments_H
