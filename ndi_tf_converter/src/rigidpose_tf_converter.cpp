#include "rigidpose_tf_converter.hpp"

namespace ndisys{
	RigidposeTfConverter::RigidposeTfConverter(const rclcpp::NodeOptions &opts):Node("rigidpose_tf_converter", opts){

	}

	void RigidposeTfConverter::rigidpose_callback(){

	}
}

#include "rclcpp_components/register_node_macro.hpp"
RCLCPP_COMPONENTS_REGISTER_NODE(ndisys::RigidposeTfConverter)
