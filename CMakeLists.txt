cmake_minimum_required(VERSION 3.29.2)

project(JailShell VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(PROJECT_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

enable_testing()

find_package(Boost REQUIRED COMPONENTS system filesystem)

add_subdirectory(src)
add_subdirectory(tests)

add_executable(jailshell src/main.cpp)

include_directories(${PROJECT_INCLUDE_DIR} ${Boost_INCLUDE_DIRS})

target_link_libraries(jailshell 
  PRIVATE
  Boost::system Boost::filesystem
  commands
  core
  errors
  server
  client
)

