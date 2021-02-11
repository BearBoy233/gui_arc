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
/// \file EncMarinerSettings.h

#ifndef QRT_EncMarinerSettings_H
#define QRT_EncMarinerSettings_H

// C++ API headers
#include "EncDisplayCategories.h"
#include "HydrographyTypes.h"
#include "Object.h"

// STL headers
#include <memory>

namespace QRTImpl { class EncMarinerSettingsImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class EncMarinerSettings : public Object
  {
    Q_OBJECT

  public:
    ~EncMarinerSettings();

    EncAreaSymbolizationType areaSymbolizationType() const;
    void setAreaSymbolizationType(EncAreaSymbolizationType type);

    EncColorScheme colorScheme() const;
    void setColorScheme(EncColorScheme scheme);

    bool isDataQuality() const;
    void setDataQuality(bool value);

    double deepContour() const;
    void setDeepContour(double meters);

    EncDisplayCategories* displayCategories() const;

    EncDisplayDepthUnits displayDepthUnits() const;
    void setDisplayDepthUnits(EncDisplayDepthUnits displayDepthUnits);

    bool isDisplayNobjnm() const;
    void setDisplayNobjnm(bool value);

    bool isHonorScamin() const;
    void setHonorScamin(bool value);

    bool isIsolatedDangers() const;
    void setIsolatedDangers(bool value);

    bool isLabelContours() const;
    void setLabelContours(bool value);

    bool isLabelSafetyContours() const;
    void setLabelSafetyContours(bool value);

    bool isLowAccuracy() const;
    void setLowAccuracy(bool value);

    EncPointSymbolizationType pointSymbolizationType() const;
    void setPointSymbolizationType(EncPointSymbolizationType type);

    double safetyContour() const;
    void setSafetyContour(double meters);

    double shallowContour() const;
    void setShallowContour(double meters);

    bool isShallowDepthPattern() const;
    void setShallowDepthPattern(bool value);

    bool isTwoDepthShades() const;
    void setTwoDepthShades(bool value);

    void resetToDefaults();

    /*! \internal */
    explicit EncMarinerSettings(const std::shared_ptr<QRTImpl::EncMarinerSettingsImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::EncMarinerSettingsImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(EncMarinerSettings)
    std::shared_ptr<QRTImpl::EncMarinerSettingsImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_EncMarinerSettings_H
