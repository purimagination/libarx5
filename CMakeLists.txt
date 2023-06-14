cmake_minimum_required (VERSION 3.7)
project (arx5_sdk)

# Default to C++17
set(CMAKE_CXX_STANDARD 17)

find_package(orocos_kdl REQUIRED)
find_package(Threads REQUIRED)
find_package(Curses REQUIRED)
find_package(Boost REQUIRED)
find_package(kdl_parser REQUIRED)

include_directories(include)
include_directories("/usr/include/eigen3")

AUX_SOURCE_DIRECTORY(src/hardware HARDWARE_SOURCES)
AUX_SOURCE_DIRECTORY(src/libcan LIBCAN_SOURCES)
AUX_SOURCE_DIRECTORY(src/arx5_base SDK_SOURCES)
AUX_SOURCE_DIRECTORY(src/arx5_utils UTILS_SOURCES)

add_executable(testHardwareInterface src/test/testHardwareInterface.cpp ${SDK_SOURCES} ${UTILS_SOURCES} ${LIBCAN_SOURCES} ${HARDWARE_SOURCES})
target_link_libraries(testHardwareInterface ${CMAKE_THREAD_LIBS_INIT} orocos-kdl)

add_executable(testRate src/test/testRate.cpp ${SDK_SOURCES} ${UTILS_SOURCES} ${LIBCAN_SOURCES} ${HARDWARE_SOURCES})
target_link_libraries(testRate ${CMAKE_THREAD_LIBS_INIT} orocos-kdl)

add_executable(testTrajectories src/test/testTrajectories.cpp ${SDK_SOURCES} ${UTILS_SOURCES} ${LIBCAN_SOURCES} ${HARDWARE_SOURCES})
target_link_libraries(testTrajectories ${CMAKE_THREAD_LIBS_INIT} orocos-kdl)

add_executable(testKinematicsDynamics src/test/testKinematicsDynamics.cpp ${SDK_SOURCES} ${UTILS_SOURCES} ${LIBCAN_SOURCES} ${HARDWARE_SOURCES})
target_link_libraries(testKinematicsDynamics ${CMAKE_THREAD_LIBS_INIT} orocos-kdl)

add_executable(testStateEstimation src/test/testStateEstimation.cpp ${SDK_SOURCES} ${UTILS_SOURCES} ${LIBCAN_SOURCES} ${HARDWARE_SOURCES})
target_link_libraries(testStateEstimation ${CMAKE_THREAD_LIBS_INIT} orocos-kdl)

add_executable(testAll src/test/testAll.cpp ${SDK_SOURCES} ${UTILS_SOURCES} ${LIBCAN_SOURCES} ${HARDWARE_SOURCES})
target_link_libraries(testAll ${CMAKE_THREAD_LIBS_INIT} orocos-kdl)

add_library(arx5_sdk STATIC ${SDK_SOURCES} ${UTILS_SOURCES} ${LIBCAN_SOURCES} ${HARDWARE_SOURCES})