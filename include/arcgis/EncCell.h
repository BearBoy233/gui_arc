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

#ifndef QRT_EncCell_H
#define QRT_EncCell_H

// C++ API headers
#include "EncDataset.h"
#include "Loadable.h"
#include "Object.h"

namespace QRTImpl { class EncCellImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class EncCell : public Object, public Loadable
  {
    Q_OBJECT

  public:
    explicit EncCell(EncDataset* dataset, QObject* parent = nullptr);
    explicit EncCell(const QString& path, QObject* parent = nullptr);
    ~EncCell();

    // properties
    EncDataset* dataset() const;
    QString path() const;

    // Loadable Interface methods
    Error loadError() const override;
    LoadStatus loadStatus() const override;
    void cancelLoad() override;
    void load() override;
    void retryLoad() override;

    /*! \internal */
    EncCell(const std::shared_ptr<QRTImpl::EncCellImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::EncCellImpl> getImpl() const;

  signals:
    void doneLoading(Esri::ArcGISRuntime::Error loadError);
    void loadStatusChanged(Esri::ArcGISRuntime::LoadStatus loadStatus);

  private:
    Q_DISABLE_COPY(EncCell)

    std::shared_ptr<QRTImpl::EncCellImpl> m_impl;

    void connectSignals();
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_EncCell_H
