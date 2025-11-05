#include "rclcpp/rclcpp.hpp"
#include "ndi_msgs/msg/rigid_array.hpp"

namespace ndisys{
	class RigidposeTfConverter: public rclcpp::Node{
		public:
		RigidposeTfConverter(const rclcpp::NodeOptions &opts);
		private:
		void rigidpose_callback();
		rclcpp::Subscription<ndi_msgs::msg::RigidArray>::SharedPtr rigid_sub_;
	};
}
