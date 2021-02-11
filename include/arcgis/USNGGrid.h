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
/// \file USNGGrid.h

#ifndef QRT_USNGGrid_H
#define QRT_USNGGrid_H

// C++ API headers
#include "Grid.h"

namespace QRTImpl {
  class USNGGridImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class USNGGrid : public Grid
  {
    Q_OBJECT

  public:
    USNGGrid(QObject* parent = nullptr);
    ~USNGGrid();

    USNGGridLabelUnit labelUnit() const;
    void setLabelUnit(USNGGridLabelUnit labelUnit);

    /*! \internal */
    USNGGrid(const std::shared_ptr<QRTImpl::USNGGridImpl>& impl, QObject* parent = nullptr);

  private:
    Q_DISABLE_COPY(USNGGrid)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_USNGGrid_H
