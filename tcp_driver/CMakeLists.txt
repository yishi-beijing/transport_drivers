


cmake_minimum_required(VERSION 3.5)
project(tcp_driver)

# Default to C++14
if (NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 14)
endif ()

if (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif ()

## dependencies
find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies()

find_package(asio_cmake_module REQUIRED)
find_package(ASIO REQUIRED)

find_package(ament_cmake_python REQUIRED)
find_package(rclpy REQUIRED)

ament_auto_add_library(${PROJECT_NAME} SHARED
        src/tcp_socket.cpp
        src/tcp_driver.cpp
        src/http_client.cpp
        src/http_client_driver.cpp
        )
ament_target_dependencies(${PROJECT_NAME} "ASIO")

ament_auto_package(
        CONFIG_EXTRAS_POST "tcp_driver-extras.cmake"
)
