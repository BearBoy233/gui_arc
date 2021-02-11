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
/// \file EncDataset.h

#ifndef QRT_EncDataset_H
#define QRT_EncDataset_H

// C++ API headers
#include "Envelope.h"
#include "Object.h"

// STL headers
#include <memory>

namespace QRTImpl { class EncDatasetImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class EncDataset : public Object
  {
    Q_OBJECT

  public:
    ~EncDataset();

    bool isAuthorized() const;
    QString description() const;
    Envelope extent() const;
    QString name() const;
    QString volumeName() const;

    /*! \internal */
    explicit EncDataset(const std::shared_ptr<QRTImpl::EncDatasetImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::EncDatasetImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(EncDataset)

    std::shared_ptr<QRTImpl::EncDatasetImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_EncDataset_H
