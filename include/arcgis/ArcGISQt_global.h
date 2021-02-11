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
/// \file ArcGISQt_global.h

#ifndef QRT_ArcGISQt_global_H
#define QRT_ArcGISQt_global_H

// Qt headers
#include <QtCore/qglobal.h>

#if defined Q_OS_WIN32 || ( defined(Q_OS_LINUX) && !defined(Q_OS_ANDROID) )
#  define LOCALSERVER_SUPPORTED
#endif

#if defined Q_OS_WIN32 || defined Q_OS_OSX || ( defined(Q_OS_LINUX) && !defined(Q_OS_ANDROID) )
#  define GRAPHICSVIEW_SUPPORTED
#endif

#endif // QRT_ArcGISQt_global_H
