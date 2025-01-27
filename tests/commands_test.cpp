#include <gtest/gtest.h>
#include <string>
#include <iostream>
#include "os_command.h"
#include "server.h"

class CommandsFixture: public ::testing::Test{
  protected:
    Sys::Core core_obj;
    void SetUp() override {
      core_obj.SetupBuiltin();
    }
};

TEST_F(CommandsFixture, LS) {
  std::string input = "ls";
  Sys::Commands::Command* cmd = core_obj.GetSysCommand(input);
  std::string result = cmd->Run();
  EXPECT_STREQ("running os command\n", result.c_str());
}

