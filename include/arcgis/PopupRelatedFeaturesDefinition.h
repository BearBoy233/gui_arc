// COPYRIGHT 1995-2017 ESRI
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
/// \file PopupRelatedFeaturesDefinition.h

#ifndef QRT_PopupRelatedFeaturesDefinition_H
#define QRT_PopupRelatedFeaturesDefinition_H

// C++ API headers
#include "Object.h"
#include "PopupRelatedFeaturesSortOrder.h"

namespace QRTImpl { class PopupRelatedFeaturesDefinitionImpl; }

namespace Esri {
namespace ArcGISRuntime {

class PopupRelatedFeaturesDefinition : public Object
{
  Q_OBJECT
public:
  PopupRelatedFeaturesDefinition(QObject* parent = nullptr);
  ~PopupRelatedFeaturesDefinition();

  bool isShowRelatedFeatures() const;
  void setShowRelatedFeatures(bool showRelatedFeatures);

  QList<PopupRelatedFeaturesSortOrder> sortOrder() const;
  void setSortOrder(const QList<PopupRelatedFeaturesSortOrder>& sortOrder);

  /*!
     \internal
   */
  PopupRelatedFeaturesDefinition(const std::shared_ptr<QRTImpl::PopupRelatedFeaturesDefinitionImpl>& impl, QObject* parent = nullptr);
  std::shared_ptr<QRTImpl::PopupRelatedFeaturesDefinitionImpl> getImpl() const;

private:
  Q_DISABLE_COPY(PopupRelatedFeaturesDefinition)
  std::shared_ptr<QRTImpl::PopupRelatedFeaturesDefinitionImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_PopupRelatedFeaturesDefinition_H
