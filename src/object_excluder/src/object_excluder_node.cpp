#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/laser_scan.hpp>
#include <visualization_msgs/msg/marker.hpp>
#include <tf2_ros/transform_listener.h>
#include <tf2_ros/buffer.h>
#include <geometry_msgs/msg/transform_stamped.hpp>
#include <cmath> 

class LaserScanProcessor : public rclcpp::Node {
public:
    LaserScanProcessor() 
        : Node("laser_scan_processor"),
          tf_buffer_(this->get_clock()),  
          tf_listener_(tf_buffer_) {     
        // Subscribe to the laser scan topic
        subscription_ = this->create_subscription<sensor_msgs::msg::LaserScan>(
            "/scan", 10, std::bind(&LaserScanProcessor::scan_callback, this, std::placeholders::_1));
        
        // Publisher for filtered laser scan
        publisher_ = this->create_publisher<sensor_msgs::msg::LaserScan>("/filtered_scan", 10);
        
        // Publisher for marker visualization in RViz
        marker_pub_ = this->create_publisher<visualization_msgs::msg::Marker>("/visualization_marker", 10);
    }

private:
    void scan_callback(const sensor_msgs::msg::LaserScan::SharedPtr msg) {
        auto filtered_scan = *msg;  // Create a copy of the incoming laser scan for filtering
        
        // Setting the cylinder radius to 0.15 meters
        const float cylinder_radius = 0.15f;
        
        // This tolerance is how much I allow the range to vary from the cylinder's size. Need to adjust this during testing.
        
        const float tolerance = 0.05f;

        // Loop through all the laser scan points
        for (size_t i = 0; i < msg->ranges.size(); ++i) {
            
            // Check if the range value is valid (not NaN or infinite)
            // This ensures I don't get bad data in my filtering
            if (std::isfinite(msg->ranges[i])) {
                
// Now, check if the laser scan range is within the size of the cylinder +/- tolerance.If it is, it's the cylinder and set the value to max range (to ignore it).
                if (msg->ranges[i] > (cylinder_radius - tolerance) && msg->ranges[i] < (cylinder_radius + tolerance)) {
                    
                    // Exclude the object by setting its range to the maximum distance
                    filtered_scan.ranges[i] = msg->range_max;  
                }
            }
        }

        // Publish the filtered laser scan for the SLAM node
        publisher_->publish(filtered_scan);

        // Logging for debugging to make sure the filtered scan was published
        RCLCPP_INFO(this->get_logger(), "Published filtered laser scan");
    }

    void publish_marker(float range, float angle) {
        // Creating a cylindrical marker to visualize in RViz (if needed)
        visualization_msgs::msg::Marker marker;
        marker.header.frame_id = "base_link";
        marker.header.stamp = this->now();
        marker.ns = "cylinder";
        marker.id = 0;  // I use ID 0 for now since I'm only publishing one marker
        marker.type = visualization_msgs::msg::Marker::CYLINDER;
        marker.action = visualization_msgs::msg::Marker::ADD;

        // Set the position of the marker based on the laser scan range and angle
        marker.pose.position.x = range * cos(angle);
        marker.pose.position.y = range * sin(angle);
        marker.pose.position.z = 0;  // assuming the cylinder is on the ground

        // Set the size of the cylinder marker
        marker.scale.x = 0.3;  // Diameter (this matches the size of cylinder in the world)
        marker.scale.y = 0.3;
        marker.scale.z = 1.0;  // Height of the cylinder
        
        // Make the marker red and visible in RViz
        marker.color.a = 1.0;  // opaque
        marker.color.r = 1.0;  // Red
        marker.color.g = 0.0;
        marker.color.b = 0.0;

        // Publish the marker to visualize in RViz
        marker_pub_->publish(marker);

        // Logging to confirm that the marker was published
        RCLCPP_INFO(this->get_logger(), "Published marker at range: %.2f, angle: %.2f", range, angle);
    }

    // Declaring the subscriptions and publishers
    rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr subscription_;
    rclcpp::Publisher<sensor_msgs::msg::LaserScan>::SharedPtr publisher_;
    rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr marker_pub_;
    tf2_ros::Buffer tf_buffer_;
    tf2_ros::TransformListener tf_listener_;
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<LaserScanProcessor>());
    rclcpp::shutdown();
    return 0;
}

