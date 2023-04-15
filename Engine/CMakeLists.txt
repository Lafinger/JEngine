set(EngineDir "${RootDir}/Engine")
set(ThirdPartyDir "${EngineDir}/ThirdParty")
set(RuntimeDir "${EngineDir}/Source/Runtime")
set(EditorDir "${EngineDir}/Source/Editor")
#set(EngineScriptsDir "${EngineDir}/Scripts")

# file(COPY ${EngineScriptsDir}
# DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

# # from https://github.com/BoomingTech/Pilot
# set(vulkan_include ${ThirdPartyDir}/VulkanSDK/include)

# if(WIN32)
#     set(vulkan_lib ${ThirdPartyDir}/VulkanSDK/lib/Win32/vulkan-1.lib)
#     set(glslangValidator_executable ${ThirdPartyDir}/VulkanSDK/bin/Win32/glslangValidator.exe)
# elseif(UNIX)
#     if(APPLE)
#       set(vulkan_lib ${ThirdPartyDir}/VulkanSDK/lib/MacOS/libvulkan.1.dylib)
#       set(glslangValidator_executable ${ThirdPartyDir}/VulkanSDK/bin/MacOS/glslangValidator)
#     else()
#       set(vulkan_lib ${ThirdPartyDir}/VulkanSDK/lib/Linux/libvulkan.so.1)
#       set(glslangValidator_executable ${ThirdPartyDir}/VulkanSDK/bin/Linux/glslangValidator)
#     endif()
# else()
#   message(FATAL_ERROR "Unknown Platform")
# endif()
# # end from

#set(WITH_PYTHON OFF) # will judge in ThirdParty/pybind11

if (NOT CMAKE_SIZEOF_VOID_P EQUAL 8)
    message(FATAL_ERROR "HEngine only supports 64-bit Platforms now")
endif ()

if (PROJECT_BINARY_DIR STREQUAL PROJECT_SOURCE_DIR)
    message(WARNING "The binary directory of CMake cannot be the same as source directory!")
endif()

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

if (WIN32)
    add_definitions(-DNOMINMAX -D_USE_Math_DEFINES)
endif()

if (MSVC)
    add_compile_options("/MP")
endif()

if (NOT MSVC)
    find_program(CCACHE_PROGRAM ccache)
    if (CCACHE_PROGRAM)
        message(STATUS "Found CCache: ${CCACHE_PROGRAM}")
        set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ${CCACHE_PROGRAM})
        set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ${CCACHE_PROGRAM})
    endif()
endif()

find_package(OpenGL 4.5 REQUIRED)

if (OpenGL_FOUND)
    message("Found OpenGL")
else()
    message("Not Found OpenGL")
endif()

# ThirdParty
add_subdirectory(ThirdParty)

