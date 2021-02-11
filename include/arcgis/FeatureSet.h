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
/// \file FeatureSet.h

#ifndef QRT_FeatureSet_H
#define QRT_FeatureSet_H

// C++ API headers
#include "FeatureIterator.h"
#include "Field.h"
#include "GeometryTypes.h"
#include "SpatialReference.h"

// STL headers
#include <memory>

namespace QRTImpl { class FeatureSetImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class FeatureSet
  {

  public:
    virtual ~FeatureSet();

    virtual QList<Field> fields() const = 0;
    virtual GeometryType geometryType() const = 0;
    virtual SpatialReference spatialReference() const = 0;
    virtual FeatureIterator iterator() const = 0;

    /*! \internal */
    virtual std::shared_ptr<QRTImpl::FeatureSetImpl> iGetImpl() const = 0;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_FeatureSet_H
