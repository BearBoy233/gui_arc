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
/// \file EncFeature.h

#ifndef QRT_EncFeature_H
#define QRT_EncFeature_H

// C++ API headers
#include "GeoElement.h"
#include "Object.h"

namespace QRTImpl { class EncFeatureImpl; }

namespace Esri {
namespace ArcGISRuntime {
  class AttributeListModel;

  class EncFeature : public Object, public GeoElement
  {
    Q_OBJECT

  public:
    ~EncFeature();

    QString acronym() const;

    AttributeListModel* attributes() const override;

    QString description() const;

    Geometry geometry() const override;
    void setGeometry(const Geometry& geometry) override;

    QString attributeDescription(const QString& acronym) const;

    /*! \internal */
    EncFeature(const std::shared_ptr<QRTImpl::EncFeatureImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::EncFeatureImpl> getImpl() const;
    std::shared_ptr<QRTImpl::GeoElementImpl> iGetImpl() const override;

  signals:
    void geometryChanged();

  private:
    Q_DISABLE_COPY(EncFeature)

    std::shared_ptr<QRTImpl::EncFeatureImpl> m_impl;

    EncFeature() = delete;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_EncFeature_H
