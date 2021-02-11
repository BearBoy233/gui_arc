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
/// \file Item.h

#ifndef QRT_Item_H
#define QRT_Item_H

// C++ API headers
#include "CoreTypes.h"
#include "Envelope.h"
#include "Object.h"
#include "SpatialReference.h"

namespace QRTImpl { class ItemImpl; }

class QIODevice;

namespace Esri {
namespace ArcGISRuntime {

  enum class ItemType;

  class Item : public Object
  {
    Q_OBJECT

  public:
    ~Item();

    // properties
    QString accessInformation() const;
    void setAccessInformation(const QString& accessInformation);

    QString termsOfUse() const;
    void setTermsOfUse(const QString& termsOfUse);

    QDateTime created() const;

    QString description() const;
    void setDescription(const QString& description);

    Envelope extent() const;
    void setExtent(const Envelope& extent);

    QString itemId() const;
    void setItemId(const QString& itemId);

    Esri::ArcGISRuntime::ItemType itemType() const;

    QDateTime modified() const;

    QString snippet() const;
    void setSnippet(const QString& snippet);

    SpatialReference spatialReference() const;
    void setSpatialReference(const SpatialReference& spatialReference);

    QStringList tags() const;
    void setTags(const QStringList& tags);

    QString title() const;
    void setTitle(const QString& title);

    QImage thumbnail() const;
    void setThumbnail(const QImage& image);
    void fetchThumbnail();

    void fetchData(const QString& filePath);

    void updateItemProperties();

    // internals
    std::shared_ptr<QRTImpl::ItemImpl> getImpl() const;

  signals:
    void updateItemPropertiesCompleted(bool success, const QString& itemId);
    void fetchThumbnailCompleted(bool success);
    void fetchDataCompleted(bool success);

  protected:
    /*! \internal */
    Item(const std::shared_ptr<QRTImpl::ItemImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::ItemImpl> m_impl;

  private:
    Q_DISABLE_COPY(Item)

  };
}
}

#endif // QRT_Item_H
