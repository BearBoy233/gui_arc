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
/// \file MGRSGrid.h

#ifndef QRT_MGRSGrid_H
#define QRT_MGRSGrid_H

// C++ API headers
#include "Grid.h"

namespace QRTImpl {
  class MGRSGridImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class MGRSGrid : public Grid
  {
    Q_OBJECT

  public:
    MGRSGrid(QObject* parent = nullptr);
    ~MGRSGrid();

    MGRSGridLabelUnit labelUnit() const;
    void setLabelUnit(MGRSGridLabelUnit labelUnit);

    /*! \internal */
    MGRSGrid(const std::shared_ptr<QRTImpl::MGRSGridImpl>& impl, QObject* parent = nullptr);

  private:
    Q_DISABLE_COPY(MGRSGrid)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_MGRSGrid_H
