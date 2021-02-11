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
/// \file Viewshed.h

#ifndef QRT_Viewshed_H
#define QRT_Viewshed_H

// C++ API headers
#include "Analysis.h"
#include "SimpleLineSymbol.h"

namespace QRTImpl { class ViewshedImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class Viewshed : public Analysis
  {
    Q_OBJECT

  public:
    ~Viewshed();

    double horizontalAngle() const;
    void setHorizontalAngle(double horizontalAngle);

    double verticalAngle() const;
    void setVerticalAngle(double verticalAngle);

    double minDistance() const;
    void setMinDistance(double minDistance);

    double maxDistance() const;
    void setMaxDistance(double maxDistance);

    bool isFrustumOutlineVisible() const;
    void setFrustumOutlineVisible(bool visible);

    static QColor visibleColor();
    static void setVisibleColor(const QColor& visibleColor);

    static QColor obstructedColor();
    static void setObstructedColor(const QColor& obstructedColor);

    static QColor frustumOutlineColor();
    static void setFrustumOutlineColor(const QColor& frustumOutlineColor);

    /*! \internal */
    explicit Viewshed(const std::shared_ptr<QRTImpl::ViewshedImpl>& impl, QObject* parent = nullptr);

    /*! \internal */
    std::shared_ptr<QRTImpl::ViewshedImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(Viewshed)
    Viewshed() = delete;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_Viewshed_H
