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
/// \file PopupRelatedFeaturesSortOrder.h

#ifndef QRT_PopupRelatedFeaturesSortOrder_H
#define QRT_PopupRelatedFeaturesSortOrder_H

// C++ API headers
#include "QueryParameters.h"

namespace QRTImpl { class PopupRelatedFeaturesSortOrderImpl; }

namespace Esri {
namespace ArcGISRuntime {

class PopupRelatedFeaturesSortOrder
{
public:
  PopupRelatedFeaturesSortOrder();
  PopupRelatedFeaturesSortOrder(const PopupRelatedFeaturesSortOrder& other);
  PopupRelatedFeaturesSortOrder(PopupRelatedFeaturesSortOrder&& other) noexcept;
  ~PopupRelatedFeaturesSortOrder();

  PopupRelatedFeaturesSortOrder& operator=(const PopupRelatedFeaturesSortOrder& other);
  PopupRelatedFeaturesSortOrder& operator=(PopupRelatedFeaturesSortOrder&& other) noexcept;

  OrderBy orderByField() const;
  void setOrderByField(const OrderBy& orderByField);

  qint64 relationshipId() const;
  void setRelationshipId(qint64 relationshipId);

  /*!
     \internal
   */
  explicit PopupRelatedFeaturesSortOrder(const std::shared_ptr<QRTImpl::PopupRelatedFeaturesSortOrderImpl>& impl);
  std::shared_ptr<QRTImpl::PopupRelatedFeaturesSortOrderImpl> getImpl() const;

private:
  std::shared_ptr<QRTImpl::PopupRelatedFeaturesSortOrderImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_PopupRelatedFeaturesSortOrder_H
