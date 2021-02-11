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
/// \file Job.h

#ifndef QRT_Job_H
#define QRT_Job_H

// C++ API headers
#include "Error.h"
#include "JobMessage.h"
#include "JsonSerializable.h"
#include "Object.h"
#include "RemoteResource.h"
#include "TaskTypes.h"
#include "TaskWatcher.h"

// Qt headers
#include <QDateTime>

namespace QRTImpl {
  class JobImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class Job : public Object, public JsonSerializable, public RemoteResource
  {
    Q_OBJECT

  public:
    ~Job();

    JobType jobType() const;

    QList<JobMessage> messages() const;

    QString serverJobId() const;

    int progress() const;

    JobStatus jobStatus() const;

    Error error() const;

    static Job* fromJson(const QString& json, QObject* parent = nullptr);

    QString toJson() const override;

    QJsonObject unknownJson() const override;

    QJsonObject unsupportedJson() const override;

    bool pause();

    bool start();

    bool cancel();

    TaskWatcher checkStatus();

    // RemoteResource interface methods
    Credential* credential() const override;
    RequestConfiguration requestConfiguration() const override;
    void setRequestConfiguration(const RequestConfiguration& requestConfiguration) override;

    /*!
       \internal
     */
    Job(const std::shared_ptr<QRTImpl::JobImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::JobImpl> getImpl() const;

  signals:
    void jobStatusChanged();
    void jobDone();
    void checkStatusCompleted(QUuid taskId, bool succeeded);
    void progressChanged();

  protected:
    explicit Job(QObject* parent);
    QUrl url() const override;
    std::shared_ptr<QRTImpl::JobImpl> m_impl;

  private:
    Q_DISABLE_COPY(Job)
    void connectSignals();
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_Job_H
