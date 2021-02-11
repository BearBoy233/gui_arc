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
/// \file ShapefileFeatureTable.h

#ifndef QRT_ShapefileFeatureTable_H
#define QRT_ShapefileFeatureTable_H

// C++ API headers
#include "FeatureTable.h"
#include "ShapefileInfo.h"

namespace QRTImpl { class ShapefileFeatureTableImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class ShapefileFeatureTable : public FeatureTable
  {
    Q_OBJECT

  public:
    ShapefileFeatureTable(const QString& path, QObject* parent = nullptr);
    ~ShapefileFeatureTable();

    ShapefileInfo info() const;

    QString path() const;

    bool isSpatialIndexEnabled() const;

    void close();

    /*! \internal */
    ShapefileFeatureTable(const std::shared_ptr<QRTImpl::ShapefileFeatureTableImpl>& impl, QObject* parent = nullptr);

  private:
    Q_DISABLE_COPY(ShapefileFeatureTable)
    ShapefileFeatureTable() = delete;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_ShapefileFeatureTable_H
