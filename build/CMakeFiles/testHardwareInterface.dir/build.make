# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/hanzx/dev/projects/arx5/libarx5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hanzx/dev/projects/arx5/libarx5/build

# Include any dependencies generated for this target.
include CMakeFiles/testHardwareInterface.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/testHardwareInterface.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/testHardwareInterface.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testHardwareInterface.dir/flags.make

CMakeFiles/testHardwareInterface.dir/src/test/testHardwareInterface.cpp.o: CMakeFiles/testHardwareInterface.dir/flags.make
CMakeFiles/testHardwareInterface.dir/src/test/testHardwareInterface.cpp.o: ../src/test/testHardwareInterface.cpp
CMakeFiles/testHardwareInterface.dir/src/test/testHardwareInterface.cpp.o: CMakeFiles/testHardwareInterface.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hanzx/dev/projects/arx5/libarx5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/testHardwareInterface.dir/src/test/testHardwareInterface.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/testHardwareInterface.dir/src/test/testHardwareInterface.cpp.o -MF CMakeFiles/testHardwareInterface.dir/src/test/testHardwareInterface.cpp.o.d -o CMakeFiles/testHardwareInterface.dir/src/test/testHardwareInterface.cpp.o -c /home/hanzx/dev/projects/arx5/libarx5/src/test/testHardwareInterface.cpp

CMakeFiles/testHardwareInterface.dir/src/test/testHardwareInterface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testHardwareInterface.dir/src/test/testHardwareInterface.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hanzx/dev/projects/arx5/libarx5/src/test/testHardwareInterface.cpp > CMakeFiles/testHardwareInterface.dir/src/test/testHardwareInterface.cpp.i

CMakeFiles/testHardwareInterface.dir/src/test/testHardwareInterface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testHardwareInterface.dir/src/test/testHardwareInterface.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hanzx/dev/projects/arx5/libarx5/src/test/testHardwareInterface.cpp -o CMakeFiles/testHardwareInterface.dir/src/test/testHardwareInterface.cpp.s

CMakeFiles/testHardwareInterface.dir/src/arx5_base/hardware_interface.cpp.o: CMakeFiles/testHardwareInterface.dir/flags.make
CMakeFiles/testHardwareInterface.dir/src/arx5_base/hardware_interface.cpp.o: ../src/arx5_base/hardware_interface.cpp
CMakeFiles/testHardwareInterface.dir/src/arx5_base/hardware_interface.cpp.o: CMakeFiles/testHardwareInterface.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hanzx/dev/projects/arx5/libarx5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/testHardwareInterface.dir/src/arx5_base/hardware_interface.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/testHardwareInterface.dir/src/arx5_base/hardware_interface.cpp.o -MF CMakeFiles/testHardwareInterface.dir/src/arx5_base/hardware_interface.cpp.o.d -o CMakeFiles/testHardwareInterface.dir/src/arx5_base/hardware_interface.cpp.o -c /home/hanzx/dev/projects/arx5/libarx5/src/arx5_base/hardware_interface.cpp

CMakeFiles/testHardwareInterface.dir/src/arx5_base/hardware_interface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testHardwareInterface.dir/src/arx5_base/hardware_interface.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hanzx/dev/projects/arx5/libarx5/src/arx5_base/hardware_interface.cpp > CMakeFiles/testHardwareInterface.dir/src/arx5_base/hardware_interface.cpp.i

CMakeFiles/testHardwareInterface.dir/src/arx5_base/hardware_interface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testHardwareInterface.dir/src/arx5_base/hardware_interface.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hanzx/dev/projects/arx5/libarx5/src/arx5_base/hardware_interface.cpp -o CMakeFiles/testHardwareInterface.dir/src/arx5_base/hardware_interface.cpp.s

