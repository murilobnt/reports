#include "command/command_help.hpp"

CommandHelp::CommandHelp(std::string description,
                         CommandInterpreter *command_interpreter)
    : MBNTCommand(description) {
  this->command_interpreter = command_interpreter;
}

bool CommandHelp::run_command(std::string content) {
  std::map<std::string, Command *> commands =
      command_interpreter->get_commands();
  std::cout << "List of commands: " << std::endl << "---" << std::endl;
  for (std::map<std::string, Command *>::iterator it = commands.begin();
       it != commands.end(); ++it) {
    std::cout << it->first << ": " << it->second->get_description() << std::endl
              << "---" << std::endl;
  }
  std::cout << "exit: Halts the execution of this application." << std::endl
            << "---" << std::endl;

  return true;
}
