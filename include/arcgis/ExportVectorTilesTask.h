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
/// \file ExportVectorTilesTask.h

#ifndef QRT_ExportVectorTilesTask_H
#define QRT_ExportVectorTilesTask_H

// C++ API headers
#include "Credential.h"
#include "ExportVectorTilesJob.h"
#include "ExportVectorTilesParameters.h"
#include "Loadable.h"
#include "Object.h"
#include "PortalItem.h"
#include "RemoteResource.h"
#include "TaskWatcher.h"
#include "VectorTileSourceInfo.h"

namespace QRTImpl { class ExportVectorTilesTaskImpl; }

namespace Esri {
namespace ArcGISRuntime {

    class ExportVectorTilesTask : public Object, public Loadable, public RemoteResource
    {
      Q_OBJECT

    public:
      explicit ExportVectorTilesTask(const QUrl& url, QObject* parent = nullptr);
      explicit ExportVectorTilesTask(const QUrl& url, Credential* credential, QObject* parent = nullptr);
      explicit ExportVectorTilesTask(PortalItem* portalItem, QObject* parent = nullptr);
      ~ExportVectorTilesTask();

      ExportVectorTilesJob* exportVectorTiles(const ExportVectorTilesParameters& parameters, const QString& vectorTileCachePath);
      ExportVectorTilesJob* exportVectorTiles(const ExportVectorTilesParameters& parameters, const QString& vectorTileCachePath, const QString& itemResourcePath);
      ExportVectorTilesJob* exportStyleResourceCache(const QString& itemResourcePath);

      TaskWatcher createDefaultExportVectorTilesParameters(const Geometry& areaOfInterest, double maxScale);

      bool hasStyleResources() const;

      PortalItem* portalItem() const;

      VectorTileSourceInfo sourceInfo() const;

      // Loadable Interface methods
      Error loadError() const override;
      LoadStatus loadStatus() const override;
      void cancelLoad() override;
      void load() override;
      void retryLoad() override;

      // RemoteResource interface methods
      QUrl url() const override;
      Credential* credential() const override;
      RequestConfiguration requestConfiguration() const override;
      void setRequestConfiguration(const RequestConfiguration& requestConfiguration) override;

    signals:
      void doneLoading(Esri::ArcGISRuntime::Error loadError);
      void loadStatusChanged(Esri::ArcGISRuntime::LoadStatus loadStatus);
      void createDefaultExportVectorTilesParametersCompleted(QUuid taskId, const Esri::ArcGISRuntime::ExportVectorTilesParameters& defaultExportTileCacheParameters);

    private:
      Q_DISABLE_COPY(ExportVectorTilesTask)

      void connectSignals();

      ExportVectorTilesTask() = delete;
      std::shared_ptr<QRTImpl::ExportVectorTilesTaskImpl> m_impl;
    };

}
}

#endif // QRT_ExportVectorTilesTask_H
