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
/// \file MobileMapPackage.h

#ifndef QRT_MobileMapPackage_H
#define QRT_MobileMapPackage_H

// C++ API headers
#include "Item.h"
#include "JsonSerializable.h"
#include "LayerListModel.h"
#include "Loadable.h"
#include "LocatorTask.h"
#include "Map.h"
#include "Object.h"

namespace QRTImpl { class MobileMapPackageImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class MobileMapPackage : public Object, public Loadable
  {
    Q_OBJECT

  public:
    explicit MobileMapPackage(const QString& path, QObject* parent = nullptr);
    ~MobileMapPackage();

    static MobileMapPackage* instance();

    Item* item() const;
    LocatorTask* locatorTask() const;
    QList<Map*> maps() const;
    QString path() const;
    QString version() const;

    static TaskWatcher isDirectReadSupported(const QString& mobileMapPackageFilePath);
    static TaskWatcher unpack(const QString& mobileMapPackageFilePath, const QString& outputDirectory);

    Error loadError() const override;
    LoadStatus loadStatus() const override;
    void cancelLoad() override;
    void load() override;
    void retryLoad() override;

    /*!
       \internal
     */
    explicit MobileMapPackage(const std::shared_ptr<QRTImpl::MobileMapPackageImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::MobileMapPackageImpl> getImpl() const;

  signals:
    void doneLoading(Esri::ArcGISRuntime::Error loadError);
    void loadStatusChanged(Esri::ArcGISRuntime::LoadStatus loadStatus);

    void isDirectReadSupportedCompleted(QUuid taskId, bool directReadSupported);
    void unpackCompleted(QUuid taskId, bool success);

  private:
    explicit MobileMapPackage(QObject* parent = nullptr);
    void connectSignals();

    Q_DISABLE_COPY(MobileMapPackage)

    std::shared_ptr<QRTImpl::MobileMapPackageImpl> m_impl;
  };

}
}
#endif // QRT_MobileMapPackage_H
