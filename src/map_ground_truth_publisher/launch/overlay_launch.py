from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import ExecuteProcess

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='map_ground_truth_publisher',
            executable='map_publisher_node',
            name='map_publisher_node',
            output='screen'
        ),
        ExecuteProcess(
            cmd=['rviz2', '-d', '/home/student/ros2_ws/your_rviz_config.rviz'],
            output='screen'
        )
    ])

