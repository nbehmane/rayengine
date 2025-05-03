cmake_minimum_required(VERSION 3.31)
project(spacegame VERSION 0.1.0 LANGUAGES C)


file (GLOB_RECURSE Ray_HEADERS CONFIGURE_DEPENDS "/raylib/include/*.h")
set (Ray_INCLUDE_DIRS "")
foreach (_headerFile ${Ray_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list(APPEND Ray_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES Ray_INCLUDE_DIRS)


file (GLOB_RECURSE Main_SOURCES CONFIGURE_DEPENDS "source/*.c")
file (GLOB_RECURSE Main_HEADERS CONFIGURE_DEPENDS "source/headers/*.h")
set (Main_INCLUDE_DIRS "")
foreach (_headerFile ${Main_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list(APPEND Main_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES Main_INCLUDE_DIRS)

add_executable(spacegame ${Main_SOURCES})

target_link_libraries(spacegame ${CMAKE_CURRENT_SOURCE_DIR}/raylib/libraylib.a)

target_link_libraries(spacegame -lopengl32)
target_link_libraries(spacegame -lgdi32)
target_link_libraries(spacegame -lwinmm)

target_include_directories(spacegame PRIVATE ${Main_INCLUDE_DIRS})
target_include_directories(spacegame PRIVATE ${Ray_INCLUDE_DIRS})