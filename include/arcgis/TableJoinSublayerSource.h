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
/// \file TableJoinSublayerSource.h

#ifndef QRT_TableJoinSublayerSource_H
#define QRT_TableJoinSublayerSource_H

// C++ API headers
#include "Field.h"
#include "SublayerSource.h"

namespace QRTImpl { class TableJoinSublayerSourceImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class TableJoinSublayerSource : public SublayerSource
  {
    Q_OBJECT

  public:
    TableJoinSublayerSource(const QString& leftFieldName, SublayerSource* leftSublayerSource,
                            const QString& rightFieldName, SublayerSource* rightSublayerSource,
                            JoinType joinType, QObject* parent = nullptr);
    ~TableJoinSublayerSource();

    JoinType joinType() const;

    QString leftFieldName() const;

    SublayerSource* leftSublayerSource() const;

    QString rightFieldName() const;

    SublayerSource* rightSublayerSource() const;

    /*! \internal */
    explicit TableJoinSublayerSource(const std::shared_ptr<QRTImpl::TableJoinSublayerSourceImpl>& impl, QObject* parent = nullptr);
    /*! \internal */
    std::shared_ptr<QRTImpl::TableJoinSublayerSourceImpl> getImpl() const;

  private:
    Q_DISABLE_COPY(TableJoinSublayerSource)
    TableJoinSublayerSource() = delete;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_TableJoinSublayerSource_H
