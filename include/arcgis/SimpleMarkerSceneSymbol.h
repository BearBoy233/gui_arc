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
/// \file SimpleMarkerSceneSymbol.h

#ifndef QRT_SimpleMarkerSceneSymbol_H
#define QRT_SimpleMarkerSceneSymbol_H

// C++ API headers
#include "MarkerSceneSymbol.h"

namespace QRTImpl { class SimpleMarkerSceneSymbolImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class SimpleMarkerSceneSymbol : public MarkerSceneSymbol
  {
    Q_OBJECT

  public:
    explicit SimpleMarkerSceneSymbol(QObject* parent = nullptr);
    SimpleMarkerSceneSymbol(SimpleMarkerSceneSymbolStyle style, const QColor& color, double height, double width, double depth, SceneSymbolAnchorPosition anchorPosition, QObject* parent = nullptr);
    ~SimpleMarkerSceneSymbol();

    SimpleMarkerSceneSymbolStyle style() const;
    void setStyle(SimpleMarkerSceneSymbolStyle style);

    static SimpleMarkerSceneSymbol* cone(const QColor& color, double diameter, double height, QObject* parent = nullptr);
    static SimpleMarkerSceneSymbol* cone(const QColor& color, double diameter, double height, SceneSymbolAnchorPosition anchorPosition, QObject* parent = nullptr);
    static SimpleMarkerSceneSymbol* cube(const QColor& color, double size, QObject* parent = nullptr);
    static SimpleMarkerSceneSymbol* cube(const QColor& color, double size, SceneSymbolAnchorPosition anchorPosition, QObject* parent = nullptr);
    static SimpleMarkerSceneSymbol* cylinder(const QColor& color, double diameter, double height, QObject* parent = nullptr);
    static SimpleMarkerSceneSymbol* cylinder(const QColor& color, double diameter, double height, SceneSymbolAnchorPosition anchorPosition, QObject* parent = nullptr);
    static SimpleMarkerSceneSymbol* diamond(const QColor& color, double size, double height, QObject* parent = nullptr);
    static SimpleMarkerSceneSymbol* diamond(const QColor& color, double size, double height, SceneSymbolAnchorPosition anchorPosition, QObject* parent = nullptr);
    static SimpleMarkerSceneSymbol* sphere(const QColor& color, double diameter, QObject* parent = nullptr);
    static SimpleMarkerSceneSymbol* sphere(const QColor& color, double diameter, SceneSymbolAnchorPosition anchorPosition, QObject* parent = nullptr);
    static SimpleMarkerSceneSymbol* tetrahedron(const QColor& color, double size, double height, QObject* parent = nullptr);
    static SimpleMarkerSceneSymbol* tetrahedron(const QColor& color, double size, double height, SceneSymbolAnchorPosition anchorPosition, QObject* parent = nullptr);

    /*! \internal */
    explicit SimpleMarkerSceneSymbol(const std::shared_ptr<QRTImpl::SimpleMarkerSceneSymbolImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::SimpleMarkerSceneSymbolImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(SimpleMarkerSceneSymbol)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_SimpleMarkerSceneSymbol_H
