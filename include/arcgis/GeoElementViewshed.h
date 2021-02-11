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
/// \file GeoElementViewshed.h

#ifndef QRT_GeoElementViewshed_H
#define QRT_GeoElementViewshed_H

// C++ API headers
#include "GeoElement.h"
#include "Viewshed.h"

namespace QRTImpl { class GeoElementViewshedImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class GeoElementViewshed : public Viewshed
  {
    Q_OBJECT

  public:
    GeoElementViewshed(GeoElement* geoElement, double horizontalAngle, double verticalAngle, double minDistance,
                       double maxDistance, double headingOffset, double pitchOffset, QObject* parent = nullptr);
    ~GeoElementViewshed();

    GeoElement* geoElement() const;

    double headingOffset() const;
    void setHeadingOffset(double headingOffset);

    double pitchOffset() const;
    void setPitchOffset(double pitchOffset);

    double offsetX() const;
    void setOffsetX(double offsetX);

    double offsetY() const;
    void setOffsetY(double offsetY);

    double offsetZ() const;
    void setOffsetZ(double offsetZ);

    /*! \internal */
    explicit GeoElementViewshed(const std::shared_ptr<QRTImpl::GeoElementViewshedImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::GeoElementViewshedImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(GeoElementViewshed)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_GeoElementViewshed_H
