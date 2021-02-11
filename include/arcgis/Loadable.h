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
/// \file Loadable.h

#ifndef QRT_Loadable_H
#define QRT_Loadable_H

// C++ API headers
#include "ArcGISQt_global.h"
#include "Error.h"
#include "MapTypes.h"

// STL headers
#include <memory>

namespace Esri {
namespace ArcGISRuntime {

  class Loadable
  {

  public:
    virtual ~Loadable();

    virtual Error loadError() const = 0;

    virtual LoadStatus loadStatus() const = 0;

    virtual void cancelLoad() = 0;

    virtual void load() = 0;

    virtual void retryLoad() = 0;

  protected:
    Loadable();

  // All implementing classes include these signals:
  //  void doneLoading(Esri::ArcGISRuntime::Error loadError);
  //  void loadStatusChanged(Esri::ArcGISRuntime::LoadStatus loadStatus);

  private:
    Q_DISABLE_COPY(Loadable)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_Loadable_H
