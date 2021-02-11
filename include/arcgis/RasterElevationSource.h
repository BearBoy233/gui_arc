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
/// \file RasterElevationSource.h

#ifndef QRT_RasterElevationSource_H
#define QRT_RasterElevationSource_H

// C++ API headers
#include "ElevationSource.h"
#include "Envelope.h"

namespace QRTImpl { class RasterElevationSourceImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class RasterElevationSource : public ElevationSource
  {
    Q_OBJECT

  public:
    explicit RasterElevationSource(const QStringList& filePaths, QObject* parent = nullptr);
    ~RasterElevationSource();

    QStringList filePaths() const;

    Envelope fullExtent() const;

    /*!
       \internal
     */
    RasterElevationSource(const std::shared_ptr<QRTImpl::RasterElevationSourceImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::RasterElevationSourceImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(RasterElevationSource)
    RasterElevationSource() = delete;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_RasterElevationSource_H
