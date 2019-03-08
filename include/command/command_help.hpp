#ifndef COMMAND_HELP_HPP
#define COMMAND_HELP_HPP

#include "command/m_bnt_command.hpp"

class CommandHelp : public MBNTCommand {
public:
  CommandHelp(std::string description, CommandInterpreter *command_interpreter);
  bool run_command(std::string content = "");
};

#endif
