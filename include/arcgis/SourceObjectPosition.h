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
/// \file SourceObjectPosition.h

#ifndef QRT_SourceObjectPosition_H
#define QRT_SourceObjectPosition_H

// Qt headers
#include <QtGlobal>

// STL headers
#include <memory>

namespace QRTImpl { class SourceObjectPositionImpl; }

namespace Esri {
namespace ArcGISRuntime {

class SourceObjectPosition
{
public:
  SourceObjectPosition();
  SourceObjectPosition(int sourceIndex, qint64 sourceObjectId, double position);
  SourceObjectPosition(const SourceObjectPosition& other);
  SourceObjectPosition(SourceObjectPosition&& other) noexcept;
  ~SourceObjectPosition();

  SourceObjectPosition& operator=(const SourceObjectPosition& other);
  SourceObjectPosition& operator=(SourceObjectPosition&& other) noexcept;

  bool isEmpty() const;

  double position() const;
  void setPosition(double position);

  int sourceIndex() const;
  void setSourceIndex(int sourceIndex);

  qint64 sourceObjectId() const;
  void setSourceObjectId(qint64 sourceObjectId);

  /*!
     \internal
   */
  SourceObjectPosition(const std::shared_ptr<QRTImpl::SourceObjectPositionImpl>& impl);
  std::shared_ptr<QRTImpl::SourceObjectPositionImpl> getImpl() const;

private:
  std::shared_ptr<QRTImpl::SourceObjectPositionImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_SourceObjectPosition_H
