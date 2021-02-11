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
/// \file Analysis.h

#ifndef QRT_Analysis_H
#define QRT_Analysis_H

// C++ API headers
#include "Object.h"
#include "SceneViewTypes.h"

namespace QRTImpl { class AnalysisImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class Analysis : public Object
  {
    Q_OBJECT

  public:
    ~Analysis();

    bool isVisible() const;
    void setVisible(bool visible);

    AnalysisType analysisType() const;

    /*! \internal */
    explicit Analysis(const std::shared_ptr<QRTImpl::AnalysisImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::AnalysisImpl> getImpl() const;

  protected:
    std::shared_ptr<QRTImpl::AnalysisImpl> m_impl;

  private:
    Q_DISABLE_COPY(Analysis)
    Analysis() = delete;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_Analysis_H
