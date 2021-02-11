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
/// \file TileCache.h

#ifndef QRT_TileCache_H
#define QRT_TileCache_H

// C++ API headers
#include "Envelope.h"
#include "Loadable.h"
#include "MapTypes.h"
#include "Object.h"
#include "TileInfo.h"

// Qt headers
#include <QImage>

namespace QRTImpl { class TileCacheImpl; }

namespace Esri {
namespace ArcGISRuntime {

class TileCache : public Object, public Loadable
{
  Q_OBJECT

public:
  TileCache(const QString& path, QObject* parent = nullptr);
  ~TileCache();

  QString path() const;

  TileInfo tileInfo() const;

  bool isAntialiasing() const;

  CacheStorageFormat cacheStorageFormat() const;

  QImage thumbnail() const;

  Envelope fullExtent() const;

  // Loadable Interface methods
  Error loadError() const override;
  LoadStatus loadStatus() const override;
  void cancelLoad() override;
  void load() override;
  void retryLoad() override;

  /*!
     \internal
   */
  TileCache(const std::shared_ptr<QRTImpl::TileCacheImpl>& impl, QObject* parent = nullptr);
  std::shared_ptr<QRTImpl::TileCacheImpl> getImpl() const;

signals:
  void doneLoading(Esri::ArcGISRuntime::Error loadError);
  void loadStatusChanged(Esri::ArcGISRuntime::LoadStatus loadStatus);

private:
  Q_DISABLE_COPY(TileCache)

  void connectSignals();
  std::shared_ptr<QRTImpl::TileCacheImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_TileCache_H
