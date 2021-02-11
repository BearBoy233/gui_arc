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
/// \file DictionarySymbolStyle.h

#ifndef QRT_DictionarySymbolStyle_H
#define QRT_DictionarySymbolStyle_H

// C++ API headers
#include "SymbolStyle.h"

// Qt headers
#include <QStringList>

namespace QRTImpl { class DictionarySymbolStyleImpl; }

namespace Esri {
namespace ArcGISRuntime {

class DictionarySymbolStyle : public SymbolStyle
{
  Q_OBJECT

public:
  explicit DictionarySymbolStyle(const QString& specificationType, QObject* parent = nullptr);
  DictionarySymbolStyle(const QString& specificationType, const QString& styleLocation, QObject* parent = nullptr);

  ~DictionarySymbolStyle();

  QMap<QString, QString> configurationProperties() const;
  void setConfigurationProperties(const QMap<QString, QString>& configurationProperties);

  QString specificationType() const;

  QStringList symbologyFieldNames() const;

  QStringList textFieldNames() const;

  using SymbolStyle::fetchSymbol;
  TaskWatcher fetchSymbol(const QVariantMap& keys);

  explicit DictionarySymbolStyle(const std::shared_ptr<QRTImpl::DictionarySymbolStyleImpl>& impl, QObject* parent = nullptr);
  std::shared_ptr<QRTImpl::DictionarySymbolStyleImpl> getImpl() const;

private:
  Q_DISABLE_COPY(DictionarySymbolStyle)
};

} // namespace ArcGISRuntime
} // namespace Esri

#endif // QRT_DictionarySymbolStyle_H
