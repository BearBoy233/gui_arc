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
/// \file LabelDefinition.h

#ifndef QRT_LabelDefinition_H
#define QRT_LabelDefinition_H

// C++ API headers
#include "JsonSerializable.h"
#include "Object.h"

namespace QRTImpl { class LabelDefinitionImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class LabelDefinition : public Object, public JsonSerializable
  {
  public:
    explicit LabelDefinition(QObject* parent = nullptr);
    ~LabelDefinition();

    static LabelDefinition* fromJson(const QString& json, QObject* parent = nullptr);
    QString toJson() const override;
    QJsonObject unknownJson() const override;
    QJsonObject unsupportedJson() const override;

    LabelDefinition(const std::shared_ptr<QRTImpl::LabelDefinitionImpl>& impl);
    std::shared_ptr<QRTImpl::LabelDefinitionImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::LabelDefinitionImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_LabelDefinition_H
