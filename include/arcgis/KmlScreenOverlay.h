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
/// \file KmlScreenOverlay.h

#ifndef QRT_KmlScreenOverlay_H
#define QRT_KmlScreenOverlay_H

// C++ API headers
#include "KmlNode.h"

namespace Esri {
namespace ArcGISRuntime {

  class KmlScreenOverlay : public KmlNode
  {
    Q_OBJECT

  public:
    ~KmlScreenOverlay();

    QColor color() const;

    int drawOrder() const;

    /*! \internal */
    explicit KmlScreenOverlay(const std::shared_ptr<QRTImpl::KmlNodeImpl>& impl, QObject* parent = nullptr);

  private:
    Q_DISABLE_COPY(KmlScreenOverlay)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_KmlScreenOverlay_H
