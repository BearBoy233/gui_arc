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
/// \file KmlNode.h

#ifndef QRT_KmlNode_H
#define QRT_KmlNode_H

// C++ API headers
#include "Envelope.h"
#include "Error.h"
#include "KmlViewpoint.h"
#include "Object.h"

// Qt headers
#include <QColor>
#include <QImage>

namespace QRTImpl { class KmlNodeImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class KmlNode : public Object
  {
    Q_OBJECT

  public:
    ~KmlNode();

    QString description() const;

    Envelope extent() const;

    QColor balloonBackgroundColor() const;

    QString balloonContent() const;

    bool isHighlighted() const;
    void setHighlighted(bool highlighted);

    bool isVisible() const;
    void setVisible(bool visible);

    QString name() const;

    KmlNode* parentNode() const;

    QString snippet() const;

    int snippetMaxLines() const;

    QImage uxIcon() const;

    int uxIconId() const;

    QColor uxIconColor() const;

    KmlViewpoint viewpoint() const;

    KmlNodeType kmlNodeType() const;

    Error refreshError() const;

    KmlRefreshStatus refreshStatus() const;

    /*! \internal */
    explicit KmlNode(const std::shared_ptr<QRTImpl::KmlNodeImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::KmlNodeImpl> getImpl() const;

  signals:
    void iconUpdated();
    void refreshStatusChanged();

  protected:
    std::shared_ptr<QRTImpl::KmlNodeImpl> m_impl;

  private:
    Q_DISABLE_COPY(KmlNode)

    void connectNotify(const QMetaMethod& signal) override;
    void disconnectNotify(const QMetaMethod& signal) override;

    QMetaObject::Connection m_nodeRefreshStatusChangedConn;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_KmlNode_H
