include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.2
)

FetchContent_MakeAvailable(googletest)
enable_testing()

add_executable(
  commands_test 
  commands_test.cpp
)


target_link_libraries(
  commands_test
  PRIVATE
  GTest::gtest_main
  server
  commands
  core
)

add_test(commands_gtest commands_test)
add_test(NAME CommandsFixture.LS COMMAND commands_test --gtest_filter=CommandsFixture.LS)
