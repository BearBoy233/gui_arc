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
/// \file EditResult.h

#ifndef QRT_EditResult_H
#define QRT_EditResult_H

// C++ API headers
#include "Error.h"
#include "GeodatabaseTypes.h"
#include "Object.h"

namespace QRTImpl { class EditResultImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class EditResult : public Object
  {
    Q_OBJECT

  public:
    ~EditResult();

    bool isCompletedWithErrors() const;

    EditOperation editOperation() const;

    Error error() const;

    QString globalId() const;

    qint64 objectId() const;

    EditResultType editResultType() const;

    EditResult(const std::shared_ptr<QRTImpl::EditResultImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::EditResultImpl> getImpl() const;

  protected:
    std::shared_ptr<QRTImpl::EditResultImpl> m_impl;

  private:
    Q_DISABLE_COPY(EditResult)

    EditResult() = delete;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_EditResult_H