CMakeFiles/testHardwareInterface.dir/src/arx5_base/joint_trajectories.cpp.o: CMakeFiles/testHardwareInterface.dir/flags.make
CMakeFiles/testHardwareInterface.dir/src/arx5_base/joint_trajectories.cpp.o: ../src/arx5_base/joint_trajectories.cpp
CMakeFiles/testHardwareInterface.dir/src/arx5_base/joint_trajectories.cpp.o: CMakeFiles/testHardwareInterface.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hanzx/dev/projects/arx5/libarx5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/testHardwareInterface.dir/src/arx5_base/joint_trajectories.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/testHardwareInterface.dir/src/arx5_base/joint_trajectories.cpp.o -MF CMakeFiles/testHardwareInterface.dir/src/arx5_base/joint_trajectories.cpp.o.d -o CMakeFiles/testHardwareInterface.dir/src/arx5_base/joint_trajectories.cpp.o -c /home/hanzx/dev/projects/arx5/libarx5/src/arx5_base/joint_trajectories.cpp

CMakeFiles/testHardwareInterface.dir/src/arx5_base/joint_trajectories.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testHardwareInterface.dir/src/arx5_base/joint_trajectories.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hanzx/dev/projects/arx5/libarx5/src/arx5_base/joint_trajectories.cpp > CMakeFiles/testHardwareInterface.dir/src/arx5_base/joint_trajectories.cpp.i

CMakeFiles/testHardwareInterface.dir/src/arx5_base/joint_trajectories.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testHardwareInterface.dir/src/arx5_base/joint_trajectories.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hanzx/dev/projects/arx5/libarx5/src/arx5_base/joint_trajectories.cpp -o CMakeFiles/testHardwareInterface.dir/src/arx5_base/joint_trajectories.cpp.s

CMakeFiles/testHardwareInterface.dir/src/arx5_base/kinematics_dynamics.cpp.o: CMakeFiles/testHardwareInterface.dir/flags.make
CMakeFiles/testHardwareInterface.dir/src/arx5_base/kinematics_dynamics.cpp.o: ../src/arx5_base/kinematics_dynamics.cpp
CMakeFiles/testHardwareInterface.dir/src/arx5_base/kinematics_dynamics.cpp.o: CMakeFiles/testHardwareInterface.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hanzx/dev/projects/arx5/libarx5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/testHardwareInterface.dir/src/arx5_base/kinematics_dynamics.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/testHardwareInterface.dir/src/arx5_base/kinematics_dynamics.cpp.o -MF CMakeFiles/testHardwareInterface.dir/src/arx5_base/kinematics_dynamics.cpp.o.d -o CMakeFiles/testHardwareInterface.dir/src/arx5_base/kinematics_dynamics.cpp.o -c /home/hanzx/dev/projects/arx5/libarx5/src/arx5_base/kinematics_dynamics.cpp

CMakeFiles/testHardwareInterface.dir/src/arx5_base/kinematics_dynamics.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testHardwareInterface.dir/src/arx5_base/kinematics_dynamics.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hanzx/dev/projects/arx5/libarx5/src/arx5_base/kinematics_dynamics.cpp > CMakeFiles/testHardwareInterface.dir/src/arx5_base/kinematics_dynamics.cpp.i

CMakeFiles/testHardwareInterface.dir/src/arx5_base/kinematics_dynamics.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testHardwareInterface.dir/src/arx5_base/kinematics_dynamics.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hanzx/dev/projects/arx5/libarx5/src/arx5_base/kinematics_dynamics.cpp -o CMakeFiles/testHardwareInterface.dir/src/arx5_base/kinematics_dynamics.cpp.s

CMakeFiles/testHardwareInterface.dir/src/arx5_base/planner.cpp.o: CMakeFiles/testHardwareInterface.dir/flags.make
CMakeFiles/testHardwareInterface.dir/src/arx5_base/planner.cpp.o: ../src/arx5_base/planner.cpp
CMakeFiles/testHardwareInterface.dir/src/arx5_base/planner.cpp.o: CMakeFiles/testHardwareInterface.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hanzx/dev/projects/arx5/libarx5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/testHardwareInterface.dir/src/arx5_base/planner.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/testHardwareInterface.dir/src/arx5_base/planner.cpp.o -MF CMakeFiles/testHardwareInterface.dir/src/arx5_base/planner.cpp.o.d -o CMakeFiles/testHardwareInterface.dir/src/arx5_base/planner.cpp.o -c /home/hanzx/dev/projects/arx5/libarx5/src/arx5_base/planner.cpp

