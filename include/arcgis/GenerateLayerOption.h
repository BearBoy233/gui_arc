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
/// \file GenerateLayerOption.h

#ifndef QRT_GenerateLayerOption_H
#define QRT_GenerateLayerOption_H

// C++ API headers
#include "TaskTypes.h"

// Qt headers
#include <QtGlobal>

// STL headers
#include <memory>

namespace QRTImpl {
  class GenerateLayerOptionImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class GenerateLayerOption
  {

  public:
    GenerateLayerOption();
    explicit GenerateLayerOption(qint64 layerId);
    GenerateLayerOption(qint64 layerId, bool includeRelated);
    GenerateLayerOption(qint64 layerId, const QString& whereClause);

    GenerateLayerOption(const GenerateLayerOption& other);
    GenerateLayerOption(GenerateLayerOption&& other) noexcept;
    ~GenerateLayerOption();

    GenerateLayerOption& operator=(const GenerateLayerOption& other);
    GenerateLayerOption& operator=(GenerateLayerOption&& other) noexcept;

    bool isEmpty() const;

    bool isIncludeRelated() const;
    void setIncludeRelated(bool includeRelated);

    qint64 layerId() const;
    void setLayerId(qint64 layerOrTableId);

    bool isUseGeometry() const;
    void setUseGeometry(bool useGeometry);

    QString whereClause() const;
    void setWhereClause(const QString& whereClause);

    GenerateLayerQueryOption queryOption() const;
    void setQueryOption(GenerateLayerQueryOption queryOption);

    /*!
      \internal
     */
    explicit GenerateLayerOption(const std::shared_ptr<QRTImpl::GenerateLayerOptionImpl>& impl);

    /*!
      \internal
     */
    std::shared_ptr<QRTImpl::GenerateLayerOptionImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::GenerateLayerOptionImpl> m_impl;
  };
}
}

#endif // QRT_GenerateLayerOption_H
