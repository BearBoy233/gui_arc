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
/// \file LoadSettings.h

#ifndef QRT_LoadSettings_H
#define QRT_LoadSettings_H

// C++ API headers
#include "MapTypes.h"
#include "Object.h"

namespace QRTImpl { class LoadSettingsImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class LoadSettings : public Object
  {
    Q_OBJECT

  public:
    explicit LoadSettings(QObject* parent = nullptr);
    ~LoadSettings();

    FeatureRenderingMode preferredPointFeatureRenderingMode() const;
    void setPreferredPointFeatureRenderingMode(FeatureRenderingMode renderingMode);

    FeatureRenderingMode preferredPolygonFeatureRenderingMode() const;
    void setPreferredPolygonFeatureRenderingMode(FeatureRenderingMode renderingMode);

    FeatureRenderingMode preferredPolylineFeatureRenderingMode() const;
    void setPreferredPolylineFeatureRenderingMode(FeatureRenderingMode renderingMode);

    bool isUseAdvancedSymbology() const;
    void setUseAdvancedSymbology(bool useAdvancedSymbology);

    /*!
       \internal
     */
    explicit LoadSettings(const std::shared_ptr<QRTImpl::LoadSettingsImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::LoadSettingsImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(LoadSettings)

    std::shared_ptr<QRTImpl::LoadSettingsImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_LoadSettings_H
