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
/// \file SuggestParameters.h

#ifndef QRT_SuggestParameters_H
#define QRT_SuggestParameters_H

// C++ API headers
#include "ArcGISQt_global.h"
#include "Point.h"

// Qt headers
#include <QStringList>

namespace QRTImpl { class SuggestParametersImpl; }

namespace Esri {
namespace ArcGISRuntime {

class SuggestParameters
{
public:
  SuggestParameters();
  SuggestParameters(const SuggestParameters& other);
  SuggestParameters(SuggestParameters&& other) noexcept;
  ~SuggestParameters();
  SuggestParameters& operator=(const SuggestParameters& other);
  SuggestParameters& operator=(SuggestParameters&& other) noexcept;

  QStringList categories() const;
  void setCategories(const QStringList& categories);

  QString countryCode() const;
  void setCountryCode(const QString& countryCode);

  int maxResults() const;
  void setMaxResults(int maxResults);

  Point preferredSearchLocation() const;
  void setPreferredSearchLocation(const Point& preferredSearchLocation);

  Geometry searchArea() const;
  void setSearchArea(const Geometry& searchArea);

  /*!
     \internal
   */
  explicit SuggestParameters(const std::shared_ptr<QRTImpl::SuggestParametersImpl>& impl);
  std::shared_ptr<QRTImpl::SuggestParametersImpl> getImpl() const;

private:
  std::shared_ptr<QRTImpl::SuggestParametersImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_SuggestParameters_H
