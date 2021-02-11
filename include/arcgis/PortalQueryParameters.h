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
/// \file PortalQueryParameters.h

#ifndef QRT_PortalQueryParameters_H
#define QRT_PortalQueryParameters_H

// C++ API headers
#include "Envelope.h"
#include "PortalTypes.h"

namespace QRTImpl { class PortalQueryParametersImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class Envelope;

  class PortalQueryParameters
  {
  public:
    PortalQueryParameters();
    PortalQueryParameters(const PortalQueryParameters& other);
    PortalQueryParameters(PortalQueryParameters&& other) noexcept;

    PortalQueryParameters& operator=(const PortalQueryParameters& other);
    PortalQueryParameters& operator=(PortalQueryParameters&& other) noexcept;

    virtual ~PortalQueryParameters();

    bool isEmpty() const;

    Envelope boundingBox() const;
    void setBoundingBox(const Envelope& boundingBox);

    int limit() const;
    void setLimit(int limit);

    QString query() const;

    bool isSearchPublic() const;
    void setSearchPublic(bool searchPublic);

    QString sortField() const;
    void setSortField(const QString& sortField);

    PortalQuerySortOrder sortOrder() const;
    void setSortOrder(PortalQuerySortOrder sortOrder);

    int startIndex() const;
    void setStartIndex(int startIndex);

  protected:
    /*! \internal */
    explicit PortalQueryParameters(const std::shared_ptr<QRTImpl::PortalQueryParametersImpl>& impl);
    std::shared_ptr<QRTImpl::PortalQueryParametersImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_PortalQueryParameters_H
