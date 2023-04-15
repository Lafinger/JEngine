set(imGuIZMOquatSourceDir ${ThirdPartyDir}/imGuIZMOquat)

set(imGuIZMOquatSrc 
    "${imGuIZMOquatSourceDir}/imGuIZMOquat.h"
    "${imGuIZMOquatSourceDir}/imGuIZMOquat.cpp"
)

add_library(imGuIZMOquat STATIC ${imGuIZMOquatSrc})
target_include_directories(imGuIZMOquat PUBLIC "${imGuIZMOquatSourceDir}")
target_link_libraries(imGuIZMOquat PUBLIC imgui glm)