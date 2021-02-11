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
/// \file SyncGeodatabaseParameters.h

#ifndef QRT_SyncGeodatabaseParameters_H
#define QRT_SyncGeodatabaseParameters_H

// C++ API headers
#include "SyncLayerOption.h"
#include "TaskTypes.h"

namespace QRTImpl {
  class SyncGeodatabaseParametersImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class SyncGeodatabaseParameters
  {

  public:
    SyncGeodatabaseParameters();
    SyncGeodatabaseParameters(const SyncGeodatabaseParameters& other);
    SyncGeodatabaseParameters(SyncGeodatabaseParameters&& other) noexcept;
    ~SyncGeodatabaseParameters();

    SyncGeodatabaseParameters& operator=(const SyncGeodatabaseParameters& other);
    SyncGeodatabaseParameters& operator=(SyncGeodatabaseParameters&& other) noexcept;

    bool isEmpty() const;

    SyncDirection geodatabaseSyncDirection() const;
    void setGeodatabaseSyncDirection(SyncDirection syncDirection);

    QList<SyncLayerOption> layerOptions() const;
    void setLayerOptions(const QList<SyncLayerOption>& syncLayerOptions);

    bool isRollbackOnFailure() const;
    void setRollbackOnFailure(bool rollbackOnFailure);

    std::shared_ptr<QRTImpl::SyncGeodatabaseParametersImpl> getImpl() const;

    /*!
       \internal
     */
    explicit SyncGeodatabaseParameters(const std::shared_ptr<QRTImpl::SyncGeodatabaseParametersImpl>& impl);

  private:
    std::shared_ptr<QRTImpl::SyncGeodatabaseParametersImpl> m_impl;

  };
}
}

#endif // QRT_SyncGeodatabaseParameters_H
