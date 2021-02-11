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
/// \file PopupField.h

#ifndef QRT_PopupField_H
#define QRT_PopupField_H

// C++ API headers
#include "Object.h"
#include "PopupFieldFormat.h"
#include "PopupTypes.h"

// Qt headers
#include <QString>

namespace QRTImpl { class PopupFieldImpl; }

namespace Esri {
namespace ArcGISRuntime {

class PopupField : public Object
{
  Q_OBJECT

public:
  explicit PopupField(QObject* parent = nullptr);
  ~PopupField();

  QString fieldName() const;
  void setFieldName(const QString& fieldName);

  PopupFieldFormat* format() const;
  void setFormat(PopupFieldFormat* format);

  bool isEditable() const;
  void setEditable(bool editable);

  bool isVisible() const;
  void setVisible(bool visible);

  QString label() const;
  void setLabel(const QString& label);

  PopupStringFieldOption stringFieldOption() const;
  void setStringFieldOption(PopupStringFieldOption popupStringFieldOption);

  QString tooltip() const;
  void setTooltip(const QString& tooltip);

  /*!
     \internal
   */
  PopupField(const std::shared_ptr<QRTImpl::PopupFieldImpl>& impl, QObject* parent = nullptr);
  std::shared_ptr<QRTImpl::PopupFieldImpl> getImpl() const;

private:
  Q_DISABLE_COPY(PopupField)

  std::shared_ptr<QRTImpl::PopupFieldImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_PopupField_H
