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
/// \file ItemResourceCache.h

#ifndef QRT_ItemResourceCache_H
#define QRT_ItemResourceCache_H

// C++ API headers
#include "Loadable.h"
#include "LocalItem.h"
#include "Object.h"

namespace QRTImpl { class ItemResourceCacheImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class ItemResourceCache : public Object, public Loadable
  {
    Q_OBJECT

  public:
    ItemResourceCache(const QString& path, QObject* parent = nullptr);
    ~ItemResourceCache();

    // Loadable Interface methods
    Error loadError() const override;
    LoadStatus loadStatus() const override;
    void cancelLoad() override;
    void load() override;
    void retryLoad() override;

    QString path() const;

    LocalItem* item() const;

    /*! \internal */
    ItemResourceCache(const std::shared_ptr<QRTImpl::ItemResourceCacheImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::ItemResourceCacheImpl> getImpl() const;

  signals:
    void doneLoading(Esri::ArcGISRuntime::Error loadError);
    void loadStatusChanged(Esri::ArcGISRuntime::LoadStatus loadStatus);

  private:
    Q_DISABLE_COPY(ItemResourceCache)

    void connectSignals();

    std::shared_ptr<QRTImpl::ItemResourceCacheImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ItemResourceCache_H
