cmake_minimum_required(VERSION 3.31)
project(game VERSION 0.1.0 LANGUAGES C)

file (GLOB_RECURSE Rayengine_HEADERS CONFIGURE_DEPENDS "source/headers/*.h")
set (Rayengine_INCLUDE_DIRS "")
foreach (_headerFile ${Ray_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list(APPEND Rayengine_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES Rayengine_INCLUDE_DIRS)


file (GLOB Main_SOURCES CONFIGURE_DEPENDS "game/*.c")
file (GLOB Main_HEADERS CONFIGURE_DEPENDS "game/*.h")
set (Main_INCLUDE_DIRS "")
foreach (_headerFile ${Main_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list(APPEND Main_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES Main_INCLUDE_DIRS)

add_executable(game ${Main_SOURCES})

target_link_libraries(game ${CMAKE_CURRENT_SOURCE_DIR}/source/build/librayengine.a)
target_link_libraries(game ${CMAKE_CURRENT_SOURCE_DIR}/raylib/libraylib.a)

target_link_libraries(game -lopengl32)
target_link_libraries(game -lgdi32)
target_link_libraries(game -lwinmm)

target_include_directories(game PRIVATE ${Main_INCLUDE_DIRS})
target_include_directories(game PRIVATE ${Rayengine_INCLUDE_DIRS})