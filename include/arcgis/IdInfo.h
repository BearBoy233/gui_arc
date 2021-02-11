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
/// \file IdInfo.h

#ifndef QRT_IdInfo_H
#define QRT_IdInfo_H

// C++ API headers
#include "ServiceTypes.h"

// STL headers
#include <memory>

namespace QRTImpl { class IdInfoImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class IdInfo
  {
  public:
    IdInfo();

    IdInfo(const IdInfo& other);
    IdInfo(IdInfo&& other) noexcept;

    IdInfo& operator=(const IdInfo& other);
    IdInfo& operator=(IdInfo&& other) noexcept;

    virtual ~IdInfo();

    bool isEmpty() const;

    qint64 infoId() const;

    QString name() const;

    IdInfoType idInfoType() const;

    /*! \internal */
    explicit IdInfo(const std::shared_ptr<QRTImpl::IdInfoImpl>& impl);
    std::shared_ptr<QRTImpl::IdInfoImpl> getImpl() const;

  protected:
    std::shared_ptr<QRTImpl::IdInfoImpl> m_impl;
  };

  /*! \internal */
  template<typename T>
  T idinfo_cast(const IdInfo&)
  {
    return IdInfo();
  }

  template<>
  inline IdInfo idinfo_cast<IdInfo>(const IdInfo& idInfo)
  {
    return idInfo;
  }

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_IdInfo_H
