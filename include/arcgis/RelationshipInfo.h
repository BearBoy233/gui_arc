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
/// \file RelationshipInfo.h

#ifndef QRT_RelationshipInfo_H
#define QRT_RelationshipInfo_H

// C++ API headers
#include "ServiceTypes.h"

// STL headers
#include <memory>

namespace QRTImpl { class RelationshipInfoImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class RelationshipInfo
  {
  public:
    RelationshipInfo();
    RelationshipInfo(const RelationshipInfo& other);
    RelationshipInfo(RelationshipInfo&& other) noexcept;
    ~RelationshipInfo();

    RelationshipInfo& operator=(const RelationshipInfo& other);
    RelationshipInfo& operator=(RelationshipInfo&& other) noexcept;

    bool isEmpty() const;

    qint64 id() const;

    bool isComposite() const;

    QString keyField() const;

    QString name() const;

    qint64 relatedTableId() const;

    Esri::ArcGISRuntime::RelationshipCardinality cardinality() const;

    Esri::ArcGISRuntime::RelationshipRole role() const;

    /*!
       \internal
     */
    RelationshipInfo(const std::shared_ptr<QRTImpl::RelationshipInfoImpl>& impl);
    std::shared_ptr<QRTImpl::RelationshipInfoImpl> getImpl() const;

  protected:
    std::shared_ptr<QRTImpl::RelationshipInfoImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_RelationshipInfo_H
