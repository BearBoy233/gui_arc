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
/// \file JobMessage.h

#ifndef QRT_JobMessage_H
#define QRT_JobMessage_H

// C++ API headers
#include "Object.h"
#include "TaskTypes.h"

namespace QRTImpl {
  class JobMessageImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class JobMessage
  {
  public:
    JobMessage();
    JobMessage(const JobMessage& other);
    JobMessage(JobMessage&& other) noexcept;
    ~JobMessage();

    JobMessage& operator=(const JobMessage& other);
    JobMessage& operator=(JobMessage&& other) noexcept;

    bool isEmpty() const;

    QString message() const;

    JobMessageSeverity severity() const;

    JobMessageSource source() const;

    QDateTime timeStamp() const;

    /*!
       \internal
     */
    explicit JobMessage(const std::shared_ptr<QRTImpl::JobMessageImpl>& impl);
    std::shared_ptr<QRTImpl::JobMessageImpl> getImpl() const;

  private:

    std::shared_ptr<QRTImpl::JobMessageImpl> m_impl;

  };
}
}
#endif // QRT_JobMessageImpl_H
