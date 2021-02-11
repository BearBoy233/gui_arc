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
/// \file Raster.h

#ifndef QRT_Raster_H
#define QRT_Raster_H

// C++ API headers
#include "Loadable.h"
#include "Object.h"
#include "RasterFunction.h"
#include "RasterTypes.h"

namespace QRTImpl { class RasterImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class Raster : public Object, public Loadable
  {
    Q_OBJECT

  public:

    Raster(const QString& path, QObject* parent = nullptr);
    Raster(RasterFunction* rasterFunction, QObject* parent = nullptr);
    ~Raster();

    QString path() const;
    RasterFunction* rasterFunction() const;

    // Loadable Interface methods
    Error loadError() const override;
    LoadStatus loadStatus() const override;
    void cancelLoad() override;
    void load() override;
    void retryLoad() override;

    RasterType rasterType() const;

    Raster(const std::shared_ptr<QRTImpl::RasterImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::RasterImpl> getImpl() const;

  signals:
    void doneLoading(Esri::ArcGISRuntime::Error loadError);
    void loadStatusChanged(Esri::ArcGISRuntime::LoadStatus loadStatus);

  protected:
    std::shared_ptr<QRTImpl::RasterImpl> m_impl;

  private:
    void connectSignals();
    Q_DISABLE_COPY(Raster)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_Raster_H
