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
/// \file SuggestResult.h

#ifndef QRT_SuggestResult_H
#define QRT_SuggestResult_H

// C++ API headers
#include "ArcGISQt_global.h"

// STL headers
#include <memory>

namespace QRTImpl { class SuggestResultImpl; }

namespace Esri {
namespace ArcGISRuntime {

class SuggestResult
{
public:
  SuggestResult();
  SuggestResult(const SuggestResult& other);
  SuggestResult(SuggestResult&& other) noexcept;
  SuggestResult& operator=(const SuggestResult& other);
  SuggestResult& operator=(SuggestResult&& other) noexcept;
  ~SuggestResult();

  QString label() const;

  bool isCollection() const;

  bool isEmpty() const;

  /*!
     \internal
   */
  SuggestResult(const std::shared_ptr<QRTImpl::SuggestResultImpl>& impl);
  std::shared_ptr<QRTImpl::SuggestResultImpl> getImpl() const;

private:
  std::shared_ptr<QRTImpl::SuggestResultImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_SuggestResult_H
