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
/// \file IdentifyLayerResult.h

#ifndef QRT_IdentifyLayerResult_H
#define QRT_IdentifyLayerResult_H

// C++ API headers
#include "GeoElement.h"
#include "Layer.h"
#include "Object.h"
#include "Popup.h"

namespace QRTImpl { class IdentifyLayerResultImpl; }

namespace Esri {
namespace ArcGISRuntime {

class IdentifyLayerResult : public Object
{
  Q_OBJECT

public:
  ~IdentifyLayerResult();

  Error error() const;

  QList<GeoElement*> geoElements() const;

  bool isTransferLimitExceeded() const;

  LayerContent* layerContent() const;

  QList<Popup*> popups() const;

  QList<IdentifyLayerResult*> sublayerResults() const;

  /*!
     \internal
   */
  IdentifyLayerResult(const std::shared_ptr<QRTImpl::IdentifyLayerResultImpl>& impl, QObject* parent = nullptr);
  std::shared_ptr<QRTImpl::IdentifyLayerResultImpl> getImpl() const;

private:
  Q_DISABLE_COPY(IdentifyLayerResult)

  std::shared_ptr<QRTImpl::IdentifyLayerResultImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

Q_DECLARE_METATYPE(Esri::ArcGISRuntime::IdentifyLayerResult*)

#endif // QRT_IdentifyLayerResult_H
