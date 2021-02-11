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
/// \file DrawingInfo.h

#ifndef QRT_DrawingInfo_H
#define QRT_DrawingInfo_H

// C++ API headers
#include "LabelingInfo.h"
#include "Renderer.h"

namespace QRTImpl { class DrawingInfoImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class DrawingInfo
  {
  public:
    DrawingInfo();
    DrawingInfo(const DrawingInfo& other);
    DrawingInfo(DrawingInfo&& other) noexcept;
    ~DrawingInfo();

    DrawingInfo& operator=(const DrawingInfo& other);
    DrawingInfo& operator=(DrawingInfo&& other) noexcept;

    bool isEmpty() const;

    QList<LabelingInfo> labelingInfos() const;

    Renderer* renderer(QObject* parent = nullptr) const;

    bool isScaleSymbols() const;

    bool isShowLabels() const;

    double transparency() const;

    /*!
       \internal
     */
    DrawingInfo(const std::shared_ptr<QRTImpl::DrawingInfoImpl>& impl);
    std::shared_ptr<QRTImpl::DrawingInfoImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::DrawingInfoImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_DrawingInfo_H
