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
/// \file ServiceDocumentInfo.h

#ifndef QRT_ServiceDocumentInfo_H
#define QRT_ServiceDocumentInfo_H

// C++ API headers
#include "ArcGISQt_global.h"
#include "ServiceTypes.h"

// Qt headers
#include <QStringList>

// STL headers
#include <memory>

namespace QRTImpl {
  class ServiceDocumentInfoImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class ServiceDocumentInfo
  {
  public:
    ServiceDocumentInfo();
    ~ServiceDocumentInfo();
    ServiceDocumentInfo(const ServiceDocumentInfo& other);
    ServiceDocumentInfo(ServiceDocumentInfo&& other) noexcept;
    ServiceDocumentInfo& operator=(const ServiceDocumentInfo& other);
    ServiceDocumentInfo& operator=(ServiceDocumentInfo&& other) noexcept;

    AntialiasingMode antialiasingMode() const;

    QString author() const;

    QString category() const;

    QString comments() const;

    QStringList keywords() const;

    QString subject() const;

    TextAntialiasingMode textAntialiasingMode() const;

    QString title() const;

    explicit ServiceDocumentInfo(const std::shared_ptr<QRTImpl::ServiceDocumentInfoImpl>& impl);
    std::shared_ptr<QRTImpl::ServiceDocumentInfoImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::ServiceDocumentInfoImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ServiceDocumentInfo_H
