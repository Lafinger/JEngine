#set(ThirdPartyDir "ThirdPartyDir")

# include(${CMAKE_SOURCE_DIR}/CMake/Tools.cmake)

if(NOT TARGET Glad)
    include(Glad.cmake)
    set_target_properties(Glad PROPERTIES FOLDER ${ThirdPartyDir}/Glad)
    # NoWarning(Glad)
endif()

# GLFW with the same name of project GLFW, so named "glfw"
if(NOT TARGET glfw)
    option(GLFW_BUILD_EXAMPLES "" OFF)
    option(GLFW_BUILD_TESTS "" OFF)
    option(GLFW_BUILD_DOCS "" OFF)
    option(GLFW_INSTALL "" OFF)
    add_subdirectory(glfw)
    set_target_properties(glfw PROPERTIES FOLDER ${ThirdPartyDir}/GLFW)
    # NoWarning(glfw)
endif()

if(NOT TARGET glm)
    option(BUILD_STATIC_LIBS "" ON)
    option(BUILD_TESTING "" OFF)
    option(GLM_TEST_ENABLE "" OFF)
    add_subdirectory(glm)
    set_target_properties(glm PROPERTIES FOLDER ${ThirdPartyDir}/glm)
    # NoWarningInterface(glm)
endif()

if(NOT TARGET imgui)
    include(imgui.cmake)
    set_target_properties(imgui PROPERTIES FOLDER ${ThirdPartyDir}/imgui)
    # NoWarning(imgui)
endif()

# if(NOT TARGET yaml-cpp)
#     include(yaml-cpp.cmake)
#     set_target_properties(yaml-cpp PROPERTIES FOLDER ${ThirdPartyDir}/yaml-cpp)
#     NoWarning(yaml-cpp)
# endif()

if(NOT TARGET spdlog)
    option(SPDLOG_BUILD_EXAMPLE "" OFF)
    option(SPDLOG_INSTALL "" OFF)
    add_subdirectory(spdlog)
    set_target_properties(spdlog PROPERTIES FOLDER ${ThirdPartyDir}/spdlog)
    # NoWarning(spdlog)
endif()

# if(NOT TARGET box2d)
#     option(BOX2D_BUILD_UNIT_TESTS "Build the Box2D unit tests" OFF)
#     option(BOX2D_BUILD_TESTBED "Build the Box2D testbed" OFF)
#     add_subdirectory(box2d)
#     set_target_properties(box2d PROPERTIES FOLDER ${ThirdPartyDir}/box2d)
#     NoWarning(box2d)
# endif()

if(NOT TARGET stb)
    include(stb.cmake)
    set_target_properties(stb PROPERTIES FOLDER ${ThirdPartyDir}/stb)
    # NoWarning(stb)
endif()

if(NOT TARGET ImGuizmo)
    include(ImGuizmo.cmake)
    set_target_properties(ImGuizmo PROPERTIES FOLDER ${ThirdPartyDir}/ImGuizmo)
    # NoWarning(ImGuizmo)
endif()

if(NOT TARGET imGuIZMOquat)
    include(imGuIZMOquat.cmake)
    set_target_properties(imGuIZMOquat PROPERTIES FOLDER ${ThirdPartyDir}/imGuIZMOquat)
    # NoWarning(ImGuizmo)
endif()


if(NOT TARGET assimp)
    OPTION( BUILD_SHARED_LIBS
      "Build package with shared libraries."
      OFF
    )
    OPTION( ASSIMP_BUILD_FRAMEWORK
      "Build package as Mac OS X Framework bundle."
      OFF
    )
    OPTION( ASSIMP_DOUBLE_PRECISION
      "Set to ON to enable double precision processing"
      OFF
    )
    OPTION( ASSIMP_OPT_BUILD_PACKAGES
      "Set to ON to generate CPack configuration files and packaging targets"
      OFF
    )
    OPTION( ASSIMP_ANDROID_JNIIOSYSTEM
      "Android JNI IOSystem support is active"
      OFF
    )
    OPTION( ASSIMP_NO_EXPORT
      "Disable Assimp's export functionality."
      OFF
    )
    OPTION( ASSIMP_BUILD_ZLIB
      "Build your own zlib"
      OFF
    )
    OPTION( ASSIMP_BUILD_ASSIMP_TOOLS
      "If the supplementary tools for Assimp are built in addition to the library."
      OFF
    )
    OPTION ( ASSIMP_BUILD_SAMPLES
      "If the official samples are built as well (needs Glut)."
      OFF
    )
    OPTION ( ASSIMP_BUILD_TESTS
      "If the test suite for Assimp is built in addition to the library."
      OFF
    )
    OPTION ( ASSIMP_COVERALLS
      "Enable this to measure test coverage."
      OFF
    )
    OPTION( ASSIMP_INSTALL
      "Disable this if you want to use assimp as a submodule."
      OFF
    )
    OPTION ( ASSIMP_ERROR_MAX
      "Enable all warnings."
      OFF
    )
    OPTION ( ASSIMP_ASAN
      "Enable AddressSanitizer."
      OFF
    )
    OPTION ( ASSIMP_UBSAN
      "Enable Undefined Behavior sanitizer."
      OFF
    )
    OPTION ( ASSIMP_BUILD_DOCS
      "Build documentation using Doxygen."
      OFF
    )
    OPTION( ASSIMP_INJECT_DEBUG_POSTFIX
      "Inject debug postfix in .a/.so/.dll lib names"
      OFF
    )

    OPTION ( ASSIMP_IGNORE_GIT_HASH
       "Don't call git to get the hash."
       OFF
    )
    add_subdirectory(assimp)
    set_target_properties(assimp PROPERTIES FOLDER ${ThirdPartyDir}/assimp)
    # NoWarning(assimp)
