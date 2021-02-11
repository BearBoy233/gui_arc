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
/// \file EncViewingGroupSettings.h

#ifndef QRT_EncViewingGroupSettings_H
#define QRT_EncViewingGroupSettings_H

// C++ API headers
#include "Object.h"

// STL headers
#include <memory>

namespace QRTImpl { class EncViewingGroupSettingsImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class EncViewingGroupSettings : public Object
  {
    Q_OBJECT

  public:
    ~EncViewingGroupSettings();

    bool isAllIsolatedDangers() const;
    void setAllIsolatedDangers(bool value);

    bool isArchipelagicSeaLanes() const;
    void setArchipelagicSeaLanes(bool value);

    bool isBoundariesAndLimits() const;
    void setBoundariesAndLimits(bool value);

    bool isBuoysBeaconsAidsToNavigation() const;
    void setBuoysBeaconsAidsToNavigation(bool value);

    bool isBuoysBeaconsStructures() const;
    void setBuoysBeaconsStructures(bool value);

    bool isChartScaleBoundaries() const;
    void setChartScaleBoundaries(bool value);

    bool isDepthContours() const;
    void setDepthContours(bool value);

    bool isDryingLine() const;
    void setDryingLine(bool value);

    bool isLights() const;
    void setLights(bool value);

    bool isMagneticVariation() const;
    void setMagneticVariation(bool value);

    bool isOtherMiscellaneous() const;
    void setOtherMiscellaneous(bool value);

    bool isProhibitedAndRestrictedAreas() const;
    void setProhibitedAndRestrictedAreas(bool value);

    bool isSeabed() const;
    void setSeabed(bool value);

    bool isShipsRoutingSystemsAndFerryRoutes() const;
    void setShipsRoutingSystemsAndFerryRoutes(bool value);

    bool isSpotSoundings() const;
    void setSpotSoundings(bool value);

    bool isStandardMiscellaneous() const;
    void setStandardMiscellaneous(bool value);

    bool isSubmarineCablesAndPipelines() const;
    void setSubmarineCablesAndPipelines(bool value);

    bool isTidal() const;
    void setTidal(bool value);

    void resetToDefaults();

    /*! \internal */
    EncViewingGroupSettings(const std::shared_ptr<QRTImpl::EncViewingGroupSettingsImpl>& impl, QObject* parent = nullptr);

    /*! \internal */
    std::shared_ptr<QRTImpl::EncViewingGroupSettingsImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(EncViewingGroupSettings)
    std::shared_ptr<QRTImpl::EncViewingGroupSettingsImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_EncViewingGroupSettings_H
