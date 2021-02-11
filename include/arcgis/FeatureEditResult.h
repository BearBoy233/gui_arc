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
/// \file FeatureEditResult.h

#ifndef QRT_FeatureEditResult_H
#define QRT_FeatureEditResult_H

// C++ API headers
#include "EditResult.h"

namespace QRTImpl { class FeatureEditResultImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class FeatureEditResult : public EditResult
  {
    Q_OBJECT

  public:
    ~FeatureEditResult();

  QList<EditResult*> attachmentResults() const;

  FeatureEditResult(const std::shared_ptr<QRTImpl::FeatureEditResultImpl>& impl, QObject* parent = nullptr);
  std::shared_ptr<QRTImpl::FeatureEditResultImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(FeatureEditResult)

    FeatureEditResult() = delete;
  };

} // namespace ArcGISRuntime
} // namespace Esri

Q_DECLARE_METATYPE(Esri::ArcGISRuntime::FeatureEditResult*)

#endif // QRT_FeatureEditResult_H
