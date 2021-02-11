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
/// \file OfflineMapItemInfo.h

#ifndef QRT_OfflineMapItemInfo_H
#define QRT_OfflineMapItemInfo_H

// C++ API headers
#include "ArcGISQt_global.h"

// Qt headers
#include <QImage>
#include <QString>

// STL headers
#include <memory>

namespace QRTImpl { class OfflineMapItemInfoImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class OfflineMapItemInfo
  {
  public:
    OfflineMapItemInfo();
    OfflineMapItemInfo(const OfflineMapItemInfo& other);
    OfflineMapItemInfo(OfflineMapItemInfo&& other) noexcept;
    ~OfflineMapItemInfo();

    OfflineMapItemInfo& operator=(const OfflineMapItemInfo& other);
    OfflineMapItemInfo& operator=(OfflineMapItemInfo&& other) noexcept;

    QString accessInformation() const;
    void setAccessInformation(const QString& accessInformation);

    QString description() const;
    void setDescription(const QString& description);

    QString snippet() const;
    void setSnippet(const QString& snippet);

    QStringList tags() const;
    void setTags(const QStringList& tags);

    QString termsOfUse() const;
    void setTermsOfUse(const QString& termsOfUse);

    QImage thumbnail() const;
    void setThumbnail(const QImage& thumbnail);

    QString title() const;
    void setTitle(const QString& title);

    /*!
       \internal
     */
    OfflineMapItemInfo(const std::shared_ptr<QRTImpl::OfflineMapItemInfoImpl>& impl);
    std::shared_ptr<QRTImpl::OfflineMapItemInfoImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::OfflineMapItemInfoImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_OfflineMapItemInfo_H
