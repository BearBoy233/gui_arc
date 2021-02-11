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
/// \file PortalItemComment.h

#ifndef QRT_PortalItemComment_H
#define QRT_PortalItemComment_H

// C++ API headers
#include "Object.h"

namespace QRTImpl { class PortalItemCommentImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class PortalItemComment : public Object
  {
    Q_OBJECT

  public:
    ~PortalItemComment();

    QString comment() const;
    QString commentId() const;
    QDateTime created() const;
    QString owner() const;

    /*!
       \internal
     */
    PortalItemComment(const std::shared_ptr<QRTImpl::PortalItemCommentImpl>& impl);

    std::shared_ptr<QRTImpl::PortalItemCommentImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::PortalItemCommentImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_PortalItemComment_H
