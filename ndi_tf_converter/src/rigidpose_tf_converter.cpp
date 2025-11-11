#include "rigidpose_tf_converter.hpp"

namespace ndisys
{
RigidposeTfConverter::RigidposeTfConverter(const rclcpp::NodeOptions & opts)
: Node("rigidpose_tf_converter", opts)
{
  rigid_sub_ = this->create_subscription<ndi_msgs::msg::RigidArray>(
    "rigid_poses", 10,
    std::bind(&RigidposeTfConverter::rigidpose_callback, this, std::placeholders::_1));
  tf_broadcaster_ = std::make_unique<tf2_ros::TransformBroadcaster>(*this);
  sensor_frame_id_ = this->declare_parameter<std::string>("sensor_frame_id", "ndi_link");
}

void RigidposeTfConverter::rigidpose_callback(ndi_msgs::msg::RigidArray::UniquePtr msg)
{
  for (int i = 0; i < (int)msg->ids.size(); i++) {
    if (msg->inbound[i] == false) {
      continue;
    }
    geometry_msgs::msg::TransformStamped tf_msg;

    tf_msg.header.frame_id = sensor_frame_id_;
    tf_msg.header.stamp = this->now();
    tf_msg.child_frame_id = msg->frames[i];

    tf_msg.transform.translation.x = msg->poses[i].position.x;
    tf_msg.transform.translation.y = msg->poses[i].position.y;
    tf_msg.transform.translation.z = msg->poses[i].position.z;
    tf_msg.transform.rotation = msg->poses[i].orientation;

    tf_broadcaster_->sendTransform(tf_msg);
  }
}
}  // namespace ndisys

#include "rclcpp_components/register_node_macro.hpp"
RCLCPP_COMPONENTS_REGISTER_NODE(ndisys::RigidposeTfConverter)
