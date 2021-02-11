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
/// \file DynamicWorkspace.h

#ifndef QRT_DynamicWorkspace_H
#define QRT_DynamicWorkspace_H

// C++ API headers
#include "Object.h"

#ifndef LOCALSERVER_SUPPORTED
#error "Local Server is not supported on this platform."
#endif

#include "LocalServerTypes.h"

namespace QRTImpl {
  class DynamicWorkspaceImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class DynamicWorkspace : public Object
  {
    Q_OBJECT

  public:
    ~DynamicWorkspace();

    QString id() const;

    DynamicWorkspaceType dynamicWorkspaceType() const;

    /*!
      \internal
    */
    explicit DynamicWorkspace(const std::shared_ptr<QRTImpl::DynamicWorkspaceImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::DynamicWorkspaceImpl> getImpl() const;

  protected:
    std::shared_ptr<QRTImpl::DynamicWorkspaceImpl> m_impl;

  private:
    Q_DISABLE_COPY(DynamicWorkspace)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_DynamicWorkspace_H
