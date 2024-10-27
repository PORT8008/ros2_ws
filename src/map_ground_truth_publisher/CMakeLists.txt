cmake_minimum_required(VERSION 3.8)
project(map_ground_truth_publisher)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(rclcpp REQUIRED)
find_package(OpenCV REQUIRED)  # Add OpenCV

# Include directories
include_directories(${OpenCV_INCLUDE_DIRS})

# Add executable for the node
add_executable(map_publisher_node src/map_publisher_node.cpp)

# Link OpenCV libraries
target_link_libraries(map_publisher_node ${OpenCV_LIBS})

ament_target_dependencies(map_publisher_node rclcpp nav_msgs)

install(TARGETS
  map_publisher_node
  DESTINATION lib/${PROJECT_NAME})

ament_package()

