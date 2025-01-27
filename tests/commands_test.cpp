#include <gtest/gtest.h>
#include <string>
#include <iostream>
#include "os_command.h"
#include "server.h"
#include <cstdio>
#include <memory>
#include <stdexcept>

class CommandsFixture: public ::testing::Test{
  protected:
    Sys::Core core_obj;
    void SetUp() override {
      core_obj.SetupBuiltin();
    }
};

// TODO: In order to assert it a environment must be created.
TEST_F(CommandsFixture, OsCommand) {
  std::string input = "ls";
  Sys::Commands::Command* cmd = core_obj.GetSysCommand(input);
  std::unique_ptr<std::string> result = cmd->Run();

  if(result != nullptr)
  {
    testing::internal::CaptureStdout();
    std::cout<<  "DATA IS:::: \n "<< *result <<std::endl;
    std::string output = ::testing::internal::GetCapturedStdout();
  }

  // EXPECT_STREQ("running os command\n", result.c_str());
}