CMakeFiles/testHardwareInterface.dir/src/arx5_base/planner.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testHardwareInterface.dir/src/arx5_base/planner.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hanzx/dev/projects/arx5/libarx5/src/arx5_base/planner.cpp > CMakeFiles/testHardwareInterface.dir/src/arx5_base/planner.cpp.i

CMakeFiles/testHardwareInterface.dir/src/arx5_base/planner.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testHardwareInterface.dir/src/arx5_base/planner.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hanzx/dev/projects/arx5/libarx5/src/arx5_base/planner.cpp -o CMakeFiles/testHardwareInterface.dir/src/arx5_base/planner.cpp.s

CMakeFiles/testHardwareInterface.dir/src/arx5_base/state_estimation.cpp.o: CMakeFiles/testHardwareInterface.dir/flags.make
CMakeFiles/testHardwareInterface.dir/src/arx5_base/state_estimation.cpp.o: ../src/arx5_base/state_estimation.cpp
CMakeFiles/testHardwareInterface.dir/src/arx5_base/state_estimation.cpp.o: CMakeFiles/testHardwareInterface.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hanzx/dev/projects/arx5/libarx5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/testHardwareInterface.dir/src/arx5_base/state_estimation.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/testHardwareInterface.dir/src/arx5_base/state_estimation.cpp.o -MF CMakeFiles/testHardwareInterface.dir/src/arx5_base/state_estimation.cpp.o.d -o CMakeFiles/testHardwareInterface.dir/src/arx5_base/state_estimation.cpp.o -c /home/hanzx/dev/projects/arx5/libarx5/src/arx5_base/state_estimation.cpp

CMakeFiles/testHardwareInterface.dir/src/arx5_base/state_estimation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testHardwareInterface.dir/src/arx5_base/state_estimation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hanzx/dev/projects/arx5/libarx5/src/arx5_base/state_estimation.cpp > CMakeFiles/testHardwareInterface.dir/src/arx5_base/state_estimation.cpp.i

CMakeFiles/testHardwareInterface.dir/src/arx5_base/state_estimation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testHardwareInterface.dir/src/arx5_base/state_estimation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hanzx/dev/projects/arx5/libarx5/src/arx5_base/state_estimation.cpp -o CMakeFiles/testHardwareInterface.dir/src/arx5_base/state_estimation.cpp.s

CMakeFiles/testHardwareInterface.dir/src/arx5_utils/rate.cpp.o: CMakeFiles/testHardwareInterface.dir/flags.make
CMakeFiles/testHardwareInterface.dir/src/arx5_utils/rate.cpp.o: ../src/arx5_utils/rate.cpp
CMakeFiles/testHardwareInterface.dir/src/arx5_utils/rate.cpp.o: CMakeFiles/testHardwareInterface.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hanzx/dev/projects/arx5/libarx5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/testHardwareInterface.dir/src/arx5_utils/rate.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/testHardwareInterface.dir/src/arx5_utils/rate.cpp.o -MF CMakeFiles/testHardwareInterface.dir/src/arx5_utils/rate.cpp.o.d -o CMakeFiles/testHardwareInterface.dir/src/arx5_utils/rate.cpp.o -c /home/hanzx/dev/projects/arx5/libarx5/src/arx5_utils/rate.cpp

CMakeFiles/testHardwareInterface.dir/src/arx5_utils/rate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testHardwareInterface.dir/src/arx5_utils/rate.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hanzx/dev/projects/arx5/libarx5/src/arx5_utils/rate.cpp > CMakeFiles/testHardwareInterface.dir/src/arx5_utils/rate.cpp.i

