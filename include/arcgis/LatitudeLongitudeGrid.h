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
/// \file LatitudeLongitudeGrid.h

#ifndef QRT_LatitudeLongitudeGrid_H
#define QRT_LatitudeLongitudeGrid_H

// C++ API headers
#include "Grid.h"

namespace QRTImpl {
  class LatitudeLongitudeGridImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class LatitudeLongitudeGrid : public Grid
  {
    Q_OBJECT

  public:
    LatitudeLongitudeGrid(QObject* parent = nullptr);
    ~LatitudeLongitudeGrid();

    LatitudeLongitudeGridLabelFormat labelFormat() const;
    void setLabelFormat(LatitudeLongitudeGridLabelFormat labelFormat);

    /*! \internal */
    LatitudeLongitudeGrid(const std::shared_ptr<QRTImpl::LatitudeLongitudeGridImpl>& impl, QObject* parent = nullptr);

  private:
    Q_DISABLE_COPY(LatitudeLongitudeGrid)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_LatitudeLongitudeGrid_H
