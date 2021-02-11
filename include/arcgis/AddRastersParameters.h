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
/// \file AddRastersParameters.h

#ifndef QRT_AddRastersParameters_H
#define QRT_AddRastersParameters_H

// C++ API headers
#include "RasterTypes.h"

// Qt headers
#include <QString>

// STL headers
#include <memory>

namespace QRTImpl { class AddRastersParametersImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class AddRastersParameters
  {
  public:
    AddRastersParameters();
    AddRastersParameters(const AddRastersParameters& other);
    AddRastersParameters(AddRastersParameters&& other) noexcept;

    AddRastersParameters& operator=(const AddRastersParameters& other);
    AddRastersParameters& operator=(AddRastersParameters&& other) noexcept;

    virtual ~AddRastersParameters();

    AddRastersParametersType addRastersParametersType() const;

    QString filter() const;
    void setFilter(const QString& filter);

    QString inputDirectory() const;
    void setInputDirectory(const QString& inputDirectory);

    QString inputFile() const;
    void setInputFile(const QString& inputFile);

    double maxPixelSizeFactor() const;
    void setMaxPixelSizeFactor(double maxPixelSizeFactor);

    double minPixelSizeFactor() const;
    void setMinPixelSizeFactor(double minPixelSizeFactor);

    QString rasterFunctionTemplateFile() const;
    void setRasterFunctionTemplateFile(const QString& templateFile);

    /*!
       \internal
     */
    AddRastersParameters(const std::shared_ptr<QRTImpl::AddRastersParametersImpl>& impl);
    std::shared_ptr<QRTImpl::AddRastersParametersImpl> getImpl() const;

  protected:
    std::shared_ptr<QRTImpl::AddRastersParametersImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_AddRastersParameters_H
