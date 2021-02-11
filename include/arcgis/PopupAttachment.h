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
/// \file PopupAttachment.h

#ifndef QRT_PopupAttachment_H
#define QRT_PopupAttachment_H

// C++ API headers
#include "Attachment.h"
#include "CoreTypes.h"
#include "Loadable.h"
#include "Object.h"
#include "PopupTypes.h"

// Qt headers
#include <QString>
#include <QUrl>

namespace QRTImpl { class PopupAttachmentImpl; }

namespace Esri {
namespace ArcGISRuntime {

class PopupAttachment : public Object, public Loadable
{
  Q_OBJECT

public:
  ~PopupAttachment();

  QString contentType() const;

  bool isLocal() const;

  QString name() const;

  qint64 size() const;

  QUrl attachmentUrl() const;

  Attachment* attachment() const;

  PopupAttachmentType popupType() const;

  PopupAttachmentEditState editState() const;

  QUuid thumbnail(int width, int height, AspectRatioMode aspectRatioMode = AspectRatioMode::KeepAspectRatio);

  QUuid fullImage();

  Error loadError() const override;
  LoadStatus loadStatus() const override;
  void cancelLoad() override;
  void load() override;
  void retryLoad() override;

  /*!
     \internal
   */
  PopupAttachment(const std::shared_ptr<QRTImpl::PopupAttachmentImpl>& impl, QObject* parent = nullptr);
  std::shared_ptr<QRTImpl::PopupAttachmentImpl> getImpl() const;

signals:
  void thumbnailCompleted(QUuid taskId, const QImage& thumbnail);
  void fullImageCompleted(QUuid taskId, const QImage& fullImage);
  void doneLoading(Esri::ArcGISRuntime::Error error);
  void loadStatusChanged(Esri::ArcGISRuntime::LoadStatus loadStatus);

private:
  PopupAttachment() = delete;
  Q_DISABLE_COPY(PopupAttachment)

  std::shared_ptr<QRTImpl::PopupAttachmentImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_PopupAttachment_H
