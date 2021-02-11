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
/// \file Error.h

#ifndef QRT_Error_H
#define QRT_Error_H

// C++ API headers
#include "ArcGISQt_global.h"
#include "ErrorTypes.h"

// Qt headers
#include <QMetaType>

// STL headers
#include <memory>

namespace QRTImpl { class ErrorImpl; }

namespace Esri {
namespace ArcGISRuntime {

class Error
{
public:
  Error();
  Error(QString message, QString additionalMessage,
        ExtendedErrorType extendedErrorType = ExtendedErrorType::None);
  Error(const Error& other);
  Error(Error&& other) noexcept;

  ~Error();

  Error& operator=(const Error& other);
  Error& operator=(Error&& other) noexcept;

  QString additionalMessage() const;
  int code() const;
  ErrorDomainType domain() const;
  QString message() const;
  ExtendedErrorType extendedErrorType() const;

  bool isEmpty() const;

  /*! \internal */
  Error(const std::shared_ptr<QRTImpl::ErrorImpl>& impl);

  /*! \internal */
  std::shared_ptr<QRTImpl::ErrorImpl> getImpl() const;

private:
  std::shared_ptr<QRTImpl::ErrorImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

Q_DECLARE_METATYPE(Esri::ArcGISRuntime::Error);

#endif // QRT_Error_H
