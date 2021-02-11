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
/// \file Object.h

#ifndef QRT_Object_H
#define QRT_Object_H

// C++ API headers
#include "ArcGISQt_global.h"
#include "Error.h"

// Qt headers
#include <QObject>

// STL headers
#include <memory>

namespace QRTImpl {
  class ObjectImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class Object : public QObject
  {
    Q_OBJECT

  public:
    explicit Object(QObject* parent = nullptr);

    ~Object();

  signals:
    void errorOccurred(Esri::ArcGISRuntime::Error error);

  protected:
    /*!
       \internal
     */
    explicit Object(const std::shared_ptr<QRTImpl::ObjectImpl>& impl, QObject* parent = nullptr);
    /*!
       \internal
     */
    void connectErrorSignal(const std::shared_ptr<QRTImpl::ObjectImpl>& impl) const;

  private:
    Q_DISABLE_COPY(Object)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_Object_H
