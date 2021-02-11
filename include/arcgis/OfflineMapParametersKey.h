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
/// \file OfflineMapParametersKey.h

#ifndef QRT_OfflineMapParametersKey_H
#define QRT_OfflineMapParametersKey_H

// C++ API headers
#include "Error.h"
#include "Layer.h"
#include "OfflineMapTypes.h"
#include "ServiceFeatureTable.h"

// Qt headers
#include <QUrl>

namespace QRTImpl {
  class OfflineMapParametersKeyImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class OfflineMapParametersKey
  {
  public:
    OfflineMapParametersKey();
    explicit OfflineMapParametersKey(Layer* layer);
    explicit OfflineMapParametersKey(ServiceFeatureTable* table);
    OfflineMapParametersKey(const OfflineMapParametersKey& other);
    OfflineMapParametersKey(OfflineMapParametersKey&& other) noexcept;
    ~OfflineMapParametersKey();

    OfflineMapParametersKey& operator=(const OfflineMapParametersKey& other);
    OfflineMapParametersKey& operator=(OfflineMapParametersKey&& other) noexcept;

    bool operator==(const OfflineMapParametersKey& other) const;
    bool operator<(const OfflineMapParametersKey& other) const;

    bool isEmpty() const;

    QUrl serviceUrl() const;

    OfflineMapParametersType type() const;

    Error keyError() const;

    /*! \internal */
    explicit OfflineMapParametersKey(const std::shared_ptr<QRTImpl::OfflineMapParametersKeyImpl>& impl);
    /*! \internal */
    std::shared_ptr<QRTImpl::OfflineMapParametersKeyImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::OfflineMapParametersKeyImpl> m_impl;
  };
} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_OfflineMapParametersKey_H
