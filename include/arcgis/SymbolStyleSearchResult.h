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
/// \file SymbolStyleSearchResult.h

#ifndef QRT_SymbolStyleSearchResult_H
#define QRT_SymbolStyleSearchResult_H

// C++ API headers
#include "ArcGISQt_global.h"
#include "Symbol.h"

// Qt headers
#include <QStringList>

namespace QRTImpl { class SymbolStyleSearchResultImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class SymbolStyleSearchResult
  {
  public:
    SymbolStyleSearchResult();
    SymbolStyleSearchResult(const SymbolStyleSearchResult& other);
    SymbolStyleSearchResult(SymbolStyleSearchResult&& other) noexcept;
    ~SymbolStyleSearchResult();
    SymbolStyleSearchResult& operator=(const SymbolStyleSearchResult& other);
    SymbolStyleSearchResult& operator=(SymbolStyleSearchResult&& other) noexcept;

    bool isEmpty() const;

    QStringList tags() const;

    QString name() const;

    QString symbolClass() const;

    QString category() const;

    QString key() const;

    Symbol* symbol(QObject* parent = nullptr) const;

    SymbolStyleSearchResult(const std::shared_ptr<QRTImpl::SymbolStyleSearchResultImpl>& impl);
    std::shared_ptr<QRTImpl::SymbolStyleSearchResultImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::SymbolStyleSearchResultImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_SymbolStyleSearchResult_H
