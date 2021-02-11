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
/// \file OfflineMapSyncLayerResult.h

#ifndef QRT_OfflineMapSyncLayerResult_H
#define QRT_OfflineMapSyncLayerResult_H

// C++ API headers
#include "FeatureEditResult.h"
#include "Object.h"

namespace QRTImpl { class OfflineMapSyncLayerResultImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class OfflineMapSyncLayerResult : public Object
  {
    Q_OBJECT

  public:
    ~OfflineMapSyncLayerResult();

    QList<FeatureEditResult*> editErrors(QObject* parent = nullptr) const;

    Error error() const;

    bool hasErrors() const;

    /*!
      \internal
     */
    explicit OfflineMapSyncLayerResult(const std::shared_ptr<QRTImpl::OfflineMapSyncLayerResultImpl>& impl, QObject* parent = nullptr);

  private:
    Q_DISABLE_COPY(OfflineMapSyncLayerResult)
    OfflineMapSyncLayerResult() = delete;

    std::shared_ptr<QRTImpl::OfflineMapSyncLayerResultImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_OfflineMapSyncLayerResult_H
