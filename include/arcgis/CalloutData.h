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
/// \file CalloutData.h

#ifndef QRT_CalloutData_H
#define QRT_CalloutData_H

// C++ API headers
#include "GeoElement.h"
#include "Object.h"
#include "Point.h"

// Qt headers
#include <QPointF>
#include <QUrl>

namespace QRTImpl { class CalloutDataImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class CalloutData: public Object
  {
    Q_OBJECT

  public:

    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString detail READ detail WRITE setDetail NOTIFY detailChanged)
    Q_PROPERTY(QUrl imageUrl READ imageUrl WRITE setImageUrl NOTIFY imageUrlChanged)
    Q_PROPERTY(QPointF screenPoint READ screenPoint NOTIFY screenPointChanged)
    Q_PROPERTY(bool visible READ isVisible WRITE setVisible NOTIFY visibleChanged)

  signals:
    void titleChanged();
    void detailChanged();
    void imageUrlChanged();
    void screenPointChanged();
    void visibleChanged();

  public:
    /*!
       \internal
     */
    ~CalloutData();
    /*!
       \internal
     */
    CalloutData(const std::shared_ptr<QRTImpl::CalloutDataImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::CalloutDataImpl> getImpl() const;

    Point location() const;
    void setLocation(const Point& location);

    GeoElement* geoElement() const;
    void setGeoElement(GeoElement* geoElement);

    Point tapLocation() const;
    void setTapLocation(const Point& tapLocation);

    QString title() const;
    void setTitle(const QString& title);

    QString detail() const;
    void setDetail(const QString& detail);

    QUrl imageUrl() const;
    void setImageUrl(const QUrl& imageUrl);

    QImage image() const;
    void setImage(const QImage& image);

    QPointF screenPoint() const;

    bool isShowCalloutForLocationDisplay() const;
    void setShowCalloutForLocationDisplay(bool calloutForLocationDisplay);

    bool isVisible() const;
    void setVisible(bool visible);

  private:
    Q_DISABLE_COPY(CalloutData)

    std::shared_ptr<QRTImpl::CalloutDataImpl> m_impl;
  };

}
}
#endif // QRT_CalloutData_H
