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
/// \file KmlContainer.h

#ifndef QRT_KmlContainer_H
#define QRT_KmlContainer_H

// C++ API headers
#include "KmlNode.h"
#include "MapTypes.h"

namespace Esri {
namespace ArcGISRuntime {

  class KmlContainer : public KmlNode
  {
    Q_OBJECT

  public:
    ~KmlContainer();

    QList<KmlNode*> childNodes() const;

    bool isOpen() const;
    void setOpen(bool open);

    bool isPartiallyVisible() const;

    KmlListItemType listItemType() const;

    /*! \internal */
    explicit KmlContainer(const std::shared_ptr<QRTImpl::KmlNodeImpl>& impl, QObject* parent = nullptr);

  private:
    Q_DISABLE_COPY(KmlContainer)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_KmlContainer_H
