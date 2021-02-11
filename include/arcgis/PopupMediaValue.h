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
/// \file PopupMediaValue.h

#ifndef QRT_PopupMediaValue_H
#define QRT_PopupMediaValue_H

// C++ API headers
#include "Object.h"

// Qt headers
#include <QString>
#include <QUrl>

namespace QRTImpl { class PopupMediaValueImpl; }

namespace Esri {
namespace ArcGISRuntime {

class PopupMediaValue : public Object
{
  Q_OBJECT

public:
  explicit PopupMediaValue(QObject* parent = nullptr);
  ~PopupMediaValue();

  QStringList fieldNames() const;
  void setFieldNames(const QStringList& fieldNames);

  QUrl linkUrl() const;
  void setLinkUrl(const QUrl& linkUrl);

  QUrl sourceUrl() const;
  void setSourceUrl(const QUrl& sourceUrl);

  QString normalizeFieldName() const;
  void setNormalizeFieldName(const QString& normalizeFieldName);

  QString tooltipFieldName() const;
  void setTooltipFieldName(const QString& tooltipFieldName);

  /*!
     \internal
   */
  PopupMediaValue(const std::shared_ptr<QRTImpl::PopupMediaValueImpl>& impl, QObject* parent = nullptr);
  std::shared_ptr<QRTImpl::PopupMediaValueImpl> getImpl() const;

private:
  Q_DISABLE_COPY(PopupMediaValue)

  std::shared_ptr<QRTImpl::PopupMediaValueImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_PopupMediaValue_H
