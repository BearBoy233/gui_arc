/**
 * @file /include/gui_arc/main_window.hpp
 *
 * @brief Qt based gui for gui_arc.
 *
 * @date November 2010
 **/
#ifndef gui_arc_MAIN_WINDOW_H
#define gui_arc_MAIN_WINDOW_H

#ifndef Q_MOC_RUN
//#include <ros/ros.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.h>
#endif

/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtWidgets/QMainWindow>
#include <QImage>
#include <QMutex>
#include "ui_main_window.h"
#include "qnode.hpp"

//#include "qrviz_widget.h"

#include "Basemap.h"
#include "Map.h"
#include "LatitudeLongitudeGrid.h"

/*****************************************************************************
** Namespace
*****************************************************************************/

const std::string mavros_state_string[] = {
"MANUAL",
"ACRO",
"ALTCTL",
"POSCTL",
"OFFBOARD",
"STABILIZED",
"RATTITUDE",
"AUTO.MISSION",
"AUTO.LOITER",
"AUTO.RTL",
"AUTO.LAND",
"AUTO.RTGS",
"AUTO.READY",
"AUTO.TAKEOFF",
"Error State",
"Please Check!",
};        //0-14 14-error 15-define state

namespace gui_arc {

/*****************************************************************************
** Interface [MainWindow]
*****************************************************************************/
/**
 * @brief Qt central, all operations relating to the view part here.
 */
class MainWindow : public QMainWindow {
Q_OBJECT

public:
	MainWindow(int argc, char** argv, QWidget *parent = 0);
	~MainWindow();

	void ReadSettings(); // Load up qt program settings at startup
	void WriteSettings(); // Save qt program settings when closing

	void closeEvent(QCloseEvent *event); // Overloaded function
	void showNoMasterMessage();

  // adding
  /*用来保护一个对象、数据结构、代码段、使得它们在同一一时刻，只有一个线程有访问权限*/
  mutable QMutex showImage_mutex_;
  //cv::Mat receiveImage;//保存接受到的图像
  //QImage ImageToQImage;//转换为QImage
  bool receiveImageFlag;//接受到图像为true 处理完设置为false

  bool flag_use_yolo = 0;
  bool flag_yolo_1st = 1;

  bool flag_battery[11];

public Q_SLOTS:
	/******************************************
	** Auto-connections (connectSlotsByName())
	*******************************************/
	void on_actionAbout_triggered();
  void on_button_connect_clicked();
	void on_checkbox_use_environment_stateChanged(int state);

  void on_checkBox_yolo_use_stateChanged(int state);

//adding
  void deal_receiveImageSignal();
  void deal_receiveImageSignal2();

  //data from QNode; slot in void connections();
  void slot_power( );

    /******************************************
    ** Manual connections
    *******************************************/
    void updateLoggingView(); // no idea why this can't connect automatically


    void slot_pB_1_start_roscore();
    void slot_pB_2_start_serial();
    void slot_pB_3_rviz_path();
    void slot_pB_4_rqt_hz();
    void slot_pB_5_drone_control();
    void slot_pB_6_camera_show();
    void slot_pB_7_track();
    void slot_pB_8_follow();

    void slot_DK_Send_command();
    void slot_DK_Send_takeoff();
    void slot_DK_Send_land();

    void slot_pB_a_flag1();
    void slot_pB_a_flag2();
    void slot_pB_a_flag4();
    void slot_pB_a_flag5();
    void slot_pB_a_move3_222();
    void slot_pB_a_move2_222();

private:
	Ui::MainWindowDesign ui;
	QNode qnode;

  void connections();

  Esri::ArcGISRuntime::MapGraphicsView* m_mapView = nullptr;
  Esri::ArcGISRuntime::Map* m_map = nullptr;

};

}  // namespace gui_arc

#endif // gui_arc_MAIN_WINDOW_H
