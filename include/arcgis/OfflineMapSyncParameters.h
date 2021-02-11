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
/// \file OfflineMapSyncParameters.h

#ifndef QRT_OfflineMapSyncParameters_H
#define QRT_OfflineMapSyncParameters_H

// C++ API headers
#include "OfflineMapItemInfo.h"
#include "TaskTypes.h"

namespace QRTImpl {
  class OfflineMapSyncParametersImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class OfflineMapSyncParameters
  {
  public:
    OfflineMapSyncParameters();
    OfflineMapSyncParameters(const OfflineMapSyncParameters& other);
    OfflineMapSyncParameters(OfflineMapSyncParameters&& other) noexcept;
    ~OfflineMapSyncParameters();

    OfflineMapSyncParameters& operator=(const OfflineMapSyncParameters& other);
    OfflineMapSyncParameters& operator=(OfflineMapSyncParameters&& other) noexcept;

    bool isRollbackOnFailure() const;
    void setRollbackOnFailure(bool rollbackOnFailure);

    SyncDirection syncDirection() const;
    void setSyncDirection(SyncDirection syncDirection);

    /*!
       \internal
     */
    explicit OfflineMapSyncParameters(const std::shared_ptr<QRTImpl::OfflineMapSyncParametersImpl>& impl);
    std::shared_ptr<QRTImpl::OfflineMapSyncParametersImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::OfflineMapSyncParametersImpl> m_impl;
  };
}
}

#endif // QRT_OfflineMapSyncParameters_H