CMakeFiles/testHardwareInterface.dir/src/arx5_utils/rate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testHardwareInterface.dir/src/arx5_utils/rate.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hanzx/dev/projects/arx5/libarx5/src/arx5_utils/rate.cpp -o CMakeFiles/testHardwareInterface.dir/src/arx5_utils/rate.cpp.s

CMakeFiles/testHardwareInterface.dir/src/libcan/CANAdapter.cpp.o: CMakeFiles/testHardwareInterface.dir/flags.make
CMakeFiles/testHardwareInterface.dir/src/libcan/CANAdapter.cpp.o: ../src/libcan/CANAdapter.cpp
CMakeFiles/testHardwareInterface.dir/src/libcan/CANAdapter.cpp.o: CMakeFiles/testHardwareInterface.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hanzx/dev/projects/arx5/libarx5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/testHardwareInterface.dir/src/libcan/CANAdapter.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/testHardwareInterface.dir/src/libcan/CANAdapter.cpp.o -MF CMakeFiles/testHardwareInterface.dir/src/libcan/CANAdapter.cpp.o.d -o CMakeFiles/testHardwareInterface.dir/src/libcan/CANAdapter.cpp.o -c /home/hanzx/dev/projects/arx5/libarx5/src/libcan/CANAdapter.cpp

CMakeFiles/testHardwareInterface.dir/src/libcan/CANAdapter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testHardwareInterface.dir/src/libcan/CANAdapter.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hanzx/dev/projects/arx5/libarx5/src/libcan/CANAdapter.cpp > CMakeFiles/testHardwareInterface.dir/src/libcan/CANAdapter.cpp.i

CMakeFiles/testHardwareInterface.dir/src/libcan/CANAdapter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testHardwareInterface.dir/src/libcan/CANAdapter.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hanzx/dev/projects/arx5/libarx5/src/libcan/CANAdapter.cpp -o CMakeFiles/testHardwareInterface.dir/src/libcan/CANAdapter.cpp.s

CMakeFiles/testHardwareInterface.dir/src/libcan/CANFrameParser.cpp.o: CMakeFiles/testHardwareInterface.dir/flags.make
CMakeFiles/testHardwareInterface.dir/src/libcan/CANFrameParser.cpp.o: ../src/libcan/CANFrameParser.cpp
CMakeFiles/testHardwareInterface.dir/src/libcan/CANFrameParser.cpp.o: CMakeFiles/testHardwareInterface.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hanzx/dev/projects/arx5/libarx5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/testHardwareInterface.dir/src/libcan/CANFrameParser.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/testHardwareInterface.dir/src/libcan/CANFrameParser.cpp.o -MF CMakeFiles/testHardwareInterface.dir/src/libcan/CANFrameParser.cpp.o.d -o CMakeFiles/testHardwareInterface.dir/src/libcan/CANFrameParser.cpp.o -c /home/hanzx/dev/projects/arx5/libarx5/src/libcan/CANFrameParser.cpp

CMakeFiles/testHardwareInterface.dir/src/libcan/CANFrameParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testHardwareInterface.dir/src/libcan/CANFrameParser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hanzx/dev/projects/arx5/libarx5/src/libcan/CANFrameParser.cpp > CMakeFiles/testHardwareInterface.dir/src/libcan/CANFrameParser.cpp.i

CMakeFiles/testHardwareInterface.dir/src/libcan/CANFrameParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testHardwareInterface.dir/src/libcan/CANFrameParser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hanzx/dev/projects/arx5/libarx5/src/libcan/CANFrameParser.cpp -o CMakeFiles/testHardwareInterface.dir/src/libcan/CANFrameParser.cpp.s

