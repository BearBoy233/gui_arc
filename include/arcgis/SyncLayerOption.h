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
/// \file SyncLayerOption.h

#ifndef QRT_SyncLayerOption_H
#define QRT_SyncLayerOption_H

// C++ API headers
#include "TaskTypes.h"

// Qt headers
#include <QtGlobal>

// STL headers
#include <memory>

namespace QRTImpl {
  class SyncLayerOptionImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class SyncLayerOption
  {

  public:
    SyncLayerOption();
    explicit SyncLayerOption(qint64 layerId);
    SyncLayerOption(qint64 layerId, SyncDirection syncDirection);
    SyncLayerOption(const SyncLayerOption& other);
    SyncLayerOption(SyncLayerOption&& other) noexcept;
    ~SyncLayerOption();

    SyncLayerOption& operator=(const SyncLayerOption& other);
    SyncLayerOption& operator=(SyncLayerOption&& other) noexcept;

    bool isEmpty() const;

    qint64 layerId() const;
    void setLayerId(qint64 layerOrTableId);

    SyncDirection syncDirection() const;
    void setSyncDirection(SyncDirection syncDirection);

    /*!
      \internal
     */
    explicit SyncLayerOption(const std::shared_ptr<QRTImpl::SyncLayerOptionImpl>& impl);

    /*!
      \internal
     */
    std::shared_ptr<QRTImpl::SyncLayerOptionImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::SyncLayerOptionImpl> m_impl;
  };
}
}

#endif // QRT_SyncLayerOption_H
