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
/// \file PictureMarkerSymbol.h

#ifndef QRT_PictureMarkerSymbol_H
#define QRT_PictureMarkerSymbol_H

// C++ API headers
#include "Credential.h"
#include "Loadable.h"
#include "MarkerSymbol.h"
#include "RemoteResource.h"

// Qt headers
#include <QImage>
#include <QUrl>

namespace QRTImpl { class PictureMarkerSymbolImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class PictureMarkerSymbol : public MarkerSymbol, public Loadable, public RemoteResource
  {
    Q_OBJECT

  public:
    explicit PictureMarkerSymbol(const QImage& image, QObject* parent = nullptr);
    explicit PictureMarkerSymbol(const QUrl& url, QObject* parent = nullptr);
    PictureMarkerSymbol(const QUrl& url, Credential* credential, QObject* parent = nullptr);
    ~PictureMarkerSymbol();

    QImage image() const;

    float height() const;
    void setHeight(float height);

    float width() const;
    void setWidth(float width);

    float opacity() const;
    void setOpacity(float opacity);

    // Loadable Interface methods
    Error loadError() const override;
    LoadStatus loadStatus() const override;
    void cancelLoad() override;
    void load() override;
    void retryLoad() override;

    // RemoteResource interface methods
    QUrl url() const override;
    Credential* credential() const override;
    RequestConfiguration requestConfiguration() const override;
    void setRequestConfiguration(const RequestConfiguration& requestConfiguration) override;

    explicit PictureMarkerSymbol(const std::shared_ptr<QRTImpl::PictureMarkerSymbolImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::PictureMarkerSymbolImpl> getImpl() const;

  signals:
    void doneLoading(Esri::ArcGISRuntime::Error loadError);
    void loadStatusChanged(Esri::ArcGISRuntime::LoadStatus loadStatus);

  private:
    Q_DISABLE_COPY(PictureMarkerSymbol)

    PictureMarkerSymbol() = delete;

    void connectSignals();
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_PictureMarkerSymbol_H
