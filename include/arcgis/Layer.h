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
/// \file Layer.h

#ifndef QRT_Layer_H
#define QRT_Layer_H

// C++ API headers
#include "Envelope.h"
#include "Item.h"
#include "LayerContent.h"
#include "Loadable.h"
#include "SpatialReference.h"

namespace QRTImpl { class LayerImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class Layer : public LayerContent, public Loadable
  {
    Q_OBJECT

  public:
    ~Layer();

    QString layerId() const;
    void setLayerId(const QString& layerId);

    void setName(const QString& name);

    QString attribution() const;

    QString description() const;
    void setDescription(const QString& description);

    double minScale() const;
    void setMinScale(double minScale);
    double maxScale() const;
    void setMaxScale(double maxScale);

    Envelope fullExtent() const;

    LayerType layerType() const;

    float opacity() const;
    void setOpacity(float opacity) const;

    SpatialReference spatialReference() const;

    bool isIdentifyEnabled() const;

    Item* item() const;

    // LayerContent Interface methods
    QString name() const override;
    bool isVisible() const override;
    void setVisible(bool visible) override;
    bool canChangeVisibility() const override;
    bool isVisibleAtScale(double scale) const override;
    bool isShowInLegend() const override;
    void setShowInLegend(bool showInLegend) override;
    bool isAutoFetchLegendInfos() const override;
    void setAutoFetchLegendInfos(bool autoFetchLegendInfos) override;
    LegendInfoListModel* legendInfos() const override;
    QList<LayerContent*> subLayerContents() const override;
    std::shared_ptr<QRTImpl::LayerContentImpl> iGetImpl() const override;

    // Loadable Interface methods
    Error loadError() const override;
    LoadStatus loadStatus() const override;
    void cancelLoad() override;
    void load() override;
    void retryLoad() override;

    /*! \internal */
    Layer(const std::shared_ptr<QRTImpl::LayerImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::LayerImpl> getImpl() const;

  signals:
    void doneLoading(Esri::ArcGISRuntime::Error loadError);
    void loadStatusChanged(Esri::ArcGISRuntime::LoadStatus loadStatus);

  protected:
    std::shared_ptr<QRTImpl::LayerImpl> m_impl;

  private:
    Layer() = delete;

    Q_DISABLE_COPY(Layer)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_Layer_H

