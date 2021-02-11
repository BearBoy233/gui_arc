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
/// \file ArcGISSublayer.h

#ifndef QRT_ArcGISSublayer_H
#define QRT_ArcGISSublayer_H

// C++ API headers
#include "ArcGISMapServiceSublayerInfo.h"
#include "LayerContent.h"
#include "LegendInfo.h"
#include "Loadable.h"
#include "MapTypes.h"
#include "PopupDefinition.h"
#include "PopupSource.h"
#include "Renderer.h"

namespace QRTImpl {
  class ArcGISSublayerImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class ArcGISSublayerListModel;

  class ArcGISSublayer : public LayerContent, public Loadable,
                         public PopupSource
  {
    Q_OBJECT

  public:
    ~ArcGISSublayer();

    QString definitionExpression() const;

    qint64 id() const;

    ArcGISMapServiceSublayerInfo mapServiceSublayerInfo() const;

    double maxScale() const;

    double minScale() const;

    float opacity() const;

    Renderer* renderer() const;

    bool isScaleSymbols() const;

    bool isLabelsEnabled() const;

    ArcGISSublayerType sublayerType() const;

    ArcGISSublayerListModel* sublayers() const;

    // LayerContent interface methods
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

    // PopupSource interface methods
    bool isPopupEnabled() const override;
    void setPopupEnabled(bool popupEnabled) override;
    PopupDefinition* popupDefinition() const override;
    void setPopupDefinition(PopupDefinition* popupDefinition) override;

    /*! \internal */
    explicit ArcGISSublayer(const std::shared_ptr<QRTImpl::ArcGISSublayerImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::ArcGISSublayerImpl> getImpl() const;

  protected:
    std::shared_ptr<QRTImpl::ArcGISSublayerImpl> m_impl;

  signals:
    void doneLoading(Esri::ArcGISRuntime::Error loadError);
    void loadStatusChanged(Esri::ArcGISRuntime::LoadStatus loadStatus);

  private:
    Q_DISABLE_COPY(ArcGISSublayer)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ArcGISSublayer_H
