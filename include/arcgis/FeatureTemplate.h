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
/// \file FeatureTemplate.h

#ifndef QRT_FeatureTemplate_H
#define QRT_FeatureTemplate_H

// C++ API headers
#include "ArcGISQt_global.h"
#include "ServiceTypes.h"

// Qt headers
#include <QVariantMap>

// STL headers
#include <memory>

namespace QRTImpl {
  class FeatureTemplateImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class FeatureTemplate
  {
  public:
    FeatureTemplate();
    FeatureTemplate(const FeatureTemplate& other);
    FeatureTemplate(FeatureTemplate&& other) noexcept;
    ~FeatureTemplate();

    FeatureTemplate& operator=(const FeatureTemplate& other);
    FeatureTemplate& operator=(FeatureTemplate&& other) noexcept;

    bool isEmpty() const;

    QString description() const;

    DrawingTool drawingTool() const;

    QString name() const;

    QVariantMap prototypeAttributes() const;

    FeatureTemplate(const std::shared_ptr<QRTImpl::FeatureTemplateImpl>& impl);
    std::shared_ptr<QRTImpl::FeatureTemplateImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::FeatureTemplateImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_FeatureTemplate_H
