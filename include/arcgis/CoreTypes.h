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
/// \file CoreTypes.h

#ifndef QRT_CoreTypes_H
#define QRT_CoreTypes_H

// Qt headers
#include <QObject>

namespace Esri {
namespace ArcGISRuntime {

  enum class AuthenticationChallengeType
  {
    Unknown = 0,
    UsernamePassword = 1,
    OAuth = 2,
    ClientCertificate = 3,
    SslHandshake = 4
  };

  enum class AuthenticationType
  {
    Unknown = 0,
    Token = 1,
    HTTP = 2,
    Certificate = 3
  };

  enum class LicenseLevel
  {
    Developer = 0,
    Lite = 1,
    Basic = 2,
    Standard = 3,
    Advanced = 4
  };

  enum class LicenseStatus
  {
    Invalid = 0,
    Expired = 1,
    LoginRequired = 2,
    Valid = 3
  };

  enum class LicenseType
  {
    Developer = 0,
    NamedUser = 1,
    LicenseKey = 2
  };

  enum class OAuthMode
  {
    Unknown = 0,
    User = 1,
    App = 2
  };

  enum class SortOrder
  {
    Ascending = 0,
    Descending = 1
  };

  enum class SpatialRelationship
  {
    Unknown = -1,
    Relate = 0,
    Equals = 1,
    Disjoint = 2,
    Intersects = 3,
    Touches = 4,
    Crosses = 5,
    Within = 6,
    Contains = 7,
    Overlaps = 8,
    EnvelopeIntersects = 9,
    IndexIntersects = 10
  };

  enum class ItemType
  {
    Unknown = -1,
    PortalItem = 0,
    LocalItem = 1
  };

  enum class LocalItemType
  {
    Unknown = -1,
    MobileMap = 0,
    MobileScene = 1,
    MobileMapPackage = 2
  };

  enum class AspectRatioMode
  {
    IgnoreAspectRatio = Qt::AspectRatioMode::IgnoreAspectRatio,
    KeepAspectRatio = Qt::AspectRatioMode::KeepAspectRatio,
    KeepAspectRatioByExpanding = Qt::AspectRatioMode::KeepAspectRatioByExpanding
  };

  enum class UnitSystem
  {
    Imperial = 0,
    Metric = 1
  };

  enum class LoginType
  {
    Unknown = -1,
    OAuth = 0,
    ClientCertificate = 1,
    UsernamePassword = 2
  };

  enum class StatisticType
  {
    Average = 0,
    Count = 1,
    Maximum = 2,
    Minimum = 3,
    StandardDeviation = 4,
    Sum = 5,
    Variance = 6
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_CoreTypes_H
