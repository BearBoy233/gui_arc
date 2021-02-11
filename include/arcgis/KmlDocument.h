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
/// \file KmlDocument.h

#ifndef QRT_KmlDocument_H
#define QRT_KmlDocument_H

// C++ API headers
#include "KmlContainer.h"

namespace Esri {
namespace ArcGISRuntime {

  class KmlDocument : public KmlContainer
  {
    Q_OBJECT

  public:
    ~KmlDocument();

    /*! \internal */
    explicit KmlDocument(const std::shared_ptr<QRTImpl::KmlNodeImpl>& impl, QObject* parent = nullptr);

  private:
    Q_DISABLE_COPY(KmlDocument)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_KmlDocument_H
