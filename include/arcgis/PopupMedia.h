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
/// \file PopupMedia.h

#ifndef QRT_PopupMedia_H
#define QRT_PopupMedia_H

// C++ API headers
#include "Object.h"
#include "PopupMediaValue.h"
#include "PopupTypes.h"

// Qt headers
#include <QString>

namespace QRTImpl { class PopupMediaImpl; }

namespace Esri {
namespace ArcGISRuntime {

class PopupMedia : public Object
{
  Q_OBJECT

public:
  explicit PopupMedia(QObject* parent = nullptr);
  ~PopupMedia();

  QString caption() const;
  void setCaption(const QString& caption);

  QString title() const;
  void setTitle(const QString& title);

  PopupMediaType popupMediaType() const;
  void setPopupMediaType(PopupMediaType popupMediaType);

  PopupMediaValue* value() const;
  void setValue(PopupMediaValue* popupMediaValue);

  /*!
     \internal
   */
  PopupMedia(const std::shared_ptr<QRTImpl::PopupMediaImpl>& impl, QObject* parent = nullptr);
  std::shared_ptr<QRTImpl::PopupMediaImpl> getImpl() const;

private:
  Q_DISABLE_COPY(PopupMedia)

  std::shared_ptr<QRTImpl::PopupMediaImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_PopupMedia_H
