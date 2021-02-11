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
/// \file MapSublayerSource.h

#ifndef QRT_MapSublayerSource_H
#define QRT_MapSublayerSource_H

// C++ API headers
#include "SublayerSource.h"

namespace QRTImpl { class MapSublayerSourceImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class MapSublayerSource : public SublayerSource
  {
    Q_OBJECT

  public:
    explicit MapSublayerSource(qint64 id, QObject* parent = nullptr);
    ~MapSublayerSource();

    QString geodatabaseVersion() const;
    void setGeodatabaseVersion(const QString& geodatabaseVersion);

    qint64 mapSublayerId() const;

    /*! \internal */
    explicit MapSublayerSource(const std::shared_ptr<QRTImpl::MapSublayerSourceImpl>& impl, QObject* parent = nullptr);
    /*! \internal */
    std::shared_ptr<QRTImpl::MapSublayerSourceImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(MapSublayerSource)
    /*! \internal */
    MapSublayerSource() = delete;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_MapSublayerSource_H
