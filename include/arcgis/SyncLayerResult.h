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
/// \file SyncLayerResult.h

#ifndef QRT_SyncLayerResult_H
#define QRT_SyncLayerResult_H

// C++ API headers
#include "FeatureEditResult.h"

namespace QRTImpl { class SyncLayerResultImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class SyncLayerResult : public Object
  {
    Q_OBJECT

  public:
    ~SyncLayerResult();

    qint64 layerId() const;
    QList<FeatureEditResult*> editResults(QObject* parent) const;
    QString tableName() const;

    /*!
      \internal
     */
    explicit SyncLayerResult(const std::shared_ptr<QRTImpl::SyncLayerResultImpl>& impl, QObject* parent = nullptr);

  private:
    /*!
      \internal
     */
    SyncLayerResult() = delete;

    Q_DISABLE_COPY(SyncLayerResult)

    std::shared_ptr<QRTImpl::SyncLayerResultImpl> m_impl;
  };
}
}

#endif // QRT_SyncLayerResult_H
