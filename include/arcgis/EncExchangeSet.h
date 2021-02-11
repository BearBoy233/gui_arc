// COPYRIGHT 1995-2017 ESRI
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
/// \file Map.h

#ifndef QRT_EncExchangeSet_H
#define QRT_EncExchangeSet_H

// C++ API headers
#include "EncDataset.h"
#include "Loadable.h"
#include "Object.h"

namespace QRTImpl { class EncExchangeSetImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class EncExchangeSet : public Object, public Loadable
  {
    Q_OBJECT

  public:
    explicit EncExchangeSet(const QStringList& paths, QObject* parent = nullptr);
    ~EncExchangeSet();

    // properties
    QList<EncDataset*> datasets() const;
    QStringList paths() const;
    QString readme() const;

    // Loadable Interface methods
    Error loadError() const override;
    LoadStatus loadStatus() const override;
    void cancelLoad() override;
    void load() override;
    void retryLoad() override;

    /*! \internal */
    EncExchangeSet(const std::shared_ptr<QRTImpl::EncExchangeSetImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::EncExchangeSetImpl> getImpl() const;

  signals:
    void doneLoading(Esri::ArcGISRuntime::Error loadError);
    void loadStatusChanged(Esri::ArcGISRuntime::LoadStatus loadStatus);

  private:
    Q_DISABLE_COPY(EncExchangeSet)

    std::shared_ptr<QRTImpl::EncExchangeSetImpl> m_impl;

    void connectSignals();
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_EncExchangeSet_H