endif()

# if(NOT TARGET bullet3)
#     OPTION(BUILD_CPU_DEMOS "Build original Bullet CPU examples" OFF)
#     OPTION(BUILD_BULLET2_DEMOS "Set when you want to build the Bullet 2 demos" OFF)
#     OPTION(BUILD_UNIT_TESTS "Build Unit Tests"	OFF)
#     add_subdirectory(bullet3)
# endif()

if(NOT TARGET spirv-cross)
    add_subdirectory(SPIRV-Cross)
    set_target_properties(spirv-cross PROPERTIES FOLDER ${ThirdPartyDir}/SPIRV-Cross)
endif()

# Learned from https://github.com/Mike-Leo-Smith/LearnVulkan/blob/master/CMakeLists.txt
if (NOT TARGET SPIRV-Headers)
    add_subdirectory(SPIRV-Headers)
endif()

if (NOT TARGET SPIRV_TOOLS)
    option(SPIRV_SKIP_EXECUTABLES
      "Skip building the executable and tests along with the library"
      on)
    option(SKIP_SPIRV_TOOLS_INSTALL "Skip installation" off)
    add_subdirectory(SPIRV-Tools)
endif()

if (NOT TARGET glslang)
    add_subdirectory(glslang)
endif()

if(NOT TARGET shaderc)
    set(SHADERC_SKIP_TESTS ON CACHE BOOL "" FORCE)
    set(SHADERC_SKIP_EXAMPLES ON CACHE BOOL "" FORCE)
    set(SHADERC_SKIP_COPYRIGHT_CHECK ON CACHE BOOL "" FORCE)
    set(SHADERC_ENABLE_SHARED_CRT ON CACHE BOOL "" FORCE)
    add_subdirectory(shaderc)
    set_target_properties(shaderc PROPERTIES FOLDER ${ThirdPartyDir}/shaderc)
    set_target_properties(shaderc_combined_genfile PROPERTIES EXCLUDE_FROM_ALL ON) # Problematic on M1 Macs
endif()

# if(NOT TARGET pybind11)
#     if(DEFINED ENV{PYTHONHOME} AND DEFINED ENV{PYTHONPATH})
#         set(WITH_PYTHON ON PARENT_SCOPE)
#     else()
#         set(WITH_PYTHON OFF PARENT_SCOPE)
#     endif()
#     add_definitions(-DPYBIND11_FINDPYTHON=ON)
#     find_package(Python COMPONENTS Interpreter Development)
#     add_subdirectory(pybind11)
# endif()

if(NOT TARGET magic_enum)
    include(magic_enum.cmake)
endif()

# if(NOT TARGET FMOD_CORE)
#     include(FMOD.cmake)
# endif()

# if(NOT TARGET headers)
#     add_library(headers INTERFACE)
#     target_include_directories(headers INTERFACE "${ThirdPartyDirDir}")
#     target_include_directories(headers INTERFACE "${ThirdPartyDirDir}/entt/include")
#     target_include_directories(headers INTERFACE "${ThirdPartyDirDir}/assimp/include")
#     target_include_directories(headers INTERFACE "${ThirdPartyDirDir}/bullet3/src")
#     target_include_directories(headers INTERFACE "${ThirdPartyDirDir}/SPIRV-Cross")
#     target_include_directories(headers INTERFACE "${ThirdPartyDirDir}/vulkanmemoryallocator/include")
#     target_include_directories(headers INTERFACE "${ThirdPartyDirDir}/pybind11/include")
#     # NoWarningInterface(headers)
# endif()