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
/// \file OfflineMapSyncResult.h

#ifndef QRT_OfflineMapSyncResult_H
#define QRT_OfflineMapSyncResult_H

// C++ API headers
#include "Error.h"
#include "FeatureLayer.h"
#include "FeatureTable.h"
#include "Object.h"
#include "OfflineMapSyncLayerResult.h"

namespace QRTImpl { class OfflineMapSyncResultImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class OfflineMapSyncResult : public Object
  {
    Q_OBJECT

  public:
    ~OfflineMapSyncResult();

    bool hasErrors() const;

    QMap<FeatureLayer*, OfflineMapSyncLayerResult*> layerResults() const;

    QMap<FeatureTable*, OfflineMapSyncLayerResult*> tableResults() const;

    /*! \internal */
    explicit OfflineMapSyncResult(const std::shared_ptr<QRTImpl::OfflineMapSyncResultImpl>& impl, QObject* parent = nullptr);

  private:
    /*! \internal */
    OfflineMapSyncResult() = delete;
    Q_DISABLE_COPY(OfflineMapSyncResult)
    std::shared_ptr<QRTImpl::OfflineMapSyncResultImpl> m_impl;
  };
}
}
#endif // QRT_OfflineMapSyncResult_H
