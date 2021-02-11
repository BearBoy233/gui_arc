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
/// \file Graphic.h

#ifndef QRT_Graphic_H
#define QRT_Graphic_H

// C++ API headers
#include "AttributeListModel.h"
#include "GeoElement.h"
#include "Geometry.h"
#include "Symbol.h"

// Qt headers
#include <QVariantMap>

namespace QRTImpl { class GraphicImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class GraphicsOverlay;

  class Graphic : public Object, public GeoElement
  {
    Q_OBJECT

  public:
    explicit Graphic(QObject* parent = nullptr);
    Graphic(const QVariantMap& attributes, QObject* parent = nullptr);
    Graphic(const Geometry& geometry, QObject* parent = nullptr);
    Graphic(const Geometry& geometry, const QVariantMap& attributes, QObject* parent = nullptr);
    Graphic(const Geometry& geometry, Symbol* symbol, QObject* parent = nullptr);
    Graphic(const Geometry& geometry, const QVariantMap& attributes, Symbol* symbol, QObject* parent = nullptr);
    ~Graphic();

    bool operator==(Graphic* other) const;

    Geometry geometry() const override;
    void setGeometry(const Geometry& geometry) override;

    bool isSelected() const;
    void setSelected(bool value);

    bool isVisible() const;
    void setVisible(bool value);

    Symbol* symbol() const;
    void setSymbol(Symbol* symbol);

    int zIndex() const;
    void setZIndex(int value);

    AttributeListModel* attributes() const override;

    GraphicsOverlay* graphicsOverlay() const;

    Graphic(const std::shared_ptr<QRTImpl::GraphicImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::GraphicImpl> getImpl() const;
    std::shared_ptr<QRTImpl::GeoElementImpl> iGetImpl() const override;

  signals:
    void geometryChanged();

  private:
    Q_DISABLE_COPY(Graphic)

    std::shared_ptr<QRTImpl::GraphicImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

Q_DECLARE_METATYPE(Esri::ArcGISRuntime::Graphic*)

#endif // QRT_Graphic_H
