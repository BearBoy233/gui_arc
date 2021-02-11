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
/// \file Bookmark.h

#ifndef QRT_Bookmark_H
#define QRT_Bookmark_H

// C++ API headers
#include "Object.h"
#include "Viewpoint.h"

namespace QRTImpl { class BookmarkImpl; }

namespace Esri {
namespace ArcGISRuntime {

class Bookmark : public Object
{
  Q_OBJECT

public:
  explicit Bookmark(QObject* parent = nullptr);
  Bookmark(const QString& name, const Viewpoint& viewpoint, QObject* parent = nullptr);
  ~Bookmark();

  QString name() const;
  void setName(const QString& name);

  Viewpoint viewpoint() const;
  void setViewpoint(const Viewpoint& viewpoint);

  Bookmark* clone(QObject* parent = nullptr) const;

  /*!
     \internal
   */
  Bookmark(const std::shared_ptr<QRTImpl::BookmarkImpl>& impl, QObject* parent = nullptr);
  std::shared_ptr<QRTImpl::BookmarkImpl> getImpl() const;

private:
  Q_DISABLE_COPY(Bookmark)

  std::shared_ptr<QRTImpl::BookmarkImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_Bookmark_H
