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
/// \file GeoElement.h

#ifndef QRT_GeoElement_H
#define QRT_GeoElement_H

// Qt headers
#include <QtGlobal>

// STL headers
#include <memory>

namespace QRTImpl { class GeoElementImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class Geometry;
  class AttributeListModel;

  class GeoElement
  {
  public:
    virtual ~GeoElement();
    virtual Geometry geometry() const = 0;
    virtual void setGeometry(const Geometry& geometry) = 0;
    virtual AttributeListModel* attributes() const = 0;
    /*! \internal */
    virtual std::shared_ptr<QRTImpl::GeoElementImpl> iGetImpl() const = 0;

  protected:
    GeoElement();

  private:
    Q_DISABLE_COPY(GeoElement)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_GeoElement_H
