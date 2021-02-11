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
/// \file FeatureType.h

#ifndef QRT_FeatureType_H
#define QRT_FeatureType_H

// C++ API headers
#include "Domain.h"
#include "FeatureTemplate.h"

// STL headers
#include <memory>

namespace QRTImpl {
  class FeatureTypeImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class FeatureType
  {
  public:
    FeatureType();
    FeatureType(const FeatureType& other);
    FeatureType(FeatureType&& other) noexcept;
    ~FeatureType();

    FeatureType& operator=(const FeatureType& other);
    FeatureType& operator=(FeatureType&& other) noexcept;

    bool isEmpty() const;

    QVariant typeId() const;

    QMap<QString, Domain> domains() const;

    QString name() const;

    QList<FeatureTemplate> templates() const;

    /*! \internal */
    FeatureType(const std::shared_ptr<QRTImpl::FeatureTypeImpl>& impl);
    std::shared_ptr<QRTImpl::FeatureTypeImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::FeatureTypeImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_FeatureType_H
