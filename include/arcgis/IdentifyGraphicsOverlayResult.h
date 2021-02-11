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
/// \file IdentifyGraphicsOverlayResult.h

#ifndef QRT_IdentifyGraphicsOverlayResult_H
#define QRT_IdentifyGraphicsOverlayResult_H

// C++ API headers
#include "Graphic.h"
#include "GraphicsOverlay.h"
#include "Object.h"
#include "Popup.h"

namespace QRTImpl { class IdentifyGraphicsOverlayResultImpl; }

namespace Esri {
namespace ArcGISRuntime {

class IdentifyGraphicsOverlayResult : public Object
{
  Q_OBJECT

public:
  ~IdentifyGraphicsOverlayResult();

  Error error() const;

  QList<Graphic*> graphics() const;

  GraphicsOverlay* graphicsOverlay() const;

  QList<Popup*> popups() const;

  /*!
     \internal
   */
  IdentifyGraphicsOverlayResult(const std::shared_ptr<QRTImpl::IdentifyGraphicsOverlayResultImpl>& impl, QObject* parent = nullptr);
  std::shared_ptr<QRTImpl::IdentifyGraphicsOverlayResultImpl> getImpl() const;

private:
  Q_DISABLE_COPY(IdentifyGraphicsOverlayResult)

  std::shared_ptr<QRTImpl::IdentifyGraphicsOverlayResultImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

Q_DECLARE_METATYPE(Esri::ArcGISRuntime::IdentifyGraphicsOverlayResult*)

#endif // QRT_IdentifyGraphicsOverlayResult_H
