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
/// \file PortalResult.h

#ifndef QRT_PortalResult_H
#define QRT_PortalResult_H

// C++ API headers
#include "Error.h"

// Qt headers
#include <QStringList>

namespace QRTImpl {
  class PortalResultImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class PortalResult
  {
  public:
    PortalResult();

    PortalResult(const PortalResult& other);

    PortalResult(PortalResult&& other) noexcept;

    virtual ~PortalResult();

    PortalResult& operator=(const PortalResult& other);

    PortalResult& operator=(PortalResult&& other) noexcept;

    QString itemId() const;

    bool isSuccess() const;

    Error error() const;

    /*!
       \internal
     */
    explicit PortalResult(const std::shared_ptr<QRTImpl::PortalResultImpl>& impl);
    std::shared_ptr<QRTImpl::PortalResultImpl> getImpl() const;

  protected:
    std::shared_ptr<QRTImpl::PortalResultImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

Q_DECLARE_METATYPE(Esri::ArcGISRuntime::PortalResult)

#endif // QRT_PortalResult_H
