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
/// \file LayerContent.h

#ifndef QRT_LayerContent_H
#define QRT_LayerContent_H

// C++ API headers
#include "LegendInfo.h"
#include "LegendInfoListModel.h"
#include "Object.h"
#include "TaskWatcher.h"

// Qt headers
#include <QPointer>
#include <QString>

namespace QRTImpl { class LayerContentImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class LayerContent : public Object
  {
    Q_OBJECT

  public:
    virtual ~LayerContent();

    virtual QString name() const = 0;

    virtual bool isVisible() const = 0;

    virtual void setVisible(bool visible) = 0;

    virtual bool canChangeVisibility() const = 0;

    virtual bool isVisibleAtScale(double scale) const = 0;

    virtual bool isShowInLegend() const = 0;

    virtual void setShowInLegend(bool showInLegend) = 0;

    virtual QList<LayerContent*> subLayerContents() const = 0;

    virtual bool isAutoFetchLegendInfos() const = 0;

    virtual void setAutoFetchLegendInfos(bool autoFetchLegendInfos) = 0;

    virtual LegendInfoListModel* legendInfos() const = 0;

    virtual std::shared_ptr<QRTImpl::LayerContentImpl> iGetImpl() const = 0;

  signals:
    void subLayerContentChanged();

  protected:
    LayerContent(const std::shared_ptr<QRTImpl::ObjectImpl>& impl, QObject* parent = nullptr);

  private:
    Q_DISABLE_COPY(LayerContent)

    LayerContent() = delete;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_LayerContent_H
