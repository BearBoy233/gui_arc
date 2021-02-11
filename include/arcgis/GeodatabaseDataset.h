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
/// \file GeodatabaseDataset.h

#ifndef QRT_GeodatabaseDataset_H
#define QRT_GeodatabaseDataset_H

// C++ API headers
#include "GeodatabaseTypes.h"
#include "Object.h"

namespace QRTImpl { class GeodatabaseDatasetImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class Geodatabase;

  class GeodatabaseDataset : public Object
  {
    Q_OBJECT

  public:
    ~GeodatabaseDataset();

    virtual Geodatabase* geodatabase() const = 0;
    virtual QString name() const = 0;
    virtual GeodatabaseDatasetType geodatabaseDatasetType() const = 0;

  protected:
    explicit GeodatabaseDataset(QObject* parent = nullptr);

  private:
    Q_DISABLE_COPY(GeodatabaseDataset)

  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_GeodatabaseDataset_H
