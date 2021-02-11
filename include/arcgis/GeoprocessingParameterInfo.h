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
/// \file GeoprocessingParameterInfo.h

#ifndef QRT_GeoprocessingParameterInfo_H
#define QRT_GeoprocessingParameterInfo_H

// C++ API headers
#include "GeoprocessingParameter.h"
#include "GeoprocessingTypes.h"

// Qt headers
#include <QString>

// STL headers
#include <memory>

namespace QRTImpl { class GeoprocessingParameterInfoImpl; }

namespace Esri {
namespace ArcGISRuntime {

class GeoprocessingParameterInfo
{
public:
  GeoprocessingParameterInfo();
  GeoprocessingParameterInfo(const GeoprocessingParameterInfo& other);
  GeoprocessingParameterInfo(GeoprocessingParameterInfo&& other) noexcept;
  ~GeoprocessingParameterInfo();

  GeoprocessingParameterInfo& operator=(const GeoprocessingParameterInfo& other);
  GeoprocessingParameterInfo& operator=(GeoprocessingParameterInfo&& other) noexcept;

  bool isEmpty() const;

  QString category() const;

  QString description() const;

  QStringList choiceList() const;

  GeoprocessingParameterType dataType() const;

  GeoprocessingParameterDirection direction() const;

  QString displayName() const;

  bool isRequired() const;

  QString name() const;

  bool isFeaturesRequireGeometry() const;

  GeoprocessingParameterType multiValueDataType() const;

  GeoprocessingParameter* defaultParameter(QObject* parent = nullptr) const;

  /*!
     \internal
   */
  GeoprocessingParameterInfo(const std::shared_ptr<QRTImpl::GeoprocessingParameterInfoImpl>& impl);
  std::shared_ptr<QRTImpl::GeoprocessingParameterInfoImpl> getImpl() const;

private:
  std::shared_ptr<QRTImpl::GeoprocessingParameterInfoImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_GeoprocessingParameterInfo_H
