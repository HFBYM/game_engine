cmake_minimum_required(VERSION 3.21)
project(game_engine)

# set the output directory
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set the configuration types
# set(CMAKE_CONFIGURATION_TYPES "Debug;Release;Dist" CACHE STRING "" FORCE)
# foreach(config IN LISTS CMAKE_CONFIGURATION_TYPES)
#     string(TOUPPER ${config} config_upper)
#     set(CMAKE_SHARED_LINKER_FLAGS_${config_upper} "-Wl,--no-undefined")
#     set(CMAKE_EXE_LINKER_FLAGS_${config_upper} "-Wl,--no-as-needed")
# endforeach()
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "" FORCE)
set(CMAKE_BUILD_TYPE Debug)

# depose ZERO   
set(CMAKE_SUPPRESS_REGENERATION TRUE)

add_subdirectory(engine)

add_subdirectory(sandbox)
# public flags
# foreach(target IN ITEMS engine sandbox)
#     target_compile_options(${target} PRIVATE
#         $<$<CONFIG:Debug>:/Od /Zi>
#         $<$<CONFIG:Release>:/O2 /Ob2>
#         $<$<CONFIG:Dist>:/Ox /Ob2>
#     )
# endforeach()