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
/// \file GeographicTransformationStep.h

#ifndef QRT_GeographicTransformationStep_H
#define QRT_GeographicTransformationStep_H

// Qt headers
#include <QStringList>

// STL headers
#include <memory>

namespace QRTImpl { class GeographicTransformationStepImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class GeographicTransformationStep
  {
  public:
    GeographicTransformationStep();
    explicit GeographicTransformationStep(int wkid);
    explicit GeographicTransformationStep(const QString& wkText);
    GeographicTransformationStep(const GeographicTransformationStep& other);
    GeographicTransformationStep(GeographicTransformationStep&& other) noexcept;
    ~GeographicTransformationStep();

    GeographicTransformationStep& operator=(const GeographicTransformationStep& other);
    GeographicTransformationStep& operator=(GeographicTransformationStep&& other) noexcept;

    bool operator==(const GeographicTransformationStep& other) const;
    bool operator!=(const GeographicTransformationStep& other) const;

    bool isEmpty() const;

    int wkid() const;
    QString wkText() const;

    bool isInverse() const;
    GeographicTransformationStep inverseTransformation() const;

    QStringList projectionEngineFilenames() const;
    bool isMissingProjectionEngineFiles() const;

    /*! \internal */
    explicit GeographicTransformationStep(const std::shared_ptr<QRTImpl::GeographicTransformationStepImpl>& impl);
    std::shared_ptr<QRTImpl::GeographicTransformationStepImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::GeographicTransformationStepImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_GeographicTransformationStep_H
