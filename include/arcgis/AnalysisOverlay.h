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
/// \file AnalysisOverlay.h

#ifndef QRT_AnalysisOverlay_H
#define QRT_AnalysisOverlay_H

// C++ API headers
#include "AnalysisListModel.h"
#include "Object.h"

namespace QRTImpl { class AnalysisOverlayImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class AnalysisOverlay : public Object
  {
    Q_OBJECT

  public:
    AnalysisOverlay(QObject* parent = nullptr);
    ~AnalysisOverlay();

    bool isVisible() const;
    void setVisible(bool visible);

    AnalysisListModel* analyses() const;

    explicit AnalysisOverlay(const std::shared_ptr<QRTImpl::AnalysisOverlayImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::AnalysisOverlayImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(AnalysisOverlay)

    std::shared_ptr<QRTImpl::AnalysisOverlayImpl> m_impl;
  };
} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_AnalysisOverlay_H
