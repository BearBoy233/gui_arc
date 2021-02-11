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
/// \file GenerateGeodatabaseParameters.h

#ifndef QRT_GenerateGeodatabaseParameters_H
#define QRT_GenerateGeodatabaseParameters_H

// C++ API headers
#include "GenerateLayerOption.h"
#include "Geometry.h"
#include "SpatialReference.h"
#include "TaskTypes.h"

namespace QRTImpl {
  class GenerateGeodatabaseParametersImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class GenerateGeodatabaseParameters
  {

  public:
    GenerateGeodatabaseParameters();
    GenerateGeodatabaseParameters(const GenerateGeodatabaseParameters& other);
    GenerateGeodatabaseParameters(GenerateGeodatabaseParameters&& other) noexcept;
    ~GenerateGeodatabaseParameters();

    GenerateGeodatabaseParameters& operator=(const GenerateGeodatabaseParameters& other);
    GenerateGeodatabaseParameters& operator=(GenerateGeodatabaseParameters&& other) noexcept;

    bool isEmpty() const;

    AttachmentSyncDirection attachmentSyncDirection() const;
    void setAttachmentSyncDirection(AttachmentSyncDirection attachmentSyncDirection);

    Geometry extent() const;
    void setExtent(const Geometry& extent);

    QList<GenerateLayerOption> layerOptions() const;
    void setLayerOptions(const QList<GenerateLayerOption>& generateLayerOptions);

    SpatialReference outSpatialReference() const;
    void setOutSpatialReference(const SpatialReference& outSpatialReference);

    bool isReturnAttachments() const;
    void setReturnAttachments(bool returnAttachments);

    SyncModel syncModel() const;
    void setSyncModel(SyncModel syncModel);

    std::shared_ptr<QRTImpl::GenerateGeodatabaseParametersImpl> getImpl() const;
    /*!
       \internal
     */
    explicit GenerateGeodatabaseParameters(const std::shared_ptr<QRTImpl::GenerateGeodatabaseParametersImpl>& impl);

  private:
    std::shared_ptr<QRTImpl::GenerateGeodatabaseParametersImpl> m_impl;
  };
}
}

#endif // QRT_GenerateGeodatabaseParameters_H
