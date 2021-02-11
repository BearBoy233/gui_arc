// COPYRIGHT 1995-2018 ESRI
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
/// \file SelectionProperties.h

#ifndef QRT_SelectionProperties_H
#define QRT_SelectionProperties_H

// Qt headers
#include <QColor>

// STL headers
#include <memory>

namespace QRTImpl { class SelectionPropertiesImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class SelectionProperties
  {
  public:
    SelectionProperties();
    explicit SelectionProperties(const QColor& color);
    SelectionProperties(const SelectionProperties& other);
    SelectionProperties(SelectionProperties&& other) noexcept;
    ~SelectionProperties();

    SelectionProperties& operator=(const SelectionProperties& other);
    SelectionProperties& operator=(SelectionProperties&& other) noexcept;

    QColor color() const;
    void setColor(const QColor& color);

    /*!
       \internal
     */
    explicit SelectionProperties(const std::shared_ptr<QRTImpl::SelectionPropertiesImpl>& impl);
    std::shared_ptr<QRTImpl::SelectionPropertiesImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::SelectionPropertiesImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_SelectionProperties_H
