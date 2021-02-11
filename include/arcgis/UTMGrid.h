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
/// \file UTMGrid.h

#ifndef QRT_UTMGrid_H
#define QRT_UTMGrid_H

// C++ API headers
#include "Grid.h"

namespace QRTImpl {
  class UTMGridImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class UTMGrid : public Grid
  {
    Q_OBJECT

  public:
    UTMGrid(QObject* parent = nullptr);
    ~UTMGrid();

    UTMGrid(const std::shared_ptr<QRTImpl::UTMGridImpl>& impl, QObject* parent = nullptr);

  private:
    Q_DISABLE_COPY(UTMGrid)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_UTMGrid_H
