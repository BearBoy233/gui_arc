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
/// \file Popup.h

#ifndef QRT_Popup_H
#define QRT_Popup_H

// C++ API headers
#include "GeoElement.h"
#include "Object.h"
#include "PopupDefinition.h"
#include "PopupField.h"
#include "Symbol.h"

// Qt headers
#include <QString>

namespace QRTImpl { class PopupImpl; }

namespace Esri {
namespace ArcGISRuntime {

class Popup : public Object
{
  Q_OBJECT

public:
  explicit Popup(GeoElement* geoElement,
                 QObject* parent = nullptr);

  Popup(GeoElement* geoElement,
        PopupDefinition* popupDefinition,
        QObject* parent = nullptr);

  ~Popup();

  GeoElement* geoElement() const;

  PopupDefinition* popupDefinition() const;

  Symbol* symbol() const;

  QString title() const;

  QString formattedValue(PopupField* popupField) const;

  /*!
     \internal
   */
  Popup(const std::shared_ptr<QRTImpl::PopupImpl>& impl, QObject* parent = nullptr);
  std::shared_ptr<QRTImpl::PopupImpl> getImpl() const;

private:
  Q_DISABLE_COPY(Popup)

  std::shared_ptr<QRTImpl::PopupImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_Popup_H