CMakeFiles/testHardwareInterface.dir/src/libcan/SocketCAN.cpp.o: CMakeFiles/testHardwareInterface.dir/flags.make
CMakeFiles/testHardwareInterface.dir/src/libcan/SocketCAN.cpp.o: ../src/libcan/SocketCAN.cpp
CMakeFiles/testHardwareInterface.dir/src/libcan/SocketCAN.cpp.o: CMakeFiles/testHardwareInterface.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hanzx/dev/projects/arx5/libarx5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/testHardwareInterface.dir/src/libcan/SocketCAN.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/testHardwareInterface.dir/src/libcan/SocketCAN.cpp.o -MF CMakeFiles/testHardwareInterface.dir/src/libcan/SocketCAN.cpp.o.d -o CMakeFiles/testHardwareInterface.dir/src/libcan/SocketCAN.cpp.o -c /home/hanzx/dev/projects/arx5/libarx5/src/libcan/SocketCAN.cpp

CMakeFiles/testHardwareInterface.dir/src/libcan/SocketCAN.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testHardwareInterface.dir/src/libcan/SocketCAN.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hanzx/dev/projects/arx5/libarx5/src/libcan/SocketCAN.cpp > CMakeFiles/testHardwareInterface.dir/src/libcan/SocketCAN.cpp.i

CMakeFiles/testHardwareInterface.dir/src/libcan/SocketCAN.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testHardwareInterface.dir/src/libcan/SocketCAN.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hanzx/dev/projects/arx5/libarx5/src/libcan/SocketCAN.cpp -o CMakeFiles/testHardwareInterface.dir/src/libcan/SocketCAN.cpp.s

CMakeFiles/testHardwareInterface.dir/src/hardware/A8120.cpp.o: CMakeFiles/testHardwareInterface.dir/flags.make
CMakeFiles/testHardwareInterface.dir/src/hardware/A8120.cpp.o: ../src/hardware/A8120.cpp
CMakeFiles/testHardwareInterface.dir/src/hardware/A8120.cpp.o: CMakeFiles/testHardwareInterface.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hanzx/dev/projects/arx5/libarx5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/testHardwareInterface.dir/src/hardware/A8120.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/testHardwareInterface.dir/src/hardware/A8120.cpp.o -MF CMakeFiles/testHardwareInterface.dir/src/hardware/A8120.cpp.o.d -o CMakeFiles/testHardwareInterface.dir/src/hardware/A8120.cpp.o -c /home/hanzx/dev/projects/arx5/libarx5/src/hardware/A8120.cpp

CMakeFiles/testHardwareInterface.dir/src/hardware/A8120.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testHardwareInterface.dir/src/hardware/A8120.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hanzx/dev/projects/arx5/libarx5/src/hardware/A8120.cpp > CMakeFiles/testHardwareInterface.dir/src/hardware/A8120.cpp.i

CMakeFiles/testHardwareInterface.dir/src/hardware/A8120.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testHardwareInterface.dir/src/hardware/A8120.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hanzx/dev/projects/arx5/libarx5/src/hardware/A8120.cpp -o CMakeFiles/testHardwareInterface.dir/src/hardware/A8120.cpp.s

CMakeFiles/testHardwareInterface.dir/src/hardware/can.cpp.o: CMakeFiles/testHardwareInterface.dir/flags.make
CMakeFiles/testHardwareInterface.dir/src/hardware/can.cpp.o: ../src/hardware/can.cpp
CMakeFiles/testHardwareInterface.dir/src/hardware/can.cpp.o: CMakeFiles/testHardwareInterface.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hanzx/dev/projects/arx5/libarx5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/testHardwareInterface.dir/src/hardware/can.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/testHardwareInterface.dir/src/hardware/can.cpp.o -MF CMakeFiles/testHardwareInterface.dir/src/hardware/can.cpp.o.d -o CMakeFiles/testHardwareInterface.dir/src/hardware/can.cpp.o -c /home/hanzx/dev/projects/arx5/libarx5/src/hardware/can.cpp

CMakeFiles/testHardwareInterface.dir/src/hardware/can.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testHardwareInterface.dir/src/hardware/can.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hanzx/dev/projects/arx5/libarx5/src/hardware/can.cpp > CMakeFiles/testHardwareInterface.dir/src/hardware/can.cpp.i

