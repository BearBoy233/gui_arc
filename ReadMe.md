
# cq_ws qt 地面站
- Version 1.0

# 第一版
	3架无人机 Wifi+Optitrack 室内编队任务

通过 串口P900 实现指令通信
通过 Wifi(ROS+rtsp) 实现图像传输
通过 ROS_Yolo 实现目标类型识别
通过 Mavros+Px4_control等 实现无人机控制

# For run
$ gedit .bashrc
Add `export LD_LIBRARY_PATH="/home/zy/ws_cq/lib_arcgis:$LD_LIBRARY_PATH"`



 

