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
/// \file ArcGISTiledElevationSource.h

#ifndef QRT_ArcGISTiledElevationSource_H
#define QRT_ArcGISTiledElevationSource_H

// C++ API headers
#include "Credential.h"
#include "ElevationSource.h"
#include "Item.h"
#include "RemoteResource.h"
#include "TileCache.h"

// Qt headers
#include <QUrl>

namespace QRTImpl { class ArcGISTiledElevationSourceImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class ArcGISTiledElevationSource : public ElevationSource, public RemoteResource
  {
    Q_OBJECT

  public:
    explicit ArcGISTiledElevationSource(const QUrl& url, QObject* parent = nullptr);
    ArcGISTiledElevationSource(const QUrl& url, Credential* credential, QObject* parent = nullptr);
    explicit ArcGISTiledElevationSource(Item* item, QObject* parent = nullptr);
    explicit ArcGISTiledElevationSource(TileCache* tileCache, QObject* parent = nullptr);
    ~ArcGISTiledElevationSource();

    Item* item() const;

    TileCache* tileCache() const;

    // RemoteResource interface methods
    QUrl url() const override;
    Credential* credential() const override;
    RequestConfiguration requestConfiguration() const override;
    void setRequestConfiguration(const RequestConfiguration& requestConfiguration) override;

    /*!
       \internal
     */
    ArcGISTiledElevationSource(const std::shared_ptr<QRTImpl::ArcGISTiledElevationSourceImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::ArcGISTiledElevationSourceImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(ArcGISTiledElevationSource)
    ArcGISTiledElevationSource() = delete;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ArcGISTiledElevationSource_H
