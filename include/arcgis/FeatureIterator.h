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
/// \file FeatureIterator.h

#ifndef QRT_FeatureIterator_H
#define QRT_FeatureIterator_H

// C++ API headers
#include "Feature.h"
#include "Object.h"

namespace QRTImpl {
  class FeatureIteratorImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class FeatureIterator
  {
  public:
    FeatureIterator();
    FeatureIterator(const FeatureIterator& other);
    FeatureIterator(FeatureIterator&& other) noexcept;
    ~FeatureIterator();

    FeatureIterator& operator=(const FeatureIterator& other);
    FeatureIterator& operator=(FeatureIterator&& other) noexcept;

    bool isEmpty() const;

    bool hasNext() const;

    Feature* next(QObject* parent = nullptr) const;

    void reset();

    QList<Feature*> features(QObject* parent = nullptr) const;

    /*! \internal */
    FeatureIterator(const std::shared_ptr<QRTImpl::FeatureIteratorImpl>& impl);
    std::shared_ptr<QRTImpl::FeatureIteratorImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::FeatureIteratorImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_FeatureIterator_H
