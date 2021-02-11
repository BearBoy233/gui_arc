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
/// \file RasterSublayerSource.h

#ifndef QRT_RasterSublayerSource_H
#define QRT_RasterSublayerSource_H

// C++ API headers
#include "Field.h"
#include "SublayerSource.h"

namespace QRTImpl { class RasterSublayerSourceImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class RasterSublayerSource : public SublayerSource
  {
    Q_OBJECT

  public:
    RasterSublayerSource(const QString& workspaceId, const QString& dataSourceName, QObject* parent = nullptr);
    ~RasterSublayerSource();

    QString dataSourceName() const;

    QString workspaceId() const;

    /*! \internal */
    explicit RasterSublayerSource(const std::shared_ptr<QRTImpl::RasterSublayerSourceImpl>& impl, QObject* parent = nullptr);
    /*! \internal */
    std::shared_ptr<QRTImpl::RasterSublayerSourceImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(RasterSublayerSource)
    RasterSublayerSource() = delete;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_RasterSublayerSource_H
