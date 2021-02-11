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
/// \file ArcGISRuntimeEnvironment.h

#ifndef QRT_ArcGISRuntimeEnvironment_H
#define QRT_ArcGISRuntimeEnvironment_H

// C++ API headers
#include "CoreTypes.h"
#include "License.h"
#include "LicenseInfo.h"
#include "LicenseResult.h"
#include "Object.h"

// Qt headers
#include <QDateTime>

namespace Esri {
namespace ArcGISRuntime {

  class ArcGISRuntimeEnvironment : public Object
  {
    Q_OBJECT

  public:
    ~ArcGISRuntimeEnvironment();

    static ArcGISRuntimeEnvironment* instance();

    static bool initialize();

    static QString installDirectory();
    static void setInstallDirectory(const QString& installDirectory);

    static bool isInstallOk();

    static LicenseResult setLicense(const QString& licenseKey);
    static LicenseResult setLicense(const QString& licenseKey, const QStringList& extensions);
    static LicenseResult setLicense(const LicenseInfo& licenseInfo);
    static License* license();

  private:
    Q_DISABLE_COPY(ArcGISRuntimeEnvironment)
    ArcGISRuntimeEnvironment(QObject* parent = nullptr);
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ArcGISRuntimeEnvironment_H
