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
/// \file Attachment.h

#ifndef QRT_Attachment_H
#define QRT_Attachment_H

// C++ API headers
#include "Object.h"
#include "TaskWatcher.h"

// Qt headers
#include <QUuid>

namespace QRTImpl { class AttachmentImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class Attachment : public Object
  {
    Q_OBJECT

  public:
    ~Attachment();

    qint64 attachmentId() const;

    QString contentType() const;

    bool isDataFetched() const;

    QString name() const;

    qint64 size() const;

    QUrl attachmentUrl() const;

    TaskWatcher fetchData();

    Attachment(const std::shared_ptr<QRTImpl::AttachmentImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::AttachmentImpl> getImpl() const;

  signals:
    void fetchDataCompleted(QUuid taskId, const QByteArray& data);

  private:
    Q_DISABLE_COPY(Attachment)

    Attachment() = delete;

    void connectSignals();

    std::shared_ptr<QRTImpl::AttachmentImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_Attachment_H
