// COPYRIGHT 1995-2018 ESRI
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
/// \file KmlPlacemark.h

#ifndef QRT_KmlPlacemark_H
#define QRT_KmlPlacemark_H

// C++ API headers
#include "AttributeListModel.h"
#include "GeoElement.h"
#include "KmlGeometry.h"
#include "KmlNode.h"
#include "MapTypes.h"

namespace Esri {
namespace ArcGISRuntime {

  class KmlPlacemark : public KmlNode, public GeoElement
  {
    Q_OBJECT

  public:
    ~KmlPlacemark();

    QList<KmlGeometry> geometries() const;

    KmlGraphicType graphicType() const;

    AttributeListModel* attributes() const override;

    Geometry geometry() const override;
    void setGeometry(const Geometry& geometry) override;

    /*! \internal */
    KmlPlacemark(const std::shared_ptr<QRTImpl::KmlNodeImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::GeoElementImpl> iGetImpl() const override;

  signals:
    void geometryChanged();

  private:
    Q_DISABLE_COPY(KmlPlacemark)
    KmlPlacemark() = delete;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_KmlPlacemark_H
