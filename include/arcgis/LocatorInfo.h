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
/// \file LocatorInfo.h

#ifndef QRT_LocatorInfo_H
#define QRT_LocatorInfo_H

// C++ API headers
#include "ArcGISQt_global.h"
#include "LocatorAttribute.h"
#include "SpatialReference.h"

// Qt headers
#include <QVariantMap>

namespace QRTImpl { class LocatorInfoImpl; }

namespace Esri {
namespace ArcGISRuntime {

class LocatorInfo
{
public:
  LocatorInfo();
  LocatorInfo(const LocatorInfo& other);
  LocatorInfo(LocatorInfo&& other) noexcept;
  LocatorInfo& operator=(const LocatorInfo& other);
  LocatorInfo& operator=(LocatorInfo&& other) noexcept;
  ~LocatorInfo();

  QList<LocatorAttribute> resultAttributes() const;

  QList<LocatorAttribute> intersectionResultAttributes() const;

  QList<LocatorAttribute> searchAttributes() const;

  QVariantMap properties() const;

  SpatialReference spatialReference() const;

  bool isSupportsIntersections() const;

  bool isSupportsPoi() const;

  bool isSupportsAddresses() const;

  bool isSupportsSuggestions() const;

  QString version() const;

  QString name() const;

  QString description() const;

  bool isEmpty() const;

  /*!
     \internal
   */
  LocatorInfo(const std::shared_ptr<QRTImpl::LocatorInfoImpl>& impl);
  std::shared_ptr<QRTImpl::LocatorInfoImpl> getImpl() const;

private:
  std::shared_ptr<QRTImpl::LocatorInfoImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_LocatorInfo_H
