
# cq_ws Qt5 地面站
- Version 1.0

# 第一版
	3架无人机 Wifi+Optitrack 室内编队任务

通过 串口P900 实现指令通信  
通过 Wifi(ROS+rtsp) 实现图像传输  
通过 ROS_Yolo 实现目标类型识别  
通过 Mavros+Px4_control等 实现无人机控制  


# Download
	git clone --recursive https://github.com/BearBoy233/gui_arc.git

# Load submodule (lib_ArcGIS) 
	git submodule update --init --recursive

# For run
$ gedit .bashrc  
	Add `export LD_LIBRARY_PATH="/home/XXXX/ws_cq/lib_arcgis:$LD_LIBRARY_PATH"`
or 
	Add `export LD_LIBRARY_PATH="/home/XXXX/ws_cq/gcs_ws/src/gui_arc/lib:$LD_LIBRARY_PATH"`



 