# JEngineLib
set(JEngineFile 

${EngineDir}/Source/Runtime/Resource/AssetManager.h
${EngineDir}/Source/Runtime/Resource/AssetManager.cpp
${EngineDir}/Source/Runtime/Resource/ConfigManager.h
${EngineDir}/Source/Runtime/Resource/ConfigManager.cpp
${EngineDir}/Source/Runtime/Resource/ModeManager.h
${EngineDir}/Source/Runtime/Resource/ModeManager.cpp
${EngineDir}/Source/Runtime/Resource/IconManager.h
${EngineDir}/Source/Runtime/Resource/IconManager.cpp

${EngineDir}/Source/Runtime/JEngine.h
${EngineDir}/Source/Runtime/Core/Base/Header.h
${EngineDir}/Source/Runtime/Core/Base/Base.h
${EngineDir}/Source/Runtime/Core/Base/PublicSingleton.h
${EngineDir}/Source/Runtime/Core/Log/Log.h
${EngineDir}/Source/Runtime/Core/Log/Log.cpp
${EngineDir}/Source/Runtime/Core/Math/Math.hpp
${EngineDir}/Source/Runtime/Core/Utils/Timestep.hpp
${EngineDir}/Source/Runtime/Core/Utils/UUID.h
${EngineDir}/Source/Runtime/Core/Utils/UUID.cpp

${EngineDir}/Source/Runtime/Application/Framework/Application.h
${EngineDir}/Source/Runtime/Application/Framework/Application.cpp
${EngineDir}/Source/Runtime/Application/Framework/Layer.hpp
${EngineDir}/Source/Runtime/Application/Framework/LayerStack.h
${EngineDir}/Source/Runtime/Application/Framework/LayerStack.cpp
${EngineDir}/Source/Runtime/Application/Framework/Window.hpp

${EngineDir}/Source/Runtime/Application/Utils/MathUtils.h
${EngineDir}/Source/Runtime/Application/Utils/MathUtils.cpp
${EngineDir}/Source/Runtime/Application/Utils/WindowsPlatformUtils.h
${EngineDir}/Source/Runtime/Application/Utils/WindowsPlatformUtils.cpp

${EngineDir}/Source/Runtime/Application/Geometry/Geometry.h
${EngineDir}/Source/Runtime/Application/Geometry/Geometry.cpp

${EngineDir}/Source/Runtime/Platform/windows/WindowsWindow.h
${EngineDir}/Source/Runtime/Platform/windows/WindowsWindow.cpp
${EngineDir}/Source/Runtime/Application/Event/Event.hpp
${EngineDir}/Source/Runtime/Application/Event/ApplicationEvent.hpp
${EngineDir}/Source/Runtime/Application/Event/KeyEvent.hpp
${EngineDir}/Source/Runtime/Application/Event/MouseEvent.hpp
${EngineDir}/Source/Runtime/Application/Input/Input.h
${EngineDir}/Source/Runtime/Application/Input/Input.cpp
${EngineDir}/Source/Runtime/Application/Input/KeyCodes.h
${EngineDir}/Source/Runtime/Application/Input/MouseCodes.h

${EngineDir}/Source/Runtime/Platform/OpenGL/OpenGLContext.h
${EngineDir}/Source/Runtime/Platform/OpenGL/OpenGLContext.cpp
${EngineDir}/Source/Runtime/Application/Renderer/RendererAPI.hpp
${EngineDir}/Source/Runtime/Application/Renderer/GraphicsContext.h
${EngineDir}/Source/Runtime/Application/Renderer/GraphicsContext.cpp

${EngineDir}/Source/Runtime/Platform/OpenGL/OpenGLImguiLayer.h
${EngineDir}/Source/Runtime/Platform/OpenGL/OpenGLImguiLayer.cpp
${EngineDir}/Source/Runtime/Application/Imgui/ImguiLayer.h
${EngineDir}/Source/Runtime/Application/Imgui/ImguiLayer.cpp

${EngineDir}/Source/Runtime/Application/Renderer/Material.h
${EngineDir}/Source/Runtime/Application/Renderer/Material.cpp
${EngineDir}/Source/Runtime/Application/Renderer/Renderer.h
${EngineDir}/Source/Runtime/Application/Renderer/Renderer.cpp
${EngineDir}/Source/Runtime/Application/Renderer/Renderer3D.h
${EngineDir}/Source/Runtime/Application/Renderer/Renderer3D.cpp
${EngineDir}/Source/Runtime/Application/Renderer/RendererAPI.hpp
${EngineDir}/Source/Runtime/Application/Mesh/Mesh.h
${EngineDir}/Source/Runtime/Application/Mesh/Mesh.cpp
${EngineDir}/Source/Runtime/Application/Mesh/SubMesh.h
${EngineDir}/Source/Runtime/Application/Mesh/SubMesh.cpp
${EngineDir}/Source/Runtime/Application/Library/Library.h
${EngineDir}/Source/Runtime/Application/Library/Library.cpp
${EngineDir}/Source/Runtime/Application/Library/ShaderLibrary.h
${EngineDir}/Source/Runtime/Application/Library/ShaderLibrary.cpp
${EngineDir}/Source/Runtime/Application/Library/TextureLibrary.h
${EngineDir}/Source/Runtime/Application/Library/TextureLibrary.cpp
${EngineDir}/Source/Runtime/Application/Library/UniformBufferLibrary.h
${EngineDir}/Source/Runtime/Application/Library/UniformBufferLibrary.cpp

${EngineDir}/Source/Runtime/Application/Renderer/RenderCommand.h
${EngineDir}/Source/Runtime/Application/Renderer/RenderCommand.cpp
${EngineDir}/Source/Runtime/Application/Renderer/Framebuffer.h
${EngineDir}/Source/Runtime/Application/Renderer/Framebuffer.cpp
${EngineDir}/Source/Runtime/Application/Renderer/Texture.h
${EngineDir}/Source/Runtime/Application/Renderer/Texture.cpp
${EngineDir}/Source/Runtime/Application/Renderer/RenderPass.h
${EngineDir}/Source/Runtime/Application/Renderer/RenderPass.cpp
${EngineDir}/Source/Runtime/Application/Renderer/Shader.h
${EngineDir}/Source/Runtime/Application/Renderer/Shader.cpp
${EngineDir}/Source/Runtime/Application/Renderer/PostProcessing.h
${EngineDir}/Source/Runtime/Application/Renderer/PostProcessing.cpp
${EngineDir}/Source/Runtime/Application/Renderer/VertexArray.h
${EngineDir}/Source/Runtime/Application/Renderer/VertexArray.cpp
${EngineDir}/Source/Runtime/Application/Renderer/VertexBuffer.h
${EngineDir}/Source/Runtime/Application/Renderer/VertexBuffer.cpp
${EngineDir}/Source/Runtime/Application/Renderer/IndexBuffer.h
${EngineDir}/Source/Runtime/Application/Renderer/IndexBuffer.cpp
${EngineDir}/Source/Runtime/Application/Renderer/UniformBuffer.h
${EngineDir}/Source/Runtime/Application/Renderer/UniformBuffer.cpp

${EngineDir}/Source/Runtime/Platform/OpenGL/OpenGLRendererAPI.h
${EngineDir}/Source/Runtime/Platform/OpenGL/OpenGLRendererAPI.cpp
${EngineDir}/Source/Runtime/Platform/OpenGL/OpenGLFramebuffer.h
${EngineDir}/Source/Runtime/Platform/OpenGL/OpenGLFramebuffer.cpp
${EngineDir}/Source/Runtime/Platform/OpenGL/OpenGLTexture.h
${EngineDir}/Source/Runtime/Platform/OpenGL/OpenGLTexture.cpp
${EngineDir}/Source/Runtime/Platform/OpenGL/NativeOpenGLShader.h
${EngineDir}/Source/Runtime/Platform/OpenGL/NativeOpenGLShader.cpp
${EngineDir}/Source/Runtime/Platform/OpenGL/OpenGLShader.h
${EngineDir}/Source/Runtime/Platform/OpenGL/OpenGLShader.cpp
${EngineDir}/Source/Runtime/Platform/OpenGL/OpenGLPostProcessing.h
${EngineDir}/Source/Runtime/Platform/OpenGL/OpenGLPostProcessing.cpp
${EngineDir}/Source/Runtime/Platform/OpenGL/OpenGLVertexArray.h
${EngineDir}/Source/Runtime/Platform/OpenGL/OpenGLVertexArray.cpp
${EngineDir}/Source/Runtime/Platform/OpenGL/OpenGLVertexBuffer.h
${EngineDir}/Source/Runtime/Platform/OpenGL/OpenGLVertexBuffer.cpp
${EngineDir}/Source/Runtime/Platform/OpenGL/OpenGLIndexBuffer.h
${EngineDir}/Source/Runtime/Platform/OpenGL/OpenGLIndexBuffer.cpp
${EngineDir}/Source/Runtime/Platform/OpenGL/OpenGLUniformBuffer.h
${EngineDir}/Source/Runtime/Platform/OpenGL/OpenGLUniformBuffer.cpp

${EngineDir}/Source/Runtime/Application/Camera/Camera.hpp
${EngineDir}/Source/Runtime/Application/Camera/EditorCamera.h
${EngineDir}/Source/Runtime/Application/Camera/EditorCamera.cpp
${EngineDir}/Source/Runtime/Application/Camera/SceneCamera.h
${EngineDir}/Source/Runtime/Application/Camera/SceneCamera.cpp

${EngineDir}/Source/Runtime/Application/EcsFramework/Component/Basic/IDComponent.h
${EngineDir}/Source/Runtime/Application/EcsFramework/Component/Basic/IDComponent.h
${EngineDir}/Source/Runtime/Application/EcsFramework/Component/Basic/TagComponent.h
${EngineDir}/Source/Runtime/Application/EcsFramework/Component/Basic/TagComponent.h
${EngineDir}/Source/Runtime/Application/EcsFramework/Component/Camera/CameraComponent.h
${EngineDir}/Source/Runtime/Application/EcsFramework/Component/Camera/CameraComponent.cpp
${EngineDir}/Source/Runtime/Application/EcsFramework/Component/Light/DirectionalLightComponent.h
${EngineDir}/Source/Runtime/Application/EcsFramework/Component/Light/DirectionalLightComponent.cpp
${EngineDir}/Source/Runtime/Application/EcsFramework/Component/Light/PointLightComponent.h
${EngineDir}/Source/Runtime/Application/EcsFramework/Component/Light/PointLightComponent.cpp
${EngineDir}/Source/Runtime/Application/EcsFramework/Component/Mesh/MeshComponent.h
${EngineDir}/Source/Runtime/Application/EcsFramework/Component/Mesh/MeshComponent.cpp
${EngineDir}/Source/Runtime/Application/EcsFramework/Component/Shape/CircleRendererComponent.h
${EngineDir}/Source/Runtime/Application/EcsFramework/Component/Shape/CircleRendererComponent.cpp
${EngineDir}/Source/Runtime/Application/EcsFramework/Component/Shape/SpriteRendererComponent.h
${EngineDir}/Source/Runtime/Application/EcsFramework/Component/Shape/SpriteRendererComponent.cpp
${EngineDir}/Source/Runtime/Application/EcsFramework/Component/Transform/TransformComponent.h
${EngineDir}/Source/Runtime/Application/EcsFramework/Component/Transform/TransformComponent.cpp
${EngineDir}/Source/Runtime/Application/EcsFramework/Component/ComponentBase.h
${EngineDir}/Source/Runtime/Application/EcsFramework/Component/ComponentConcept.h
${EngineDir}/Source/Runtime/Application/EcsFramework/Component/ComponentGroup.h
${EngineDir}/Source/Runtime/Application/EcsFramework/Entity/Entity.h
${EngineDir}/Source/Runtime/Application/EcsFramework/Entity/Entity.cpp
${EngineDir}/Source/Runtime/Application/EcsFramework/Level/Level.h
${EngineDir}/Source/Runtime/Application/EcsFramework/Level/Level.cpp
${EngineDir}/Source/Runtime/Application/EcsFramework/Registry/Registry.h
${EngineDir}/Source/Runtime/Application/EcsFramework/Registry/Registry.cpp
${EngineDir}/Source/Runtime/Application/EcsFramework/System/Render/EnvironmentSystem.h
${EngineDir}/Source/Runtime/Application/EcsFramework/System/Render/EnvironmentSystem.cpp
${EngineDir}/Source/Runtime/Application/EcsFramework/System/Render/RenderSystem3D.h
${EngineDir}/Source/Runtime/Application/EcsFramework/System/Render/RenderSystem3D.cpp
${EngineDir}/Source/Runtime/Application/EcsFramework/System/System.h
${EngineDir}/Source/Runtime/Application/EcsFramework/System/SystemGroup.h


${EngineDir}/Source/Editor/ImGuiWrapper/ImGuiWrapper.h
${EngineDir}/Source/Editor/ImGuiWrapper/ImGuiWrapper.cpp
${EngineDir}/Source/Editor/Panels/ContentBrowserPanel.h
${EngineDir}/Source/Editor/Panels/ContentBrowserPanel.cpp
${EngineDir}/Source/Editor/Panels/SceneHierarchyPanel.h
${EngineDir}/Source/Editor/Panels/SceneHierarchyPanel.cpp
${EngineDir}/Source/Editor/Panels/SceneSettingsPanel.h
${EngineDir}/Source/Editor/Panels/SceneSettingsPanel.cpp
${EngineDir}/Source/Editor/EditorLayer.h
${EngineDir}/Source/Editor/EditorLayer.cpp

${EngineDir}/Source/Editor/Test/RawLayer.h
${EngineDir}/Source/Editor/Test/RawLayer.cpp
)

