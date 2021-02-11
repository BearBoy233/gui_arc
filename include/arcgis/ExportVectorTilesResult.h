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
/// \file ExportVectorTilesResult.h

#ifndef QRT_ExportVectorTilesResult_H
#define QRT_ExportVectorTilesResult_H

// C++ API headers
#include "ItemResourceCache.h"
#include "Object.h"
#include "VectorTileCache.h"

namespace QRTImpl { class ExportVectorTilesResultImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class ExportVectorTilesResult : public Object
  {
  public:
    ~ExportVectorTilesResult();

    ItemResourceCache* itemResourceCache() const;

    VectorTileCache* vectorTileCache() const;

    /*!
     \internal
    */
    ExportVectorTilesResult(const std::shared_ptr<QRTImpl::ExportVectorTilesResultImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::ExportVectorTilesResultImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(ExportVectorTilesResult)
    ExportVectorTilesResult() = delete;

    std::shared_ptr<QRTImpl::ExportVectorTilesResultImpl> m_impl;
  };

}
}

#endif // QRT_ExportVectorTilesResult_H
