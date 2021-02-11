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
/// \file ElevationSource.h

#ifndef QRT_ElevationSource_H
#define QRT_ElevationSource_H

// C++ API headers
#include "Loadable.h"
#include "Object.h"
#include "SceneViewTypes.h"

namespace QRTImpl { class ElevationSourceImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class ElevationSource : public Object, public Loadable
  {
    Q_OBJECT

  public:
    ~ElevationSource();

    bool isEnabled() const;
    void setEnabled(bool enabled);

    QString name() const;
    void setName(const QString& name);

    ElevationSourceType elevationSourceType() const;

    // Loadable Interface methods
    Error loadError() const override;
    LoadStatus loadStatus() const override;
    void cancelLoad() override;
    void load() override;
    void retryLoad() override;

    /*!
       \internal
     */
    ElevationSource(const std::shared_ptr<QRTImpl::ElevationSourceImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::ElevationSourceImpl> getImpl() const;

  signals:
    void doneLoading(Esri::ArcGISRuntime::Error loadError);
    void loadStatusChanged(Esri::ArcGISRuntime::LoadStatus loadStatus);

  protected:
    std::shared_ptr<QRTImpl::ElevationSourceImpl> m_impl;

  private:
    Q_DISABLE_COPY(ElevationSource)
    ElevationSource() = delete;

    void connectSignals();
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ElevationSource_H
