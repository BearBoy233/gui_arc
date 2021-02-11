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
/// \file PopupTypes.h

#ifndef QRT_PopupTypes_H
#define QRT_PopupTypes_H

// Qt headers
#include <QObject>

namespace Esri {
namespace ArcGISRuntime {

  enum class PopupDateFormat
  {
    DayShortMonthYear = 0,
    LongDate = 1,
    LongMonthDayYear = 2,
    LongMonthYear = 3,
    ShortDate = 4,
    ShortDateLE = 5,
    ShortDateLELongTime = 6,
    ShortDateLELongTime24 = 7,
    ShortDateLEShortTime = 8,
    ShortDateLEShortTime24 = 9,
    ShortDateLongTime = 10,
    ShortDateLongTime24 = 11,
    ShortDateShortTime = 12,
    ShortDateShortTime24 = 13,
    ShortMonthYear = 14,
    Year = 15,
    Unknown = -1
  };

  enum class PopupMediaType
  {
    Image = 0,
    BarChart = 1,
    ColumnChart = 2,
    LineChart = 3,
    PieChart = 4,
    Unknown = -1
  };

  enum class PopupStringFieldOption
  {
    SingleLine = 0,
    MultiLine = 1,
    RichText = 2,
    Unknown = -1
  };

  enum class FeatureTypeChangeMode
  {
    ResetToDefaults = 0,
    KeepValues = 1
  };

  enum class PopupErrorCode
  {
    InvalidGeoElement = 11000,
    NullNotAllowed = 11001,
    ValueOutOfRange = 11002,
    ExceedsMaxLength = 11003
  };

  enum class PopupAttachmentType
  {
    Image = 0,
    Video = 1,
    Document = 2,
    Other = 3
  };

  enum class PopupAttachmentEditState
  {
    Original = 0,
    Added = 1,
    Deleted = 2
  };

  enum class PopupExpressionReturnType
  {
    String = 0,
    Number = 1
  };

} // namespace ArcGISRuntime
} // namespace Esri

Q_DECLARE_METATYPE(Esri::ArcGISRuntime::PopupDateFormat)
Q_DECLARE_METATYPE(Esri::ArcGISRuntime::PopupStringFieldOption)
Q_DECLARE_METATYPE(Esri::ArcGISRuntime::PopupAttachmentType)
Q_DECLARE_METATYPE(Esri::ArcGISRuntime::PopupAttachmentEditState)
Q_DECLARE_METATYPE(Esri::ArcGISRuntime::PopupExpressionReturnType)

#endif // QRT_PopupTypes_H
