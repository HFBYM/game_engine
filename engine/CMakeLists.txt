# project(engine)

file(GLOB_RECURSE ENGINE_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/engine/*.cpp)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/$<CONFIG>-windows-x64/engine)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/$<CONFIG>-windows-x64/engine)

add_library(engine SHARED ${ENGINE_SRC})
target_include_directories(engine PUBLIC    
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)
# Windows
if(WIN32)
    target_compile_definitions(engine PRIVATE
        EG_PLATFORM_WINDOWS
        EG_BUILD_DLL
    )
    target_compile_options(engine PRIVATE
        /permissive-
        /Zc:__cplusplus
    )
endif()

# define from build type
target_compile_definitions(engine
    PUBLIC
    $<$<CONFIG:Debug>:EG_DEBUG>
    $<$<CONFIG:Release>:EG_RELEASE>
    $<$<CONFIG:Dist>:EG_DIST>
)
