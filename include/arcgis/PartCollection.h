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
/// \file PartCollection.h

#ifndef QRT_PartCollection_H
#define QRT_PartCollection_H

// C++ API headers
#include "Object.h"
#include "Part.h"
#include "SpatialReference.h"

namespace QRTImpl { class PartCollectionImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class PartCollection : public Object
  {
    Q_OBJECT

  public:
    PartCollection(const SpatialReference& spatialReference, QObject* parent = nullptr);

    ~PartCollection();

    bool isEmpty() const;

    int size() const;

    SpatialReference spatialReference() const;

    Part* part(int index) const;

    int indexOf(Part* part) const;

    int addPart(Part* part);

    void addParts(const QList<Part*>& parts);

    void setPart(int index, Part* part);

    void insertPart(int index, Part* part);

    void removeAll();

    void removePart(int index);

    std::shared_ptr<QRTImpl::PartCollectionImpl> getImpl() const;

    /*!
     \internal
     */
    PartCollection(const std::shared_ptr<QRTImpl::PartCollectionImpl>& impl, QObject* parent = nullptr);

  private:
    std::shared_ptr<QRTImpl::PartCollectionImpl> m_impl;
    Q_DISABLE_COPY(PartCollection)
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_PartCollection_H

