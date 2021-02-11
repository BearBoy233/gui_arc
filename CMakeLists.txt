
cmake_minimum_required(VERSION 3.1.2)

project(gui_arc)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(QT Core Gui Widgets OpenGL Qml QuickWidgets Network Positioning Sensors Multimedia)
set(QT_LIBRARIES Qt5::Core Qt5::Gui Qt5::Widgets Qt5::OpenGL Qt5::Qml Qt5::QuickWidgets 
	Qt5::Network Qt5::Positioning Qt5::Sensors Qt5::Multimedia
   )
find_package(Qt5 REQUIRED ${QT})

find_package(OpenCV 3.2 REQUIRED)
find_package(catkin REQUIRED COMPONENTS
    roscpp
    message_generation
    rviz
    std_msgs
    sensor_msgs
    cv_bridge
    image_transport
)

include_directories(	
	${catkin_INCLUDE_DIRS}
        ${OpenCV_INCLUDE_DIRS}
	include/arcgis
	include/arcgis/LocalServer
	# ${CMAKE_CURRENT_BINARY_DIR}/..
)

# 添加动态连接库的路径 ArcGIS
link_directories(${PROJECT_SOURCE_DIR}/lib) 
# link_directories(/home/zy/ws_cq/lib_arcgis) 

add_message_files(
  FILES
M_Heartbeat.msg
M_KCF_Select.msg
M_POS_GPS.msg
M_POS_Local.msg
M_switch_state.msg
M_mission_loc.msg
trans_data.msg
)

generate_messages(
  DEPENDENCIES
  #geometry_msgs nav_msgs std_msgs sensor_msgs
)


catkin_package(
	INCLUDE_DIRS include
	#  LIBRARIES control DEPENDS system_lib
   	CATKIN_DEPENDS roscpp
)

file(GLOB QT_FORMS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ui/*.ui)
QT5_WRAP_UI(QT_FORMS_HPP ${QT_FORMS})

file(GLOB QT_RESOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} resources/*.qrc)
QT5_ADD_RESOURCES(QT_RESOURCES_CPP ${QT_RESOURCES})

file(GLOB_RECURSE QT_MOC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS include/gui_arc/*.hpp)
QT5_WRAP_CPP(QT_MOC_HPP ${QT_MOC})

file(GLOB_RECURSE QT_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS src/*.cpp)

add_executable(gui_arc ${QT_SOURCES} ${QT_RESOURCES_CPP} ${QT_FORMS_HPP} ${QT_MOC_HPP} ${HEADERS})
target_link_libraries(gui_arc ${QT_LIBRARIES} ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})
target_link_libraries(gui_arc -lEsriRuntimeQt -lEsriCommonQt -lruntimecore)

install(TARGETS gui_arc RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

