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
/// \file TransportationNetworkDataset.h

#ifndef QRT_TransportationNetworkDataset_H
#define QRT_TransportationNetworkDataset_H

// C++ API headers
#include "GeodatabaseDataset.h"
#include "GeodatabaseTypes.h"
#include "Object.h"

namespace QRTImpl { class TransportationNetworkDatasetImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class Geodatabase;

  class TransportationNetworkDataset : public GeodatabaseDataset
  {
    Q_OBJECT

  public:
    ~TransportationNetworkDataset();

    QString alias() const;

    Geodatabase *geodatabase() const override;

    QString name() const override;

    GeodatabaseDatasetType geodatabaseDatasetType() const override;

    TransportationNetworkDataset(const std::shared_ptr<QRTImpl::TransportationNetworkDatasetImpl>& impl, QObject* parent = nullptr);

    std::shared_ptr<QRTImpl::TransportationNetworkDatasetImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(TransportationNetworkDataset)
    TransportationNetworkDataset() = delete;

    std::shared_ptr<QRTImpl::TransportationNetworkDatasetImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_GeodatabaseDataset_H
