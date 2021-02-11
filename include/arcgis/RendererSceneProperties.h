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
/// \file RendererSceneProperties.h

#ifndef QRT_RendererSceneProperties_H
#define QRT_RendererSceneProperties_H

// C++ API headers
#include "SceneViewTypes.h"

// Qt headers
#include <QString>

// STL headers
#include <memory>

namespace QRTImpl { class RendererScenePropertiesImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class RendererSceneProperties
  {
  public:
    RendererSceneProperties();
    RendererSceneProperties(const QString& extrusionExpression, ExtrusionMode extrusionMode);
    RendererSceneProperties(const QString& headingExpression, const QString& pitchExpression, const QString& rollExpression);
    RendererSceneProperties(const RendererSceneProperties& other);
    RendererSceneProperties(RendererSceneProperties&& other) noexcept;
    ~RendererSceneProperties();

    RendererSceneProperties& operator=(const RendererSceneProperties& other);
    RendererSceneProperties& operator=(RendererSceneProperties&& other) noexcept;

    bool isEmpty() const;

    QString extrusionExpression() const;
    void setExtrusionExpression(const QString& extrusionExpression);

    ExtrusionMode extrusionMode() const;
    void setExtrusionMode(ExtrusionMode extrusionMode);

    QString headingExpression() const;
    void setHeadingExpression(const QString& headingExpression);

    QString pitchExpression() const;
    void setPitchExpression(const QString& pitchExpression);

    QString rollExpression() const;
    void setRollExpression(const QString& rollExpression);

    /*! \internal */
    RendererSceneProperties(const std::shared_ptr<QRTImpl::RendererScenePropertiesImpl>& impl);
    std::shared_ptr<QRTImpl::RendererScenePropertiesImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::RendererScenePropertiesImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_RendererSceneProperties_H
