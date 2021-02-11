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
/// \file FeatureSubtype.h

#ifndef QRT_FeatureSubtype_H
#define QRT_FeatureSubtype_H

// C++ API headers
#include "Domain.h"

// Qt headers
#include <QVariantMap>

// STL headers
#include <memory>

namespace QRTImpl {
  class FeatureSubtypeImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class FeatureSubtype
  {
  public:
    FeatureSubtype();
    FeatureSubtype(const FeatureSubtype& other);
    FeatureSubtype(FeatureSubtype&& other) noexcept;
    ~FeatureSubtype();

    FeatureSubtype& operator=(const FeatureSubtype& other);
    FeatureSubtype& operator=(FeatureSubtype&& other) noexcept;

    bool isEmpty() const;

    QVariant code() const;

    QMap<QString, Domain> domains() const;

    QString name() const;

    QVariantMap prototypeAttributes() const;

    /*! \internal */
    FeatureSubtype(const std::shared_ptr<QRTImpl::FeatureSubtypeImpl>& impl);
    std::shared_ptr<QRTImpl::FeatureSubtypeImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::FeatureSubtypeImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_FeatureSubtype_H
