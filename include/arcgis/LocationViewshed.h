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
/// \file LocationViewshed.h

#ifndef QRT_LocationViewshed_H
#define QRT_LocationViewshed_H

// C++ API headers
#include "Camera.h"
#include "Point.h"
#include "Viewshed.h"

namespace QRTImpl { class LocationViewshedImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class LocationViewshed : public Viewshed
  {
    Q_OBJECT

  public:
    LocationViewshed(const Camera& camera, double minDistance, double maxDistance, QObject* parent = nullptr);
    LocationViewshed(const Point& location,
                     double heading, double pitch,
                     double horizontalAngle, double verticalAngle,
                     double minDistance, double maxDistance, QObject* parent = nullptr);
    ~LocationViewshed();

    Point location() const;
    void setLocation(const Point& location);

    double heading() const;
    void setHeading(double heading);

    double pitch() const;
    void setPitch(double pitch);

    void updateFromCamera(const Camera& camera);

    /*! \internal */
    explicit LocationViewshed(const std::shared_ptr<QRTImpl::LocationViewshedImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::LocationViewshedImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(LocationViewshed)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_LocationViewshed_H
