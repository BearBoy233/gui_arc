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
/// \file ModelSceneSymbol.h

#ifndef QRT_ModelSceneSymbol_H
#define QRT_ModelSceneSymbol_H

// C++ API headers
#include "Credential.h"
#include "Loadable.h"
#include "MarkerSceneSymbol.h"
#include "RemoteResource.h"

// Qt headers
#include <QUrl>

namespace QRTImpl { class ModelSceneSymbolImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class ModelSceneSymbol : public MarkerSceneSymbol, public Loadable, public RemoteResource
  {
    Q_OBJECT

  public:
    explicit ModelSceneSymbol(const QUrl& url, QObject* parent = nullptr);
    ModelSceneSymbol(const QUrl& url, Credential* credential, QObject* parent = nullptr);
    ModelSceneSymbol(const QUrl& url, float scale, QObject* parent = nullptr);
    ModelSceneSymbol(const QUrl& url, Credential* credential, float scale, QObject* parent = nullptr);
    ~ModelSceneSymbol();

    float scale() const;

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

    /*! \internal */
    explicit ModelSceneSymbol(const std::shared_ptr<QRTImpl::ModelSceneSymbolImpl>& impl, QObject* parent = nullptr);
    /*! \internal */
    std::shared_ptr<QRTImpl::ModelSceneSymbolImpl> getImpl() const;

  signals:
    void doneLoading(Esri::ArcGISRuntime::Error loadError);
    void loadStatusChanged(Esri::ArcGISRuntime::LoadStatus loadStatus);

  private:
    Q_DISABLE_COPY(ModelSceneSymbol)

    ModelSceneSymbol() = delete;

    void connectSignals();
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ModelSceneSymbol_H
