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
/// \file Surface.h

#ifndef QRT_Surface_H
#define QRT_Surface_H

// C++ API headers
#include "BackgroundGrid.h"
#include "ElevationSourceListModel.h"
#include "Loadable.h"
#include "Object.h"
#include "Point.h"
#include "TaskWatcher.h"

namespace QRTImpl { class SurfaceImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class Surface : public Object, public Loadable
  {
    Q_OBJECT

  public:
    explicit Surface(QObject* parent = nullptr);
    explicit Surface(const QList<ElevationSource*>& elevationSources, QObject* parent = nullptr);
    ~Surface();

    float elevationExaggeration() const;
    void setElevationExaggeration(float exaggeration);

    ElevationSourceListModel* elevationSources() const;

    bool isEnabled() const;
    void setEnabled(bool enabled);

    QString name() const;
    void setName(const QString& name);

    BackgroundGrid backgroundGrid() const;
    void setBackgroundGrid(const BackgroundGrid& backgroundGrid);

    TaskWatcher locationToElevation(const Point& location);

    // Loadable Interface methods
    Error loadError() const override;
    LoadStatus loadStatus() const override;
    void cancelLoad() override;
    void load() override;
    void retryLoad() override;

    /*!
       \internal
     */
    Surface(const std::shared_ptr<QRTImpl::SurfaceImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::SurfaceImpl> getImpl() const;

  signals:
    void doneLoading(Esri::ArcGISRuntime::Error loadError);
    void loadStatusChanged(Esri::ArcGISRuntime::LoadStatus loadStatus);
    void locationToElevationCompleted(QUuid taskId, double elevation);

  private:
    Q_DISABLE_COPY(Surface)

    void connectSignals();

    std::shared_ptr<QRTImpl::SurfaceImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_Surface_H
