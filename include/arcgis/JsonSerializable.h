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
/// \file JsonSerializable.h

#ifndef QRT_JsonSerializable_H
#define QRT_JsonSerializable_H

// C++ API headers
#include "ArcGISQt_global.h"

// Qt headers
#include <QJsonObject>
#include <QString>

namespace Esri {
namespace ArcGISRuntime {

class JsonSerializable
{
public:
    JsonSerializable();
    virtual ~JsonSerializable();

    // implemented by all inheriting classes
    virtual QString toJson() const = 0;
    virtual QJsonObject unknownJson() const = 0;
    virtual QJsonObject unsupportedJson() const = 0;

    // implemented by value types
    //static virtual T fromJson(const QString& json) = 0;

    // implemented by pointer types
    //static virtual T* fromJson(const QString& json, QObject* parent = nullptr) = 0;
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_JsonSerializableImpl_H
