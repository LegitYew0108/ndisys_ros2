cmake_minimum_required(VERSION 3.8)
project(ndi_tf_converter)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake_auto REQUIRED)

ament_auto_find_build_dependencies()

ament_auto_add_library(rigidpose_tf_converter SHARED
	src/rigidpose_tf_converter.cpp
)

target_include_directories(rigidpose_tf_converter PUBLIC
	include/${PROJECT_NAME}
)

rclcpp_components_register_node(rigidpose_tf_converter
	PLUGIN "ndisys::RigidposeTfConverter"
  EXECUTABLE rigidpose_tf_converter_node
)

ament_auto_package()
