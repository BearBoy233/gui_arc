// COPYRIGHT 1995-2018 ESRI
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
/// \file PopupExpression.h

#ifndef QRT_PopupExpression_H
#define QRT_PopupExpression_H

// C++ API headers
#include "Object.h"
#include "PopupTypes.h"

// Qt headers
#include <QString>

namespace QRTImpl { class PopupExpressionImpl; }

namespace Esri {
namespace ArcGISRuntime {

class PopupExpression : public Object
{
  Q_OBJECT

public:
  ~PopupExpression();

  QString expression() const;
  void setExpression(const QString& expression);

  QString name() const;
  void setName(const QString& name);

  Esri::ArcGISRuntime::PopupExpressionReturnType returnType() const;
  void setReturnType(Esri::ArcGISRuntime::PopupExpressionReturnType returnType);

  QString title() const;
  void setTitle(const QString& title);

  /*!
     \internal
   */
  PopupExpression(const std::shared_ptr<QRTImpl::PopupExpressionImpl>& impl, QObject* parent = nullptr);
  std::shared_ptr<QRTImpl::PopupExpressionImpl> getImpl() const;

private:
  PopupExpression() = delete;
  Q_DISABLE_COPY(PopupExpression)

  std::shared_ptr<QRTImpl::PopupExpressionImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_PopupExpression_H
