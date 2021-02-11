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
/// \file ReverseGeocodeParameters.h

#ifndef QRT_ReverseGeocodeParameters_H
#define QRT_ReverseGeocodeParameters_H

// C++ API headers
#include "ArcGISQt_global.h"
#include "SpatialReference.h"

// Qt headers
#include <QStringList>

namespace QRTImpl { class ReverseGeocodeParametersImpl; }

namespace Esri {
namespace ArcGISRuntime {

class ReverseGeocodeParameters
{
public:
  ReverseGeocodeParameters();
  ReverseGeocodeParameters(const ReverseGeocodeParameters& other);
  ReverseGeocodeParameters(ReverseGeocodeParameters&& other);
  ~ReverseGeocodeParameters();
  ReverseGeocodeParameters& operator=(const ReverseGeocodeParameters& other);
  ReverseGeocodeParameters& operator=(ReverseGeocodeParameters&& other);

  QStringList resultAttributeNames() const;
  void setResultAttributeNames(const QStringList& resultAttributeNames);

  QStringList featureTypes() const;
  void setFeatureTypes(const QStringList& featureTypes);

  bool isForStorage() const;
  void setForStorage(bool forStorage);

  int maxResults() const;
  void setMaxResults(int maxResults);

  double maxDistance() const;
  void setMaxDistance(double maxDistance);

  QString outputLanguageCode() const;
  void setOutputLanguageCode(const QString& outputLanguageCode);

  SpatialReference outputSpatialReference() const;
  void setOutputSpatialReference(const SpatialReference& outputSpatialReference);

  /*!
     \internal
   */
  explicit ReverseGeocodeParameters(const std::shared_ptr<QRTImpl::ReverseGeocodeParametersImpl>& impl);
  std::shared_ptr<QRTImpl::ReverseGeocodeParametersImpl> getImpl() const;

private:
  std::shared_ptr<QRTImpl::ReverseGeocodeParametersImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ReverseGeocodeParameters_H
