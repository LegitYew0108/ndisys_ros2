#include "ndi_msgs/msg/rigid_array.hpp"
#include "rclcpp/rclcpp.hpp"
#include "tf2_ros/transform_broadcaster.hpp"

namespace ndisys
{
class RigidposeTfConverter : public rclcpp::Node
{
public:
  RigidposeTfConverter(const rclcpp::NodeOptions & opts);

private:
  void rigidpose_callback(ndi_msgs::msg::RigidArray::UniquePtr msg);
  std::string sensor_frame_id_;
  rclcpp::Subscription<ndi_msgs::msg::RigidArray>::SharedPtr rigid_sub_;
  std::unique_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;
};
}  // namespace ndisys
