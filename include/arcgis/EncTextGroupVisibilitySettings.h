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
/// \file EncTextGroupVisibilitySettings.h

#ifndef QRT_EncTextGroupVisibilitySettings_H
#define QRT_EncTextGroupVisibilitySettings_H

// C++ API headers
#include "Object.h"

// STL headers
#include <memory>

namespace QRTImpl { class EncTextGroupVisibilitySettingsImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class EncTextGroupVisibilitySettings : public Object
  {
    Q_OBJECT

  public:
    ~EncTextGroupVisibilitySettings();

    bool isBerthNumber() const;
    void setBerthNumber(bool value);

    bool isCurrentVelocity() const;
    void setCurrentVelocity(bool value);

    bool isGeographicNames() const;
    void setGeographicNames(bool value);

    bool isHeightOfIsletOrLandFeature() const;
    void setHeightOfIsletOrLandFeature(bool value);

    bool isImportantText() const;
    void setImportantText(bool value);

    bool isLightDescription() const;
    void setLightDescription(bool value);

    bool isMagneticVariationAndSweptDepth() const;
    void setMagneticVariationAndSweptDepth(bool value);

    bool isNamesForPositionReporting() const;
    void setNamesForPositionReporting(bool value);

    bool isNatureOfSeabed() const;
    void setNatureOfSeabed(bool value);

    bool isNoteOnChartData() const;
    void setNoteOnChartData(bool value);

    void resetToDefaults();

    /*! \internal */
    EncTextGroupVisibilitySettings(const std::shared_ptr<QRTImpl::EncTextGroupVisibilitySettingsImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::EncTextGroupVisibilitySettingsImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(EncTextGroupVisibilitySettings)
    std::shared_ptr<QRTImpl::EncTextGroupVisibilitySettingsImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_EncTextGroupVisibilitySettings_H
