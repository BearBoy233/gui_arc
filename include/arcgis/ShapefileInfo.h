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
/// \file ShapefileInfo.h

#ifndef QRT_ShapefileInfo_H
#define QRT_ShapefileInfo_H

// Qt headers
#include <QImage>
#include <QStringList>

// STL headers
#include <memory>

namespace QRTImpl {
  class ShapefileInfoImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class ShapefileInfo
  {
  public:
    ShapefileInfo();
    ShapefileInfo(const ShapefileInfo& other);
    ShapefileInfo(ShapefileInfo&& other) noexcept;
    ~ShapefileInfo();

    ShapefileInfo& operator=(const ShapefileInfo& other);
    ShapefileInfo& operator=(ShapefileInfo&& other) noexcept;

    bool isEmpty() const;

    QString copyrightText() const;

    QString credits() const;

    QString description() const;

    QString summary() const;

    QStringList tags() const;

    QImage thumbnail() const;

    /*! \internal */
    ShapefileInfo(const std::shared_ptr<QRTImpl::ShapefileInfoImpl>& impl);
    std::shared_ptr<QRTImpl::ShapefileInfoImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::ShapefileInfoImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ShapefileInfo_H
