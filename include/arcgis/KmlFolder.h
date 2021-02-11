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
/// \file KmlFolder.h

#ifndef QRT_KmlFolder_H
#define QRT_KmlFolder_H

// C++ API headers
#include "KmlContainer.h"

namespace Esri {
namespace ArcGISRuntime {

  class KmlFolder : public KmlContainer
  {
    Q_OBJECT

  public:
    ~KmlFolder();

    /*! \internal */
    explicit KmlFolder(const std::shared_ptr<QRTImpl::KmlNodeImpl>& impl, QObject* parent = nullptr);

  private:
    Q_DISABLE_COPY(KmlFolder)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_KmlFolder_H
