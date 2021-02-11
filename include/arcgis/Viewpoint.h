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
/// \file Viewpoint.h

#ifndef QRT_Viewpoint_H
#define QRT_Viewpoint_H

// C++ API headers
#include "ArcGISQt_global.h"
#include "Camera.h"
#include "JsonSerializable.h"
#include "MapTypes.h"
#include "Point.h"

// STL headers
#include <memory>

namespace QRTImpl { class ViewpointImpl; }

namespace Esri {
namespace ArcGISRuntime {

class Viewpoint : public JsonSerializable
{
public:
  Viewpoint();
  Viewpoint(double latitude, double longitude, double scale);
  Viewpoint(double latitude, double longitude, double scale, const Camera& camera);
  Viewpoint(const Point& center, double scale);
  Viewpoint(const Point& center, double scale, const Camera& camera);
  Viewpoint(const Point& center, double scale, double rotation);
  Viewpoint(const Point& center, double scale, double rotation, const Camera& camera);
  Viewpoint(const Geometry& targetExtent);
  Viewpoint(const Geometry& targetExtent, const Camera& camera);
  Viewpoint(const Geometry& targetExtent, double rotation);
  Viewpoint(const Geometry& targetExtent, double rotation, const Camera& camera);
  Viewpoint(const Viewpoint& other);
  Viewpoint(Viewpoint&& other) noexcept;
  Viewpoint& operator=(const Viewpoint& other);
  Viewpoint& operator=(Viewpoint&& other) noexcept;
  ~Viewpoint();

  bool isEmpty() const;
  static Viewpoint fromJson(const QString& json);
  QString toJson() const override;
  QJsonObject unknownJson() const override;
  QJsonObject unsupportedJson() const override;

  double rotation() const;
  double targetScale() const;
  ViewpointType viewpointType() const;
  Geometry targetGeometry() const;
  Camera camera() const;

  /*!
     \internal
   */
  Viewpoint(const std::shared_ptr<QRTImpl::ViewpointImpl>& impl);
  std::shared_ptr<QRTImpl::ViewpointImpl> getImpl() const;

private:
  std::shared_ptr<QRTImpl::ViewpointImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_Viewpoint_H
