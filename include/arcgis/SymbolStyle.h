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
/// \file SymbolStyle.h

#ifndef QRT_SymbolStyle_H
#define QRT_SymbolStyle_H

// C++ API headers
#include "Loadable.h"
#include "Object.h"
#include "Symbol.h"
#include "SymbolStyleSearchParameters.h"
#include "SymbolStyleSearchResultListModel.h"
#include "SymbolTypes.h"
#include "TaskWatcher.h"

// Qt headers
#include <QStringList>

namespace QRTImpl { class SymbolStyleImpl; }

namespace Esri {
namespace ArcGISRuntime {

class SymbolStyle : public Object, public Loadable
{
  Q_OBJECT

public:
  explicit SymbolStyle(const QString& styleLocation, QObject* parent = nullptr);

  ~SymbolStyle();

  QString styleLocation() const;

  SymbolStyleType symbolStyleType() const;

  TaskWatcher fetchSymbol(const QStringList& keys);

  TaskWatcher searchSymbols(const SymbolStyleSearchParameters& searchParameters);

  TaskWatcher defaultSearchParameters();

  // Loadable
  Error loadError() const override;
  LoadStatus loadStatus() const override;
  void cancelLoad() override;
  void load() override;
  void retryLoad() override;

  /*! \internal */
  explicit SymbolStyle(const std::shared_ptr<QRTImpl::SymbolStyleImpl>& impl, QObject* parent = nullptr);
  std::shared_ptr<QRTImpl::SymbolStyleImpl> getImpl() const;

signals:
  void defaultSearchParametersCompleted(QUuid taskId, const Esri::ArcGISRuntime::SymbolStyleSearchParameters& searchParameters);
  void searchSymbolsCompleted(QUuid taskId, Esri::ArcGISRuntime::SymbolStyleSearchResultListModel* searchResults);
  void fetchSymbolCompleted(QUuid taskId, Esri::ArcGISRuntime::Symbol* symbol);
  // Loadable signals
  void doneLoading(Esri::ArcGISRuntime::Error loadError);
  void loadStatusChanged(Esri::ArcGISRuntime::LoadStatus loadStatus);

protected:
  std::shared_ptr<QRTImpl::SymbolStyleImpl> m_impl;

private:
  Q_DISABLE_COPY(SymbolStyle)
  void connectSignals();
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_SymbolStyle_H
