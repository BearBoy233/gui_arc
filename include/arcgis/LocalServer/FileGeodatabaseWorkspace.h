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
/// \file FileGeodatabaseWorkspace.h

#ifndef QRT_FileGeodatabaseWorkspace_H
#define QRT_FileGeodatabaseWorkspace_H

// C++ API headers
#include "DynamicWorkspace.h"

namespace Esri {
namespace ArcGISRuntime {

  class FileGeodatabaseWorkspace : public DynamicWorkspace
  {
    Q_OBJECT

  public:
    FileGeodatabaseWorkspace(const QString& id, const QString& filePath, QObject* parent = nullptr);
    ~FileGeodatabaseWorkspace();

    QString filePath() const;

    /*!
      \internal
    */
    FileGeodatabaseWorkspace(const std::shared_ptr<QRTImpl::DynamicWorkspaceImpl>& impl, QObject* parent = nullptr);

  private:
    Q_DISABLE_COPY(FileGeodatabaseWorkspace)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_FileGeodatabaseWorkspace_H
