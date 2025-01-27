
add_library(commands commands/os_command.cpp)
add_library(core core/core.cpp)
add_library(errors errors/command_not_found_err.cpp)


target_include_directories(commands PUBLIC ${PROJECT_INCLUDE_DIR})
target_include_directories(core PUBLIC ${PROJECT_INCLUDE_DIR})
target_include_directories(errors PUBLIC ${PROJECT_INCLUDE_DIR})
