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
/// \file TableSublayerSource.h

#ifndef QRT_TableSublayerSource_H
#define QRT_TableSublayerSource_H

// C++ API headers
#include "Field.h"
#include "SublayerSource.h"

namespace QRTImpl { class TableSublayerSourceImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class TableSublayerSource : public SublayerSource
  {
    Q_OBJECT

  public:
    TableSublayerSource(const QString& workspaceId, const QString& dataSourceName, QObject* parent = nullptr);
    ~TableSublayerSource();

    QString dataSourceName() const;

    QString geodatabaseVersion() const;
    void setGeodatabaseVersion(const QString& geodatabaseVersion);

    QString workspaceId() const;

    /*! \internal */
    explicit TableSublayerSource(const std::shared_ptr<QRTImpl::TableSublayerSourceImpl>& impl, QObject* parent = nullptr);
    /*! \internal */
    std::shared_ptr<QRTImpl::TableSublayerSourceImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(TableSublayerSource)
    TableSublayerSource() = delete;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_TableSublayerSource_H
