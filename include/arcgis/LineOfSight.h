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
/// \file LineOfSight.h

#ifndef QRT_LineOfSight_H
#define QRT_LineOfSight_H

// C++ API headers
#include "Analysis.h"

// Qt headers
#include <QColor>

namespace QRTImpl { class LineOfSightImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class LineOfSight : public Analysis
  {
    Q_OBJECT

  public:
    ~LineOfSight();

    LineOfSightTargetVisibility targetVisibility() const;

    static float lineWidth();
    static void setLineWidth(float lineWidth);

    static QColor visibleColor();
    static void setVisibleColor(const QColor& visibleColor);

    static QColor obstructedColor();
    static void setObstructedColor(const QColor& obstructedColor);

    /*! \internal */
    explicit LineOfSight(const std::shared_ptr<QRTImpl::LineOfSightImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::LineOfSightImpl> getImpl() const;

  signals:
    void targetVisibilityChanged(Esri::ArcGISRuntime::LineOfSightTargetVisibility targetVisibility);

  private:
    Q_DISABLE_COPY(LineOfSight)
    LineOfSight() = delete;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_LineOfSight_H
