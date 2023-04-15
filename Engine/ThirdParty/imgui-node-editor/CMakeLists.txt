cmake_minimum_required(VERSION 3.10)

project(imgui-node-editor)


set(IMGUI_NODE_SRC 
	crude_json.cpp
	imgui_canvas.cpp
	imgui_node_editor.cpp
	imgui_node_editor_api.cpp
)
	  
add_library(imgui-node-editor ${IMGUI_NODE_SRC})

target_include_directories(imgui-node-editor PUBLIC
	../imgui/src
)

target_include_directories(imgui-node-editor PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>")

