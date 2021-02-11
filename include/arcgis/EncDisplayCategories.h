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
/// \file EncDisplayCategories.h

#ifndef QRT_EncDisplayCategories_H
#define QRT_EncDisplayCategories_H

// C++ API headers
#include "EncDisplayCategories.h"
#include "Object.h"

// STL headers
#include <memory>

namespace QRTImpl { class EncDisplayCategoriesImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class EncDisplayCategories : public Object
  {
    Q_OBJECT

  public:
    ~EncDisplayCategories();

    bool isDisplayBase() const;
    void setDisplayBase(bool value);

    bool isOtherDisplay() const;
    void setOtherDisplay(bool value);

    bool isStandardDisplay() const;
    void setStandardDisplay(bool value);

    /*! \internal */
    explicit EncDisplayCategories(const std::shared_ptr<QRTImpl::EncDisplayCategoriesImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::EncDisplayCategoriesImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(EncDisplayCategories)
    std::shared_ptr<QRTImpl::EncDisplayCategoriesImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_EncDisplayCategories_H
