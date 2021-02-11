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
/// \file ArcGISMapImageSublayer.h

#ifndef QRT_ArcGISMapImageSublayer_H
#define QRT_ArcGISMapImageSublayer_H

// C++ API headers
#include "ArcGISSublayer.h"
#include "LabelDefinitionListModel.h"
#include "ServiceFeatureTable.h"
#include "SublayerSource.h"

namespace QRTImpl {
  class ArcGISSublayerImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class ArcGISMapImageSublayer : public ArcGISSublayer
  {
    Q_OBJECT

  public:
    explicit ArcGISMapImageSublayer(qint64 id, QObject* parent = nullptr);
    ArcGISMapImageSublayer(qint64 id, SublayerSource* sublayerSource, QObject* parent = nullptr);
    ~ArcGISMapImageSublayer();

    bool isDefaultVisible() const;
    SublayerSource* source() const;
    void setDefinitionExpression(const QString& definitionExpression);
    void setMaxScale(double maxScale);
    void setMinScale(double minScale);
    void setName(const QString& name);
    void setOpacity(float opacity);
    void setRenderer(Renderer* renderer);
    void setScaleSymbols(bool scaleSymbols);
    void setLabelsEnabled(bool labelsEnabled);
    ServiceFeatureTable* table() const;

    LabelDefinitionListModel* labelDefinitions() const;

    /*! \internal */
    explicit ArcGISMapImageSublayer(const std::shared_ptr<QRTImpl::ArcGISSublayerImpl>& impl, QObject* parent = nullptr);

  private:
    Q_DISABLE_COPY(ArcGISMapImageSublayer)
  };

} // namespace ArcGISRuntime
} // namespace Esri


#endif // QRT_ArcGISMapImageSublayer_H
