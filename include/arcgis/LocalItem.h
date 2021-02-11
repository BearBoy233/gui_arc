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
/// \file LocalItem.h

#ifndef QRT_LocalItem_H
#define QRT_LocalItem_H

// C++ API headers
#include "Item.h"

namespace QRTImpl { class LocalItemImpl; }

namespace Esri {
namespace ArcGISRuntime {

  enum class LocalItemType;

  class LocalItem : public Item
  {
    Q_OBJECT

  public:
    ~LocalItem();

    LocalItemType localItemType() const;

    QString originalPortalItemId() const;

    QString path() const;

    /*! \internal */
    LocalItem(const std::shared_ptr<QRTImpl::LocalItemImpl>& impl);
    std::shared_ptr<QRTImpl::LocalItemImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(LocalItem)
    LocalItem() = delete;
  };

}
}
#endif // QRT_LocalItem_H
