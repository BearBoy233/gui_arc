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
/// \file EncEnvironmentSettings.h

#ifndef QRT_EncEnvironmentSettings_H
#define QRT_EncEnvironmentSettings_H

// C++ API headers
#include "EncDisplaySettings.h"
#include "Object.h"

namespace QRTImpl { class EncEnvironmentSettingsImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class EncEnvironmentSettings : public Object
  {
    Q_OBJECT

  public:
    ~EncEnvironmentSettings();

    static EncEnvironmentSettings* instance();

    static EncDisplaySettings* displaySettings();

    static QString resourcePath();
    static void setResourcePath(const QString& path);

    static QString sencDataPath();
    static void setSencDataPath(const QString& path);

  private:
    Q_DISABLE_COPY(EncEnvironmentSettings)

    explicit EncEnvironmentSettings(QObject* parent = nullptr);
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_EncEnvironmentSettings_H
