#include "application/application.hpp"
#include "interpreter/command_interpreter.hpp"

bool CommandInterpreter::interpret(std::string command, std::string content) {
  std::map<std::string, Command *>::iterator it = commands.find(command);
  if (it == commands.end())
    return false;

  it->second->run_command(content);
  return true;
}

void CommandInterpreter::set_state_marker(std::string state_marker) {
  this->state_marker = state_marker;
}

std::string CommandInterpreter::get_state_marker() { return state_marker; }
