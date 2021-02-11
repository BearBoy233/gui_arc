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
/// \file RemoteResource.h

#ifndef QRT_RemoteResource_H
#define QRT_RemoteResource_H

// C++ API headers
#include "Credential.h"
#include "RequestConfiguration.h"

namespace Esri {
namespace ArcGISRuntime {

  class RemoteResource
  {

  public:
    virtual ~RemoteResource();

    // Derived classes have to override
    virtual Credential* credential() const = 0;
    virtual QUrl url() const = 0;
    virtual RequestConfiguration requestConfiguration() const = 0;
    virtual void setRequestConfiguration(const RequestConfiguration& requestConfiguration) = 0;
  };
}
}
#endif // QRT_RemoteResourceImpl_H
