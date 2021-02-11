/**
 * @file /src/main_window.cpp
 *
 * @brief Implementation for the qt gui.
 *
 * @date February 2011
 **/
/*****************************************************************************
** Includes
*****************************************************************************/

//  line_edit_master
//  line_edit_host
//  checkbox_use_environment
//  checkbox_remember_settings
//  label

#include <QtGui>
#include <QMessageBox>
#include <iostream>
#include "../include/gui_arc/main_window.hpp"

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace gui_arc {

using namespace Qt;
using namespace Esri::ArcGISRuntime;

/*****************************************************************************
** Implementation [MainWindow]
*****************************************************************************/

MainWindow::MainWindow(int argc, char** argv, QWidget *parent)
	: QMainWindow(parent)
	, qnode(argc,argv)
{
	ui.setupUi(this); // Calling this incidentally connects all ui's triggers to on_...() callbacks in this class.
    QObject::connect(ui.actionAbout_Qt, SIGNAL(triggered(bool)), qApp, SLOT(aboutQt())); // qApp is a global variable for the application

    //ReadSettings();
	setWindowIcon(QIcon(":/images/icon.png"));
	ui.tab_manager->setCurrentIndex(0); // ensure the first tab is showing - qt-designer should have this already hardwired, but often loses it (settings?).
    QObject::connect(&qnode, SIGNAL(rosShutdown()), this, SLOT(close()));

	/*********************
	** Logging
	**********************/
	ui.view_logging->setModel(qnode.loggingModel());
    QObject::connect(&qnode, SIGNAL(loggingUpdated()), this, SLOT(updateLoggingView()));


    //adding
    //QObject::connect(&trackerThread,SIGNAL(receiveImageSignal()),this,SLOT(deal_receiveImageSignal()));
    QObject::connect(&qnode,SIGNAL(receiveImageSignal()),this,SLOT(deal_receiveImageSignal()));

    QObject::connect(&qnode,SIGNAL(receiveImageSignal2()),this,SLOT(deal_receiveImageSignal2()));

    /*********************
    ** Auto Start
    **********************/
    /*
    if ( ui.checkbox_remember_settings->isChecked() ) {
        on_button_connect_clicked(true);
    }
    */

    ui.dock_status->hide();
    ui.dockWidget_rosmaster->hide();
    ui.dock_pos_control->hide();
    ui.dock_ros_main_2->show();

    QObject::connect(ui.pB_1_start_roscore, SIGNAL(clicked()), this, SLOT(slot_pB_1_start_roscore()));  // roscore 启动
    QObject::connect(ui.pB_2_start_serial, SIGNAL(clicked()), this, SLOT(slot_pB_2_start_serial()));
    QObject::connect(ui.pB_3_rviz_path, SIGNAL(clicked()), this, SLOT(slot_pB_3_rviz_path()) );
    QObject::connect(ui.pB_4_rqt_hz, SIGNAL(clicked()), this, SLOT(slot_pB_4_rqt_hz()) );
    QObject::connect(ui.pB_5_drone_control, SIGNAL(clicked()), this, SLOT(slot_pB_5_drone_control()) );
    QObject::connect(ui.pB_6_camera_show, SIGNAL(clicked()), this, SLOT(slot_pB_6_camera_show()) );
    QObject::connect(ui.pB_7_track, SIGNAL(clicked()), this, SLOT(slot_pB_7_track()) );
    QObject::connect(ui.pB_8_follow, SIGNAL(clicked()), this, SLOT(slot_pB_8_follow()) );

    QObject::connect(ui.DK_Send_command, SIGNAL(clicked()), this, SLOT(slot_DK_Send_command()) );
    QObject::connect(ui.DK_Send_takeoff, SIGNAL(clicked()), this, SLOT(slot_DK_Send_takeoff()) );
    QObject::connect(ui.DK_Send_land, SIGNAL(clicked()), this, SLOT(slot_DK_Send_land()) );

    QObject::connect(ui.pB_a_flag1, SIGNAL(clicked()), this, SLOT(slot_pB_a_flag1()) );
    QObject::connect(ui.pB_a_flag2, SIGNAL(clicked()), this, SLOT(slot_pB_a_flag2()) );
    QObject::connect(ui.pB_a_flag4, SIGNAL(clicked()), this, SLOT(slot_pB_a_flag4()) );
    QObject::connect(ui.pB_a_flag5, SIGNAL(clicked()), this, SLOT(slot_pB_a_flag5()) );

    QObject::connect(ui.pB_a_move3_222, SIGNAL(clicked()), this, SLOT(slot_pB_a_move3_222()) );
    QObject::connect(ui.pB_a_move2_222, SIGNAL(clicked()), this, SLOT(slot_pB_a_move2_222()) );

    //init
    ui.drone_label_power_1->setText(QString::number(0.0)+"V");
    ui.drone_progressBar_1->setValue(0);
    ui.drone_label_sys_state_1->setText(QString::number(-1));
    ui.drone_State_lineEdit_1->setText( mavros_state_string[15].c_str() );
    ui.drone_func_type_1->setText( "待连接" );

    ui.drone_label_power_2->setText(QString::number(0.0)+"V");
    ui.drone_progressBar_2->setValue(0);
    ui.drone_label_sys_state_2->setText(QString::number(-1));
    ui.drone_State_lineEdit_2->setText( mavros_state_string[15].c_str() );
    ui.drone_func_type_2->setText( "待连接" );

    ui.drone_label_power_3->setText(QString::number(0.0)+"V");
    ui.drone_progressBar_3->setValue(0);
    ui.drone_label_sys_state_3->setText(QString::number(-1));
    ui.drone_State_lineEdit_3->setText( mavros_state_string[15].c_str() );
    ui.drone_func_type_3->setText( "待连接" );

    for (int jj=0;jj<11;jj++)
    {flag_battery[jj] = 1;
    }

    //qrviz = new QRviz_widget(ui.widget_rviz);
    //qrviz->showFullScreen();
    //qrviz->show();

    //
    // Create map from URL source and assign to a map view
    // Map* m_map = new Map(URLOfMapSource);
    // m_mapView->setMap(m_map);
    // https://www.arcgis.com/home/webmap/viewer.html?webmap=69fdcd8e40734712aaec34194d4b988c

    /*
    QUrl url2;
    url2.setUrl("https://www.arcgis.com/home/webmap/viewer.html?webmap=69fdcd8e40734712aaec34194d4b988c");
    PortalItem* portalItem = new PortalItem(url2, this);
    Map* map_t = new Map(portalItem, this);
    ui.graphicsView->setMap(map_t);
    */

    // Create map from URL source and assign to a map view
    // Map* m_map = new Map(URLOfMapSource);
    // m_mapView->setMap(m_map);

    // origin
    /*
    m_map = new Esri::ArcGISRuntime::Map(Esri::ArcGISRuntime::Basemap::topographic(this), this);
    ui.graphicsView->setMap(m_map);
    */

    // after using namespace
    // Create the Widget view
    // m_mapView = new MapGraphicsView(this);
    m_mapView = ui.graphicsView;
    // Create a map using the topographic Basemap
    m_map = new Map(Basemap::imageryWithLabelsVector(this), this);
    Viewpoint vp(39.959082, 116.315450,     10000);
    // m_map = new Map(Basemap::topographic(this), this);
    // Viewpoint vp(39.960282019017534, 116.31697823021696,     10000);

    // Set map to map view
    m_mapView->setMap(m_map);

    // create a grid for showing Latitude and Longitude (Meridians and Parallels)
    LatitudeLongitudeGrid* latlonGrid = new LatitudeLongitudeGrid(this);
    m_mapView->setGrid(latlonGrid);

    //Polygon visibleArea = m_mapView->visibleArea;
    // 设置初始经纬比例  East South m
    // Viewpoint vp(39.960282019017534, 116.31697823021696, 150000);
    // Rotate the viewpoint 30 degrees counterclockwise
    // TaskWatcher tw = m_mapView->setViewpointRotation(m_mapView->mapRotation() + 30);

    TaskWatcher tw2 = m_mapView->setViewpointAnimated(vp, 2.0, AnimationCurve::EaseInOutCubic);
    // Operations that return a TaskWatcher can be cancelled
    //tw.cancel();

    /*
    // The code below selects a position source and start the location display.
    // stop the location display if running
    if (m_mapView->locationDisplay()->isStarted())
      stopLocationDisplay();
    // set the source
    if (source.isEmpty() || source == coreLocation())
    {
      m_mapView->locationDisplay()->setPositionSource(QGeoPositionInfoSource::createDefaultSource(this));
    }
    else if (source == simulated())
    {
      auto source = new QNmeaPositionInfoSource(QNmeaPositionInfoSource::SimulationMode, this);
      auto file = new QFile(":/Resources/campus.txt", this);
      source->setDevice(file);
      m_mapView->locationDisplay()->setPositionSource(source);
    }
    // set the compass
    QCompass* compass = new QCompass(this);
    compass->setDataRate(1);
    m_mapView->locationDisplay()->setCompass(compass);
    // start the location display
    if (locationDisplayStarted())
    {
      m_mapView->locationDisplay()->start();
    }
    */

    //链接connect
    connections();
}

MainWindow::~MainWindow() {}

/*****************************************************************************
** Implementation [Slots]
*****************************************************************************/

void MainWindow::showNoMasterMessage() {
	QMessageBox msgBox;
	msgBox.setText("Couldn't find the ros master.");
	msgBox.exec();
    close();
}

/*
 * These triggers whenever the button is clicked, regardless of whether it
 * is already checked or not.
 */

void MainWindow::on_button_connect_clicked() { //bool check
  qnode.init();
  //ui.button_connect->setEnabled(false);
  ui.dock_status->show();

  /*
	if ( ui.checkbox_use_environment->isChecked() ) {
		if ( !qnode.init() ) {
			showNoMasterMessage();
		} else {
			ui.button_connect->setEnabled(false);
		}
	} else {
		if ( ! qnode.init(ui.line_edit_master->text().toStdString(),
				   ui.line_edit_host->text().toStdString()) ) {
			showNoMasterMessage();
		} else {
			ui.button_connect->setEnabled(false);
			ui.line_edit_master->setReadOnly(true);
			ui.line_edit_host->setReadOnly(true);
			ui.line_edit_topic->setReadOnly(true);
		}
	}
  */
}


void MainWindow::on_checkbox_use_environment_stateChanged(int state) {
	bool enabled;
	if ( state == 0 ) {
		enabled = true;
	} else {
		enabled = false;
	}
	ui.line_edit_master->setEnabled(enabled);
	ui.line_edit_host->setEnabled(enabled);
	//ui.line_edit_topic->setEnabled(enabled);
}

void MainWindow::on_checkBox_yolo_use_stateChanged(int state) {
  //bool enabled;
  if ( state == 0 ) {
    flag_use_yolo = 0;
    //enabled = true;
  } else {
    flag_use_yolo = 1;

    if (flag_yolo_1st)
    {
      system("gnome-terminal -x bash -c 'source ~/test_yolo/ros-darknet/devel/setup.bash; roslaunch darknet_ros yolo_v3.launch; exec bash'&");
      flag_yolo_1st = 0;
    }

    //enabled = false;
  }
  //ui.line_edit_master->setEnabled(enabled);
  //ui.line_edit_host->setEnabled(enabled);
  //ui.line_edit_topic->setEnabled(enabled);
}

/*****************************************************************************
** Implemenation [Slots][manually connected]
*****************************************************************************/

/**
 * This function is signalled by the underlying model. When the model changes,
 * this will drop the cursor down to the last line in the QListview to ensure
 * the user can always see the latest log message.
 */
void MainWindow::updateLoggingView() {
        ui.view_logging->scrollToBottom();
}

/*****************************************************************************
** Implementation [Menu]
*****************************************************************************/

void MainWindow::on_actionAbout_triggered() {
    QMessageBox::about(this, tr("About ..."),tr("<h2>PACKAGE_NAME Test Program 0.10</h2><p>Copyright Yujin Robot</p><p>This package needs an about description.</p>"));
}

/*****************************************************************************
** Implementation [Configuration]
*****************************************************************************/

void MainWindow::ReadSettings() {
    QSettings settings("Qt-Ros Package", "gui_arc");
    restoreGeometry(settings.value("geometry").toByteArray());
    restoreState(settings.value("windowState").toByteArray());
    QString master_url = settings.value("master_url",QString("http://192.168.1.2:11311/")).toString();
    QString host_url = settings.value("host_url", QString("192.168.1.3")).toString();
    //QString topic_name = settings.value("topic_name", QString("/chatter")).toString();
    ui.line_edit_master->setText(master_url);
    ui.line_edit_host->setText(host_url);
    //ui.line_edit_topic->setText(topic_name);
    bool remember = settings.value("remember_settings", false).toBool();
    ui.checkbox_remember_settings->setChecked(remember);
    bool checked = settings.value("use_environment_variables", false).toBool();
    ui.checkbox_use_environment->setChecked(checked);
    if ( checked ) {
    	ui.line_edit_master->setEnabled(false);
    	ui.line_edit_host->setEnabled(false);
    	//ui.line_edit_topic->setEnabled(false);
    }
}

void MainWindow::WriteSettings() {
    QSettings settings("Qt-Ros Package", "gui_arc");
    settings.setValue("master_url",ui.line_edit_master->text() );
    settings.setValue("host_url",ui.line_edit_host->text());
    //settings.setValue("topic_name",ui.line_edit_topic->text());
    settings.setValue("use_environment_variables",QVariant(ui.checkbox_use_environment->isChecked()));
    settings.setValue("geometry", saveGeometry());
    settings.setValue("windowState", saveState());
    settings.setValue("remember_settings",QVariant(ui.checkbox_remember_settings->isChecked()));

}

void MainWindow::closeEvent(QCloseEvent *event)
{
  // WriteSettings();
	QMainWindow::closeEvent(event);
}

//connections

void MainWindow::connections()
{
    //电源的信号
    connect(&qnode,SIGNAL(power( )),this,SLOT(slot_power( )));

}

void MainWindow::slot_power( )
{ int temp_sys;
  if (qnode.drone_connect[1])
  {
    ui.drone_label_power_1->setText(QString::number(qnode.drone_battery_voltage[1])+"V");
    ui.drone_progressBar_1->setValue(qnode.drone_battery_remaining[1]);
    ui.drone_label_sys_state_1->setText(QString::number(qnode.drone_sys_state[1]));
    temp_sys = qnode.drone_mode[1];
    ui.drone_State_lineEdit_1->setText( mavros_state_string[temp_sys].c_str() );
    ui.drone_func_type_1->setText( "垂直打击" );

    if(qnode.drone_battery_remaining[1]<=20 && flag_battery[1])
    {
        //ui.progressBar->setStyleSheet("QProgressBar::chunk {background-color: red;width: 20px;} QProgressBar {border: 2px solid grey;border-radius: 5px;text-align: center;}");
        flag_battery[1] = 0;
        QMessageBox::warning(NULL, "电量不足", "1号机电量不足，请及时降落！", QMessageBox::Yes , QMessageBox::Yes);
    }

  }

  if (qnode.drone_connect[2])
  {
    ui.drone_label_power_2->setText(QString::number(qnode.drone_battery_voltage[2])+"V");
    ui.drone_progressBar_2->setValue(qnode.drone_battery_remaining[2]);
    ui.drone_label_sys_state_2->setText(QString::number(qnode.drone_sys_state[2]));
    temp_sys = qnode.drone_mode[2];
    ui.drone_State_lineEdit_2->setText( mavros_state_string[temp_sys].c_str() );
    ui.drone_func_type_2->setText( "框选追踪" );

    if(qnode.drone_battery_remaining[2]<=20 && flag_battery[2])
    {
        //ui.progressBar->setStyleSheet("QProgressBar::chunk {background-color: red;width: 20px;} QProgressBar {border: 2px solid grey;border-radius: 5px;text-align: center;}");
        flag_battery[2] = 0;
        QMessageBox::warning(NULL, "电量不足", "2号机电量不足，请及时降落！", QMessageBox::Yes , QMessageBox::Yes);
    }
  }

  if (qnode.drone_connect[3])
  {
    ui.drone_label_power_3->setText(QString::number(qnode.drone_battery_voltage[3])+"V");
    ui.drone_progressBar_3->setValue(qnode.drone_battery_remaining[3]);
    ui.drone_label_sys_state_3->setText(QString::number(qnode.drone_sys_state[3]));
    temp_sys = qnode.drone_mode[3];
    ui.drone_State_lineEdit_3->setText( mavros_state_string[temp_sys].c_str() );
    ui.drone_func_type_3->setText( "全局监控" );

    if(qnode.drone_battery_remaining[3]<=20 && flag_battery[3])
    {
         //ui.progressBar->setStyleSheet("QProgressBar::chunk {background-color: red;width: 20px;} QProgressBar {border: 2px solid grey;border-radius: 5px;text-align: center;}");
        flag_battery[3] = 0;
        QMessageBox::warning(NULL, "电量不足", "3号机电量不足，请及时降落！", QMessageBox::Yes , QMessageBox::Yes);
    }
  }


  //ui.drone_1_progressBar->setValue((int)p);
  //ui.drone_1_label_power->setText(QString::number(p).mid(0,5)+"V");
    /*
    ui.label_power->setText(QString::number(p).mid(0,5)+"V");
    double n=(p-10)/1.5;
    int value=n*100;
    ui.progressBar->setValue(value>100?100:value);
    //当电量过低时发出提示
    if(n*100<=20)
    {
         ui.progressBar->setStyleSheet("QProgressBar::chunk {background-color: red;width: 20px;} QProgressBar {border: 2px solid grey;border-radius: 5px;text-align: center;}");
          // QMessageBox::warning(NULL, "电量不足", "电量不足，请及时充电！", QMessageBox::Yes , QMessageBox::Yes);
    }
    else{
        ui.progressBar->setStyleSheet("QProgressBar {border: 2px solid grey;border-radius: 5px;text-align: center;}");
    }
    */
}


//
void MainWindow::slot_pB_1_start_roscore()
{
  system("gnome-terminal -x bash -c 'roscore'&");
  //ui.checkBox_roscore->setEnabled(0);
  ui.checkBox_roscore->setChecked(1);
}

void MainWindow::slot_pB_2_start_serial()
{
  system("gnome-terminal -x bash -c 'source ~/swarm_p9_ws/devel/setup.bash; roslaunch serial_p9 serial_gcs.launch; exec bash'&");
  //ui.checkBox_serial->setEnabled(0);
  ui.checkBox_serial->setChecked(1);
}

void MainWindow::slot_pB_3_rviz_path()
{ system("gnome-terminal -x bash -c 'rviz'&");}

void MainWindow::slot_pB_4_rqt_hz()
{ system("gnome-terminal -x bash -c 'rqt'&");}

void MainWindow::slot_pB_5_drone_control()
{
  ui.dock_pos_control->show();
  //system("gnome-terminal -x bash -c 'rqt'&");
  //ui.checkBox_roscore->setEnabled(0);
}

void MainWindow::slot_pB_6_camera_show()
{
  //ui.dock_pos_control->show();
  system("gnome-terminal -x bash -c 'source ~/ros_cam_ws/devel/setup.bash; roslaunch rocon_rtsp_camera_relay rtsp_camera_relay_3.launch; exec bash'&");
  //ui.checkBox_roscore->setEnabled(0);
}

void MainWindow::slot_pB_7_track()
{ system("gnome-terminal -x bash -c 'source ~/ros_cam_ws/devel/setup.bash; roslaunch rocon_rtsp_camera_relay rtsp_camera_relay_uav2.launch; exec bash'&");
  system("gnome-terminal -x bash -c 'source ~/testqt_ws/devel/setup.bash; rosrun tracker_widget_2 tracker_widget_2; exec bash'&");
}

void MainWindow::slot_pB_8_follow()
{ system("gnome-terminal -x bash -c 'source ~/ros_cam_ws/devel/setup.bash; roslaunch rocon_rtsp_camera_relay rtsp_camera_relay_uav1.launch; exec bash'&");
  system("gnome-terminal -x bash -c 'source ~/testqt_ws/devel/setup.bash; rosrun tracker_widget tracker_widget; exec bash'&");
}


void MainWindow::slot_pB_a_flag1()
{system("gnome-terminal -x bash -c 'rostopic pub -1 /flag  std_msgs/Int32 \"data: 1\"; exec bash'&");}

void MainWindow::slot_pB_a_flag2()
{system("gnome-terminal -x bash -c 'rostopic pub -1 /flag  std_msgs/Int32 \"data: 2\"; exec bash'&");}

void MainWindow::slot_pB_a_flag4()
{system("gnome-terminal -x bash -c 'rostopic pub -1 /flag  std_msgs/Int32 \"data: 4\"; exec bash'&");}

void MainWindow::slot_pB_a_flag5()
{system("gnome-terminal -x bash -c 'rostopic pub -1 /flag  std_msgs/Int32 \"data: 5\"; exec bash'&");}

void MainWindow::slot_pB_a_move3_222()
{system("gnome-terminal -x bash -c 'rostopic pub -1 /serial_p9/send/mission_loc gui_arc/M_mission_loc \"{Send_ID: 10, Receive_ID: 3, state: 3, x: 1.6, y: 1.4, z: 1.5, yaw: -2.5294}\"; exec bash'&");}

void MainWindow::slot_pB_a_move2_222()
{system("gnome-terminal -x bash -c 'rostopic pub -1 /serial_p9/send/mission_loc gui_arc/M_mission_loc \"{Send_ID: 10, Receive_ID: 2, state: 3, x: -0.5, y: -0.5, z: 1.5, yaw: 0.0}\"; exec bash'&");}


void MainWindow::slot_DK_Send_command()
{ // 3
  float x,y,z,yaw;
  uint8_t state, receive_ID;
  state = 3;

  receive_ID = uint8_t(ui.DC_input_no->currentIndex() + 1);
  x = ui.DC_input_x->text().toFloat();
  y = ui.DC_input_y->text().toFloat();
  z = ui.DC_input_z->text().toFloat();
  yaw = float(ui.DC_input_yaw->text().toDouble()/180.0*3.1415926535);
  qnode.cb_pb_mission_loc(receive_ID,x,y,z,yaw,state);
}

void MainWindow::slot_DK_Send_takeoff()
{ // 1
  float x,y,z,yaw;
  uint8_t state, receive_ID;
  state = 1;

  receive_ID = uint8_t(ui.DC_input_no->currentIndex() + 1);
  x = ui.DC_input_x->text().toFloat();
  y = ui.DC_input_y->text().toFloat();
  z = ui.DC_input_z->text().toFloat();
  yaw = float(ui.DC_input_yaw->text().toDouble()/180.0*3.1415926535);
  qnode.cb_pb_mission_loc(receive_ID,x,y,z,yaw,state);

  qnode.flag_save_path_data[receive_ID] = 2;
}

void MainWindow::slot_DK_Send_land()
{ // 2
  // system("gnome-terminal -x bash -c 'rostopic pub -1 /flag  std_msgs/Int32 \"data: 5\"; exec bash'&");
  // system("gnome-terminal -x bash -c 'rostopic pub -1 /flag  std_msgs/Int32 \"data: 1\"; exec bash'&");

  float x,y,z,yaw;
  uint8_t state, receive_ID;
  state = 2;

  receive_ID = uint8_t(ui.DC_input_no->currentIndex() + 1);
  x = ui.DC_input_x->text().toFloat();
  y = ui.DC_input_y->text().toFloat();
  z = ui.DC_input_z->text().toFloat();
  yaw = float(ui.DC_input_yaw->text().toDouble()/180.0*3.1415926535);
  qnode.cb_pb_mission_loc(receive_ID,x,y,z,yaw,state);

  qnode.flag_save_path_data[receive_ID] = 0;
}


// Adding
void MainWindow::deal_receiveImageSignal()
{
  if (!flag_use_yolo)
  {
    showImage_mutex_.lock();
    QImage qImg = qnode.qImageFromBGRimage.copy();
    ui.camera_image_label->setPixmap(QPixmap::fromImage(qImg));
    showImage_mutex_.unlock();
  }
}

void MainWindow::deal_receiveImageSignal2()
{
  if (flag_use_yolo)
  {
    showImage_mutex_.lock();
    QImage qImg2 = qnode.qImageFromBGRimage2.copy();
    ui.camera_image_label->setPixmap(QPixmap::fromImage(qImg2));
    showImage_mutex_.unlock();
  }
}

}  // namespace gui_arc