set(JEngineHeader
${EngineDir}/Source/Runtime/JEngine.h
${EngineDir}/Source/Runtime/Core/Base/header.h
${EngineDir}/Source/Runtime/Core/Base/Base.h
${EngineDir}/Source/Runtime/Core/Base/PublicSingleton.h
${EngineDir}/Source/Runtime/Core/Log/Log.h
)
add_library(JEngineLib STATIC ${JEngineFile})
target_include_directories(JEngineLib PUBLIC ${EngineDir}/Source PUBLIC ThirdParty/entt/include PUBLIC ThirdParty/imgui-notify PUBLIC ThirdParty/imGuIZMOquat)

target_link_libraries(JEngineLib PUBLIC Glad)
target_link_libraries(JEngineLib PUBLIC glfw)
target_link_libraries(JEngineLib PUBLIC stb)
target_link_libraries(JEngineLib PUBLIC glm)
target_link_libraries(JEngineLib PUBLIC spdlog)
target_link_libraries(JEngineLib PUBLIC OpenGL32)
target_link_libraries(JEngineLib PUBLIC assimp)
target_link_libraries(JEngineLib PUBLIC shaderc)
target_link_libraries(JEngineLib PUBLIC magic_enum)
target_link_libraries(JEngineLib PUBLIC imgui)
target_link_libraries(JEngineLib PUBLIC ImGuizmo)
target_link_libraries(JEngineLib PUBLIC imGuIZMOquat)
target_link_libraries(JEngineLib PUBLIC spirv-cross-core)
target_link_libraries(JEngineLib PUBLIC spirv-cross-glsl)

# be used in ConfigManager
target_compile_definitions(JEngineLib 
# PRIVATE JENGINE_BUILD_DLL
PRIVATE GLFW_INCLUDE_NONE
PRIVATE IMGUI_IMPL_OPENGL_LOADER_CUSTOM
# PRIVATE JENGINE_DEBUG
"ENGINE_ROOT_DIR=${EngineDir}"
)


add_executable(${PROJECT_NAME} ${EngineDir}/Source/main.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC JEngineLib)
target_include_directories(${PROJECT_NAME} PUBLIC ${EngineDir}/Source PUBLIC ThirdParty/entt/include)



# if(WITH_PYTHON)
#     add_compile_definitions(WITH_PYTHON)
# endif()

# list(APPEND CMAKE_MODULE_PATH 
#   "${PROJECT_SOURCE_DIR}/CMake"
#   "${PROJECT_SOURCE_DIR}/CMake/Packages"
# )
# 
# if (WIN32)
#     find_package(DirectX11)
# endif()

#add_subdirectory(Runtime)
#add_subdirectory(editor)

# if(MSVC)
#     set_property(DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT HEngineEditor)
# endif()