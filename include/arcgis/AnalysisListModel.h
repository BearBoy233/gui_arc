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
/// \file AnalysisListModel.h

#ifndef QRT_AnalysisListModel_H
#define QRT_AnalysisListModel_H

// C++ API headers
#include "Analysis.h"
#include "ArcGISQt_global.h"

// Qt headers
#include <QAbstractListModel>

namespace QRTImpl { class AnalysisListImpl; }

namespace Esri {
namespace ArcGISRuntime {

  class AnalysisListModel : public QAbstractListModel
  {
    Q_OBJECT

  public:

    enum AnalysisRoles
    {
      AnalysisVisibleRole = Qt::UserRole + 1,
      AnalysisTypeRole
    };

    ~AnalysisListModel();

    bool isEmpty() const;

    void clear();

    int size() const;

    void append(Analysis* analysis);

    void insert(int index, Analysis* analysis);

    void removeAt(int index);

    void removeOne(Analysis* analysis);

    void move(int from, int to);

    Analysis* at(int index) const;

    bool contains(Analysis* analysis) const;

    int indexOf(Analysis* analysis) const;

    Analysis* first() const;

    Analysis* last() const;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;

    bool removeRows(int row, int count, const QModelIndex& parent = QModelIndex()) override;

    /*!
       \internal
     */
    AnalysisListModel(const std::shared_ptr<QRTImpl::AnalysisListImpl>& impl, QObject* parent = nullptr);
    std::shared_ptr<QRTImpl::AnalysisListImpl> getImpl() const;

  signals:
    void analysisAdded(int index);
    void analysisRemoved(int index);
    void errorOccurred(Esri::ArcGISRuntime::Error error);

  protected:
    QHash<int, QByteArray> roleNames() const override;

  private:
    Q_DISABLE_COPY(AnalysisListModel)

    AnalysisListModel() = delete;
    void setupRoles();
    void connectSignals();

    QHash<int, QByteArray> m_roles;
    std::shared_ptr<QRTImpl::AnalysisListImpl> m_impl;
  };

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_AnalysisListModel_H
