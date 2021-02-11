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
/// \file TravelMode.h

#ifndef QRT_TravelMode_H
#define QRT_TravelMode_H

// C++ API headers
#include "AttributeParameterValue.h"
#include "NetworkAnalystTypes.h"
#include "Object.h"

// Qt headers
#include <QVariantMap>

namespace QRTImpl { class TravelModeImpl; }

namespace Esri {
namespace ArcGISRuntime {

class TravelMode : public QObject
{
  Q_OBJECT

public:
  TravelMode();
  TravelMode(const TravelMode& other);
  TravelMode(TravelMode&& other) noexcept;
  ~TravelMode();

  TravelMode& operator=(const TravelMode& other);
  TravelMode& operator=(TravelMode&& other) noexcept;

  bool isEmpty() const;

  QList<AttributeParameterValue> attributeParameterValues() const;
  void setAttributeParameterValues(const QList<AttributeParameterValue>& attributeParameterValues);

  QString description() const;
  void setDescription(const QString& description);

  QString distanceAttributeName() const;
  void setDistanceAttributeName(const QString& distanceAttributeName);

  QString impedanceAttributeName() const;
  void setImpedanceAttributeName(const QString& impedanceAttributeName);

  QString name() const;
  void setName(const QString& name);

  double outputGeometryPrecision() const;
  void setOutputGeometryPrecision(double outputGeometryPrecision);

  QStringList restrictionAttributeNames() const;
  void setRestrictionAttributeNames(const QStringList& restrictionAttributeNames);

  QString timeAttributeName() const;
  void setTimeAttributeName(const QString& timeAttributename);

  QString type() const;
  void setType(const QString& type);

  UTurnPolicy uTurnPolicy() const;
  void setUTurnPolicy(UTurnPolicy uTurnPolicy);

  bool isUseHierarchy() const;
  void setUseHierarchy(bool useHierarchy);

  /*!
     \internal
   */
  TravelMode(const std::shared_ptr<QRTImpl::TravelModeImpl>& impl);
  std::shared_ptr<QRTImpl::TravelModeImpl> getImpl() const;

private:
  std::shared_ptr<QRTImpl::TravelModeImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_TravelMode_H
