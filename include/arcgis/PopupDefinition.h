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
/// \file PopupDefinition.h

#ifndef QRT_PopupDefinition_H
#define QRT_PopupDefinition_H

// C++ API headers
#include "GeoElement.h"
#include "Object.h"
#include "PopupExpression.h"
#include "PopupField.h"
#include "PopupMedia.h"
#include "PopupRelatedFeaturesDefinition.h"
#include "PopupSource.h"
#include "PopupTypes.h"

// Qt headers
#include <QString>

namespace QRTImpl { class PopupDefinitionImpl; }

namespace Esri {
namespace ArcGISRuntime {

class PopupDefinition : public Object
{
  Q_OBJECT

public:
  explicit PopupDefinition(QObject* parent = nullptr);
  explicit PopupDefinition(GeoElement* geoElement, QObject* parent = nullptr);
  explicit PopupDefinition(PopupSource* popupSource, QObject* parent = nullptr);
  ~PopupDefinition();

  bool isDeleteAllowed() const;
  void setDeleteAllowed(bool deleteAllowed);

  bool isEditingAllowed() const;
  void setEditingAllowed(bool editingAllowed);

  bool isEditGeometryAllowed() const;
  void setEditGeometryAllowed(bool editGeometryAllowed);

  QString description() const;
  void setDescription(const QString& description);

  void setExpressions(const QList<PopupExpression*>& fields);
  QList<PopupExpression*> expressions() const;

  QList<PopupField*> fields() const;
  void setFields(const QList<PopupField*>& fields);

  QList<PopupMedia*> media() const;
  void setMedia(const QList<PopupMedia*>& media);

  bool isShowAttachments() const;
  void setShowAttachments(bool showAttachments);

  bool isShowEditSummary() const;
  void setShowEditSummary(bool showEditSummary);

  PopupRelatedFeaturesDefinition* relatedFeaturesDefinition() const;
  void setRelatedFeaturesDefinition(PopupRelatedFeaturesDefinition* relatedFeaturesDefinition);

  bool isShowRelatedRecords() const;
  void setShowRelatedRecords(bool showRelatedRecords);

  QString title() const;
  void setTitle(const QString& title);

  /*!
     \internal
   */
  PopupDefinition(const std::shared_ptr<QRTImpl::PopupDefinitionImpl>& impl, QObject* parent = nullptr);
  std::shared_ptr<QRTImpl::PopupDefinitionImpl> getImpl() const;

private:
  Q_DISABLE_COPY(PopupDefinition)

  std::shared_ptr<QRTImpl::PopupDefinitionImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_PopupDefinition_H
