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
/// \file Field.h

#ifndef QRT_Field_H
#define QRT_Field_H

// C++ API headers
#include "ArcGISQt_global.h"
#include "Domain.h"

// STL headers
#include <memory>

namespace QRTImpl {
  class FieldImpl;
}

namespace Esri {
namespace ArcGISRuntime {

  class Field
  {
  public:
    Field();
    Field(FieldType fieldType, const QString& name, const QString& alias, int length,
          const Domain& domain, bool isEditable, bool isNullable);
    Field(const Field& other);
    Field(Field&& other) noexcept;
    ~Field();

    Field& operator=(const Field& other);
    Field& operator=(Field&& other) noexcept;

    bool isEmpty() const;

    QString alias() const;

    Domain domain() const;

    FieldType fieldType() const;

    bool isEditable() const;

    bool isNullable() const;

    int length() const;

    QString name() const;

    QString toJson() const;

    static Field createDate(const QString& name, const QString& alias);
    static Field createDouble(const QString& name, const QString& alias);
    static Field createFloat(const QString& name, const QString& alias);
    static Field createLongInt(const QString& name, const QString& alias);
    static Field createShortInt(const QString& name, const QString& alias);
    static Field createText(const QString& name, const QString& alias, int length);
    static Field fromJSON(const QString& json);

    Field(const std::shared_ptr<QRTImpl::FieldImpl>& impl);
    std::shared_ptr<QRTImpl::FieldImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::FieldImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_Field_H
