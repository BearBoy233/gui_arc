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
/// \file MultipartBuilder.h

#ifndef QRT_MultipartBuilder_H
#define QRT_MultipartBuilder_H

// C++ API headers
#include "GeometryBuilder.h"
#include "Multipoint.h"
#include "PartCollection.h"
#include "SpatialReference.h"

// STL headers
#include <memory>

namespace QRTImpl { class MultipartBuilderImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class MultipartBuilder : public GeometryBuilder
  {
    Q_OBJECT

  public:
    ~MultipartBuilder();

    PartCollection* parts() const;

    void setParts(PartCollection* parts);

    int addPoint(const Point& point);

    int addPoint(double x, double y);

    int addPoint(double x, double y, double z);

    void addPoints(const QList<Point>& points);

    std::shared_ptr<QRTImpl::GeometryBuilderImpl> getImpl() const override;

  protected:
    MultipartBuilder(const std::shared_ptr<QRTImpl::MultipartBuilderImpl>& impl, QObject* parent = nullptr);

  private:
    Q_DISABLE_COPY(MultipartBuilder)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_MultipartBuilder_H

