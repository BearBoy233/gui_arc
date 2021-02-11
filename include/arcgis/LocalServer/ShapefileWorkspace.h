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
/// \file ShapefileWorkspace.h

#ifndef QRT_ShapefileWorkspace_H
#define QRT_ShapefileWorkspace_H

// C++ API headers
#include "DynamicWorkspace.h"

namespace Esri {
namespace ArcGISRuntime {

  class ShapefileWorkspace : public DynamicWorkspace
  {
    Q_OBJECT

  public:
    ShapefileWorkspace(const QString& id, const QString& folderPath, QObject* parent = nullptr);
    ~ShapefileWorkspace();

    QString folderPath() const;

    /*!
      \internal
    */
    ShapefileWorkspace(const std::shared_ptr<QRTImpl::DynamicWorkspaceImpl>& impl, QObject* parent = nullptr);

  private:
    Q_DISABLE_COPY(ShapefileWorkspace)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ShapefileWorkspace_H
