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
/// \file EstimateTileCacheSizeResult.h

#ifndef QRT_EstimateTileCacheSizeResult_H
#define QRT_EstimateTileCacheSizeResult_H

// C++ API headers
#include "Object.h"

namespace QRTImpl { class EstimateTileCacheSizeResultImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class EstimateTileCacheSizeResult : public Object
  {

  public:
    ~EstimateTileCacheSizeResult();

    int tileCount() const;
    quint64 fileSize() const;

    /*! \internal */
    explicit EstimateTileCacheSizeResult(const std::shared_ptr<QRTImpl::EstimateTileCacheSizeResultImpl>& impl, QObject* parent = nullptr);

  private:
    /*! \internal */
    EstimateTileCacheSizeResult() = delete;
    Q_DISABLE_COPY(EstimateTileCacheSizeResult)
    std::shared_ptr<QRTImpl::EstimateTileCacheSizeResultImpl> m_impl;
  };
}
}
#endif // QRT_EstimateTileCacheSizeResult_H
