add_library(command_utils command_utils.cpp)

target_include_directories(command_utils PUBLIC ${PROJECT_INCLUDE_DIR})
target_link_libraries(command_utils Boost::system Boost::filesystem)
