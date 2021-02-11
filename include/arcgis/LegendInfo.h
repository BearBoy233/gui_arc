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
/// \file LegendInfo.h

#ifndef QRT_LegendInfo_H
#define QRT_LegendInfo_H

// C++ API headers
#include "Object.h"
#include "Symbol.h"

// Qt headers
#include <QString>

namespace QRTImpl { class LegendInfoImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class LegendInfo : public Object
  {
    Q_OBJECT

  public:
    ~LegendInfo();

    QString name() const;

    Symbol* symbol(QObject* parent = nullptr) const;

    /*!
       \internal
     */
    LegendInfo(const std::shared_ptr<QRTImpl::LegendInfoImpl>& impl, QObject* parent = nullptr);

    std::shared_ptr<QRTImpl::LegendInfoImpl> getImpl() const;

  private:
    LegendInfo() = delete;

    Q_DISABLE_COPY(LegendInfo)

    std::shared_ptr<QRTImpl::LegendInfoImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_LegendInfo_H
