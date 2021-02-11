/**
 * @file /src/qnode.cpp
 *
 * @brief Ros communication central!
 *
 * @date February 2011
 **/

/*****************************************************************************
** Includes
*****************************************************************************/

#include <ros/ros.h>
#include <ros/network.h>
#include <string>
#include <std_msgs/String.h>
#include <sstream>
#include "../include/gui_arc/qnode.hpp"

//#include "sensor_msgs/image_encodings.h"//added head file

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace gui_arc {

/*****************************************************************************
** Implementation
*****************************************************************************/

QNode::QNode(int argc, char** argv ) :
	init_argc(argc),
	init_argv(argv)
	{}

QNode::~QNode() {
    if( ros::isStarted() ) {
      ros::shutdown(); // explicitly needed since we use ros::start();
      ros::waitForShutdown();
    }
	wait();
}

bool QNode::init() {
	ros::init(init_argc,init_argv,"gui_arc");
	if ( ! ros::master::check() ) {
		return false;
	}
	ros::start(); // explicitly needed since our nodehandle is going out of scope.
	ros::NodeHandle n;

  // Add your ros communications here.
	chatter_publisher = n.advertise<std_msgs::String>("chatter", 1000);


  pub_serial_mission_loc = n.advertise<gui_arc::M_mission_loc>("/serial_p9/send/mission_loc", 10);
  // drone current pose
  sub_pos_local = n.subscribe<gui_arc::M_POS_Local>("/serial_p9/receive/pos_local", 10, &QNode::cb_sub_pos_local, this);

  sub_pos_vrpn_car = n.subscribe<geometry_msgs::PoseStamped>("/vrpn_client_node/turtlebot1/pose", 1, &QNode::cb_sub_pos_vrpn_car, this);
  sub_pos_local_car = n.subscribe<gui_arc::M_POS_Local>("/serial_p9/receive/set_pos_local", 10, &QNode::cb_sub_pos_local_car, this);
  // show path in rviz
  pub_rviz_drone_pos_1 = n.advertise<nav_msgs::Path>("/show_rviz/path/drone1", 1, true);
  pub_rviz_drone_pos_2 = n.advertise<nav_msgs::Path>("/show_rviz/path/drone2", 1, true);
  pub_rviz_drone_pos_3 = n.advertise<nav_msgs::Path>("/show_rviz/path/drone3", 1, true);
  pub_rviz_car = n.advertise<nav_msgs::Path>("/show_rviz/path/car", 1, true);
  // Init
  /*
  path_rviz_drone_pos_1.header.stamp = ros::Time::now();
  path_rviz_drone_pos_1.header.frame_id = "map";
  path_rviz_drone_pos_2.header.stamp = ros::Time::now();
  path_rviz_drone_pos_2.header.frame_id = "map";
  path_rviz_drone_pos_3.header.stamp = ros::Time::now();
  path_rviz_drone_pos_3.header.frame_id = "map";
  path_rviz_car.header.stamp = ros::Time::now();
  path_rviz_car.header.frame_id = "map";
  */
  init_msg_path.header.stamp = ros::Time::now();
  init_msg_path.header.frame_id = "map";

  path_rviz_drone_pos_1 = init_msg_path;
  path_rviz_drone_pos_2 = init_msg_path;
  path_rviz_drone_pos_3 = init_msg_path;
  path_rviz_car = init_msg_path;

  // show heartbeat
  sub_hearbeat = n.subscribe<gui_arc::M_Heartbeat>("/serial_p9/receive/heartbeat", 10, &QNode::cb_sub_hearbeat, this);

  // pub_ID = nh.advertise<mavlink_uart::Mu_Switch_State>("/receive/need_switch_state", 10);

  for (int i=0; i<NN; i++)
  {  drone_connect[i] = false;
     drone_mode[i] = 15;
     flag_save_path_data[i] = 0;
  }

  //adding
  //ros::NodeHandle nh;
  //image_transport::ImageTransport it(nh);
  image_transport::ImageTransport it(n);
  //receiveImage_sub = it.subscribe("/rtsp_camera_relay_"+ uavname + "/image",5,&tracker_thread::receiveImage_cb,this,image_transport::TransportHints("compressed"));// 订阅 图像信息
  receiveImage_sub = it.subscribe("/rtsp_camera_relay/image",20,&QNode::receiveImage_cb,this,image_transport::TransportHints("compressed"));// 订阅 图像信息

  receiveImage_sub2 = it.subscribe("/darknet_ros/detection_image",20,&QNode::receiveImage_cb2,this);//image_transport::TransportHints("compressed"));// 订阅 图像信息
  //receiveImage_sub2 = it.subscribe("/rtsp_camera_relay/image",20,&QNode::receiveImage_cb2,this,image_transport::TransportHints("compressed"));// 订阅 图像信息

	start();
	return true;
}

// 不用此初始化 init()
bool QNode::init(const std::string &master_url, const std::string &host_url) {
	std::map<std::string,std::string> remappings;
	remappings["__master"] = master_url;
	remappings["__hostname"] = host_url;
	ros::init(remappings,"gui_arc");
	if ( ! ros::master::check() ) {
		return false;
	}
	ros::start(); // explicitly needed since our nodehandle is going out of scope.
	ros::NodeHandle n;
	// Add your ros communications here.
	chatter_publisher = n.advertise<std_msgs::String>("chatter", 1000);
	start();
	return true;
}

void QNode::run() {
  ros::Rate loop_rate(20);

  int count = 0;
  while ( ros::ok() )
  {
    ros::spinOnce();

    if (count ==20 )
    {
      emit power();
      count = 0;
    }
    count++;

    /* example
		std_msgs::String msg;
		std::stringstream ss;
		ss << "hello world " << count;
		msg.data = ss.str();
		chatter_publisher.publish(msg);
		log(Info,std::string("I sent: ")+msg.data);
    ++count;
    */

    loop_rate.sleep();
	}


	std::cout << "Ros shutdown, proceeding to close the gui." << std::endl;
	Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}


void QNode::log( const LogLevel &level, const std::string &msg) {
	logging_model.insertRows(logging_model.rowCount(),1);
	std::stringstream logging_model_msg;
	switch ( level ) {
		case(Debug) : {
				ROS_DEBUG_STREAM(msg);
				logging_model_msg << "[DEBUG] [" << ros::Time::now() << "]: " << msg;
				break;
		}
		case(Info) : {
				ROS_INFO_STREAM(msg);
				logging_model_msg << "[INFO] [" << ros::Time::now() << "]: " << msg;
				break;
		}
		case(Warn) : {
				ROS_WARN_STREAM(msg);
				logging_model_msg << "[INFO] [" << ros::Time::now() << "]: " << msg;
				break;
		}
		case(Error) : {
				ROS_ERROR_STREAM(msg);
				logging_model_msg << "[ERROR] [" << ros::Time::now() << "]: " << msg;
				break;
		}
		case(Fatal) : {
				ROS_FATAL_STREAM(msg);
				logging_model_msg << "[FATAL] [" << ros::Time::now() << "]: " << msg;
				break;
		}
	}
	QVariant new_row(QString(logging_model_msg.str().c_str()));
	logging_model.setData(logging_model.index(logging_model.rowCount()-1),new_row);
	Q_EMIT loggingUpdated(); // used to readjust the scrollbar
}



void QNode::cb_sub_hearbeat(const gui_arc::M_Heartbeat::ConstPtr& msg)
{
  received_heartbeat = *msg;
/*
  received_heartbeat.mav_mode;
  received_heartbeat.task_status;
  received_heartbeat.battery_voltage;
  received_heartbeat.battery_remaining;
*/
  int i;
  i = int(received_heartbeat.Send_ID);
  drone_connect[i] = true;
  drone_battery_voltage[i] = ( double(received_heartbeat.battery_voltage) )*0.1 + 6.0;
  drone_battery_remaining[i] = int(received_heartbeat.battery_remaining);
  drone_mode[i] = int(received_heartbeat.mav_mode);
  drone_sys_state[i] = int(received_heartbeat.task_status);
}

void QNode::cb_sub_pos_local(const gui_arc::M_POS_Local::ConstPtr& msg)
{
  received_pos_local = *msg;

  geometry_msgs::PoseStamped this_pose_stamped;
  this_pose_stamped.header.stamp = ros::Time::now();
  this_pose_stamped.header.frame_id = "map";
  this_pose_stamped.pose.position.x = double(received_pos_local.x);
  this_pose_stamped.pose.position.y = double(received_pos_local.y);
  this_pose_stamped.pose.position.z = double(received_pos_local.z);
  this_pose_stamped.pose.orientation.x = 0;
  this_pose_stamped.pose.orientation.y = 0;
  this_pose_stamped.pose.orientation.z = 1;
  this_pose_stamped.pose.orientation.w = 1;

  int temp_no;
  temp_no = int(received_pos_local.Send_ID);

  if (flag_save_path_data[temp_no]==2)
  {
    flag_save_path_data[temp_no] = 1;
    switch ( temp_no )
    { case 1:
        init_msg_path.header.stamp = this_pose_stamped.header.stamp;
        init_msg_path.header.frame_id = "map";
        path_rviz_drone_pos_1 = init_msg_path;

        path_rviz_drone_pos_1.poses.push_back(this_pose_stamped);
        pub_rviz_drone_pos_1.publish(path_rviz_drone_pos_1);
      break;

      case 2:
        init_msg_path.header.stamp = this_pose_stamped.header.stamp;
        init_msg_path.header.frame_id = "map";
        path_rviz_drone_pos_2 = init_msg_path;

        path_rviz_drone_pos_2.poses.push_back(this_pose_stamped);
        pub_rviz_drone_pos_2.publish(path_rviz_drone_pos_2);
      break;

      case 3:
        init_msg_path.header.stamp = this_pose_stamped.header.stamp;
        init_msg_path.header.frame_id = "map";
        path_rviz_drone_pos_3 = init_msg_path;

        path_rviz_drone_pos_3.poses.push_back(this_pose_stamped);
        pub_rviz_drone_pos_3.publish(path_rviz_drone_pos_3);
      break;
    }


  }
  else if (flag_save_path_data[temp_no]==1)
  {
    switch ( temp_no )
    { case 1:
         path_rviz_drone_pos_1.poses.push_back(this_pose_stamped);
         pub_rviz_drone_pos_1.publish(path_rviz_drone_pos_1);
      break;

      case 2:
        path_rviz_drone_pos_2.poses.push_back(this_pose_stamped);
        pub_rviz_drone_pos_2.publish(path_rviz_drone_pos_2);
      break;

      case 3:
        path_rviz_drone_pos_3.poses.push_back(this_pose_stamped);
        pub_rviz_drone_pos_3.publish(path_rviz_drone_pos_3);
      break;
    }
  }
  //
}

void QNode::cb_sub_pos_local_car(const gui_arc::M_POS_Local::ConstPtr& msg)
{
  received_pos_local_car = *msg;

  if (!car_vrpn_1)
  {
    geometry_msgs::PoseStamped this_pose_stamped;
    this_pose_stamped.header.stamp = ros::Time::now();
    this_pose_stamped.header.frame_id = "map";
    this_pose_stamped.pose.position.x = double(received_pos_local_car.x);
    this_pose_stamped.pose.position.y = double(received_pos_local_car.y);
    this_pose_stamped.pose.position.z = double(received_pos_local_car.z);
    this_pose_stamped.pose.orientation.x = 0;
    this_pose_stamped.pose.orientation.y = 0;
    this_pose_stamped.pose.orientation.z = 1;
    this_pose_stamped.pose.orientation.w = 1;

    path_rviz_car.poses.push_back(this_pose_stamped);
    pub_rviz_car.publish(path_rviz_car);
  }
  //
}

void QNode::cb_sub_pos_vrpn_car(const geometry_msgs::PoseStamped::ConstPtr& msg)
{
  received_pos_vrpn_car = *msg;

  if (car_vrpn_1)
  {
    geometry_msgs::PoseStamped this_pose_stamped;
    this_pose_stamped = received_pos_vrpn_car;
    this_pose_stamped.header.frame_id = "map";
    this_pose_stamped.pose.orientation.x = 0;
    this_pose_stamped.pose.orientation.y = 0;
    this_pose_stamped.pose.orientation.z = 1;
    this_pose_stamped.pose.orientation.w = 1;

    path_rviz_car.poses.push_back(this_pose_stamped);
    pub_rviz_car.publish(path_rviz_car);
  }
  //
}

void QNode::cb_pb_mission_loc(uint8_t receive_ID, float x, float y, float z, float yaw, uint8_t state)
{
  send_mission_loc.Receive_ID = receive_ID;
  send_mission_loc.Send_ID = 0x0a;
  send_mission_loc.state = state;
  send_mission_loc.x = x;
  send_mission_loc.y = y;
  send_mission_loc.z = z;
  send_mission_loc.yaw = yaw;

  pub_serial_mission_loc.publish(send_mission_loc);
  //
}


//adding
void QNode::receiveImage_cb(const sensor_msgs::ImageConstPtr& msg)
{
    try
    {
        receiveImage = cv_bridge::toCvCopy(msg,sensor_msgs::image_encodings::RGB8)->image;
        qImageFromBGRimage = QImage(receiveImage.data,receiveImage.cols,receiveImage.rows,receiveImage.step[0], QImage::Format_RGB888);
        Q_EMIT receiveImageSignal();
    }
    catch (cv_bridge::Exception& e)
    {
        std::cout << "sub1Image_cb could not convert from " << msg->encoding.c_str() << "to 'brg8'." << std::endl;
    }
}

void QNode::receiveImage_cb2(const sensor_msgs::ImageConstPtr& msg)
{
    try
    {
        receiveImage2 = cv_bridge::toCvCopy(msg,sensor_msgs::image_encodings::RGB8)->image;
        qImageFromBGRimage2 = QImage(receiveImage2.data,receiveImage2.cols,receiveImage2.rows,receiveImage2.step[0], QImage::Format_RGB888);
        Q_EMIT receiveImageSignal2();
    }
    catch (cv_bridge::Exception& e)
    {
        std::cout << "sub1Image_cb could not convert from " << msg->encoding.c_str() << "to 'brg8'." << std::endl;
    }
}


}  // namespace gui_arc
