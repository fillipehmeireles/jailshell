cmake_minimum_required(VERSION 3.29.2)

project(JailShell VERSION 1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find Boost library
find_package(Boost REQUIRED COMPONENTS system filesystem)

# Add the executable target
add_executable(jailshell src/main.cpp 
  src/client.cpp 
  src/sys/commands/command.cpp 
  src/sys/core/core.cpp
)

include_directories(${CMAKE_SOURCE_DIR}/include ${Boost_INCLUDE_DIRS})

# Link Boost libraries to the target
target_link_libraries(jailshell Boost::system Boost::filesystem)
