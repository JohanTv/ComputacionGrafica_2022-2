cmake_minimum_required(VERSION 3.19)
project(LABGRAFICA)

set(CMAKE_CXX_STANDARD 20)

include_directories(src, include)

if(UNIX AND NOT APPLE)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -fopenmp")
endif()

find_package(X11 REQUIRED)

file(GLOB source_files
        src/*.cpp)

add_executable(${PROJECT_NAME}
        ${source_files}
        main.cpp)

include_directories(${X11_INCLUDE_DIR})
link_directories(${X11_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${X11_LIBRARIES})