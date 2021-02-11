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
/// \file LabelingInfo.h

#ifndef QRT_LabelingInfo_H
#define QRT_LabelingInfo_H

// C++ API headers
#include "ServiceTypes.h"
#include "TextSymbol.h"

namespace QRTImpl { class LabelingInfoImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class LabelingInfo
  {
  public:
    LabelingInfo();
    LabelingInfo(const LabelingInfo& other);
    LabelingInfo(LabelingInfo&& other) noexcept;
    ~LabelingInfo();

    LabelingInfo& operator=(const LabelingInfo& other);
    LabelingInfo& operator=(LabelingInfo&& other) noexcept;

    bool isEmpty() const;

    QString labelExpression() const;

    LabelingPlacement labelPlacement() const;

    double maxScale() const;

    double minScale() const;

    TextSymbol* symbol(QObject* parent = nullptr) const;

    bool isUseCodedValues() const;

    QString where() const;

    LabelingInfo(const std::shared_ptr<QRTImpl::LabelingInfoImpl>& impl);
    std::shared_ptr<QRTImpl::LabelingInfoImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::LabelingInfoImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_LabelingInfo_H
