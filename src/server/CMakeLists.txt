add_library(server server.cpp)

target_include_directories(server PUBLIC ${PROJECT_INCLUDE_DIR})
target_link_libraries(server Boost::system Boost::filesystem)
