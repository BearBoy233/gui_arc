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
/// \file KmlNetworkLink.h

#ifndef QRT_KmlNetworkLink_H
#define QRT_KmlNetworkLink_H

// C++ API headers
#include "KmlNode.h"
#include "MapTypes.h"

namespace Esri {
namespace ArcGISRuntime {

  class KmlNetworkLink : public KmlNode
  {
    Q_OBJECT

  public:
    ~KmlNetworkLink();

    QUrl url() const;

    bool canFlyToNode() const;

    QList<KmlNode*> childNodes() const;

    bool hasRefreshVisibility() const;

    bool isOpen() const;
    void setOpen(bool open);

    KmlListItemType listItemType() const;

    bool isPartiallyVisible() const;

    /*! \internal */
    explicit KmlNetworkLink(const std::shared_ptr<QRTImpl::KmlNodeImpl>& impl, QObject* parent = nullptr);

  private:
    Q_DISABLE_COPY(KmlNetworkLink)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_KmlNetworkLink_H
