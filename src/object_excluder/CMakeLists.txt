cmake_minimum_required(VERSION 3.5)
project(object_excluder)

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(visualization_msgs REQUIRED)
find_package(tf2_ros REQUIRED)

# Include directories
include_directories(include)

# Declare the executable
add_executable(object_excluder_node src/object_excluder_node.cpp)

# Specify dependencies for the target
ament_target_dependencies(object_excluder_node
  rclcpp
  sensor_msgs
  visualization_msgs
  tf2_ros
)

# Install targets
install(TARGETS
  object_excluder_node
  DESTINATION lib/${PROJECT_NAME})

ament_package()

