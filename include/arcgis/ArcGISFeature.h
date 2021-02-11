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
/// \file ArcGISFeature.h

#ifndef QRT_ArcGISFeature_H
#define QRT_ArcGISFeature_H

// C++ API headers
#include "AttachmentListModel.h"
#include "Feature.h"
#include "Loadable.h"
#include "RelationshipInfo.h"

// Qt headers
#include <QPointer>

namespace QRTImpl { class ArcGISFeatureImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class ArcGISFeature : public Feature, public Loadable
  {
    Q_OBJECT

  public:
    ~ArcGISFeature();

    bool canEditAttachments() const;
    bool canUpdateGeometry() const;

    AttachmentListModel* attachments() const;

    bool refreshObjectId() const;

    void relateFeature(ArcGISFeature* feature);

    void relateFeature(ArcGISFeature* feature, const RelationshipInfo& relationshipInfo);

    void unrelateFeature(ArcGISFeature* feature);

    // Loadable Interface methods
    Error loadError() const override;

    LoadStatus loadStatus() const override;

    void cancelLoad() override;

    void load() override;

    void retryLoad() override;

    ArcGISFeature(const std::shared_ptr<QRTImpl::ArcGISFeatureImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::ArcGISFeatureImpl> getImpl() const;

  signals:
    void doneLoading(Esri::ArcGISRuntime::Error loadError);
    void loadStatusChanged(Esri::ArcGISRuntime::LoadStatus loadStatus);

  private:
    Q_DISABLE_COPY(ArcGISFeature)

    ArcGISFeature() = delete;

    mutable QPointer<AttachmentListModel> m_attachments;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ArcGISFeature_H
