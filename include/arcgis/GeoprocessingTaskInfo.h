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
/// \file GeoprocessingTaskInfo.h

#ifndef QRT_GeoprocessingTaskInfo_H
#define QRT_GeoprocessingTaskInfo_H

// C++ API headers
#include "GeoprocessingParameterInfo.h"
#include "GeoprocessingTypes.h"

// Qt headers
#include <QList>
#include <QString>
#include <QUrl>

// STL headers
#include <memory>

namespace QRTImpl { class GeoprocessingTaskInfoImpl; }

namespace Esri {
namespace ArcGISRuntime {

class GeoprocessingTaskInfo
{
public:
  GeoprocessingTaskInfo();
  GeoprocessingTaskInfo(const GeoprocessingTaskInfo& other);
  GeoprocessingTaskInfo(GeoprocessingTaskInfo&& other) noexcept;
  ~GeoprocessingTaskInfo();

  GeoprocessingTaskInfo& operator=(const GeoprocessingTaskInfo& other);
  GeoprocessingTaskInfo& operator=(GeoprocessingTaskInfo&& other) noexcept;

  bool isEmpty() const;

  QUrl url() const;

  QString category() const;

  QString description() const;

  QString displayName() const;

  GeoprocessingExecutionType executionType() const;

  QUrl helpURL() const;

  QString name() const;

  QList<GeoprocessingParameterInfo> parameterInfos() const;

  /*!
     \internal
   */
  GeoprocessingTaskInfo(const std::shared_ptr<QRTImpl::GeoprocessingTaskInfoImpl>& impl);
  std::shared_ptr<QRTImpl::GeoprocessingTaskInfoImpl> getImpl() const;

private:
  std::shared_ptr<QRTImpl::GeoprocessingTaskInfoImpl> m_impl;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_GeoprocessingTaskInfo_H
