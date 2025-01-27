add_library(client client.cpp)

target_include_directories(client PUBLIC ${PROJECT_INCLUDE_DIR})
target_link_libraries(client Boost::system Boost::filesystem)
