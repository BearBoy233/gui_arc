/**
 * @file /include/gui_arc/qnode.hpp
 *
 * @brief Communications central!
 *
 * @date February 2011
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef gui_arc_QNODE_HPP_
#define gui_arc_QNODE_HPP_

/*****************************************************************************
** Includes
*****************************************************************************/

// To workaround boost/qt4 problems that won't be bugfixed. Refer to
//    https://bugreports.qt.io/browse/QTBUG-22829
#ifndef Q_MOC_RUN
#include <ros/ros.h>

#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.h>
#endif

#include <string>
#include <QThread>
#include <QStringListModel>
#include <iostream>
#include <QGraphicsView>

#include <geometry_msgs/PoseStamped.h>
#include <gui_arc/M_POS_Local.h>
#include <gui_arc/M_Heartbeat.h>
#include <gui_arc/M_mission_loc.h>
#include <nav_msgs/Path.h>

/*****************************************************************************
** Namespaces
*****************************************************************************/
#define NN 10

namespace gui_arc {

/*****************************************************************************
** Class
*****************************************************************************/

class QNode : public QThread {
    Q_OBJECT
public:
	QNode(int argc, char** argv );
	virtual ~QNode();
	bool init();
	bool init(const std::string &master_url, const std::string &host_url);
	void run();

	/*********************
	** Logging
	**********************/
	enum LogLevel {
	         Debug,
	         Info,
	         Warn,
	         Error,
	         Fatal
	 };

	QStringListModel* loggingModel() { return &logging_model; }
	void log( const LogLevel &level, const std::string &msg);



  //adding
  image_transport::Subscriber receiveImage_sub;
  image_transport::Subscriber receiveImage_sub2;

  cv::Mat receiveImage;//保存接受到的图像
  QImage qImageFromBGRimage;//转换为QImage

  cv::Mat receiveImage2;//保存接受到的图像
  QImage qImageFromBGRimage2;//转换为QImage
  //bool receiveImageFlag;//接受到图像为true 处理完设置为false

  void receiveImage_cb(const sensor_msgs::ImageConstPtr& msg);
  void receiveImage_cb2(const sensor_msgs::ImageConstPtr& msg);




// Add 回调函数 ----------------------------------------------------
  bool car_vrpn_1 = 1;

  void cb_sub_hearbeat(const gui_arc::M_Heartbeat::ConstPtr& msg);
  void cb_sub_pos_local(const gui_arc::M_POS_Local::ConstPtr& msg);
  void cb_sub_pos_local_car(const gui_arc::M_POS_Local::ConstPtr& msg);
  void cb_pb_mission_loc(uint8_t receive_ID, float x, float y, float z, float yaw, uint8_t state);

  void cb_sub_pos_vrpn_car(const geometry_msgs::PoseStamped::ConstPtr& msg);


// emit --
 bool   drone_connect[NN];
 double  drone_battery_voltage[NN];
 int    drone_battery_remaining[NN];
 int    drone_mode[NN];
 int    drone_sys_state[NN];

 int flag_save_path_data[NN];


//----------------------------------------------
Q_SIGNALS:
	void loggingUpdated();
    void rosShutdown();

    void power( );        //界面1hz 信息更新触发

    // adding
    void receiveImageSignal();
    void receiveImageSignal2();

private:
	int init_argc;
	char** init_argv;
	ros::Publisher chatter_publisher;
    QStringListModel logging_model;

// Add ROS ----------------------------------------------------
  ros::Time current_time, last_time;
  //
  ros::Subscriber sub_hearbeat;
  gui_arc::M_Heartbeat received_heartbeat;

  ros::Publisher pub_serial_mission_loc;
  gui_arc::M_mission_loc send_mission_loc;

  // show path in rviz
  ros::Subscriber sub_pos_local;
  ros::Subscriber sub_pos_vrpn_car;
  ros::Subscriber sub_pos_local_car;
  gui_arc::M_POS_Local received_pos_local;
  gui_arc::M_POS_Local received_pos_local_car;
  geometry_msgs::PoseStamped received_pos_vrpn_car;
  ros::Publisher pub_rviz_drone_pos_1;
  ros::Publisher pub_rviz_drone_pos_2;
  ros::Publisher pub_rviz_drone_pos_3;
  ros::Publisher pub_rviz_car;
  nav_msgs::Path path_rviz_drone_pos_1;
  nav_msgs::Path path_rviz_drone_pos_2;
  nav_msgs::Path path_rviz_drone_pos_3;
  nav_msgs::Path init_msg_path;
  nav_msgs::Path path_rviz_car;


};

}  // namespace gui_arc

#endif /* gui_arc_QNODE_HPP_ */
