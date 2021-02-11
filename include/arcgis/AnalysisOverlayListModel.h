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
/// \file AnalysisOverlayListModel.h

#ifndef QRT_AnalysisOverlayListModel_H
#define QRT_AnalysisOverlayListModel_H

// C++ API headers
#include "AnalysisOverlay.h"
#include "ArcGISQt_global.h"

// Qt headers
#include <QAbstractListModel>

namespace QRTImpl { class AnalysisOverlayListImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class AnalysisOverlayListModel : public QAbstractListModel
  {
    Q_OBJECT

  public:

    enum AnalysisOverlayRoles
    {
      AnalysisOverlayVisibleRole = Qt::UserRole + 1
    };

    ~AnalysisOverlayListModel();

    bool isEmpty() const;

    void clear();

    int size() const;

    void append(AnalysisOverlay* analysisOverlay);

    void insert(int index, AnalysisOverlay* analysisOverlay);

    void removeAt(int index);

    void removeOne(AnalysisOverlay* analysisOverlay);

    void move(int from, int to);

    AnalysisOverlay* at(int index) const;

    bool contains(AnalysisOverlay* analysisOverlay) const;

    int indexOf(AnalysisOverlay* analysisOverlay) const;

    AnalysisOverlay* first() const;

    AnalysisOverlay* last() const;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;

    bool removeRows(int row, int count, const QModelIndex& parent = QModelIndex()) override;

    /*!
       \internal
     */
    AnalysisOverlayListModel(const std::shared_ptr<QRTImpl::AnalysisOverlayListImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::AnalysisOverlayListImpl> getImpl() const;

  signals:
    void analysisOverlayAdded(int index);
    void analysisOverlayRemoved(int index);
    void errorOccurred(Esri::ArcGISRuntime::Error error);

  protected:
    QHash<int, QByteArray> roleNames() const override;

  private:
    Q_DISABLE_COPY(AnalysisOverlayListModel)

    AnalysisOverlayListModel() = delete;
    void setupRoles();
    void connectSignals();

    QHash<int, QByteArray> m_roles;
    std::shared_ptr<QRTImpl::AnalysisOverlayListImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_AnalysisOverlayListModel_H
