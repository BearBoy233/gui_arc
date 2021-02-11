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
/// \file SublayerSource.h

#ifndef QRT_SublayerSource_H
#define QRT_SublayerSource_H

// C++ API headers
#include "MapTypes.h"
#include "Object.h"

namespace QRTImpl { class SublayerSourceImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class SublayerSource : public Object
  {
    Q_OBJECT

  public:
    /*! \internal */
    ~SublayerSource();

    SublayerSourceType sublayerSourceType() const;

    /*! \internal */
    SublayerSource(const std::shared_ptr<QRTImpl::SublayerSourceImpl>& impl, QObject* parent = nullptr);
    /*! \internal */
    std::shared_ptr<QRTImpl::SublayerSourceImpl> getImpl() const;

  protected:
    std::shared_ptr<QRTImpl::SublayerSourceImpl> m_impl;

  private:
    Q_DISABLE_COPY(SublayerSource)
    SublayerSource() = delete;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_SublayerSource_H
