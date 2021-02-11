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
/// \file GenerateOfflineMapParameters.h

#ifndef QRT_GenerateOfflineMapParameters_H
#define QRT_GenerateOfflineMapParameters_H

// C++ API headers
#include "Geometry.h"
#include "OfflineMapItemInfo.h"
#include "OfflineMapTypes.h"
#include "TaskTypes.h"

namespace QRTImpl {
  class GenerateOfflineMapParametersImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class GenerateOfflineMapParameters
  {
  public:
    GenerateOfflineMapParameters();
    GenerateOfflineMapParameters(const Geometry& areaOfInterest, double minScale, double maxScale);
    GenerateOfflineMapParameters(const GenerateOfflineMapParameters& other);
    GenerateOfflineMapParameters(GenerateOfflineMapParameters&& other) noexcept;
    ~GenerateOfflineMapParameters();

    GenerateOfflineMapParameters& operator=(const GenerateOfflineMapParameters& other);
    GenerateOfflineMapParameters& operator=(GenerateOfflineMapParameters&& other) noexcept;

    Geometry areaOfInterest() const;
    void setAreaOfInterest(const Geometry& areaOfInterest);

    bool isDefinitionExpressionFilterEnabled() const;
    void setDefinitionExpressionFilterEnabled(bool definitionExpressionFilterEnabled);

    bool isContinueOnErrors() const;
    void setContinueOnErrors(bool continueOnErrors);

    AttachmentSyncDirection attachmentSyncDirection() const;
    void setAttachmentSyncDirection(AttachmentSyncDirection syncDirection);

    bool isIncludeBasemap() const;
    void setIncludeBasemap(bool includeBasemap);

    DestinationTableRowFilter destinationTableRowFilter() const;
    void setDestinationTableRowFilter(DestinationTableRowFilter destinationTableRowFilter);

    OfflineMapItemInfo itemInfo() const;
    void setItemInfo(const OfflineMapItemInfo& offlineMapItemInfo);

    double minScale() const;
    void setMinScale(double minScale);

    double maxScale() const;
    void setMaxScale(double maxScale);

    ReturnLayerAttachmentOption returnLayerAttachmentOption() const;
    void setReturnLayerAttachmentOption(ReturnLayerAttachmentOption layerAttachmentOption);

    bool isReturnSchemaOnlyForEditableLayers() const;
    void setReturnSchemaOnlyForEditableLayers(bool returnSchemaOnly);

    std::shared_ptr<QRTImpl::GenerateOfflineMapParametersImpl> getImpl() const;
    /*!
       \internal
     */
    explicit GenerateOfflineMapParameters(const std::shared_ptr<QRTImpl::GenerateOfflineMapParametersImpl>& impl);

  private:
    std::shared_ptr<QRTImpl::GenerateOfflineMapParametersImpl> m_impl;
  };
}
}

#endif // QRT_GenerateOfflineMapParameters_H
