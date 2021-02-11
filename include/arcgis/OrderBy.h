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
/// \file QueryParameters.h

#ifndef QRT_OrderBy_H
#define QRT_OrderBy_H

// C++ API headers
#include "CoreTypes.h"

// Qt headers
#include <QString>

// STL headers
#include <memory>

namespace QRTImpl {
  class OrderByImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class OrderBy
  {
  public:
    OrderBy();
    OrderBy(const QString& fieldName, SortOrder sortOrder);
    OrderBy(const OrderBy& other);
    OrderBy(OrderBy&& other) noexcept;
    ~OrderBy();

    OrderBy& operator=(const OrderBy& other);
    OrderBy& operator=(OrderBy&& other) noexcept;

    bool isEmpty() const;
    void clear();

    QString fieldName() const;
    void setFieldName(const QString& fieldName);

    SortOrder sortOrder() const;
    void setSortOrder(SortOrder sortOrder);

    OrderBy(const std::shared_ptr<QRTImpl::OrderByImpl>& impl);
    std::shared_ptr<QRTImpl::OrderByImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::OrderByImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_OrderBy_H
