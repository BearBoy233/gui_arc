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
/// \file PictureFillSymbol.h

#ifndef QRT_PictureFillSymbol_H
#define QRT_PictureFillSymbol_H

// C++ API headers
#include "Credential.h"
#include "FillSymbol.h"
#include "Loadable.h"
#include "RemoteResource.h"

// Qt headers
#include <QImage>
#include <QUrl>

namespace QRTImpl { class PictureFillSymbolImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class PictureFillSymbol : public FillSymbol, public Loadable, public RemoteResource
  {
    Q_OBJECT

  public:
    explicit PictureFillSymbol(const QImage& image, QObject* parent = nullptr);
    explicit PictureFillSymbol(const QUrl& url, QObject* parent = nullptr);
    PictureFillSymbol(const QUrl& url, Credential* credential, QObject* parent = nullptr);
    ~PictureFillSymbol();

    QImage image() const;

    float height() const;
    void setHeight(float height);

    float width() const;
    void setWidth(float width);

    float opacity() const;
    void setOpacity(float opacity);

    double angle() const;
    void setAngle(double angle);

    double scaleX() const;
    void setScaleX(double scaleX);

    double scaleY() const;
    void setScaleY(double scaleY);

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

    // internal
    explicit PictureFillSymbol(const std::shared_ptr<QRTImpl::PictureFillSymbolImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::PictureFillSymbolImpl> getImpl() const;

  signals:
    void doneLoading(Esri::ArcGISRuntime::Error loadError);
    void loadStatusChanged(Esri::ArcGISRuntime::LoadStatus loadStatus);

  private:
    Q_DISABLE_COPY(PictureFillSymbol)

    void connectSignals();
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_PictureFillSymbol_H
