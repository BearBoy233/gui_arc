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
/// \file TableQuerySublayerSource.h

#ifndef QRT_TableQuerySublayerSource_H
#define QRT_TableQuerySublayerSource_H

// C++ API headers
#include "Field.h"
#include "GeometryTypes.h"
#include "SpatialReference.h"
#include "SublayerSource.h"

namespace QRTImpl { class TableQuerySublayerSourceImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class TableQuerySublayerSource : public SublayerSource
  {
    Q_OBJECT

  public:
    TableQuerySublayerSource(const QString& workspaceId, const QString& sqlQuery, const QStringList& objectIdFieldNames, QObject* parent = nullptr);
    ~TableQuerySublayerSource();

    QString sqlQuery() const;

    GeometryType geometryType() const;
    void setGeometryType(GeometryType geometryType);

    QStringList objectIdFieldNames() const;

    SpatialReference spatialReference() const;
    void setSpatialReference(const SpatialReference& spatialReference);

    QString workspaceId() const;

    /*! \internal */
    explicit TableQuerySublayerSource(const std::shared_ptr<QRTImpl::TableQuerySublayerSourceImpl>& impl, QObject* parent = nullptr);
    /*! \internal */
    std::shared_ptr<QRTImpl::TableQuerySublayerSourceImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(TableQuerySublayerSource)
    TableQuerySublayerSource() = delete;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_TableQuerySublayerSource_H
