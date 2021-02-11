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
/// \file SymbolStyleSearchParameters.h

#ifndef QRT_SymbolStyleSearchParameters_H
#define QRT_SymbolStyleSearchParameters_H

// C++ API headers
#include "ArcGISQt_global.h"

// Qt headers
#include <QStringList>

// STL headers
#include <memory>

namespace QRTImpl { class SymbolStyleSearchParametersImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class SymbolStyleSearchParameters
  {
  public:
    SymbolStyleSearchParameters();
    SymbolStyleSearchParameters(const SymbolStyleSearchParameters& other);
    SymbolStyleSearchParameters(SymbolStyleSearchParameters&& other) noexcept;
    ~SymbolStyleSearchParameters();
    SymbolStyleSearchParameters& operator=(const SymbolStyleSearchParameters& other);
    SymbolStyleSearchParameters& operator=(SymbolStyleSearchParameters&& other) noexcept;

    QStringList categories() const;
    void setCategories(const QStringList& categories);
    bool isCategoriesStrictlyMatch() const;
    void setCategoriesStrictlyMatch(bool strictlyMatch);

    QStringList keys() const;
    void setKeys(const QStringList& keys);
    bool isKeysStrictlyMatch() const;
    void setKeysStrictlyMatch(bool strictlyMatch);

    QStringList names() const;
    void setNames(const QStringList& names);
    bool isNamesStrictlyMatch() const;
    void setNamesStrictlyMatch(bool strictlyMatch);

    QStringList symbolClasses() const;
    void setSymbolClasses(const QStringList& symbolClasses);
    bool isSymbolClassesStrictlyMatch() const;
    void setSymbolClassesStrictlyMatch(bool strictlyMatch);

    QStringList tags() const;
    void setTags(const QStringList& tags);
    bool isTagsStrictlyMatch() const;
    void setTagsStrictlyMatch(bool strictlyMatch);

    bool isEmpty() const;

    /*!
       \internal
      */
    SymbolStyleSearchParameters(const std::shared_ptr<QRTImpl::SymbolStyleSearchParametersImpl>& impl);
    std::shared_ptr<QRTImpl::SymbolStyleSearchParametersImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::SymbolStyleSearchParametersImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_SymbolStyleSearchParameters_H
