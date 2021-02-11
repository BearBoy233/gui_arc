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
/// \file BackgroundGrid.h

#ifndef QRT_BackgroundGrid_H
#define QRT_BackgroundGrid_H

// Qt headers
#include <QColor>

// STL headers
#include <memory>

namespace QRTImpl { class BackgroundGridImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class BackgroundGrid
  {

  public:
    BackgroundGrid();
    BackgroundGrid(const QColor& color, const QColor& gridLineColor, float gridLineWidth, float gridSize);

    BackgroundGrid(const BackgroundGrid& other);
    BackgroundGrid(BackgroundGrid&& other) noexcept;
    BackgroundGrid& operator=(const BackgroundGrid& other);
    BackgroundGrid& operator=(BackgroundGrid&& other) noexcept;

    ~BackgroundGrid();

    QColor color() const;
    void setColor(const QColor& color);

    QColor gridLineColor() const;
    void setGridLineColor(const QColor& color);

    double gridLineWidth() const;
    void setGridLineWidth(double gridLineWidth);

    double gridSize() const;
    void setGridSize(double gridSize);

    bool isVisible() const;
    void setVisible(bool visible);

    /*!
      \internal
     */
    BackgroundGrid(const std::shared_ptr<QRTImpl::BackgroundGridImpl>& impl);

    /*!
      \internal
     */
    std::shared_ptr<QRTImpl::BackgroundGridImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::BackgroundGridImpl> m_impl;
  };

}
}
#endif // QRT_BackgroundGrid_H