CMakeFiles/testHardwareInterface.dir/src/hardware/can.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testHardwareInterface.dir/src/hardware/can.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hanzx/dev/projects/arx5/libarx5/src/hardware/can.cpp -o CMakeFiles/testHardwareInterface.dir/src/hardware/can.cpp.s

CMakeFiles/testHardwareInterface.dir/src/hardware/dbus.cpp.o: CMakeFiles/testHardwareInterface.dir/flags.make
CMakeFiles/testHardwareInterface.dir/src/hardware/dbus.cpp.o: ../src/hardware/dbus.cpp
CMakeFiles/testHardwareInterface.dir/src/hardware/dbus.cpp.o: CMakeFiles/testHardwareInterface.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hanzx/dev/projects/arx5/libarx5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/testHardwareInterface.dir/src/hardware/dbus.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/testHardwareInterface.dir/src/hardware/dbus.cpp.o -MF CMakeFiles/testHardwareInterface.dir/src/hardware/dbus.cpp.o.d -o CMakeFiles/testHardwareInterface.dir/src/hardware/dbus.cpp.o -c /home/hanzx/dev/projects/arx5/libarx5/src/hardware/dbus.cpp

CMakeFiles/testHardwareInterface.dir/src/hardware/dbus.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testHardwareInterface.dir/src/hardware/dbus.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hanzx/dev/projects/arx5/libarx5/src/hardware/dbus.cpp > CMakeFiles/testHardwareInterface.dir/src/hardware/dbus.cpp.i

CMakeFiles/testHardwareInterface.dir/src/hardware/dbus.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testHardwareInterface.dir/src/hardware/dbus.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hanzx/dev/projects/arx5/libarx5/src/hardware/dbus.cpp -o CMakeFiles/testHardwareInterface.dir/src/hardware/dbus.cpp.s

CMakeFiles/testHardwareInterface.dir/src/hardware/math_ops.cpp.o: CMakeFiles/testHardwareInterface.dir/flags.make
CMakeFiles/testHardwareInterface.dir/src/hardware/math_ops.cpp.o: ../src/hardware/math_ops.cpp
CMakeFiles/testHardwareInterface.dir/src/hardware/math_ops.cpp.o: CMakeFiles/testHardwareInterface.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hanzx/dev/projects/arx5/libarx5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/testHardwareInterface.dir/src/hardware/math_ops.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/testHardwareInterface.dir/src/hardware/math_ops.cpp.o -MF CMakeFiles/testHardwareInterface.dir/src/hardware/math_ops.cpp.o.d -o CMakeFiles/testHardwareInterface.dir/src/hardware/math_ops.cpp.o -c /home/hanzx/dev/projects/arx5/libarx5/src/hardware/math_ops.cpp

CMakeFiles/testHardwareInterface.dir/src/hardware/math_ops.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testHardwareInterface.dir/src/hardware/math_ops.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hanzx/dev/projects/arx5/libarx5/src/hardware/math_ops.cpp > CMakeFiles/testHardwareInterface.dir/src/hardware/math_ops.cpp.i

CMakeFiles/testHardwareInterface.dir/src/hardware/math_ops.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testHardwareInterface.dir/src/hardware/math_ops.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hanzx/dev/projects/arx5/libarx5/src/hardware/math_ops.cpp -o CMakeFiles/testHardwareInterface.dir/src/hardware/math_ops.cpp.s

