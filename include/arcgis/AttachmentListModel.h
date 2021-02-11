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
/// \file AttachmentListModel.h

#ifndef QRT_AttachmentListModel_H
#define QRT_AttachmentListModel_H

// C++ API headers
#include "ArcGISQt_global.h"
#include "Attachment.h"
#include "TaskWatcher.h"

// Qt headers
#include <QAbstractListModel>
#include <QFile>

// STL headers
#include <memory>

namespace QRTImpl { class ArcGISFeatureImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class AttachmentListModel : public QAbstractListModel
  {
    Q_OBJECT

  public:

    enum AttachmentRoles
    {
      AttachmentNameRole = Qt::UserRole + 1,
      AttachmentContentTypeRole = Qt::UserRole + 2,
      AttachmentDataFetchedRole = Qt::UserRole + 3,
      AttachmentSizeRole = Qt::UserRole + 4,
      AttachmentUrlRole = Qt::UserRole + 5,
      AttachmentIdRole = Qt::UserRole + 6
    };

    ~AttachmentListModel();

    bool isAutoFetchAttachments() const;
    void setAutoFetchAttachments(bool autoFetchAttachments);

    bool isAutoApplyEdits() const;
    void setAutoApplyEdits(bool autoApplyEdits);

    TaskWatcher addAttachment(QFile* file, const QString& contentType, const QString& name);
    TaskWatcher deleteAttachment(Attachment* attachment);
    TaskWatcher deleteAttachment(int index);
    TaskWatcher deleteAttachments(const QList<Attachment*>& attachments);
    TaskWatcher deleteAttachments(int index, int count = 1);
    TaskWatcher fetchAttachments();
    TaskWatcher updateAttachment(Attachment* attachment, QFile* file, const QString& contentType, const QString& name);
    TaskWatcher updateAttachment(int index, QFile* file, const QString& contentType, const QString& name);

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;

    bool removeRows(int row, int count, const QModelIndex& parent = QModelIndex()) override;

    AttachmentListModel(const std::shared_ptr<QRTImpl::ArcGISFeatureImpl>& impl, QObject* parent = nullptr);

  signals:
    void addAttachmentCompleted(QUuid taskId, Esri::ArcGISRuntime::Attachment* attachment);
    void deleteAttachmentCompleted(QUuid taskId);
    void deleteAttachmentsCompleted(QUuid taskId);
    void fetchAttachmentsCompleted(QUuid taskId, const QList<Esri::ArcGISRuntime::Attachment*>& attachments);
    void updateAttachmentCompleted(QUuid taskId);
    void errorOccurred(Error error);

  protected:
    QHash<int, QByteArray> roleNames() const override;

  private:
    Q_DISABLE_COPY(AttachmentListModel)

    AttachmentListModel() = delete;

    void connectSignals();
    void setupRoles();
    void updateAttachmentsInternal();

    std::shared_ptr<QRTImpl::ArcGISFeatureImpl> m_impl;

    QHash<int, QByteArray> m_roles;
    bool m_autoFetchAttachments;
    bool m_autoApplyEdits;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_AttachmentListModel_H
