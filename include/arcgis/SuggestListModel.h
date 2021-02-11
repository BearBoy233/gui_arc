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
/// \file SuggestListModel.h

#ifndef QRT_SuggestListModel_H
#define QRT_SuggestListModel_H

// C++ API headers
#include "ArcGISQt_global.h"
#include "Error.h"
#include "SuggestParameters.h"
#include "SuggestResult.h"

// Qt headers
#include <QAbstractListModel>

// STL headers
#include <memory>

namespace QRTImpl { class LocatorTaskImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class SuggestListModel : public QAbstractListModel
  {
    Q_OBJECT

  public:

    enum SuggestRoles
    {
      SuggestLabelRole = Qt::UserRole + 1
    };

    ~SuggestListModel();

    QString searchText() const;
    void setSearchText(const QString& searchText);

    SuggestParameters suggestParameters() const;
    void setSuggestParameters(const SuggestParameters& parameters);
    void clearSuggestParameters();

    int suggestTimerThreshold() const;
    void setSuggestTimerThreshold(int thresholdInMs);

    bool suggestInProgress() const;

    QList<SuggestResult> suggestResults() const;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    explicit SuggestListModel(const std::shared_ptr<QRTImpl::LocatorTaskImpl>& impl, QObject* parent = nullptr);

  signals:
    void searchTextChanged();
    void suggestCompleted();
    void suggestInProgressChanged();
    void errorOccurred(Esri::ArcGISRuntime::Error error);

  protected:
    QHash<int, QByteArray> roleNames() const override;

  private:
    Q_DISABLE_COPY(SuggestListModel)

    SuggestListModel() = delete;

    void connectSignals();
    void setupRoles();

    std::shared_ptr<QRTImpl::LocatorTaskImpl> m_impl;

    QList<SuggestResult> m_suggestResults;
    QHash<int, QByteArray> m_roles;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_SuggestListModel_H
