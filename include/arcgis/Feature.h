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
/// \file Feature.h

#ifndef QRT_Feature_H
#define QRT_Feature_H

// C++ API headers
#include "AttributeListModel.h"
#include "Field.h"
#include "GeoElement.h"
#include "GeodatabaseTypes.h"
#include "Geometry.h"
#include "Object.h"

namespace QRTImpl { class FeatureImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class FeatureTable;

  class Feature : public Object, public GeoElement
  {
    Q_OBJECT

  public:
    ~Feature();

    FeatureObjectType featureObjectType() const;

    AttributeListModel* attributes() const override;

    FeatureTable* featureTable() const;

    Geometry geometry() const override;
    void setGeometry(const Geometry& geometry) override;

    bool refresh();

    /*! \internal */
    Feature(const std::shared_ptr<QRTImpl::FeatureImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::FeatureImpl> getImpl() const;
    std::shared_ptr<QRTImpl::GeoElementImpl> iGetImpl() const override;

  signals:
    void geometryChanged();

  protected:
    std::shared_ptr<QRTImpl::FeatureImpl> m_impl;

  private:
    Q_DISABLE_COPY(Feature)

    Feature() = delete;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_Feature_H
