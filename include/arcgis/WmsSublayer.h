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
/// \file WmsSublayer.h

#ifndef QRT_WmsSublayer_H
#define QRT_WmsSublayer_H

// C++ API headers
#include "LayerContent.h"
#include "MapTypes.h"
#include "WmsLayerInfo.h"

namespace QRTImpl {
  class WmsSublayerImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class WmsSublayer : public LayerContent
  {
    Q_OBJECT

  public:
    ~WmsSublayer();

    QString currentStyle() const;
    void setCurrentStyle(const QString& currentStyle);

    WmsLayerInfo sublayerInfo() const;

    // LayerContent interface methods
    bool canChangeVisibility() const override;
    bool isVisible() const override;
    void setVisible(bool visible) override;
    bool isVisibleAtScale(double scale) const override;
    QString name() const override;
    bool isShowInLegend() const override;
    void setShowInLegend(bool showInLegend) override;
    bool isAutoFetchLegendInfos() const override;
    void setAutoFetchLegendInfos(bool autoFetchLegendInfos) override;
    LegendInfoListModel* legendInfos() const override;
    QList<LayerContent*> subLayerContents() const override;
    std::shared_ptr<QRTImpl::LayerContentImpl> iGetImpl() const override;

    /*! \internal */
    explicit WmsSublayer(const std::shared_ptr<QRTImpl::WmsSublayerImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::WmsSublayerImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(WmsSublayer)
    std::shared_ptr<QRTImpl::WmsSublayerImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_WmsSublayer_H
