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
/// \file GenerateOfflineMapParameterOverrides.h

#ifndef QRT_GenerateOfflineMapParameterOverrides_H
#define QRT_GenerateOfflineMapParameterOverrides_H

// C++ API headers
#include "ExportTileCacheParameters.h"
#include "ExportVectorTilesParameters.h"
#include "GenerateGeodatabaseParameters.h"
#include "Object.h"
#include "OfflineMapItemInfo.h"
#include "OfflineMapParametersKey.h"

namespace QRTImpl
{
  class GenerateOfflineMapParameterOverridesImpl;
}

namespace Esri
{
  namespace ArcGISRuntime
  {
    class GenerateOfflineMapParameterOverrides : public Object
    {
      Q_OBJECT
    public:
      ~GenerateOfflineMapParameterOverrides();

      QMap<OfflineMapParametersKey, ExportTileCacheParameters> exportTileCacheParameters() const;
      void setExportTileCacheParameters(const QMap<OfflineMapParametersKey, ExportTileCacheParameters>& exportTileCacheParameters);

      QMap<OfflineMapParametersKey, ExportVectorTilesParameters> exportVectorTilesParameters() const;
      void setExportVectorTilesParameters(const QMap<OfflineMapParametersKey, ExportVectorTilesParameters>& exportVectorTilesParameters);

      QMap<OfflineMapParametersKey, GenerateGeodatabaseParameters> generateGeodatabaseParameters() const;
      void setGenerateGeodatabaseParameters(const QMap<OfflineMapParametersKey, GenerateGeodatabaseParameters>& generateGeodatabaseParameters);

      /*! \internal */
      std::shared_ptr<QRTImpl::GenerateOfflineMapParameterOverridesImpl> getImpl() const;
      /*! \internal */
      GenerateOfflineMapParameterOverrides(const std::shared_ptr<QRTImpl::GenerateOfflineMapParameterOverridesImpl>& impl, QObject* parent = nullptr);

    private:
      GenerateOfflineMapParameterOverrides() = delete;

      std::shared_ptr<QRTImpl::GenerateOfflineMapParameterOverridesImpl> m_impl;
    };
  } // namespace ArcGISRuntime
} // namespace Esri

Q_DECLARE_METATYPE(Esri::ArcGISRuntime::GenerateOfflineMapParameterOverrides*)

#endif // QRT_GenerateOfflineMapParameterOverrides_H
