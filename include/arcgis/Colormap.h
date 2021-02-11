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
/// \file Colormap.h

#ifndef QRT_Colormap_H
#define QRT_Colormap_H

// C++ API headers
#include "Object.h"

namespace QRTImpl { class ColormapImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class Colormap : public Object
  {
    Q_OBJECT

  public:
    ~Colormap();
    static Colormap* create(const QList<QColor>& colors, QObject* parent = nullptr);

    Colormap(const std::shared_ptr<QRTImpl::ColormapImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::ColormapImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::ColormapImpl> m_impl;

    Q_DISABLE_COPY(Colormap)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_Colormap_H
