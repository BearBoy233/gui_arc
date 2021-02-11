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
/// \file ViewInsets.h

#ifndef QRT_ViewInsets_H
#define QRT_ViewInsets_H

// C++ API headers
#include "Object.h"

namespace QRTImpl { class ViewInsetsImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class ViewInsets : public Object
  {
    Q_OBJECT

    Q_PROPERTY(double left READ left WRITE setLeft NOTIFY viewInsetsChanged)
    Q_PROPERTY(double right READ right WRITE setRight NOTIFY viewInsetsChanged)
    Q_PROPERTY(double top READ top WRITE setTop NOTIFY viewInsetsChanged)
    Q_PROPERTY(double bottom READ bottom WRITE setBottom NOTIFY viewInsetsChanged)
    Q_PROPERTY(bool empty READ isEmpty NOTIFY viewInsetsChanged)

  public:
    ViewInsets(double left, double right, double top, double bottom, QObject* parent = nullptr);
    ~ViewInsets();

    bool isEmpty() const;

    double left() const;
    double right() const;
    double top() const;
    double bottom() const;

    /*! \internal */
    ViewInsets(const std::shared_ptr<QRTImpl::ViewInsetsImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::ViewInsetsImpl> getImpl() const;

  signals:
    void viewInsetsChanged();

  private:
    Q_DISABLE_COPY(ViewInsets)
    ViewInsets() = delete;

    void connectSignals();

    void setLeft(double left);
    void setRight(double right);
    void setTop(double top);
    void setBottom(double bottom);

    std::shared_ptr<QRTImpl::ViewInsetsImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ViewInsets_H
