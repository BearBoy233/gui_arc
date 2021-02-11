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
/// \file DownloadPreplannedOfflineMapParameters.h

#ifndef QRT_DownloadPreplannedOfflineMapParameters_H
#define QRT_DownloadPreplannedOfflineMapParameters_H

// C++ API headers
#include "PreplannedMapArea.h"

namespace QRTImpl {
  class DownloadPreplannedOfflineMapParametersImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class DownloadPreplannedOfflineMapParameters
  {
  public:
    DownloadPreplannedOfflineMapParameters();
    explicit DownloadPreplannedOfflineMapParameters(PreplannedMapArea* preplannedMapArea);
    DownloadPreplannedOfflineMapParameters(const DownloadPreplannedOfflineMapParameters& other);
    DownloadPreplannedOfflineMapParameters(DownloadPreplannedOfflineMapParameters&& other) noexcept;
    ~DownloadPreplannedOfflineMapParameters();

    DownloadPreplannedOfflineMapParameters& operator=(const DownloadPreplannedOfflineMapParameters& other);
    DownloadPreplannedOfflineMapParameters& operator=(DownloadPreplannedOfflineMapParameters&& other) noexcept;

    bool isContinueOnErrors() const;
    void setContinueOnErrors(bool continueOnErrors);

    bool isIncludeBasemap() const;
    void setIncludeBasemap(bool includeBasemap);

    PreplannedMapArea* preplannedMapArea(QObject* parent = nullptr) const;
    void setPreplannedMapArea(PreplannedMapArea* preplannedMapArea);

    /*!
       \internal
     */
    std::shared_ptr<QRTImpl::DownloadPreplannedOfflineMapParametersImpl> getImpl() const;

    /*!
       \internal
     */
    explicit DownloadPreplannedOfflineMapParameters(const std::shared_ptr<QRTImpl::DownloadPreplannedOfflineMapParametersImpl>& impl);

  private:
    std::shared_ptr<QRTImpl::DownloadPreplannedOfflineMapParametersImpl> m_impl;
  };
} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_DownloadPreplannedOfflineMapParameters_H
