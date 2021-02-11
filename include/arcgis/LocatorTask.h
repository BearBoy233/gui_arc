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
/// \file LocatorTask.h

#ifndef QRT_LocatorTask_H
#define QRT_LocatorTask_H

// C++ API headers
#include "Credential.h"
#include "GeocodeParameters.h"
#include "GeocodeResult.h"
#include "Loadable.h"
#include "LocatorInfo.h"
#include "Object.h"
#include "Point.h"
#include "RemoteResource.h"
#include "ReverseGeocodeParameters.h"
#include "SuggestListModel.h"
#include "SuggestParameters.h"
#include "SuggestResult.h"
#include "TaskWatcher.h"

// Qt headers
#include <QMap>
#include <QUrl>
#include <QUuid>

namespace QRTImpl { class LocatorTaskImpl; }

namespace Esri {
namespace ArcGISRuntime {

class LocatorTask : public Object, public Loadable, public RemoteResource
{
  Q_OBJECT

public:
  LocatorTask(const QUrl& url, QObject* parent = nullptr);
  LocatorTask(const QUrl& url, Credential* credential, QObject* parent = nullptr);
  ~LocatorTask();

  LocatorInfo locatorInfo() const;

  TaskWatcher geocode(const QString& searchText);

  TaskWatcher geocodeWithParameters(const QString& searchText, const GeocodeParameters& parameters);

  TaskWatcher geocodeWithSearchValues(const QMap<QString, QString>& searchValues);

  TaskWatcher geocodeWithSearchValuesAndParameters(const QMap<QString, QString>& searchValues, const GeocodeParameters& parameters);

  TaskWatcher geocodeWithSuggestResult(const SuggestResult& suggestResult);

  TaskWatcher geocodeWithSuggestResultAndParameters(const SuggestResult& suggestResult, const GeocodeParameters& parameters);

  TaskWatcher reverseGeocode(const Point& location);

  TaskWatcher reverseGeocodeWithParameters(const Point& location, const ReverseGeocodeParameters& parameters);

  SuggestListModel* suggestions() const;

  Error loadError() const override;
  LoadStatus loadStatus() const override;
  void cancelLoad() override;
  void load() override;
  void retryLoad() override;

  // RemoteResource interface methods
  QUrl url() const override;
  Credential* credential() const override;
  RequestConfiguration requestConfiguration() const override;
  void setRequestConfiguration(const RequestConfiguration& requestConfiguration) override;

  /*!
     \internal
   */
  LocatorTask(const std::shared_ptr<QRTImpl::LocatorTaskImpl>& impl, QObject* parent = nullptr);
  std::shared_ptr<QRTImpl::LocatorTaskImpl> getImpl() const;

signals:
  void geocodeCompleted(QUuid taskId, const QList<Esri::ArcGISRuntime::GeocodeResult>& geocodeResults);
  void doneLoading(Esri::ArcGISRuntime::Error loadError);
  void loadStatusChanged(Esri::ArcGISRuntime::LoadStatus loadStatus);

private:
  Q_DISABLE_COPY(LocatorTask)

  void connectSignals();

  std::shared_ptr<QRTImpl::LocatorTaskImpl> m_impl;
  mutable SuggestListModel* m_suggestModel = nullptr;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_LocatorTask_H
