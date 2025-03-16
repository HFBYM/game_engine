# project(sandbox)

file(GLOB_RECURSE SANDBOX_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/$<CONFIG>-windows-x64/sandbox)
add_executable(sandbox ${SANDBOX_SRC})
target_link_libraries(sandbox PRIVATE engine)
if(WIN32)
    target_compile_definitions(sandbox PRIVATE
        EG_PLATFORM_WINDOWS
    )
    add_custom_command(TARGET sandbox POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/bin/$<CONFIG>-windows-x64/engine/engine.dll
        ${CMAKE_SOURCE_DIR}/bin/$<CONFIG>-windows-x64/sandbox
    )
endif()
