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
/// \file GenerateOfflineMapResult.h

#ifndef QRT_GenerateOfflineMapResult_H
#define QRT_GenerateOfflineMapResult_H

// C++ API headers
#include "Error.h"
#include "FeatureTable.h"
#include "Layer.h"
#include "Map.h"
#include "MobileMapPackage.h"
#include "Object.h"

namespace QRTImpl { class GenerateOfflineMapResultImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class GenerateOfflineMapResult : public Object
  {

  public:
    ~GenerateOfflineMapResult();

    Map* offlineMap(QObject* parent = nullptr) const;

    MobileMapPackage* mobileMapPackage(QObject* parent = nullptr) const;

    bool hasErrors() const;

    QMap<Layer*, Error> layerErrors() const;

    QMap<FeatureTable*, Error> tableErrors() const;

    /*! \internal */
    explicit GenerateOfflineMapResult(const std::shared_ptr<QRTImpl::GenerateOfflineMapResultImpl>& impl, QObject* parent = nullptr);

  private:
    /*! \internal */
    GenerateOfflineMapResult() = delete;
    Q_DISABLE_COPY(GenerateOfflineMapResult)
    std::shared_ptr<QRTImpl::GenerateOfflineMapResultImpl> m_impl;
  };
}
}
#endif // QRT_GenerateOfflineMapResult_H
