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
/// \file TaskWatcher.h

#ifndef QRT_TaskWatcher_H
#define QRT_TaskWatcher_H

// Qt headers
#include <QString>
#include <QUuid>

// STL headers
#include <memory>

namespace QRTImpl { class TaskWatcherImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class TaskWatcher
  {
  public:
    TaskWatcher();
    TaskWatcher(const TaskWatcher& other);
    TaskWatcher(TaskWatcher&& other) noexcept;
    ~TaskWatcher();
    TaskWatcher& operator=(const TaskWatcher& other);
    TaskWatcher& operator=(TaskWatcher&& other) noexcept;

    bool cancel();

    bool isCanceled() const;

    bool isDone() const;

    bool isValid() const;

    QUuid taskId() const;

    QString description() const;

    /*! \internal */
    TaskWatcher(const std::shared_ptr<QRTImpl::TaskWatcherImpl>& impl);

    /*! \internal */
    std::shared_ptr<QRTImpl::TaskWatcherImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::TaskWatcherImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_TaskWatcher_H

