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
/// \file VectorTileCache.h

#ifndef QRT_VectorTileCache_H
#define QRT_VectorTileCache_H

// C++ API headers
#include "Loadable.h"
#include "Object.h"
#include "VectorTileSourceInfo.h"

namespace QRTImpl { class VectorTileCacheImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class VectorTileCache : public Object, public Loadable
  {
    Q_OBJECT

  public:
    explicit VectorTileCache(const QString& path, QObject* parent = nullptr);
    ~VectorTileCache();

    // Loadable Interface methods
    Error loadError() const override;
    LoadStatus loadStatus() const override;
    void cancelLoad() override;
    void load() override;
    void retryLoad() override;

    QImage thumbnail() const;

    QString path() const;

    VectorTileSourceInfo sourceInfo() const;

    /*!
       \internal
     */
    VectorTileCache(const std::shared_ptr<QRTImpl::VectorTileCacheImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::VectorTileCacheImpl> getImpl() const;

  signals:
    void doneLoading(Esri::ArcGISRuntime::Error loadError);
    void loadStatusChanged(Esri::ArcGISRuntime::LoadStatus loadStatus);

  private:
    Q_DISABLE_COPY(VectorTileCache)

    void connectSignals();
    std::shared_ptr<QRTImpl::VectorTileCacheImpl> m_impl;
  };

} // ArcGISRuntime
} // Esri
#endif // QRT_VectorTileCache_H