# Object files for target testHardwareInterface
testHardwareInterface_OBJECTS = \
"CMakeFiles/testHardwareInterface.dir/src/test/testHardwareInterface.cpp.o" \
"CMakeFiles/testHardwareInterface.dir/src/arx5_base/hardware_interface.cpp.o" \
"CMakeFiles/testHardwareInterface.dir/src/arx5_base/joint_trajectories.cpp.o" \
"CMakeFiles/testHardwareInterface.dir/src/arx5_base/kinematics_dynamics.cpp.o" \
"CMakeFiles/testHardwareInterface.dir/src/arx5_base/planner.cpp.o" \
"CMakeFiles/testHardwareInterface.dir/src/arx5_base/state_estimation.cpp.o" \
"CMakeFiles/testHardwareInterface.dir/src/arx5_utils/rate.cpp.o" \
"CMakeFiles/testHardwareInterface.dir/src/libcan/CANAdapter.cpp.o" \
"CMakeFiles/testHardwareInterface.dir/src/libcan/CANFrameParser.cpp.o" \
"CMakeFiles/testHardwareInterface.dir/src/libcan/SocketCAN.cpp.o" \
"CMakeFiles/testHardwareInterface.dir/src/hardware/A8120.cpp.o" \
"CMakeFiles/testHardwareInterface.dir/src/hardware/can.cpp.o" \
"CMakeFiles/testHardwareInterface.dir/src/hardware/dbus.cpp.o" \
"CMakeFiles/testHardwareInterface.dir/src/hardware/math_ops.cpp.o"

# External object files for target testHardwareInterface
testHardwareInterface_EXTERNAL_OBJECTS =

testHardwareInterface: CMakeFiles/testHardwareInterface.dir/src/test/testHardwareInterface.cpp.o
testHardwareInterface: CMakeFiles/testHardwareInterface.dir/src/arx5_base/hardware_interface.cpp.o
testHardwareInterface: CMakeFiles/testHardwareInterface.dir/src/arx5_base/joint_trajectories.cpp.o
testHardwareInterface: CMakeFiles/testHardwareInterface.dir/src/arx5_base/kinematics_dynamics.cpp.o
testHardwareInterface: CMakeFiles/testHardwareInterface.dir/src/arx5_base/planner.cpp.o
testHardwareInterface: CMakeFiles/testHardwareInterface.dir/src/arx5_base/state_estimation.cpp.o
testHardwareInterface: CMakeFiles/testHardwareInterface.dir/src/arx5_utils/rate.cpp.o
testHardwareInterface: CMakeFiles/testHardwareInterface.dir/src/libcan/CANAdapter.cpp.o
testHardwareInterface: CMakeFiles/testHardwareInterface.dir/src/libcan/CANFrameParser.cpp.o
testHardwareInterface: CMakeFiles/testHardwareInterface.dir/src/libcan/SocketCAN.cpp.o
testHardwareInterface: CMakeFiles/testHardwareInterface.dir/src/hardware/A8120.cpp.o
testHardwareInterface: CMakeFiles/testHardwareInterface.dir/src/hardware/can.cpp.o
testHardwareInterface: CMakeFiles/testHardwareInterface.dir/src/hardware/dbus.cpp.o
testHardwareInterface: CMakeFiles/testHardwareInterface.dir/src/hardware/math_ops.cpp.o
testHardwareInterface: CMakeFiles/testHardwareInterface.dir/build.make
testHardwareInterface: /usr/lib/x86_64-linux-gnu/liborocos-kdl.so
testHardwareInterface: CMakeFiles/testHardwareInterface.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hanzx/dev/projects/arx5/libarx5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Linking CXX executable testHardwareInterface"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testHardwareInterface.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testHardwareInterface.dir/build: testHardwareInterface
.PHONY : CMakeFiles/testHardwareInterface.dir/build

CMakeFiles/testHardwareInterface.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testHardwareInterface.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testHardwareInterface.dir/clean

CMakeFiles/testHardwareInterface.dir/depend:
	cd /home/hanzx/dev/projects/arx5/libarx5/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hanzx/dev/projects/arx5/libarx5 /home/hanzx/dev/projects/arx5/libarx5 /home/hanzx/dev/projects/arx5/libarx5/build /home/hanzx/dev/projects/arx5/libarx5/build /home/hanzx/dev/projects/arx5/libarx5/build/CMakeFiles/testHardwareInterface.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testHardwareInterface.dir/depend

