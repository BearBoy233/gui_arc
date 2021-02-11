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
/// \file LocalFeatureService.h

#ifndef QRT_LocalFeatureService_H
#define QRT_LocalFeatureService_H

// C++ API headers
#include "Object.h"

#ifndef LOCALSERVER_SUPPORTED
#error "Local Server is not supported on this platform."
#endif

#include "LocalMapService.h"
#include <QUrl>

namespace QRTImpl {
  class LocalFeatureServiceImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class LocalFeatureService : public LocalMapService
  {
    Q_OBJECT

  public:
    LocalFeatureService(const QString& packagePath, QObject* parent = nullptr);

    ~LocalFeatureService();

    QUrl mapServiceUrl() const;

    QUrl url() const override;

    bool isZDefaultEnabled() const;
    void setZDefaultEnabled(bool zDefaultEnabled);

    double zDefaultValue() const;
    void setZDefaultValue(double zDefaultValue);

    /*! \internal */
    LocalFeatureService(const std::shared_ptr<QRTImpl::LocalFeatureServiceImpl>& impl, QObject* parent = nullptr);

  private:
    Q_DISABLE_COPY(LocalFeatureService)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_LocalFeatureService_H
