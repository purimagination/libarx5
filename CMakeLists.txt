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

AUX_SOURCE_DIRECTORY(src/libcan LIBCAN_SOURCES)
AUX_SOURCE_DIRECTORY(src/arx5_base SDK_SOURCES)

add_executable(testHardwareInterface src/test/testHardwareInterface.cpp ${SDK_SOURCES} ${LIBCAN_SOURCES})
target_link_libraries(testHardwareInterface ${CMAKE_THREAD_LIBS_INIT} orocos-kdl kdl_parser)

add_executable(testRate src/test/testRate.cpp ${SDK_SOURCES} ${LIBCAN_SOURCES})
target_link_libraries(testRate ${CMAKE_THREAD_LIBS_INIT} orocos-kdl kdl_parser)

add_executable(testTrajectories src/test/testTrajectories.cpp ${SDK_SOURCES} ${LIBCAN_SOURCES})
target_link_libraries(testTrajectories ${CMAKE_THREAD_LIBS_INIT} orocos-kdl kdl_parser)

add_executable(testKinematicsDynamics src/test/testKinematicsDynamics.cpp ${SDK_SOURCES} ${LIBCAN_SOURCES})
target_link_libraries(testKinematicsDynamics ${CMAKE_THREAD_LIBS_INIT} orocos-kdl kdl_parser)

add_executable(testStateEstimation src/test/testStateEstimation.cpp ${SDK_SOURCES} ${LIBCAN_SOURCES})
target_link_libraries(testStateEstimation ${CMAKE_THREAD_LIBS_INIT} orocos-kdl kdl_parser)

add_executable(testTeaching src/test/testTeaching.cpp ${SDK_SOURCES} ${LIBCAN_SOURCES})
target_link_libraries(testTeaching ${CMAKE_THREAD_LIBS_INIT} orocos-kdl kdl_parser)

add_executable(test4005 src/test/test4005.cpp ${SDK_SOURCES} ${LIBCAN_SOURCES})
target_link_libraries(test4005 ${CMAKE_THREAD_LIBS_INIT} orocos-kdl kdl_parser)




add_executable(zeroPosition src/examples/zeroPosition.cpp ${SDK_SOURCES} ${LIBCAN_SOURCES})
target_link_libraries(zeroPosition ${CMAKE_THREAD_LIBS_INIT} orocos-kdl kdl_parser)

add_executable(gravityOff src/examples/gravityOff.cpp ${SDK_SOURCES} ${LIBCAN_SOURCES})
target_link_libraries(gravityOff ${CMAKE_THREAD_LIBS_INIT} orocos-kdl kdl_parser)

add_executable(gravityOffRecording src/examples/gravityOffRecording.cpp ${SDK_SOURCES} ${LIBCAN_SOURCES})
target_link_libraries(gravityOffRecording ${CMAKE_THREAD_LIBS_INIT} orocos-kdl kdl_parser)

add_executable(gravityOffPlaying src/examples/gravityOffPlaying.cpp ${SDK_SOURCES} ${LIBCAN_SOURCES})
target_link_libraries(gravityOffPlaying ${CMAKE_THREAD_LIBS_INIT} orocos-kdl kdl_parser)

add_executable(calibrate src/examples/calibrate.cpp ${SDK_SOURCES} ${LIBCAN_SOURCES})
target_link_libraries(calibrate ${CMAKE_THREAD_LIBS_INIT} orocos-kdl kdl_parser)

add_executable(gravityOffTeleoperation src/examples/gravityOffTeleoperation.cpp ${SDK_SOURCES} ${LIBCAN_SOURCES})
target_link_libraries(gravityOffTeleoperation ${CMAKE_THREAD_LIBS_INIT} orocos-kdl kdl_parser)

add_library(arx5_sdk STATIC ${SDK_SOURCES} ${LIBCAN_SOURCES})