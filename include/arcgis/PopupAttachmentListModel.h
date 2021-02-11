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
/// \file PopupAttachmentListModel.h

#ifndef QRT_PopupAttachmentListModel_H
#define QRT_PopupAttachmentListModel_H

// C++ API headers
#include "CoreTypes.h"

// Qt headers
#include <QAbstractListModel>
#include <QList>

namespace Esri {
namespace ArcGISRuntime {

  class PopupAttachmentManager;
  class PopupAttachment;

  class PopupAttachmentListModel : public QAbstractListModel
  {
    Q_OBJECT

    Q_PROPERTY(int count READ rowCount NOTIFY countChanged)
    Q_PROPERTY(int thumbnailWidth READ thumbnailWidth NOTIFY thumbnailWidthChanged)
    Q_PROPERTY(int thumbnailHeight READ thumbnailHeight NOTIFY thumbnailHeightChanged)

  public:

    enum PopupAttachmentRoles
    {
      PopupAttachmentNameRole = Qt::DisplayRole,
      PopupAttachmentContentTypeRole = Qt::UserRole + 1,
      PopupAttachmentSizeRole = Qt::UserRole + 2,
      PopupAttachmentLocalRole = Qt::UserRole + 3,
      PopupAttachmentAttachmentUrlRole = Qt::UserRole + 4,
      PopupAttachmentPopupTypeRole = Qt::UserRole + 5,
      PopupAttachmentEditStateRole = Qt::UserRole + 6,
      PopupAttachmentThumbnailUrlRole = Qt::UserRole + 7,
      PopupAttachmentFullImageUrlRole = Qt::UserRole + 8
    };

    ~PopupAttachmentListModel();

    Esri::ArcGISRuntime::AspectRatioMode thumbnailAspectRatioMode() const;
    void setThumbnailAspectRatioMode(Esri::ArcGISRuntime::AspectRatioMode thumbnailAspectRatioMode);

    int thumbnailWidth() const;
    void setThumbnailWidth(int thumbnailWidth);

    int thumbnailHeight() const;
    void setThumbnailHeight(int thumbnailHeight);

    bool autoLoad() const;
    void setAutoLoad(bool autoLoad);

    bool autoFetchThumbnails() const;
    void setAutoFetchThumbnails(bool autoFetchThumbnails);

    bool autoFetchFullImages() const;
    void setAutoFetchFullImages(bool autoFetchFullImages);

    bool applyFilter() const;
    void setApplyFilter(bool applyFilter);

    int size() const;

    PopupAttachment* at(int index) const;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    explicit PopupAttachmentListModel(PopupAttachmentManager* popupAttachmentManager, QObject* parent = nullptr);

  signals:
    void countChanged();
    void thumbnailWidthChanged();
    void thumbnailHeightChanged();

  protected:
    QHash<int, QByteArray> roleNames() const override;

  private:
    Q_DISABLE_COPY(PopupAttachmentListModel)

    void connectSignals();
    void setupRoles();
    void connectAttachmentSignals(PopupAttachment* attachment, const QModelIndex& index) const;
    void reset();
    void updateAndRefresh();

    QHash<int, QByteArray> m_roles;

    PopupAttachmentManager* m_popupAttachmentManager = nullptr;
    bool m_autoLoad = true;
    bool m_autoFetchThumbnails = true;
    bool m_autoFetchFullImages = true;
    bool m_applyFilter = false;
    int m_thumbnailWidth  = 64;
    int m_thumbnailHeight = 64;
    Esri::ArcGISRuntime::AspectRatioMode m_thumbnailAspectRatioMode = Esri::ArcGISRuntime::AspectRatioMode::KeepAspectRatio;
    QList<PopupAttachment*> m_attachments;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_PopupAttachmentListModel_H
