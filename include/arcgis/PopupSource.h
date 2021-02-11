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
/// \file PopupSource.h

#ifndef QRT_PopupSource_H
#define QRT_PopupSource_H

// C++ API headers
#include "ArcGISQt_global.h"

namespace Esri {
namespace ArcGISRuntime {

  class PopupDefinition;

  class PopupSource
  {
  public:
    virtual ~PopupSource();
    virtual bool isPopupEnabled() const = 0;
    virtual void setPopupEnabled(bool popupEnabled) = 0;

    virtual PopupDefinition* popupDefinition() const = 0;
    virtual void setPopupDefinition(PopupDefinition* popupDefinition) = 0;

  protected:
    explicit PopupSource();

  private:
    Q_DISABLE_COPY(PopupSource)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_PopupSource_H
