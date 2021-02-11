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
/// \file GeoprocessingDataFile.h

#ifndef QRT_GeoprocessingDataFile_H
#define QRT_GeoprocessingDataFile_H

// C++ API headers
#include "GeoprocessingParameter.h"
#include "RemoteResource.h"
#include "TaskWatcher.h"

// Qt headers
#include <QUrl>

namespace QRTImpl { class GeoprocessingDataFileImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class GeoprocessingDataFile : public GeoprocessingParameter, public RemoteResource
  {
    Q_OBJECT

  public:
    explicit GeoprocessingDataFile(QObject* parent = nullptr);
    explicit GeoprocessingDataFile(const QUrl& url, QObject* parent = nullptr);
    explicit GeoprocessingDataFile(const QUrl& url, Credential* credential, QObject* parent = nullptr);
    ~GeoprocessingDataFile();

    void setUrl(const QUrl& url);

    QString inputFilePath() const;
    void setInputFilePath(const QString& path);

    QString uploadId() const;
    void setUploadId(const QString& uploadId);

    TaskWatcher fetchFile(const QString& filePath);

    // RemoteResource interface methods
    QUrl url() const override;
    Credential* credential() const override;
    RequestConfiguration requestConfiguration() const override;
    void setRequestConfiguration(const RequestConfiguration& requestConfiguration) override;

    /*!
       \internal
     */
    GeoprocessingDataFile(const std::shared_ptr<QRTImpl::GeoprocessingDataFileImpl>& impl, QObject* parent = nullptr);

  signals:
    void fetchFileCompleted(QUuid taskId, const QString& filePath);

  private:
    Q_DISABLE_COPY(GeoprocessingDataFile)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_GeoprocessingDataFile_H

