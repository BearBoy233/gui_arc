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
/// \file PopupManager.h

#ifndef QRT_PopupManager_H
#define QRT_PopupManager_H

// C++ API headers
#include "Domain.h"
#include "FeatureTemplate.h"
#include "FeatureType.h"
#include "GeometryBuilder.h"
#include "Object.h"
#include "Popup.h"
#include "PopupAttachmentManager.h"
#include "PopupAttributeListModel.h"
#include "PopupField.h"
#include "PopupTypes.h"
#include "ServiceTypes.h"
#include "Symbol.h"

namespace QRTImpl { class PopupManagerImpl; }

namespace Esri {
namespace ArcGISRuntime {

class PopupManager : public Object
{
  Q_OBJECT

  Q_PROPERTY(PopupAttachmentManager* attachmentManager READ attachmentManager)
  Q_PROPERTY(PopupAttributeListModel* displayedFields READ displayedFields)
  Q_PROPERTY(PopupAttributeListModel* editableFields READ editableFields)
  Q_PROPERTY(QString title READ title)
  Q_PROPERTY(QString customHtmlDescription READ customHtmlDescription)
  Q_PROPERTY(QString editSummary READ editSummary)
  Q_PROPERTY(bool editingAllowed READ isEditingAllowed)
  Q_PROPERTY(bool editGeometryAllowed READ isEditGeometryAllowed)
  Q_PROPERTY(bool deleteAllowed READ isDeleteAllowed)
  Q_PROPERTY(bool showEditSummary READ isShowEditSummary)
  Q_PROPERTY(bool showCustomHtmlDescription READ isShowCustomHtmlDescription)
  Q_PROPERTY(bool showMedia READ isShowMedia)
  Q_PROPERTY(bool showAttachments READ isShowAttachments)
  Q_PROPERTY(bool editing READ isEditing)
  Q_PROPERTY(bool geoElementValid READ isGeoElementValid)

public:
  explicit PopupManager(Popup* popup, QObject* parent = nullptr);
  ~PopupManager();

  Popup* popup() const;

  PopupAttachmentManager* attachmentMananger() const;

  PopupAttachmentManager* attachmentManager() const;

  PopupAttributeListModel* displayedFields() const;

  PopupAttributeListModel* editableFields() const;

  QList<FeatureType> featureTypes() const;

  QString title() const;

  QString customHtmlDescription() const;

  QString editSummary() const;

  Symbol* symbol() const;

  void setEditingGeometryBuilder(GeometryBuilder* builder);
  GeometryBuilder* editingGeometryBuilder() const;

  bool isEditingAllowed() const;
  bool isEditGeometryAllowed() const;
  bool isDeleteAllowed() const;
  bool isShowEditSummary() const;
  bool isShowCustomHtmlDescription() const;
  bool isShowMedia() const;
  bool isShowAttachments() const;
  bool isEditing() const;
  bool isGeoElementValid() const;

  PopupField* fieldByName(const QString& fieldName) const;
  Q_INVOKABLE QString substitute(const QString& templateString) const;

  Q_INVOKABLE bool startEditing();
  Q_INVOKABLE void finishEditing(); // async, see editingCompleted
  Q_INVOKABLE void cancelEditing();

  bool doesChangeRequireNotification(const FeatureTemplate& featureTemplate) const;

  Error updateValue(const QVariant& newValue, PopupField* popupField);
  Error updateValue(const FeatureTemplate& featureTemplate, FeatureTypeChangeMode changeMode);

  QString formattedValue(PopupField* popupField) const;
  QVariant fieldValue(PopupField* popupField) const;
  FieldType fieldType(PopupField* popupField) const;
  QString fieldLabel(PopupField* popupField) const;
  Domain domain(PopupField* popupField) const;
  int maxLength(PopupField* popupField) const;
  bool isNullable(PopupField* popupField) const;
  bool isFeatureType(PopupField* popupField) const;
  Error validationError(PopupField* popupField) const;
  QString rangeDomainValidationText(PopupField* popupField) const;

  /*!
     \internal
   */
  PopupManager(const std::shared_ptr<QRTImpl::PopupManagerImpl>& impl, QObject* parent = nullptr);
  std::shared_ptr<QRTImpl::PopupManagerImpl> getImpl() const;

signals:
  void geoElementValidChanged();
  void featureTypeChanged();
  void editingCompleted(Esri::ArcGISRuntime::Error error);
  void geometryBuilderRequired();

private:
  Q_DISABLE_COPY(PopupManager)

  void connectSignals();

  mutable PopupAttributeListModel* m_displayedFields = nullptr;
  mutable PopupAttributeListModel* m_editableFields = nullptr;

  std::shared_ptr<QRTImpl::PopupManagerImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_PopupManager_H
