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
/// \file Grid.h

#ifndef QRT_Grid_H
#define QRT_Grid_H

// C++ API headers
#include "MapViewTypes.h"
#include "Object.h"
#include "Symbol.h"

namespace QRTImpl { class GridImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class Grid : public Object
  {
    Q_OBJECT

  public:
    ~Grid();

    bool isVisible() const;
    void setVisible(bool visible);

    double labelOffset() const;
    void setLabelOffset(double labelOffset);

    GridLabelPosition labelPosition() const;
    void setLabelPosition(GridLabelPosition labelPosition);

    bool isLabelsVisible() const;
    void setLabelsVisible(bool labelsVisible);

    int levelCount() const;

    GridType gridType() const;

    Symbol* lineSymbol(int level) const;
    void setLineSymbol(int level, Symbol* lineSymbol);

    Symbol* textSymbol(int level) const;
    void setTextSymbol(int level, Symbol* textSymbol);

    /*! \internal */
    Grid(const std::shared_ptr<QRTImpl::GridImpl>& impl, QObject* parent = nullptr);
    /*! \internal */
    std::shared_ptr<QRTImpl::GridImpl> getImpl() const;

  protected:
    Q_DISABLE_COPY(Grid)
    std::shared_ptr<QRTImpl::GridImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_Grid_H
