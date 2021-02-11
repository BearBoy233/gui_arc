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
/// \file RasterFunction.h

#ifndef QRT_RasterFunction_H
#define QRT_RasterFunction_H

// C++ API headers
#include "Object.h"
#include "RasterFunctionArguments.h"

namespace QRTImpl { class RasterFunctionImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class RasterFunction : public Object
  {
    Q_OBJECT

  public:

    RasterFunction(const QString& path, QObject* parent = nullptr);
    ~RasterFunction();

    RasterFunctionArguments* arguments() const;

    static RasterFunction* fromJson(const QString& json, QObject* parent = nullptr);

    RasterFunction(const std::shared_ptr<QRTImpl::RasterFunctionImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::RasterFunctionImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::RasterFunctionImpl> m_impl;

    Q_DISABLE_COPY(RasterFunction)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_RasterFunction_H
