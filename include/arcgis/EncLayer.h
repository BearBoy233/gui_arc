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
/// \file Layer.h

#ifndef QRT_EncLayer_H
#define QRT_EncLayer_H

// C++ API headers
#include "Layer.h"

namespace QRTImpl { class EncLayerImpl; }

namespace Esri {
namespace ArcGISRuntime {
  class EncCell;
  class EncFeature;
  class EncEnvironmentSettings;

  class EncLayer : public Layer
  {
    Q_OBJECT

  public:
    EncLayer(EncCell* encCell, QObject* parent = nullptr);
    ~EncLayer();

    EncCell* cell() const;

    void clearSelection() const;

    void selectFeature(EncFeature* encfeature) const;

    static EncEnvironmentSettings* encEnvironmentSettings();

    /*! \internal */
    EncLayer(const std::shared_ptr<QRTImpl::EncLayerImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::EncLayerImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(EncLayer)

    EncLayer() = delete;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_EncLayer_H
