#include <rclcpp/rclcpp.hpp>
#include <nav_msgs/msg/occupancy_grid.hpp>
#include <opencv2/opencv.hpp>

class MapPublisherNode : public rclcpp::Node {
public:
    MapPublisherNode() : Node("map_publisher_node") {
        // Create the publisher only once in the constructor
        map_pub_ = this->create_publisher<nav_msgs::msg::OccupancyGrid>("/map_ground_truth", 10);

        // Load the map and publish it
        publishMap();
    }

private:
    void publishMap() {
        // Load the map (PGM format)
        std::string map_path = "/home/student/ros2_ws/Maps/G_creator_maps/smart_factory_map_test.pgm";
        cv::Mat map_image = cv::imread(map_path, cv::IMREAD_GRAYSCALE);

        if (map_image.empty()) {
            RCLCPP_ERROR(this->get_logger(), "Failed to load map from: %s", map_path.c_str());
            return;
        }

        RCLCPP_INFO(this->get_logger(), "Loaded map from: %s", map_path.c_str());

        // Create an OccupancyGrid message
        nav_msgs::msg::OccupancyGrid occupancy_grid_msg;
        occupancy_grid_msg.header.stamp = this->now();
        occupancy_grid_msg.header.frame_id = "map";

        // Fill the metadata (adjust this depending on your map resolution and origin)
        occupancy_grid_msg.info.resolution = 0.05; // Example resolution in meters per pixel
        occupancy_grid_msg.info.width = map_image.cols;
        occupancy_grid_msg.info.height = map_image.rows;
        occupancy_grid_msg.info.origin.position.x = 0.0;  // Adjust if necessary
        occupancy_grid_msg.info.origin.position.y = 0.0;  // Adjust if necessary
        occupancy_grid_msg.info.origin.position.z = 0.0;
        occupancy_grid_msg.info.origin.orientation.w = 1.0; // No rotation

        // Convert the map data from the OpenCV image to OccupancyGrid format
        for (int i = 0; i < map_image.rows; i++) {
            for (int j = 0; j < map_image.cols; j++) {
                int pixel_value = map_image.at<uchar>(i, j);
                int occupancy_value = (pixel_value == 255) ? 0 : (pixel_value == 0 ? 100 : -1);
                occupancy_grid_msg.data.push_back(occupancy_value);
            }
        }

        RCLCPP_INFO(this->get_logger(), "Publishing the map...");

        // Publish the map
        map_pub_->publish(occupancy_grid_msg);  // Corrected: Now actually publishing the map
    }

    rclcpp::Publisher<nav_msgs::msg::OccupancyGrid>::SharedPtr map_pub_;
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MapPublisherNode>());
    rclcpp::shutdown();
    return 0;
}

