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
/// \file SpatialReference.h

#ifndef QRT_SpatialReference_H
#define QRT_SpatialReference_H

// C++ API headers
#include "ArcGISQt_global.h"
#include "JsonSerializable.h"

// Qt headers
#include <QMetaType>

// STL headers
#include <memory>

namespace QRTImpl { class SpatialReferenceImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class Unit;
  class Point;

  class SpatialReference : public JsonSerializable
  {

  public:

    SpatialReference();

    SpatialReference(const QString& wktext);

    SpatialReference(int wkid);

    SpatialReference(int wkid, int verticalWkid);

    SpatialReference(const SpatialReference& other);

    SpatialReference(SpatialReference&& other) noexcept;

    ~SpatialReference();

    SpatialReference& operator=(const SpatialReference& other);

    SpatialReference& operator=(SpatialReference&& other) noexcept;

    bool operator==(const SpatialReference& other) const;

    bool operator!=(const SpatialReference& other) const;

    bool isEmpty() const;

    int wkid() const;

    int verticalWkid() const;

    QString wkText() const;

    Unit unit() const;

    bool isGeographic() const;

    bool isProjected() const;

    bool isPannable() const;

    SpatialReference baseGeographic() const;

    double convergenceAngle(const Point& point) const;

    static SpatialReference wgs84();

    static SpatialReference webMercator();

    static SpatialReference fromJson(const QString& json);

    QString toJson() const override;

    QJsonObject unknownJson() const override;

    QJsonObject unsupportedJson() const override;

    /*!
       \internal
     */
    explicit SpatialReference(const std::shared_ptr<QRTImpl::SpatialReferenceImpl>& impl);
    std::shared_ptr<QRTImpl::SpatialReferenceImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::SpatialReferenceImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

Q_DECLARE_METATYPE(Esri::ArcGISRuntime::SpatialReference)

#endif // QRT_SpatialReference_H

