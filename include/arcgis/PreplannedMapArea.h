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
/// \file PreplannedMapArea.h

#ifndef QRT_PreplannedMapArea_H
#define QRT_PreplannedMapArea_H

// C++ API headers
#include "Geometry.h"
#include "ImmutablePortalItemListModel.h"
#include "Loadable.h"
#include "Object.h"
#include "TaskWatcher.h"

// Qt headers
#include <QUuid>

namespace QRTImpl {
  class PreplannedMapAreaImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class PortalItem;

  class PreplannedMapArea : public Object, public Loadable
  {
    Q_OBJECT

  public:
    PreplannedMapArea(PortalItem* portalItem, QObject* parent = nullptr);
    ~PreplannedMapArea();

    Geometry areaOfInterest() const;

    PortalItem* portalItem() const;

    // Loadable Interface methods
    Error loadError() const override;
    LoadStatus loadStatus() const override;
    void cancelLoad() override;
    void load() override;
    void retryLoad() override;

    TaskWatcher contentItems();

    std::shared_ptr<QRTImpl::PreplannedMapAreaImpl> getImpl() const;

    /*! \internal */
    explicit PreplannedMapArea(const std::shared_ptr<QRTImpl::PreplannedMapAreaImpl>& impl, QObject* parent = nullptr);

  signals:
    void doneLoading(Esri::ArcGISRuntime::Error loadError);
    void loadStatusChanged(Esri::ArcGISRuntime::LoadStatus loadStatus);
    void contentItemsCompleted(QUuid taskId, Esri::ArcGISRuntime::ImmutablePortalItemListModel* contentItems);

  private:
    PreplannedMapArea() = delete;
    Q_DISABLE_COPY(PreplannedMapArea)

    void connectSignals();

    Esri::ArcGISRuntime::ImmutablePortalItemListModel* m_immutableItemsModel = nullptr;

    std::shared_ptr<QRTImpl::PreplannedMapAreaImpl> m_impl;
  };
}
}

#endif // QRT_PreplannedMapArea_H
