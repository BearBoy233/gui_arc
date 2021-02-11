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
/// \file EnterpriseGeodatabaseWorkspace.h

#ifndef QRT_EnterpriseGeodatabaseWorkspace_H
#define QRT_EnterpriseGeodatabaseWorkspace_H

// C++ API headers
#include "DynamicWorkspace.h"

namespace Esri {
namespace ArcGISRuntime {

  class EnterpriseGeodatabaseWorkspace : public DynamicWorkspace
  {
    Q_OBJECT

  public:
    static EnterpriseGeodatabaseWorkspace* createFromConnectionFile(const QString& id,
                                                                    const QString& connectionFilePath,
                                                                    bool lockVersion,
                                                                    QObject* parent = nullptr);

    static EnterpriseGeodatabaseWorkspace* createFromConnectionString(const QString& id,
                                                                      const QString& connectionString,
                                                                      bool lockVersion,
                                                                      QObject* parent = nullptr);

    ~EnterpriseGeodatabaseWorkspace();

    bool isLockVersion() const;

    QString connection() const;

    /*!
      \internal
    */
    EnterpriseGeodatabaseWorkspace(const std::shared_ptr<QRTImpl::DynamicWorkspaceImpl>& impl, QObject* parent = nullptr);

  private:
    Q_DISABLE_COPY(EnterpriseGeodatabaseWorkspace)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_EnterpriseGeodatabaseWorkspace_H
