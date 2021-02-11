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
/// \file DictionaryRenderer.h

#ifndef QRT_DictionaryRenderer_H
#define QRT_DictionaryRenderer_H

// C++ API headers
#include "DictionarySymbolStyle.h"
#include "Renderer.h"

// Qt headers
#include <QMap>

namespace QRTImpl { class DictionaryRendererImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class DictionaryRenderer : public Renderer
  {
    Q_OBJECT

  public:
    explicit DictionaryRenderer(DictionarySymbolStyle* dictionarySymbolStyle,
                                QObject* parent = nullptr);

    DictionaryRenderer(DictionarySymbolStyle* dictionarySymbolStyle,
                       const QMap<QString, QString>& symbologyFieldOverrides,
                       const QMap<QString, QString>& textFieldOverrides,
                       QObject* parent = nullptr);

    ~DictionaryRenderer();

    QMap<QString, QString> symbologyFieldOverrides() const;

    QMap<QString, QString> textFieldOverrides() const;

    bool isTextVisible() const;
    void setTextVisible(bool visible);

    double textVisibilityMinScale() const;
    void setTextVisibilityMinScale(double minScale);

    double textVisibilityMaxScale() const;
    void setTextVisibilityMaxScale(double maxScale);

    DictionarySymbolStyle* dictionarySymbolStyle() const;

    /*!
     \internal
    */
    explicit DictionaryRenderer(const std::shared_ptr<QRTImpl::DictionaryRendererImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::DictionaryRendererImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(DictionaryRenderer)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_DictionaryRenderer_H
