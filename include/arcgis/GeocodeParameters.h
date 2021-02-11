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
/// \file GeocodeParameters.h

#ifndef QRT_GeocodeParameters_H
#define QRT_GeocodeParameters_H

// C++ API headers
#include "ArcGISQt_global.h"
#include "Point.h"
#include "SpatialReference.h"

// Qt headers
#include <QStringList>

namespace QRTImpl { class GeocodeParametersImpl; }

namespace Esri {
namespace ArcGISRuntime {

class GeocodeParameters
{
public:
  GeocodeParameters();
  GeocodeParameters(const GeocodeParameters& other);
  GeocodeParameters(GeocodeParameters&& other) noexcept;
  ~GeocodeParameters();
  GeocodeParameters& operator=(const GeocodeParameters& other);
  GeocodeParameters& operator=(GeocodeParameters&& other) noexcept;

  QStringList resultAttributeNames() const;
  void setResultAttributeNames(const QStringList& resultAttributeNames);

  QStringList categories() const;
  void setCategories(const QStringList& categories);

  QString countryCode() const;
  void setCountryCode(const QString& countryCode);

  bool isForStorage() const;
  void setForStorage(bool forStorage);

  int maxResults() const;
  void setMaxResults(int maxResults);

  double minScore() const;
  void setMinScore(double minScore);

  QString outputLanguageCode() const;
  void setOutputLanguageCode(const QString& outputLanguageCode);

  SpatialReference outputSpatialReference() const;
  void setOutputSpatialReference(const SpatialReference& outputSpatialReference);

  Point preferredSearchLocation() const;
  void setPreferredSearchLocation(const Point& preferredSearchLocation);

  Geometry searchArea() const;
  void setSearchArea(const Geometry& searchArea);

  /*!
     \internal
   */
  explicit GeocodeParameters(const std::shared_ptr<QRTImpl::GeocodeParametersImpl>& impl);
  std::shared_ptr<QRTImpl::GeocodeParametersImpl> getImpl() const;

private:
  std::shared_ptr<QRTImpl::GeocodeParametersImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_GeocodeParameters_H
