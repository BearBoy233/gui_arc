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
/// \file TransformationCatalog.h

#ifndef QRT_TransformationCatalog_H
#define QRT_TransformationCatalog_H

// C++ API headers
#include "Object.h"

namespace QRTImpl { class TransformationCatalogImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class DatumTransformation;
  class SpatialReference;
  class Envelope;

  class TransformationCatalog : public Object
  {
    Q_OBJECT

  public:
    ~TransformationCatalog();

    static TransformationCatalog* instance();

    static QString projectionEngineDirectory();

    static void setProjectionEngineDirectory(const QString& projectionEngineDirectory);

    static QList<DatumTransformation*> transformationsBySuitability(const SpatialReference& inputSpatialReference,
                                                                    const SpatialReference& outputSpatialReference);

    static QList<DatumTransformation*> transformationsBySuitability(const SpatialReference& inputSpatialReference,
                                                                    const SpatialReference& outputSpatialReference,
                                                                    const Envelope& areaOfInterest);

    static DatumTransformation* transformation(const SpatialReference& inputSpatialReference,
                                               const SpatialReference& outputSpatialReference);

    static DatumTransformation* transformation(const SpatialReference& inputSpatialReference,
                                               const SpatialReference& outputSpatialReference,
                                               const Envelope& areaOfInterest);

  private:
    Q_DISABLE_COPY(TransformationCatalog)

    TransformationCatalog(QObject* parent = nullptr);
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_TransformationCatalog_H
