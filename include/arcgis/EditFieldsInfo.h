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
/// \file EditFieldsInfo.h

#ifndef QRT_EditFieldsInfo_H
#define QRT_EditFieldsInfo_H

// Qt headers
#include <QString>

// STL headers
#include <memory>

namespace QRTImpl { class EditFieldsInfoImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class EditFieldsInfo
  {
  public:
    EditFieldsInfo();
    EditFieldsInfo(const EditFieldsInfo& other);
    EditFieldsInfo(EditFieldsInfo&& other) noexcept;
    ~EditFieldsInfo();

    EditFieldsInfo& operator=(const EditFieldsInfo& other);
    EditFieldsInfo& operator=(EditFieldsInfo&& other) noexcept;

    bool isEmpty() const;

    QString creationDateField() const;

    QString creatorField() const;

    QString editDateField() const;

    QString editorField() const;

    QString realm() const;

    EditFieldsInfo(const std::shared_ptr<QRTImpl::EditFieldsInfoImpl>& impl);
    std::shared_ptr<QRTImpl::EditFieldsInfoImpl> getImpl() const;

  private:
    std::shared_ptr<QRTImpl::EditFieldsInfoImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_EditFieldsInfo_H
