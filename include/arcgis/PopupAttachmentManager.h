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
/// \file PopupAttachmentManager.h

#ifndef QRT_PopupAttachmentManager_H
#define QRT_PopupAttachmentManager_H

// C++ API headers
#include "ArcGISFeature.h"
#include "Object.h"
#include "PopupAttachment.h"
#include "PopupAttachmentListModel.h"

// Qt headers
#include <QList>

namespace QRTImpl { class PopupAttachmentManagerImpl; }

namespace Esri {
namespace ArcGISRuntime {

class PopupAttachmentManager : public Object
{
  Q_OBJECT

  Q_PROPERTY(PopupAttachmentListModel* attachmentsModel READ attachmentsModel)

public:
  explicit PopupAttachmentManager(ArcGISFeature* arcGISFeature, QObject* parent = nullptr);
  ~PopupAttachmentManager();

  PopupAttachmentListModel* attachmentsModel() const;

  QUuid addAttachment(const QUrl& localFilePath, const QString& contentType, const QString& name);
  PopupAttachment* addAttachment(const QImage& image, const QString& contentType, const QString& name);
  PopupAttachment* addAttachment(const QByteArray& data, const QString& contentType, const QString& name);

  void deleteAttachment(PopupAttachment* popupAttachment);

  QList<PopupAttachment*> attachments() const;

  QList<PopupAttachment*> filterAttachments() const;

  QUuid fetchAttachments();

  QUuid applyChanges();
  void revertChanges();

  /*!
     \internal
   */
  PopupAttachmentManager(const std::shared_ptr<QRTImpl::PopupAttachmentManagerImpl>& impl, QObject* parent = nullptr);
  std::shared_ptr<QRTImpl::PopupAttachmentManagerImpl> getImpl() const;

signals:
  void addAttachmentCompleted(QUuid taskId, Esri::ArcGISRuntime::PopupAttachment* popupAttachment);
  void applyChangesCompleted(QUuid taskId, Esri::ArcGISRuntime::Error error);
  void fetchAttachmentsCompleted(QUuid taskId, const QList<Esri::ArcGISRuntime::PopupAttachment*>& popupAttachments);

private:
  PopupAttachmentManager() = delete;
  Q_DISABLE_COPY(PopupAttachmentManager)

  mutable PopupAttachmentListModel* m_attachmentsModel = nullptr;
  std::shared_ptr<QRTImpl::PopupAttachmentManagerImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_PopupAttachmentManager_H
