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
/// \file PortalFolder.h

#ifndef QRT_PortalFolder_H
#define QRT_PortalFolder_H

// C++ API headers
#include "ErrorTypes.h"

// Qt headers
#include <QDateTime>
#include <QMetaType>
#include <QString>

// STL headers
#include <memory>

namespace QRTImpl { class PortalFolderImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class Portal;

  class PortalFolder
  {
  public:
    PortalFolder();
    PortalFolder(const PortalFolder& other);
    PortalFolder(PortalFolder&& other) noexcept;
    PortalFolder& operator=(const PortalFolder& other);
    PortalFolder& operator=(PortalFolder&& other) noexcept;
    ~PortalFolder();

    QDateTime created() const;

    QString folderId() const;

    QString title() const;

    /*!
       \internal
     */
    PortalFolder(const std::shared_ptr<QRTImpl::PortalFolderImpl>& impl);

    std::shared_ptr<QRTImpl::PortalFolderImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::PortalFolderImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

Q_DECLARE_METATYPE(Esri::ArcGISRuntime::PortalFolder)

#endif // QRT_PortalFolder_H
